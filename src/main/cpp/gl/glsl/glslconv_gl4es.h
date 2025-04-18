//
// Created by BZLZHH on 2025/4/3.
//

#ifndef MOBILEGLUES_GLSLCONV_GL4ES_H
#define MOBILEGLUES_GLSLCONV_GL4ES_H

#include <cstdint>
#include "../gl.h"
namespace gl4es_code {
    typedef struct GL4ES_shaderconv_need_s {
        int need_color;      // front and back
        int need_secondary;  //  same
        int need_fogcoord;
        int need_texcoord;      // max texcoord needed (-1 for none)
        int need_notexarray;    // need to not use tex array
        int need_normalmatrix;  // if normal matrix is needed (for highp / mediump choosing)
        int need_mvmatrix;
        int need_mvpmatrix;
        int need_clean;         // this shader needs to stay "clean", no hack in here
        int need_clipvertex;
        uint32_t need_texs;          // flags of what tex is needed
    } GL4ES_shaderconv_need_t;

    char *GL4ES_ConvertShader(const char *pEntry, int isVertex, GL4ES_shaderconv_need_t *need,
                              int forwardPort);

    char *GL4ES_ConvertShaderVgpu(char *shader_source, GLenum type);

    int GL4ES_testGenericShader(GLenum type, char *glsl);
};
#endif //MOBILEGLUES_GLSLCONV_GL4ES_H
