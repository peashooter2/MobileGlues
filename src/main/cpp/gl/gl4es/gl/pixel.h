#ifndef _GL4ES_PIXEL_H_
#define _GL4ES_PIXEL_H_

#include <stdbool.h>
#include "gles.h"

typedef struct {
    GLenum type;
    GLint red, green, blue, alpha;
    int maxv;
} GL4ES_colorlayout_t;

typedef struct {
    GLfloat r, g, b, a;
} GL4ES_pixel_t;

#define widthalign(width, align) ((((uintptr_t)(width))+((uintptr_t)(align)-1))&(~((uintptr_t)(align)-1)))

bool GL4ES_pixel_convert(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   GLenum dst_format, GLenum dst_type, GLuint stride, GLuint align);

bool GL4ES_pixel_transform(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   const GLfloat *scale, const GLfloat *bias);

bool GL4ES_pixel_scale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLuint new_width, GLuint new_height,
                  GLenum format, GLenum type);

bool GL4ES_pixel_halfscale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool GL4ES_pixel_thirdscale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool GL4ES_pixel_quarterscale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool GL4ES_pixel_doublescale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool GL4ES_pixel_to_ppm(const GLvoid *pixels,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type, GLuint name, GLuint align);

// sRGB ->RGB colorspace conversion, for RGBA data...
void GL4ES_pixel_srgb_inplace(GLvoid* pixels, GLuint width, GLuint height);

#endif // _GL4ES_PIXEL_H_
