//
// Created by BZLZHH on 2025/1/26.
//

#include <cctype>
#include "shader.h"

#include "gl.h"
#include "log.h"
#include "../gles/loader.h"
#include "../includes.h"
#include "glsl/glsl_for_es.h"
#include "../config/settings.h"

#define DEBUG 0

struct shader_t shaderInfo;

bool can_run_essl3(unsigned int esversion, const char *glsl) {
    if (strncmp(glsl, "#version 100", 12) == 0) {
        return true;
    }

    unsigned int glsl_version = 0;
    if (strncmp(glsl, "#version 300 es", 15) == 0) {
        glsl_version = 300;
    } else if (strncmp(glsl, "#version 310 es", 15) == 0) {
        glsl_version = 310;
    } else if (strncmp(glsl, "#version 320 es", 15) == 0) {
        glsl_version = 320;
    } else {
        return false;
    }
    return esversion >= glsl_version;
}

bool is_direct_shader(const char *glsl)
{
    bool es3_ability = can_run_essl3(hardware->es_version, glsl);
    return es3_ability;
}

extern "C" EXPORT GLuint glCreateShader(GLenum type) {
    LOG()
    GLuint shader = gl4es_glCreateShader(type);
    CHECK_GL_ERROR
    return shader;
}

extern "C" EXPORT void glCompileShader(GLuint shader) {
    LOG()
    gl4es_glCompileShader(shader);
    CHECK_GL_ERROR
}

void glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint *length) {
    LOG()
    gl4es_glShaderSource(shader,count,string,length);
    shaderInfo.id = 0;
    shaderInfo.converted = "";
    shaderInfo.frag_data_changed = 0;
    size_t l = 0;
    for (int i=0; i<count; i++) l+=(length && length[i] >= 0)?length[i]:strlen(string[i]);
    std::string glsl_src, essl_src;
    glsl_src.reserve(l + 1);
    if (length) {
        for (int i = 0; i < count; i++) {
            if(length[i] >= 0)
                glsl_src += std::string_view(string[i], length[i]);
            else
                glsl_src += string[i];
        }
    } else {
        for (int i=0; i < count; i++)
            glsl_src += string[i];
    }
    if (GLES.glShaderSource) {
        if(is_direct_shader(glsl_src.c_str())){
            LOG_D("[INFO] [Shader] Direct shader source: ")
            LOG_D("%s", glsl_src.c_str())
            essl_src = glsl_src;
        } else {
            int glsl_version = getGLSLVersion(glsl_src.c_str());
            if (glsl_version < 140) { LOG_D("Shader won't be processed in mg shaderconv."); return; } // will be converted in gl4es
            LOG_D("[INFO] [Shader] Shader source: ")
            LOG_D("%s", glsl_src.c_str())
            GLint shaderType;
            GLES.glGetShaderiv(shader, GL_SHADER_TYPE, &shaderType);
            essl_src = getCachedESSL(glsl_src.c_str(), hardware->es_version);
            if (essl_src.empty())
                essl_src = GLSLtoGLSLES(glsl_src.c_str(), shaderType, hardware->es_version, glsl_version);
            if (essl_src.empty()) {
                LOG_E("Failed to convert shader %d.", shader)
                return;
            }
            LOG_D("\n[INFO] [Shader] Converted Shader source: \n%s", essl_src.c_str())
        }
        if (!essl_src.empty()) {
            shaderInfo.id = shader;
            shaderInfo.converted = essl_src;
            const char* s[] = { essl_src.c_str() };
            GLES.glShaderSource(shader, count, s, nullptr);
        } else LOG_E("Failed to convert glsl.")
        CHECK_GL_ERROR
    } else {
        LOG_E("No GLES.glShaderSource")
    }
}

void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) {
    LOG()
    GET_GL4ES_FUNC(void, glGetShaderiv, GLuint shader, GLenum pname, GLint *params)
    CALL_GL4ES_FUNC(glGetShaderiv, shader, pname, params)
    GLES.glGetShaderiv(shader, pname, params);
    if(global_settings.ignore_error >= 1 && pname == GL_COMPILE_STATUS && !*params) {
        GLchar infoLog[512];
        GLES.glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        LOG_W_FORCE("Shader %d compilation failed: \n%s", shader, infoLog)
        LOG_W_FORCE("Now try to cheat.")
        *params = GL_TRUE;
    }
    CHECK_GL_ERROR
}

extern "C" {
EXPORT void glDeleteObjectARB(GLhandleARB obj) {
    if (glIsProgram(obj)) {
        glDeleteProgram(obj);
    } else {
        glDeleteShader(obj);
    }
}

EXPORT GLhandleARB glGetHandleARB(GLenum pname) {
    if (pname == GL_PROGRAM_OBJECT_ARB) {
        GLint currentProg;
        glGetIntegerv(GL_CURRENT_PROGRAM, &currentProg);
        return (GLhandleARB)currentProg;
    }
    return 0;
}

EXPORT void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj) {
    glDetachShader(containerObj, attachedObj);
}

EXPORT GLhandleARB glCreateShaderObjectARB(GLenum shaderType) {
    return glCreateShader(shaderType);
}

EXPORT void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count,
                              const GLchar **string, const GLint *length) {
    glShaderSource(shaderObj, count, string, length);
}

EXPORT GLhandleARB glCreateProgramObjectARB(void) {
    return glCreateProgram();
}

EXPORT void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj) {
    glAttachShader(containerObj, obj);
}

EXPORT void glLinkProgramARB(GLhandleARB programObj) {
    glLinkProgram(programObj);
}

