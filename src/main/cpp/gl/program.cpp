//
// Created by hanji on 2025/2/3.
//

#include <regex.h>
#include "log.h"
#include "shader.h"
#include "program.h"
#include <regex>
#include <cstring>
#include <iostream>
#include "../config/settings.h"

#define DEBUG 0

char* updateLayoutLocation(const char* esslSource, GLuint color, const char* name) {
    std::string shaderCode(esslSource);

    std::string pattern = std::string(R"((layout\s*$[^)]*location\s*=\s*\d+[^)]*$\s*)?)")
                          + R"(out\s+((?:highp|mediump|lowp|\w+\s+)*\w+)\s+)"
                          + name + R"(\s*;)";

    std::string replacement = "layout (location = " + std::to_string(color)
                              + ") out $2 " + name + ";";

    std::regex reg(pattern);
    std::string modifiedCode = std::regex_replace(shaderCode, reg, replacement);

    char* result = new char[modifiedCode.size() + 1];
    strcpy(result, modifiedCode.c_str());
    return result;
}

void glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name) {
    LOG()
    GET_GL4ES_FUNC(void, glBindFragDataLocation, GLuint program, GLuint color, const GLchar *name)
    CALL_GL4ES_FUNC(glBindFragDataLocation, program, color, name)
    LOG_D("glBindFragDataLocation(%d, %d, %s)", program, color, name)
//    if (g_gles_caps.GL_EXT_blend_func_extended) {
//        GLES.glBindFragDataLocationEXT(program, color, name);
//    } else {
//        LOG_W("Warning: No GL_EXT_blend_func_extended, skipping glBindFragDataLocation...");
//    }

    if (strlen(name) > 8 && strncmp(name, "outColor", 8) == 0) {
        const char* numberStr = name + 8;
        bool isNumber = true;
        for (int i = 0; numberStr[i] != '\0'; ++i) {
            if (!isdigit(numberStr[i])) {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            unsigned int extractedColor = static_cast<unsigned int>(std::stoul(numberStr));
            if (extractedColor == color) {
                // outColor was bound in glsl process. exit now
                LOG_D("Find outColor* with color *, skipping")
                return;
            }
        }
    }

    char* origin_glsl = nullptr;
    if (shaderInfo.frag_data_changed) {
        size_t glslLen  = strlen(shaderInfo.frag_data_changed_converted) + 1;
        origin_glsl = (char *)malloc(glslLen);
        if (origin_glsl == nullptr) {
            LOG_E("Memory reallocation failed for frag_data_changed_converted\n")
            return;
        }
        strcpy(origin_glsl, shaderInfo.frag_data_changed_converted);
    } else {
        size_t glslLen  = shaderInfo.converted.length() + 1;
        origin_glsl = (char *)malloc(glslLen);
        if (origin_glsl == nullptr) {
            LOG_E("Memory reallocation failed for converted\n")
            return;
        }
        strcpy(origin_glsl, shaderInfo.converted.c_str());
    }

    char* result_glsl = updateLayoutLocation(origin_glsl, color, name);
    free(origin_glsl);

    shaderInfo.frag_data_changed_converted = result_glsl;
    shaderInfo.frag_data_changed = 1;
}

extern "C" EXPORT GLuint glCreateProgram() {
    LOG()
    GLuint program = gl4es_glCreateProgram();
    CHECK_GL_ERROR
    return program;
}

void glLinkProgram(GLuint program) {
    LOG()
    LOG_D("glLinkProgram(%d)", program)
    if (!shaderInfo.converted.empty() && shaderInfo.frag_data_changed) {
        GLES.glShaderSource(shaderInfo.id, 1, (const GLchar * const*) &shaderInfo.frag_data_changed_converted, nullptr);
        GLES.glCompileShader(shaderInfo.id);
        GLint status = 0;
        GLES.glGetShaderiv(shaderInfo.id, GL_COMPILE_STATUS, &status);
        if(status!=GL_TRUE) {
            char tmp[500];
            GLES.glGetShaderInfoLog(shaderInfo.id, 500, nullptr, tmp);
            LOG_E("Failed to compile patched shader, log:\n%s", tmp)
        }
        GLES.glDetachShader(program, shaderInfo.id);
        GLES.glAttachShader(program, shaderInfo.id);
        CHECK_GL_ERROR
    }
    shaderInfo.id = 0;
    shaderInfo.converted = "";
    shaderInfo.frag_data_changed_converted = nullptr;
    shaderInfo.frag_data_changed = 0;
    //GLES.glLinkProgram(program);
    GET_GL4ES_FUNC(void, glLinkProgram, GLuint program)
    CALL_GL4ES_FUNC(glLinkProgram, program)

    CHECK_GL_ERROR
}

void glGetProgramiv(GLuint program, GLenum pname, GLint *params) {
    LOG()
    GET_GL4ES_FUNC(void, glGetProgramiv, GLuint program, GLenum pname, GLint *params)
    CALL_GL4ES_FUNC(glGetProgramiv, program, pname, params)
    GLES.glGetProgramiv(program, pname, params);
    if(global_settings.ignore_error >= 1 && (pname == GL_LINK_STATUS || pname == GL_VALIDATE_STATUS) && !*params) {
        GLchar infoLog[512];
        GLES.glGetProgramInfoLog(program, 512, nullptr, infoLog);

        LOG_W_FORCE("Program %d linking failed: \n%s", program, infoLog);
        LOG_W_FORCE("Now try to cheat.");
        *params = GL_TRUE;
    }
    CHECK_GL_ERROR
}

extern "C" {
EXPORT void glGetActiveUniformName(GLuint program,
                          GLuint uniformIndex,
                          GLsizei bufSize,
                          GLsizei* length,
                          char* uniformName)
{
    GLint uniformSize;
    GLenum uniformType;
    char rawName[bufSize];

    glGetActiveUniform(program, uniformIndex, bufSize, length,
                       &uniformSize, &uniformType, rawName);

    char* bracketPos = strchr(rawName, '[');
    if (bracketPos != nullptr) {
        *bracketPos = '\0';
    }

    strncpy(uniformName, rawName, bufSize);
    if (length != nullptr && *length > bufSize) {
        *length = (GLsizei)strlen(rawName);
    }
}
EXPORT void glGetActiveUniformNameARB(GLuint program,
                                      GLuint uniformIndex,
                                      GLsizei bufSize,
                                      GLsizei* length,
                                      char* uniformName) __attribute__((alias("glGetActiveUniformName")));

EXPORT GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const char *name) {
    if (program == 0 || glIsProgram(program) == GL_FALSE) {
        return -1;
    }
    
    GLuint resourceIndex = glGetProgramResourceIndex(program, programInterface, name);
    if (resourceIndex == GL_INVALID_INDEX) {
        return -1;
    }

    switch (programInterface) {
        case GL_PROGRAM_OUTPUT: {
            GLint index = 0;
            GLenum props[] = { GL_INDEX };
            GLsizei length;
            glGetProgramResourceiv(program, programInterface, resourceIndex,
                                   1, props, 1, &length, &index);
            return index;
        }
        case GL_UNIFORM: {
            return -1;
        }
        default: {
            return -1;
        }
    }
}
EXPORT void glGetProgramResourceLocationIndexARB(GLuint program, GLenum programInterface, const char *name) __attribute__((alias("glGetProgramResourceLocationIndex")));

EXPORT void glGetAttachedObjectsARB(GLhandleARB program, GLsizei maxCount, GLsizei* count, GLhandleARB* objects) {
    if (program == 0 || glIsProgram(program) == GL_FALSE) {
        return;
    }
    glGetAttachedShaders(program, maxCount, count, (GLuint*)objects);
}

EXPORT GLhandleARB glCreateProgramARB() { return glCreateProgram(); }

}