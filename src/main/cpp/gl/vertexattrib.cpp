//
// Created by Swung 0x48 on 2025/2/19.
//

#include "vertexattrib.h"

#define DEBUG 0

void glVertexAttribI1ui(GLuint index, GLuint x) {
    LOG()
    GET_GL4ES_FUNC(void, glVertexAttribI1ui, GLuint, GLuint)
    CALL_GL4ES_FUNC(glVertexAttribI1ui, index, x)
    GLES.glVertexAttribI4ui(index, x, 0, 0, 0);
}

void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    LOG()
    GET_GL4ES_FUNC(void, glVertexAttribI2ui, GLuint, GLuint, GLuint)
    CALL_GL4ES_FUNC(glVertexAttribI2ui, index, x, y)
    GLES.glVertexAttribI4ui(index, x, y, 0, 0);
}

void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    LOG()
    GET_GL4ES_FUNC(void, glVertexAttribI3ui, GLuint, GLuint, GLuint, GLuint)
    CALL_GL4ES_FUNC(glVertexAttribI3ui, index, x, y, z)
    GLES.glVertexAttribI4ui(index, x, y, z, 0);
}