EXPORT void glUseProgramObjectARB(GLhandleARB programObj) {
    glUseProgram(programObj);
}

EXPORT void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params) {
    GLint iparam;
    if (glIsShader(obj)) {
        glGetShaderiv(obj, pname, &iparam);
    } else {
        glGetProgramiv(obj, pname, &iparam);
    }
    if (params) {
        params[0] = (GLfloat)iparam;
    }
}

EXPORT void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params) {
    if (glIsShader(obj)) {
        glGetShaderiv(obj, pname, params);
    } else {
        glGetProgramiv(obj, pname, params);
    }
}

//EXPORT void glVertexAttrib1fARB(GLuint index, GLfloat v0) { glVertexAttrib1f(index, v0); }
EXPORT void glVertexAttrib1sARB(GLuint index, GLshort v0) { glVertexAttrib1f(index, v0); }
EXPORT void glVertexAttrib1dARB(GLuint index, GLdouble v0) { glVertexAttrib1f(index, v0); }
//EXPORT void glVertexAttrib2fARB(GLuint index, GLfloat v0, GLfloat v1) { glVertexAttrib2f(index, v0, v1); }
EXPORT void glVertexAttrib2sARB(GLuint index, GLshort v0, GLshort v1) { glVertexAttrib2f(index, v0, v1); }
EXPORT void glVertexAttrib2dARB(GLuint index, GLdouble v0, GLdouble v1) { glVertexAttrib2f(index, v0, v1); }
//EXPORT void glVertexAttrib3fARB(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2) { glVertexAttrib3f(index, v0, v1, v2); }
EXPORT void glVertexAttrib3sARB(GLuint index, GLshort v0, GLshort v1, GLshort v2) { glVertexAttrib3f(index, v0, v1, v2); }
EXPORT void glVertexAttrib3dARB(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2) { glVertexAttrib3f(index, v0, v1, v2); }
//EXPORT void glVertexAttrib4fARB(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { glVertexAttrib4f(index, v0, v1, v2, v3); }
EXPORT void glVertexAttrib4sARB(GLuint index, GLshort v0, GLshort v1, GLshort v2, GLshort v3) { glVertexAttrib4f(index, v0, v1, v2, v3); }
EXPORT void glVertexAttrib4dARB(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { glVertexAttrib4f(index, v0, v1, v2, v3); }

//EXPORT void glVertexAttrib1fvARB(GLuint index, const GLfloat *v) { glVertexAttrib1fv(index, v); }
EXPORT void glVertexAttrib1svARB(GLuint index, const GLshort *v) { glVertexAttrib1fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib1dvARB(GLuint index, const GLdouble *v) { glVertexAttrib1fv(index, (GLfloat*)v); }
//EXPORT void glVertexAttrib2fvARB(GLuint index, const GLfloat *v) { glVertexAttrib2fv(index, v); }
EXPORT void glVertexAttrib2svARB(GLuint index, const GLshort *v) { glVertexAttrib2fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib2dvARB(GLuint index, const GLdouble *v) { glVertexAttrib2fv(index, (GLfloat*)v); }
//EXPORT void glVertexAttrib3fvARB(GLuint index, const GLfloat *v) { glVertexAttrib3fv(index, v); }
EXPORT void glVertexAttrib3svARB(GLuint index, const GLshort *v) { glVertexAttrib3fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib3dvARB(GLuint index, const GLdouble *v) { glVertexAttrib3fv(index, (GLfloat*)v); }
//EXPORT void glVertexAttrib4fvARB(GLuint index, const GLfloat *v) { glVertexAttrib4fv(index, v); }
EXPORT void glVertexAttrib4svARB(GLuint index, const GLshort *v) { glVertexAttrib4fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib4dvARB(GLuint index, const GLdouble *v) { glVertexAttrib4fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib4ivARB(GLuint index, const GLint *v) { glVertexAttrib4fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib4bvARB(GLuint index, const GLbyte *v) { glVertexAttrib4fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib4ubvARB(GLuint index, const GLubyte *v) { glVertexAttrib4fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib4usvARB(GLuint index, const GLushort *v) { glVertexAttrib4fv(index, (GLfloat*)v); }
EXPORT void glVertexAttrib4uivARB(GLuint index, const GLuint *v) { glVertexAttrib4fv(index, (GLfloat*)v); }

EXPORT void glCompileShaderARB(GLhandleARB shader) { glCompileShader(shader); }
EXPORT GLhandleARB glCreateShaderARB(GLenum shaderType) { return glCreateShader(shaderType); }

//EXPORT void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
//    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
//}

//EXPORT void glEnableVertexAttribArrayARB(GLuint index) { glEnableVertexAttribArray(index); }
//EXPORT void glDisableVertexAttribArrayARB(GLuint index) { glDisableVertexAttribArray(index); }

//EXPORT void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB *name) {
//    glBindAttribLocation(programObj, index, name);
//}

//EXPORT void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength,
//                                 GLsizei *length, GLint *size, GLenum *type, GLcharARB *name) {
//    glGetActiveAttrib(programObj, index, maxLength, length, size, type, name);
//}

//EXPORT GLint glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB *name) {
//    return glGetAttribLocation(programObj, name);
//}

EXPORT void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble *params) { glGetVertexAttribfv(index, pname,(GLfloat*) params); }
//EXPORT void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat *params) { glGetVertexAttribfv(index, pname, params); }
//EXPORT void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint *params) { glGetVertexAttribiv(index, pname, params); }
//EXPORT void glGetVertexAttribPointervARB(GLuint index, GLenum pname, void **pointer) {
//    glGetVertexAttribPointerv(index, pname, pointer);
//}

}