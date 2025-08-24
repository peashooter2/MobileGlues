//
// Created by BZLZHH on 2025/1/27.
//

#include <GL/gl.h>

#ifndef MOBILEGLUES_GLES_H
#define MOBILEGLUES_GLES_H

#define GL_TEXTURE_LOD_BIAS_QCOM 0x8C96

#define APIENTRY_GLES

#define GL_FUNC_TYPEDEF(type, name, ...)                                       \
  typedef type(APIENTRY_GLES *name##_PTR)(__VA_ARGS__);

#ifdef __cplusplus
extern "C" {
#endif

GL_FUNC_TYPEDEF(void, glActiveTexture, GLenum texture)
GL_FUNC_TYPEDEF(void, glAttachShader, GLuint program, GLuint shader)
GL_FUNC_TYPEDEF(void, glBindAttribLocation, GLuint program, GLuint index,
                const GLchar *name)
GL_FUNC_TYPEDEF(void, glBindBuffer, GLenum target, GLuint buffer)
GL_FUNC_TYPEDEF(void, glBindFramebuffer, GLenum target, GLuint framebuffer)
GL_FUNC_TYPEDEF(void, glBindRenderbuffer, GLenum target, GLuint renderbuffer)
GL_FUNC_TYPEDEF(void, glBindTexture, GLenum target, GLuint texture)
GL_FUNC_TYPEDEF(void, glBlendColor, GLfloat red, GLfloat green, GLfloat blue,
                GLfloat alpha)
GL_FUNC_TYPEDEF(void, glBlendEquation, GLenum mode)
GL_FUNC_TYPEDEF(void, glBlendEquationSeparate, GLenum modeRGB, GLenum modeAlpha)
GL_FUNC_TYPEDEF(void, glBlendFunc, GLenum sfactor, GLenum dfactor)
GL_FUNC_TYPEDEF(void, glBlendFuncSeparate, GLenum sfactorRGB, GLenum dfactorRGB,
                GLenum sfactorAlpha, GLenum dfactorAlpha)
GL_FUNC_TYPEDEF(void, glBufferData, GLenum target, GLsizeiptr size,
                const void *data, GLenum usage)
GL_FUNC_TYPEDEF(void, glBufferSubData, GLenum target, GLintptr offset,
                GLsizeiptr size, const void *data)
GL_FUNC_TYPEDEF(GLenum, glCheckFramebufferStatus, GLenum target)
GL_FUNC_TYPEDEF(void, glClear, GLbitfield mask)
GL_FUNC_TYPEDEF(void, glClearColor, GLfloat red, GLfloat green, GLfloat blue,
                GLfloat alpha)
GL_FUNC_TYPEDEF(void, glClearDepthf, GLfloat d)
GL_FUNC_TYPEDEF(void, glClearStencil, GLint s)
GL_FUNC_TYPEDEF(void, glColorMask, GLboolean red, GLboolean green,
                GLboolean blue, GLboolean alpha)
GL_FUNC_TYPEDEF(void, glCompileShader, GLuint shader)
GL_FUNC_TYPEDEF(void, glCompressedTexImage2D, GLenum target, GLint level,
                GLenum internalformat, GLsizei width, GLsizei height,
                GLint border, GLsizei imageSize, const void *data)
GL_FUNC_TYPEDEF(void, glCompressedTexSubImage2D, GLenum target, GLint level,
                GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                GLenum format, GLsizei imageSize, const void *data)
// GL_FUNC_TYPEDEF(void, glCopyTexImage1D, GLenum target, GLint level, GLenum
// internalFormat, GLint x, GLint y, GLsizei width, GLint border);
GL_FUNC_TYPEDEF(void, glCopyTexImage2D, GLenum target, GLint level,
                GLenum internalformat, GLint x, GLint y, GLsizei width,
                GLsizei height, GLint border)
GL_FUNC_TYPEDEF(void, glCopyTexSubImage2D, GLenum target, GLint level,
                GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width,
                GLsizei height)
GL_FUNC_TYPEDEF(GLuint, glCreateProgram)
GL_FUNC_TYPEDEF(GLuint, glCreateShader, GLenum type)
GL_FUNC_TYPEDEF(void, glCullFace, GLenum mode)
GL_FUNC_TYPEDEF(void, glDeleteBuffers, GLsizei n, const GLuint *buffers)
GL_FUNC_TYPEDEF(void, glDeleteFramebuffers, GLsizei n,
                const GLuint *framebuffers)
GL_FUNC_TYPEDEF(void, glDeleteProgram, GLuint program)
GL_FUNC_TYPEDEF(void, glDeleteRenderbuffers, GLsizei n,
                const GLuint *renderbuffers)
GL_FUNC_TYPEDEF(void, glDeleteShader, GLuint shader)
GL_FUNC_TYPEDEF(void, glDeleteTextures, GLsizei n, const GLuint *textures)
GL_FUNC_TYPEDEF(void, glDepthFunc, GLenum func)
GL_FUNC_TYPEDEF(void, glDepthMask, GLboolean flag)
GL_FUNC_TYPEDEF(void, glDepthRangef, GLfloat n, GLfloat f)
GL_FUNC_TYPEDEF(void, glDetachShader, GLuint program, GLuint shader)
GL_FUNC_TYPEDEF(void, glDisable, GLenum cap)
GL_FUNC_TYPEDEF(void, glDisableVertexAttribArray, GLuint index)
GL_FUNC_TYPEDEF(void, glDrawArrays, GLenum mode, GLint first, GLsizei count)
GL_FUNC_TYPEDEF(void, glDrawElements, GLenum mode, GLsizei count, GLenum type,
                const void *indices)
GL_FUNC_TYPEDEF(void, glEnable, GLenum cap)
GL_FUNC_TYPEDEF(void, glEnableVertexAttribArray, GLuint index)
GL_FUNC_TYPEDEF(void, glFinish)
GL_FUNC_TYPEDEF(void, glFlush)
GL_FUNC_TYPEDEF(void, glFramebufferRenderbuffer, GLenum target,
                GLenum attachment, GLenum renderbuffertarget,
                GLuint renderbuffer)
GL_FUNC_TYPEDEF(void, glFramebufferTexture2D, GLenum target, GLenum attachment,
                GLenum textarget, GLuint texture, GLint level)
GL_FUNC_TYPEDEF(void, glFrontFace, GLenum mode)
GL_FUNC_TYPEDEF(void, glGenBuffers, GLsizei n, GLuint *buffers)
GL_FUNC_TYPEDEF(void, glGenerateMipmap, GLenum target)
GL_FUNC_TYPEDEF(void, glGenFramebuffers, GLsizei n, GLuint *framebuffers)
GL_FUNC_TYPEDEF(void, glGenRenderbuffers, GLsizei n, GLuint *renderbuffers)
GL_FUNC_TYPEDEF(void, glGenTextures, GLsizei n, GLuint *textures)
GL_FUNC_TYPEDEF(void, glGetActiveAttrib, GLuint program, GLuint index,
                GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type,
                GLchar *name)
GL_FUNC_TYPEDEF(void, glGetActiveUniform, GLuint program, GLuint index,
                GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type,
                GLchar *name)
GL_FUNC_TYPEDEF(void, glGetAttachedShaders, GLuint program, GLsizei maxCount,
                GLsizei *count, GLuint *shaders)
GL_FUNC_TYPEDEF(GLint, glGetAttribLocation, GLuint program, const GLchar *name)
GL_FUNC_TYPEDEF(void, glGetBooleanv, GLenum pname, GLboolean *data)
GL_FUNC_TYPEDEF(void, glGetBufferParameteriv, GLenum target, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(GLenum, glGetError)
GL_FUNC_TYPEDEF(const GLubyte *, glGetString, GLenum)
GL_FUNC_TYPEDEF(const GLubyte *, glGetStringi, GLenum, GLuint)
GL_FUNC_TYPEDEF(void, glGetFloatv, GLenum pname, GLfloat *data)
GL_FUNC_TYPEDEF(void, glGetFramebufferAttachmentParameteriv, GLenum target,
                GLenum attachment, GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(void, glGetIntegerv, GLenum pname, GLint *data)
GL_FUNC_TYPEDEF(void, glGetProgramiv, GLuint program, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetProgramInfoLog, GLuint program, GLsizei bufSize,
                GLsizei *length, GLchar *infoLog)
GL_FUNC_TYPEDEF(void, glGetRenderbufferParameteriv, GLenum target, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetShaderiv, GLuint shader, GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(void, glGetShaderInfoLog, GLuint shader, GLsizei bufSize,
                GLsizei *length, GLchar *infoLog)
GL_FUNC_TYPEDEF(void, glGetShaderPrecisionFormat, GLenum shadertype,
                GLenum precisiontype, GLint *range, GLint *precision)
GL_FUNC_TYPEDEF(void, glGetShaderSource, GLuint shader, GLsizei bufSize,
                GLsizei *length, GLchar *source)
GL_FUNC_TYPEDEF(void, glGetTexParameterfv, GLenum target, GLenum pname,
                GLfloat *params)
GL_FUNC_TYPEDEF(void, glGetTexParameteriv, GLenum target, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetUniformfv, GLuint program, GLint location,
                GLfloat *params)
GL_FUNC_TYPEDEF(void, glGetUniformiv, GLuint program, GLint location,
                GLint *params)
GL_FUNC_TYPEDEF(GLint, glGetUniformLocation, GLuint program, const GLchar *name)
GL_FUNC_TYPEDEF(void, glGetVertexAttribfv, GLuint index, GLenum pname,
                GLfloat *params)
GL_FUNC_TYPEDEF(void, glGetVertexAttribiv, GLuint index, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetVertexAttribPointerv, GLuint index, GLenum pname,
                void **pointer)
GL_FUNC_TYPEDEF(void, glHint, GLenum target, GLenum mode)
GL_FUNC_TYPEDEF(GLboolean, glIsBuffer, GLuint buffer)
GL_FUNC_TYPEDEF(GLboolean, glIsEnabled, GLenum cap)
GL_FUNC_TYPEDEF(GLboolean, glIsFramebuffer, GLuint framebuffer)
GL_FUNC_TYPEDEF(GLboolean, glIsProgram, GLuint program)
GL_FUNC_TYPEDEF(GLboolean, glIsRenderbuffer, GLuint renderbuffer)
GL_FUNC_TYPEDEF(GLboolean, glIsShader, GLuint shader)
GL_FUNC_TYPEDEF(GLboolean, glIsTexture, GLuint texture)
GL_FUNC_TYPEDEF(void, glLineWidth, GLfloat width)
GL_FUNC_TYPEDEF(void, glLinkProgram, GLuint program)
GL_FUNC_TYPEDEF(void, glPixelStorei, GLenum pname, GLint param)
GL_FUNC_TYPEDEF(void, glPolygonOffset, GLfloat factor, GLfloat units)
GL_FUNC_TYPEDEF(void, glReadPixels, GLint x, GLint y, GLsizei width,
                GLsizei height, GLenum format, GLenum type, void *pixels)
GL_FUNC_TYPEDEF(void, glReleaseShaderCompiler)
GL_FUNC_TYPEDEF(void, glRenderbufferStorage, GLenum target,
                GLenum internalformat, GLsizei width, GLsizei height)
GL_FUNC_TYPEDEF(void, glSampleCoverage, GLfloat value, GLboolean invert)
GL_FUNC_TYPEDEF(void, glScissor, GLint x, GLint y, GLsizei width,
                GLsizei height)
GL_FUNC_TYPEDEF(void, glShaderBinary, GLsizei count, const GLuint *shaders,
                GLenum binaryformat, const void *binary, GLsizei length)
GL_FUNC_TYPEDEF(void, glShaderSource, GLuint shader, GLsizei count,
                const GLchar *const *string, const GLint *length)
GL_FUNC_TYPEDEF(void, glStencilFunc, GLenum func, GLint ref, GLuint mask)
GL_FUNC_TYPEDEF(void, glStencilFuncSeparate, GLenum face, GLenum func,
                GLint ref, GLuint mask)
GL_FUNC_TYPEDEF(void, glStencilMask, GLuint mask)
GL_FUNC_TYPEDEF(void, glStencilMaskSeparate, GLenum face, GLuint mask)
GL_FUNC_TYPEDEF(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass)
GL_FUNC_TYPEDEF(void, glStencilOpSeparate, GLenum face, GLenum sfail,
                GLenum dpfail, GLenum dppass)
// GL_FUNC_TYPEDEF(void, glTexImage1D, GLenum target, GLint level, GLint
// internalFormat, GLsizei width, GLint border, GLenum format, GLenum type,
// const GLvoid* pixels);
GL_FUNC_TYPEDEF(void, glTexImage2D, GLenum target, GLint level,
                GLint internalformat, GLsizei width, GLsizei height,
                GLint border, GLenum format, GLenum type, const void *pixels)
// GL_FUNC_TYPEDEF(void, glTexStorage1D, GLenum target, GLsizei levels, GLenum
// internalFormat, GLsizei width);
GL_FUNC_TYPEDEF(void, glTexParameterf, GLenum target, GLenum pname,
                GLfloat param)
GL_FUNC_TYPEDEF(void, glTexParameterfv, GLenum target, GLenum pname,
                const GLfloat *params)
GL_FUNC_TYPEDEF(void, glTexParameteri, GLenum target, GLenum pname, GLint param)
GL_FUNC_TYPEDEF(void, glTexParameteriv, GLenum target, GLenum pname,
                const GLint *params)
GL_FUNC_TYPEDEF(void, glTexSubImage2D, GLenum target, GLint level,
                GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                GLenum format, GLenum type, const void *pixels)
GL_FUNC_TYPEDEF(void, glUniform1f, GLint location, GLfloat v0)
GL_FUNC_TYPEDEF(void, glUniform1fv, GLint location, GLsizei count,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniform1i, GLint location, GLint v0)
GL_FUNC_TYPEDEF(void, glUniform1iv, GLint location, GLsizei count,
                const GLint *value)
GL_FUNC_TYPEDEF(void, glUniform2f, GLint location, GLfloat v0, GLfloat v1)
GL_FUNC_TYPEDEF(void, glUniform2fv, GLint location, GLsizei count,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniform2i, GLint location, GLint v0, GLint v1)
GL_FUNC_TYPEDEF(void, glUniform2iv, GLint location, GLsizei count,
                const GLint *value)
GL_FUNC_TYPEDEF(void, glUniform3f, GLint location, GLfloat v0, GLfloat v1,
                GLfloat v2)
GL_FUNC_TYPEDEF(void, glUniform3fv, GLint location, GLsizei count,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniform3i, GLint location, GLint v0, GLint v1, GLint v2)
GL_FUNC_TYPEDEF(void, glUniform3iv, GLint location, GLsizei count,
                const GLint *value)
GL_FUNC_TYPEDEF(void, glUniform4f, GLint location, GLfloat v0, GLfloat v1,
                GLfloat v2, GLfloat v3)
GL_FUNC_TYPEDEF(void, glUniform4fv, GLint location, GLsizei count,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniform4i, GLint location, GLint v0, GLint v1, GLint v2,
                GLint v3)
GL_FUNC_TYPEDEF(void, glUniform4iv, GLint location, GLsizei count,
                const GLint *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix2fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix3fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix4fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUseProgram, GLuint program)
GL_FUNC_TYPEDEF(void, glValidateProgram, GLuint program)
GL_FUNC_TYPEDEF(void, glVertexAttrib1f, GLuint index, GLfloat x)
GL_FUNC_TYPEDEF(void, glVertexAttrib1fv, GLuint index, const GLfloat *v)
GL_FUNC_TYPEDEF(void, glVertexAttrib2f, GLuint index, GLfloat x, GLfloat y)
GL_FUNC_TYPEDEF(void, glVertexAttrib2fv, GLuint index, const GLfloat *v)
GL_FUNC_TYPEDEF(void, glVertexAttrib3f, GLuint index, GLfloat x, GLfloat y,
                GLfloat z)
GL_FUNC_TYPEDEF(void, glVertexAttrib3fv, GLuint index, const GLfloat *v)
GL_FUNC_TYPEDEF(void, glVertexAttrib4f, GLuint index, GLfloat x, GLfloat y,
                GLfloat z, GLfloat w)
GL_FUNC_TYPEDEF(void, glVertexAttrib4fv, GLuint index, const GLfloat *v)
GL_FUNC_TYPEDEF(void, glVertexAttribPointer, GLuint index, GLint size,
                GLenum type, GLboolean normalized, GLsizei stride,
                const void *pointer)
GL_FUNC_TYPEDEF(void, glViewport, GLint x, GLint y, GLsizei width,
                GLsizei height)
GL_FUNC_TYPEDEF(void, glReadBuffer, GLenum src)
GL_FUNC_TYPEDEF(void, glDrawRangeElements, GLenum mode, GLuint start,
                GLuint end, GLsizei count, GLenum type, const void *indices)
GL_FUNC_TYPEDEF(void, glTexImage3D, GLenum target, GLint level,
                GLint internalformat, GLsizei width, GLsizei height,
                GLsizei depth, GLint border, GLenum format, GLenum type,
                const void *pixels)
GL_FUNC_TYPEDEF(void, glTexSubImage3D, GLenum target, GLint level,
                GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                GLsizei height, GLsizei depth, GLenum format, GLenum type,
                const void *pixels)
GL_FUNC_TYPEDEF(void, glCopyTexSubImage3D, GLenum target, GLint level,
                GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y,
                GLsizei width, GLsizei height)
GL_FUNC_TYPEDEF(void, glCompressedTexImage3D, GLenum target, GLint level,
                GLenum internalformat, GLsizei width, GLsizei height,
                GLsizei depth, GLint border, GLsizei imageSize,
                const void *data)
GL_FUNC_TYPEDEF(void, glCompressedTexSubImage3D, GLenum target, GLint level,
                GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize,
                const void *data)
GL_FUNC_TYPEDEF(void, glGenQueries, GLsizei n, GLuint *ids)
GL_FUNC_TYPEDEF(void, glDeleteQueries, GLsizei n, const GLuint *ids)
GL_FUNC_TYPEDEF(GLboolean, glIsQuery, GLuint id)
GL_FUNC_TYPEDEF(void, glBeginQuery, GLenum target, GLuint id)
GL_FUNC_TYPEDEF(void, glEndQuery, GLenum target)
GL_FUNC_TYPEDEF(void, glGetQueryiv, GLenum target, GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(void, glGetQueryObjectuiv, GLuint id, GLenum pname,
                GLuint *params)
GL_FUNC_TYPEDEF(GLboolean, glUnmapBuffer, GLenum target)
GL_FUNC_TYPEDEF(void, glGetBufferPointerv, GLenum target, GLenum pname,
                void **params)
GL_FUNC_TYPEDEF(void, glDrawBuffers, GLsizei n, const GLenum *bufs)
GL_FUNC_TYPEDEF(void, glUniformMatrix2x3fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix3x2fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix2x4fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix4x2fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix3x4fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glUniformMatrix4x3fv, GLint location, GLsizei count,
                GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glBlitFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1,
                GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1,
                GLbitfield mask, GLenum filter)
GL_FUNC_TYPEDEF(void, glRenderbufferStorageMultisample, GLenum target,
                GLsizei samples, GLenum internalformat, GLsizei width,
                GLsizei height)
GL_FUNC_TYPEDEF(void, glFramebufferTextureLayer, GLenum target,
                GLenum attachment, GLuint texture, GLint level, GLint layer)
GL_FUNC_TYPEDEF(void, glFlushMappedBufferRange, GLenum target, GLintptr offset,
                GLsizeiptr length)
GL_FUNC_TYPEDEF(void, glBindVertexArray, GLuint array)
GL_FUNC_TYPEDEF(void, glDeleteVertexArrays, GLsizei n, const GLuint *arrays)
GL_FUNC_TYPEDEF(void, glGenVertexArrays, GLsizei n, GLuint *arrays)
GL_FUNC_TYPEDEF(GLboolean, glIsVertexArray, GLuint array)
GL_FUNC_TYPEDEF(void, glGetIntegeri_v, GLenum target, GLuint index, GLint *data)
GL_FUNC_TYPEDEF(void, glBeginTransformFeedback, GLenum primitiveMode)
GL_FUNC_TYPEDEF(void, glEndTransformFeedback)
GL_FUNC_TYPEDEF(void, glBindBufferRange, GLenum target, GLuint index,
                GLuint buffer, GLintptr offset, GLsizeiptr size)
GL_FUNC_TYPEDEF(void, glBindBufferBase, GLenum target, GLuint index,
                GLuint buffer)
GL_FUNC_TYPEDEF(void, glTransformFeedbackVaryings, GLuint program,
                GLsizei count, const GLchar *const *varyings, GLenum bufferMode)
GL_FUNC_TYPEDEF(void, glGetTransformFeedbackVarying, GLuint program,
                GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size,
                GLenum *type, GLchar *name)
GL_FUNC_TYPEDEF(void, glVertexAttribIPointer, GLuint index, GLint size,
                GLenum type, GLsizei stride, const void *pointer)
GL_FUNC_TYPEDEF(void, glGetVertexAttribIiv, GLuint index, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetVertexAttribIuiv, GLuint index, GLenum pname,
                GLuint *params)
GL_FUNC_TYPEDEF(void, glVertexAttribI4i, GLuint index, GLint x, GLint y,
                GLint z, GLint w)
GL_FUNC_TYPEDEF(void, glVertexAttribI4ui, GLuint index, GLuint x, GLuint y,
                GLuint z, GLuint w)
GL_FUNC_TYPEDEF(void, glVertexAttribI4iv, GLuint index, const GLint *v)
GL_FUNC_TYPEDEF(void, glVertexAttribI4uiv, GLuint index, const GLuint *v)
GL_FUNC_TYPEDEF(void, glGetUniformuiv, GLuint program, GLint location,
                GLuint *params)
GL_FUNC_TYPEDEF(GLint, glGetFragDataLocation, GLuint program,
                const GLchar *name)
GL_FUNC_TYPEDEF(void, glUniform1ui, GLint location, GLuint v0)
GL_FUNC_TYPEDEF(void, glUniform2ui, GLint location, GLuint v0, GLuint v1)
GL_FUNC_TYPEDEF(void, glUniform3ui, GLint location, GLuint v0, GLuint v1,
                GLuint v2)
GL_FUNC_TYPEDEF(void, glUniform4ui, GLint location, GLuint v0, GLuint v1,
                GLuint v2, GLuint v3)
GL_FUNC_TYPEDEF(void, glUniform1uiv, GLint location, GLsizei count,
                const GLuint *value)
GL_FUNC_TYPEDEF(void, glUniform2uiv, GLint location, GLsizei count,
                const GLuint *value)
GL_FUNC_TYPEDEF(void, glUniform3uiv, GLint location, GLsizei count,
                const GLuint *value)
GL_FUNC_TYPEDEF(void, glUniform4uiv, GLint location, GLsizei count,
                const GLuint *value)
GL_FUNC_TYPEDEF(void, glClearBufferiv, GLenum buffer, GLint drawbuffer,
                const GLint *value)
GL_FUNC_TYPEDEF(void, glClearBufferuiv, GLenum buffer, GLint drawbuffer,
                const GLuint *value)
GL_FUNC_TYPEDEF(void, glClearBufferfv, GLenum buffer, GLint drawbuffer,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glClearBufferfi, GLenum buffer, GLint drawbuffer,
                GLfloat depth, GLint stencil)
GL_FUNC_TYPEDEF(void, glCopyBufferSubData, GLenum readTarget,
                GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset,
                GLsizeiptr size)
GL_FUNC_TYPEDEF(void, glGetUniformIndices, GLuint program, GLsizei uniformCount,
                const GLchar *const *uniformNames, GLuint *uniformIndices)
GL_FUNC_TYPEDEF(void, glGetActiveUniformsiv, GLuint program,
                GLsizei uniformCount, const GLuint *uniformIndices,
                GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(GLuint, glGetUniformBlockIndex, GLuint program,
                const GLchar *uniformBlockName)
GL_FUNC_TYPEDEF(void, glGetActiveUniformBlockiv, GLuint program,
                GLuint uniformBlockIndex, GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(void, glGetActiveUniformBlockName, GLuint program,
                GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length,
                GLchar *uniformBlockName)
GL_FUNC_TYPEDEF(void, glUniformBlockBinding, GLuint program,
                GLuint uniformBlockIndex, GLuint uniformBlockBinding)
GL_FUNC_TYPEDEF(void, glDrawArraysInstanced, GLenum mode, GLint first,
                GLsizei count, GLsizei instancecount)
GL_FUNC_TYPEDEF(void, glDrawElementsInstanced, GLenum mode, GLsizei count,
                GLenum type, const void *indices, GLsizei instancecount)
GL_FUNC_TYPEDEF(GLsync, glFenceSync, GLenum condition, GLbitfield flags)
GL_FUNC_TYPEDEF(GLboolean, glIsSync, GLsync sync)
GL_FUNC_TYPEDEF(void, glDeleteSync, GLsync sync)
GL_FUNC_TYPEDEF(GLenum, glClientWaitSync, GLsync sync, GLbitfield flags,
                GLuint64 timeout)
GL_FUNC_TYPEDEF(void, glWaitSync, GLsync sync, GLbitfield flags,
                GLuint64 timeout)
GL_FUNC_TYPEDEF(void, glGetInteger64v, GLenum pname, GLint64 *data)
GL_FUNC_TYPEDEF(void, glGetSynciv, GLsync sync, GLenum pname, GLsizei bufSize,
                GLsizei *length, GLint *values)
GL_FUNC_TYPEDEF(void, glGetInteger64i_v, GLenum target, GLuint index,
                GLint64 *data)
GL_FUNC_TYPEDEF(void, glGetBufferParameteri64v, GLenum target, GLenum pname,
                GLint64 *params)
GL_FUNC_TYPEDEF(void, glGenSamplers, GLsizei count, GLuint *samplers)
GL_FUNC_TYPEDEF(void, glDeleteSamplers, GLsizei count, const GLuint *samplers)
GL_FUNC_TYPEDEF(GLboolean, glIsSampler, GLuint sampler)
GL_FUNC_TYPEDEF(void, glBindSampler, GLuint unit, GLuint sampler)
GL_FUNC_TYPEDEF(void, glSamplerParameteri, GLuint sampler, GLenum pname,
                GLint param)
GL_FUNC_TYPEDEF(void, glSamplerParameteriv, GLuint sampler, GLenum pname,
                const GLint *param)
GL_FUNC_TYPEDEF(void, glSamplerParameterf, GLuint sampler, GLenum pname,
                GLfloat param)
GL_FUNC_TYPEDEF(void, glSamplerParameterfv, GLuint sampler, GLenum pname,
                const GLfloat *param)
GL_FUNC_TYPEDEF(void, glGetSamplerParameteriv, GLuint sampler, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetSamplerParameterfv, GLuint sampler, GLenum pname,
                GLfloat *params)
GL_FUNC_TYPEDEF(void, glVertexAttribDivisor, GLuint index, GLuint divisor)
GL_FUNC_TYPEDEF(void, glBindTransformFeedback, GLenum target, GLuint id)
GL_FUNC_TYPEDEF(void, glDeleteTransformFeedbacks, GLsizei n, const GLuint *ids)
GL_FUNC_TYPEDEF(void, glGenTransformFeedbacks, GLsizei n, GLuint *ids)
GL_FUNC_TYPEDEF(GLboolean, glIsTransformFeedback, GLuint id)
GL_FUNC_TYPEDEF(void, glPauseTransformFeedback)
GL_FUNC_TYPEDEF(void, glResumeTransformFeedback)
GL_FUNC_TYPEDEF(void, glGetProgramBinary, GLuint program, GLsizei bufSize,
                GLsizei *length, GLenum *binaryFormat, void *binary)
GL_FUNC_TYPEDEF(void, glProgramBinary, GLuint program, GLenum binaryFormat,
                const void *binary, GLsizei length)
GL_FUNC_TYPEDEF(void, glProgramParameteri, GLuint program, GLenum pname,
                GLint value)
GL_FUNC_TYPEDEF(void, glInvalidateFramebuffer, GLenum target,
                GLsizei numAttachments, const GLenum *attachments)
GL_FUNC_TYPEDEF(void, glInvalidateSubFramebuffer, GLenum target,
                GLsizei numAttachments, const GLenum *attachments, GLint x,
                GLint y, GLsizei width, GLsizei height)
GL_FUNC_TYPEDEF(void, glTexStorage2D, GLenum target, GLsizei levels,
                GLenum internalformat, GLsizei width, GLsizei height)
GL_FUNC_TYPEDEF(void, glTexStorage3D, GLenum target, GLsizei levels,
                GLenum internalformat, GLsizei width, GLsizei height,
                GLsizei depth)
GL_FUNC_TYPEDEF(void, glGetInternalformativ, GLenum target,
                GLenum internalformat, GLenum pname, GLsizei bufSize,
                GLint *params)
GL_FUNC_TYPEDEF(void, glDispatchCompute, GLuint num_groups_x,
                GLuint num_groups_y, GLuint num_groups_z)
GL_FUNC_TYPEDEF(void, glDispatchComputeIndirect, GLintptr indirect)
GL_FUNC_TYPEDEF(void, glDrawArraysIndirect, GLenum mode, const void *indirect)
GL_FUNC_TYPEDEF(void, glDrawElementsIndirect, GLenum mode, GLenum type,
                const void *indirect)
GL_FUNC_TYPEDEF(void, glFramebufferParameteri, GLenum target, GLenum pname,
                GLint param)
GL_FUNC_TYPEDEF(void, glGetFramebufferParameteriv, GLenum target, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetProgramInterfaceiv, GLuint program,
                GLenum programInterface, GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(GLuint, glGetProgramResourceIndex, GLuint program,
                GLenum programInterface, const GLchar *name)
GL_FUNC_TYPEDEF(void, glGetProgramResourceName, GLuint program,
                GLenum programInterface, GLuint index, GLsizei bufSize,
                GLsizei *length, GLchar *name)
GL_FUNC_TYPEDEF(void, glGetProgramResourceiv, GLuint program,
                GLenum programInterface, GLuint index, GLsizei propCount,
                const GLenum *props, GLsizei bufSize, GLsizei *length,
                GLint *params)
GL_FUNC_TYPEDEF(GLint, glGetProgramResourceLocation, GLuint program,
                GLenum programInterface, const GLchar *name)
GL_FUNC_TYPEDEF(void, glUseProgramStages, GLuint pipeline, GLbitfield stages,
                GLuint program)
GL_FUNC_TYPEDEF(void, glActiveShaderProgram, GLuint pipeline, GLuint program)
GL_FUNC_TYPEDEF(GLuint, glCreateShaderProgramv, GLenum type, GLsizei count,
                const GLchar *const *strings)
GL_FUNC_TYPEDEF(void, glBindProgramPipeline, GLuint pipeline)
GL_FUNC_TYPEDEF(void, glDeleteProgramPipelines, GLsizei n,
                const GLuint *pipelines)
GL_FUNC_TYPEDEF(void, glGenProgramPipelines, GLsizei n, GLuint *pipelines)
GL_FUNC_TYPEDEF(GLboolean, glIsProgramPipeline, GLuint pipeline)
GL_FUNC_TYPEDEF(void, glGetProgramPipelineiv, GLuint pipeline, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glProgramUniform1i, GLuint program, GLint location,
                GLint v0)
GL_FUNC_TYPEDEF(void, glProgramUniform2i, GLuint program, GLint location,
                GLint v0, GLint v1)
GL_FUNC_TYPEDEF(void, glProgramUniform3i, GLuint program, GLint location,
                GLint v0, GLint v1, GLint v2)
GL_FUNC_TYPEDEF(void, glProgramUniform4i, GLuint program, GLint location,
                GLint v0, GLint v1, GLint v2, GLint v3)
GL_FUNC_TYPEDEF(void, glProgramUniform1ui, GLuint program, GLint location,
                GLuint v0)
GL_FUNC_TYPEDEF(void, glProgramUniform2ui, GLuint program, GLint location,
                GLuint v0, GLuint v1)
GL_FUNC_TYPEDEF(void, glProgramUniform3ui, GLuint program, GLint location,
                GLuint v0, GLuint v1, GLuint v2)
GL_FUNC_TYPEDEF(void, glProgramUniform4ui, GLuint program, GLint location,
                GLuint v0, GLuint v1, GLuint v2, GLuint v3)
GL_FUNC_TYPEDEF(void, glProgramUniform1f, GLuint program, GLint location,
                GLfloat v0)
GL_FUNC_TYPEDEF(void, glProgramUniform2f, GLuint program, GLint location,
                GLfloat v0, GLfloat v1)
GL_FUNC_TYPEDEF(void, glProgramUniform3f, GLuint program, GLint location,
                GLfloat v0, GLfloat v1, GLfloat v2)
GL_FUNC_TYPEDEF(void, glProgramUniform4f, GLuint program, GLint location,
                GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
GL_FUNC_TYPEDEF(void, glProgramUniform1iv, GLuint program, GLint location,
                GLsizei count, const GLint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform2iv, GLuint program, GLint location,
                GLsizei count, const GLint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform3iv, GLuint program, GLint location,
                GLsizei count, const GLint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform4iv, GLuint program, GLint location,
                GLsizei count, const GLint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform1uiv, GLuint program, GLint location,
                GLsizei count, const GLuint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform2uiv, GLuint program, GLint location,
                GLsizei count, const GLuint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform3uiv, GLuint program, GLint location,
                GLsizei count, const GLuint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform4uiv, GLuint program, GLint location,
                GLsizei count, const GLuint *value)
GL_FUNC_TYPEDEF(void, glProgramUniform1fv, GLuint program, GLint location,
                GLsizei count, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniform2fv, GLuint program, GLint location,
                GLsizei count, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniform3fv, GLuint program, GLint location,
                GLsizei count, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniform4fv, GLuint program, GLint location,
                GLsizei count, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix2fv, GLuint program, GLint location,
                GLsizei count, GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix3fv, GLuint program, GLint location,
                GLsizei count, GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix4fv, GLuint program, GLint location,
                GLsizei count, GLboolean transpose, const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix2x3fv, GLuint program,
                GLint location, GLsizei count, GLboolean transpose,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix3x2fv, GLuint program,
                GLint location, GLsizei count, GLboolean transpose,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix2x4fv, GLuint program,
                GLint location, GLsizei count, GLboolean transpose,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix4x2fv, GLuint program,
                GLint location, GLsizei count, GLboolean transpose,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix3x4fv, GLuint program,
                GLint location, GLsizei count, GLboolean transpose,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glProgramUniformMatrix4x3fv, GLuint program,
                GLint location, GLsizei count, GLboolean transpose,
                const GLfloat *value)
GL_FUNC_TYPEDEF(void, glValidateProgramPipeline, GLuint pipeline)
GL_FUNC_TYPEDEF(void, glGetProgramPipelineInfoLog, GLuint pipeline,
                GLsizei bufSize, GLsizei *length, GLchar *infoLog)
GL_FUNC_TYPEDEF(void, glBindImageTexture, GLuint unit, GLuint texture,
                GLint level, GLboolean layered, GLint layer, GLenum access,
                GLenum format)
GL_FUNC_TYPEDEF(void, glGetBooleani_v, GLenum target, GLuint index,
                GLboolean *data)
GL_FUNC_TYPEDEF(void, glMemoryBarrier, GLbitfield barriers)
GL_FUNC_TYPEDEF(void, glMemoryBarrierByRegion, GLbitfield barriers)
GL_FUNC_TYPEDEF(void, glTexStorage2DMultisample, GLenum target, GLsizei samples,
                GLenum internalformat, GLsizei width, GLsizei height,
                GLboolean fixedsamplelocations)
GL_FUNC_TYPEDEF(void, glGetMultisamplefv, GLenum pname, GLuint index,
                GLfloat *val)
GL_FUNC_TYPEDEF(void, glSampleMaski, GLuint maskNumber, GLbitfield mask)
GL_FUNC_TYPEDEF(void, glGetTexLevelParameteriv, GLenum target, GLint level,
                GLenum pname, GLint *params)
GL_FUNC_TYPEDEF(void, glGetTexLevelParameterfv, GLenum target, GLint level,
                GLenum pname, GLfloat *params)
GL_FUNC_TYPEDEF(void, glBindVertexBuffer, GLuint bindingindex, GLuint buffer,
                GLintptr offset, GLsizei stride)
GL_FUNC_TYPEDEF(void, glVertexAttribFormat, GLuint attribindex, GLint size,
                GLenum type, GLboolean normalized, GLuint relativeoffset)
GL_FUNC_TYPEDEF(void, glVertexAttribIFormat, GLuint attribindex, GLint size,
                GLenum type, GLuint relativeoffset)
GL_FUNC_TYPEDEF(void, glVertexAttribBinding, GLuint attribindex,
                GLuint bindingindex)
GL_FUNC_TYPEDEF(void, glVertexBindingDivisor, GLuint bindingindex,
                GLuint divisor)
GL_FUNC_TYPEDEF(void, glBlendBarrier)
GL_FUNC_TYPEDEF(void, glCopyImageSubData, GLuint srcName, GLenum srcTarget,
                GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ,
                GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX,
                GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight,
                GLsizei srcDepth)
GL_FUNC_TYPEDEF(void, glDebugMessageControl, GLenum source, GLenum type,
                GLenum severity, GLsizei count, const GLuint *ids,
                GLboolean enabled)
GL_FUNC_TYPEDEF(void, glDebugMessageInsert, GLenum source, GLenum type,
                GLuint id, GLenum severity, GLsizei length, const GLchar *buf)
GL_FUNC_TYPEDEF(void, glDebugMessageCallback, GLDEBUGPROC callback,
                const void *userParam)
GL_FUNC_TYPEDEF(GLuint, glGetDebugMessageLog, GLuint count, GLsizei bufSize,
                GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities,
                GLsizei *lengths, GLchar *messageLog)
GL_FUNC_TYPEDEF(void, glPushDebugGroup, GLenum source, GLuint id,
                GLsizei length, const GLchar *message)
GL_FUNC_TYPEDEF(void, glPopDebugGroup)
GL_FUNC_TYPEDEF(void, glObjectLabel, GLenum identifier, GLuint name,
                GLsizei length, const GLchar *label)
GL_FUNC_TYPEDEF(void, glGetObjectLabel, GLenum identifier, GLuint name,
                GLsizei bufSize, GLsizei *length, GLchar *label)
GL_FUNC_TYPEDEF(void, glObjectPtrLabel, const void *ptr, GLsizei length,
                const GLchar *label)
GL_FUNC_TYPEDEF(void, glGetObjectPtrLabel, const void *ptr, GLsizei bufSize,
                GLsizei *length, GLchar *label)
GL_FUNC_TYPEDEF(void, glGetPointerv, GLenum pname, void **params)
GL_FUNC_TYPEDEF(void, glEnablei, GLenum target, GLuint index)
GL_FUNC_TYPEDEF(void, glDisablei, GLenum target, GLuint index)
GL_FUNC_TYPEDEF(void, glBlendEquationi, GLuint buf, GLenum mode)
GL_FUNC_TYPEDEF(void, glBlendEquationSeparatei, GLuint buf, GLenum modeRGB,
                GLenum modeAlpha)
GL_FUNC_TYPEDEF(void, glBlendFunci, GLuint buf, GLenum src, GLenum dst)
GL_FUNC_TYPEDEF(void, glBlendFuncSeparatei, GLuint buf, GLenum srcRGB,
                GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
GL_FUNC_TYPEDEF(void, glColorMaski, GLuint index, GLboolean r, GLboolean g,
                GLboolean b, GLboolean a)
GL_FUNC_TYPEDEF(GLboolean, glIsEnabledi, GLenum target, GLuint index)
GL_FUNC_TYPEDEF(void, glDrawElementsBaseVertex, GLenum mode, GLsizei count,
                GLenum type, const void *indices, GLint basevertex)
GL_FUNC_TYPEDEF(void, glDrawRangeElementsBaseVertex, GLenum mode, GLuint start,
                GLuint end, GLsizei count, GLenum type, const void *indices,
                GLint basevertex)
GL_FUNC_TYPEDEF(void, glDrawElementsInstancedBaseVertex, GLenum mode,
                GLsizei count, GLenum type, const void *indices,
                GLsizei instancecount, GLint basevertex)
GL_FUNC_TYPEDEF(void, glFramebufferTexture, GLenum target, GLenum attachment,
                GLuint texture, GLint level)
GL_FUNC_TYPEDEF(void, glPrimitiveBoundingBox, GLfloat minX, GLfloat minY,
                GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY,
                GLfloat maxZ, GLfloat maxW)
GL_FUNC_TYPEDEF(GLenum, glGetGraphicsResetStatus)
GL_FUNC_TYPEDEF(void, glReadnPixels, GLint x, GLint y, GLsizei width,
                GLsizei height, GLenum format, GLenum type, GLsizei bufSize,
                void *data)
GL_FUNC_TYPEDEF(void, glGetnUniformfv, GLuint program, GLint location,
                GLsizei bufSize, GLfloat *params)
GL_FUNC_TYPEDEF(void, glGetnUniformiv, GLuint program, GLint location,
                GLsizei bufSize, GLint *params)
GL_FUNC_TYPEDEF(void, glGetnUniformuiv, GLuint program, GLint location,
                GLsizei bufSize, GLuint *params)
GL_FUNC_TYPEDEF(void, glMinSampleShading, GLfloat value)
GL_FUNC_TYPEDEF(void, glPatchParameteri, GLenum pname, GLint value)
GL_FUNC_TYPEDEF(void, glTexParameterIiv, GLenum target, GLenum pname,
                const GLint *params)
GL_FUNC_TYPEDEF(void, glTexParameterIuiv, GLenum target, GLenum pname,
                const GLuint *params)
GL_FUNC_TYPEDEF(void, glGetTexParameterIiv, GLenum target, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetTexParameterIuiv, GLenum target, GLenum pname,
                GLuint *params)
GL_FUNC_TYPEDEF(void, glSamplerParameterIiv, GLuint sampler, GLenum pname,
                const GLint *param)
GL_FUNC_TYPEDEF(void, glSamplerParameterIuiv, GLuint sampler, GLenum pname,
                const GLuint *param)
GL_FUNC_TYPEDEF(void, glGetSamplerParameterIiv, GLuint sampler, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetSamplerParameterIuiv, GLuint sampler, GLenum pname,
                GLuint *params)
GL_FUNC_TYPEDEF(void, glTexBuffer, GLenum target, GLenum internalformat,
                GLuint buffer)
GL_FUNC_TYPEDEF(void, glTexBufferRange, GLenum target, GLenum internalformat,
                GLuint buffer, GLintptr offset, GLsizeiptr size)
GL_FUNC_TYPEDEF(void, glTexStorage3DMultisample, GLenum target, GLsizei samples,
                GLenum internalformat, GLsizei width, GLsizei height,
                GLsizei depth, GLboolean fixedsamplelocations)
GL_FUNC_TYPEDEF(void *, glMapBufferRange, GLenum target, GLintptr offset,
                GLsizeiptr length, GLbitfield access)
GL_FUNC_TYPEDEF(void, glBufferStorageEXT, GLenum target, GLsizeiptr size,
                const void *data, GLbitfield flags)
GL_FUNC_TYPEDEF(void, glGetQueryObjectivEXT, GLuint id, GLenum pname,
                GLint *params)
GL_FUNC_TYPEDEF(void, glGetQueryObjecti64vEXT, GLuint id, GLenum pname,
                GLint64 *params)
GL_FUNC_TYPEDEF(void, glBindFragDataLocationEXT, GLuint program,
                GLuint colorNumber, const GLchar *name)
GL_FUNC_TYPEDEF(void *, glMapBufferOES, GLenum target, GLenum access)

GL_FUNC_TYPEDEF(void, glMultiDrawArraysIndirectEXT, GLenum mode,
                const void *indirect, GLsizei drawcount, GLsizei stride)
GL_FUNC_TYPEDEF(void, glMultiDrawElementsIndirectEXT, GLenum mode, GLenum type,
                const void *indirect, GLsizei drawcount, GLsizei stride)
GL_FUNC_TYPEDEF(void, glBruh)
GL_FUNC_TYPEDEF(void, glMultiDrawElementsBaseVertexEXT, GLenum mode,
                const GLsizei *count, GLenum type, const void *const *indices,
                GLsizei drawcount, const GLint *basevertex)

#define GL_FUNC_DECL(name) name##_PTR name;

struct gles_func_t {
  GL_FUNC_DECL(glActiveTexture)
  GL_FUNC_DECL(glAttachShader)
  GL_FUNC_DECL(glBindAttribLocation)
  GL_FUNC_DECL(glBindBuffer)
  GL_FUNC_DECL(glBindFramebuffer)
  GL_FUNC_DECL(glBindRenderbuffer)
  GL_FUNC_DECL(glBindTexture)
  GL_FUNC_DECL(glBlendColor)
  GL_FUNC_DECL(glBlendEquation)
  GL_FUNC_DECL(glBlendEquationSeparate)
  GL_FUNC_DECL(glBlendFunc)
  GL_FUNC_DECL(glBlendFuncSeparate)
  GL_FUNC_DECL(glBufferData)
  GL_FUNC_DECL(glBufferSubData)
  GL_FUNC_DECL(glCheckFramebufferStatus)
  GL_FUNC_DECL(glClear)
  GL_FUNC_DECL(glClearColor)
  GL_FUNC_DECL(glClearDepthf)
  GL_FUNC_DECL(glClearStencil)
  GL_FUNC_DECL(glColorMask)
  GL_FUNC_DECL(glCompileShader)
  GL_FUNC_DECL(glCompressedTexImage2D)
  GL_FUNC_DECL(glCompressedTexSubImage2D)
  //    GL_FUNC_DECL(glCopyTexImage1D)
  GL_FUNC_DECL(glCopyTexImage2D)
  GL_FUNC_DECL(glCopyTexSubImage2D)
  GL_FUNC_DECL(glCreateProgram)
  GL_FUNC_DECL(glCreateShader)
  GL_FUNC_DECL(glCullFace)
  GL_FUNC_DECL(glDeleteBuffers)
  GL_FUNC_DECL(glDeleteFramebuffers)
  GL_FUNC_DECL(glDeleteProgram)
  GL_FUNC_DECL(glDeleteRenderbuffers)
  GL_FUNC_DECL(glDeleteShader)
  GL_FUNC_DECL(glDeleteTextures)
  GL_FUNC_DECL(glDepthFunc)
  GL_FUNC_DECL(glDepthMask)
  GL_FUNC_DECL(glDepthRangef)
  GL_FUNC_DECL(glDetachShader)
  GL_FUNC_DECL(glDisable)
  GL_FUNC_DECL(glDisableVertexAttribArray)
  GL_FUNC_DECL(glDrawArrays)
  GL_FUNC_DECL(glDrawElements)
  GL_FUNC_DECL(glEnable)
  GL_FUNC_DECL(glEnableVertexAttribArray)
  GL_FUNC_DECL(glFinish)
  GL_FUNC_DECL(glFlush)
  GL_FUNC_DECL(glFramebufferRenderbuffer)
  GL_FUNC_DECL(glFramebufferTexture2D)
  GL_FUNC_DECL(glFrontFace)
  GL_FUNC_DECL(glGenBuffers)
  GL_FUNC_DECL(glGenerateMipmap)
  GL_FUNC_DECL(glGenFramebuffers)
  GL_FUNC_DECL(glGenRenderbuffers)
  GL_FUNC_DECL(glGenTextures)
  GL_FUNC_DECL(glGetActiveAttrib)
  GL_FUNC_DECL(glGetActiveUniform)
  GL_FUNC_DECL(glGetAttachedShaders)
  GL_FUNC_DECL(glGetAttribLocation)
  GL_FUNC_DECL(glGetBooleanv)
  GL_FUNC_DECL(glGetBufferParameteriv)
  GL_FUNC_DECL(glGetError)
  GL_FUNC_DECL(glGetString)
  GL_FUNC_DECL(glGetStringi)
  GL_FUNC_DECL(glGetFloatv)
  GL_FUNC_DECL(glGetFramebufferAttachmentParameteriv)
  GL_FUNC_DECL(glGetIntegerv)
  GL_FUNC_DECL(glGetProgramiv)
  GL_FUNC_DECL(glGetProgramInfoLog)
  GL_FUNC_DECL(glGetRenderbufferParameteriv)
  GL_FUNC_DECL(glGetShaderiv)
  GL_FUNC_DECL(glGetShaderInfoLog)
  GL_FUNC_DECL(glGetShaderPrecisionFormat)
  GL_FUNC_DECL(glGetShaderSource)
  GL_FUNC_DECL(glGetTexParameterfv)
  GL_FUNC_DECL(glGetTexParameteriv)
  GL_FUNC_DECL(glGetUniformfv)
  GL_FUNC_DECL(glGetUniformiv)
  GL_FUNC_DECL(glGetUniformLocation)
  GL_FUNC_DECL(glGetVertexAttribfv)
  GL_FUNC_DECL(glGetVertexAttribiv)
  GL_FUNC_DECL(glGetVertexAttribPointerv)
  GL_FUNC_DECL(glHint)
  GL_FUNC_DECL(glIsBuffer)
  GL_FUNC_DECL(glIsEnabled)
  GL_FUNC_DECL(glIsFramebuffer)
  GL_FUNC_DECL(glIsProgram)
  GL_FUNC_DECL(glIsRenderbuffer)
  GL_FUNC_DECL(glIsShader)
  GL_FUNC_DECL(glIsTexture)
  GL_FUNC_DECL(glLineWidth)
  GL_FUNC_DECL(glLinkProgram)
  GL_FUNC_DECL(glPixelStorei)
  GL_FUNC_DECL(glPolygonOffset)
  GL_FUNC_DECL(glReadPixels)
  GL_FUNC_DECL(glReleaseShaderCompiler)
  GL_FUNC_DECL(glRenderbufferStorage)
  GL_FUNC_DECL(glSampleCoverage)
  GL_FUNC_DECL(glScissor)
  GL_FUNC_DECL(glShaderBinary)
  GL_FUNC_DECL(glShaderSource)
  GL_FUNC_DECL(glStencilFunc)
  GL_FUNC_DECL(glStencilFuncSeparate)
  GL_FUNC_DECL(glStencilMask)
  GL_FUNC_DECL(glStencilMaskSeparate)
  GL_FUNC_DECL(glStencilOp)
  GL_FUNC_DECL(glStencilOpSeparate)
  //    GL_FUNC_DECL(glTexImage1D)
  GL_FUNC_DECL(glTexImage2D)
  //    GL_FUNC_DECL(glTexStorage1D)
  GL_FUNC_DECL(glTexParameterf)
  GL_FUNC_DECL(glTexParameterfv)
  GL_FUNC_DECL(glTexParameteri)
  GL_FUNC_DECL(glTexParameteriv)
  GL_FUNC_DECL(glTexSubImage2D)
  GL_FUNC_DECL(glUniform1f)
  GL_FUNC_DECL(glUniform1fv)
  GL_FUNC_DECL(glUniform1i)
  GL_FUNC_DECL(glUniform1iv)
  GL_FUNC_DECL(glUniform2f)
  GL_FUNC_DECL(glUniform2fv)
  GL_FUNC_DECL(glUniform2i)
  GL_FUNC_DECL(glUniform2iv)
  GL_FUNC_DECL(glUniform3f)
  GL_FUNC_DECL(glUniform3fv)
  GL_FUNC_DECL(glUniform3i)
  GL_FUNC_DECL(glUniform3iv)
  GL_FUNC_DECL(glUniform4f)
  GL_FUNC_DECL(glUniform4fv)
  GL_FUNC_DECL(glUniform4i)
  GL_FUNC_DECL(glUniform4iv)
  GL_FUNC_DECL(glUniformMatrix2fv)
  GL_FUNC_DECL(glUniformMatrix3fv)
  GL_FUNC_DECL(glUniformMatrix4fv)
  GL_FUNC_DECL(glUseProgram)
  GL_FUNC_DECL(glValidateProgram)
  GL_FUNC_DECL(glVertexAttrib1f)
  GL_FUNC_DECL(glVertexAttrib1fv)
  GL_FUNC_DECL(glVertexAttrib2f)
  GL_FUNC_DECL(glVertexAttrib2fv)
  GL_FUNC_DECL(glVertexAttrib3f)
  GL_FUNC_DECL(glVertexAttrib3fv)
  GL_FUNC_DECL(glVertexAttrib4f)
  GL_FUNC_DECL(glVertexAttrib4fv)
  GL_FUNC_DECL(glVertexAttribPointer)
  GL_FUNC_DECL(glViewport)
  GL_FUNC_DECL(glReadBuffer)
  GL_FUNC_DECL(glDrawRangeElements)
  GL_FUNC_DECL(glTexImage3D)
  GL_FUNC_DECL(glTexSubImage3D)
  GL_FUNC_DECL(glCopyTexSubImage3D)
  GL_FUNC_DECL(glCompressedTexImage3D)
  GL_FUNC_DECL(glCompressedTexSubImage3D)
  GL_FUNC_DECL(glGenQueries)
  GL_FUNC_DECL(glDeleteQueries)
  GL_FUNC_DECL(glIsQuery)
  GL_FUNC_DECL(glBeginQuery)
  GL_FUNC_DECL(glEndQuery)
  GL_FUNC_DECL(glGetQueryiv)
  GL_FUNC_DECL(glGetQueryObjectuiv)
  GL_FUNC_DECL(glUnmapBuffer)
  GL_FUNC_DECL(glGetBufferPointerv)
  GL_FUNC_DECL(glDrawBuffers)
  GL_FUNC_DECL(glUniformMatrix2x3fv)
  GL_FUNC_DECL(glUniformMatrix3x2fv)
  GL_FUNC_DECL(glUniformMatrix2x4fv)
  GL_FUNC_DECL(glUniformMatrix4x2fv)
  GL_FUNC_DECL(glUniformMatrix3x4fv)
  GL_FUNC_DECL(glUniformMatrix4x3fv)
  GL_FUNC_DECL(glBlitFramebuffer)
  GL_FUNC_DECL(glRenderbufferStorageMultisample)
  GL_FUNC_DECL(glFramebufferTextureLayer)
  GL_FUNC_DECL(glFlushMappedBufferRange)
  GL_FUNC_DECL(glBindVertexArray)
  GL_FUNC_DECL(glDeleteVertexArrays)
  GL_FUNC_DECL(glGenVertexArrays)
  GL_FUNC_DECL(glIsVertexArray)
  GL_FUNC_DECL(glGetIntegeri_v)
  GL_FUNC_DECL(glBeginTransformFeedback)
  GL_FUNC_DECL(glEndTransformFeedback)
  GL_FUNC_DECL(glBindBufferRange)
  GL_FUNC_DECL(glBindBufferBase)
  GL_FUNC_DECL(glTransformFeedbackVaryings)
  GL_FUNC_DECL(glGetTransformFeedbackVarying)
  GL_FUNC_DECL(glVertexAttribIPointer)
  GL_FUNC_DECL(glGetVertexAttribIiv)
  GL_FUNC_DECL(glGetVertexAttribIuiv)
  GL_FUNC_DECL(glVertexAttribI4i)
  GL_FUNC_DECL(glVertexAttribI4ui)
  GL_FUNC_DECL(glVertexAttribI4iv)
  GL_FUNC_DECL(glVertexAttribI4uiv)
  GL_FUNC_DECL(glGetUniformuiv)
  GL_FUNC_DECL(glGetFragDataLocation)
  GL_FUNC_DECL(glUniform1ui)
  GL_FUNC_DECL(glUniform2ui)
  GL_FUNC_DECL(glUniform3ui)
  GL_FUNC_DECL(glUniform4ui)
  GL_FUNC_DECL(glUniform1uiv)
  GL_FUNC_DECL(glUniform2uiv)
  GL_FUNC_DECL(glUniform3uiv)
  GL_FUNC_DECL(glUniform4uiv)
  GL_FUNC_DECL(glClearBufferiv)
  GL_FUNC_DECL(glClearBufferuiv)
  GL_FUNC_DECL(glClearBufferfv)
  GL_FUNC_DECL(glClearBufferfi)
  GL_FUNC_DECL(glCopyBufferSubData)
  GL_FUNC_DECL(glGetUniformIndices)
  GL_FUNC_DECL(glGetActiveUniformsiv)
  GL_FUNC_DECL(glGetUniformBlockIndex)
  GL_FUNC_DECL(glGetActiveUniformBlockiv)
  GL_FUNC_DECL(glGetActiveUniformBlockName)
  GL_FUNC_DECL(glUniformBlockBinding)
  GL_FUNC_DECL(glDrawArraysInstanced)
  GL_FUNC_DECL(glDrawElementsInstanced)
  GL_FUNC_DECL(glFenceSync)
  GL_FUNC_DECL(glIsSync)
  GL_FUNC_DECL(glDeleteSync)
  GL_FUNC_DECL(glClientWaitSync)
  GL_FUNC_DECL(glWaitSync)
  GL_FUNC_DECL(glGetInteger64v)
  GL_FUNC_DECL(glGetSynciv)
  GL_FUNC_DECL(glGetInteger64i_v)
  GL_FUNC_DECL(glGetBufferParameteri64v)
  GL_FUNC_DECL(glGenSamplers)
  GL_FUNC_DECL(glDeleteSamplers)
  GL_FUNC_DECL(glIsSampler)
  GL_FUNC_DECL(glBindSampler)
  GL_FUNC_DECL(glSamplerParameteri)
  GL_FUNC_DECL(glSamplerParameteriv)
  GL_FUNC_DECL(glSamplerParameterf)
  GL_FUNC_DECL(glSamplerParameterfv)
  GL_FUNC_DECL(glGetSamplerParameteriv)
  GL_FUNC_DECL(glGetSamplerParameterfv)
  GL_FUNC_DECL(glVertexAttribDivisor)
  GL_FUNC_DECL(glBindTransformFeedback)
  GL_FUNC_DECL(glDeleteTransformFeedbacks)
  GL_FUNC_DECL(glGenTransformFeedbacks)
  GL_FUNC_DECL(glIsTransformFeedback)
  GL_FUNC_DECL(glPauseTransformFeedback)
  GL_FUNC_DECL(glResumeTransformFeedback)
  GL_FUNC_DECL(glGetProgramBinary)
  GL_FUNC_DECL(glProgramBinary)
  GL_FUNC_DECL(glProgramParameteri)
  GL_FUNC_DECL(glInvalidateFramebuffer)
  GL_FUNC_DECL(glInvalidateSubFramebuffer)
  GL_FUNC_DECL(glTexStorage2D)
  GL_FUNC_DECL(glTexStorage3D)
  GL_FUNC_DECL(glGetInternalformativ)
  GL_FUNC_DECL(glDispatchCompute)
  GL_FUNC_DECL(glDispatchComputeIndirect)
  GL_FUNC_DECL(glDrawArraysIndirect)
  GL_FUNC_DECL(glDrawElementsIndirect)
  GL_FUNC_DECL(glFramebufferParameteri)
  GL_FUNC_DECL(glGetFramebufferParameteriv)
  GL_FUNC_DECL(glGetProgramInterfaceiv)
  GL_FUNC_DECL(glGetProgramResourceIndex)
  GL_FUNC_DECL(glGetProgramResourceName)
  GL_FUNC_DECL(glGetProgramResourceiv)
  GL_FUNC_DECL(glGetProgramResourceLocation)
  GL_FUNC_DECL(glUseProgramStages)
  GL_FUNC_DECL(glActiveShaderProgram)
  GL_FUNC_DECL(glCreateShaderProgramv)
  GL_FUNC_DECL(glBindProgramPipeline)
  GL_FUNC_DECL(glDeleteProgramPipelines)
  GL_FUNC_DECL(glGenProgramPipelines)
  GL_FUNC_DECL(glIsProgramPipeline)
  GL_FUNC_DECL(glGetProgramPipelineiv)
  GL_FUNC_DECL(glProgramUniform1i)
  GL_FUNC_DECL(glProgramUniform2i)
  GL_FUNC_DECL(glProgramUniform3i)
  GL_FUNC_DECL(glProgramUniform4i)
  GL_FUNC_DECL(glProgramUniform1ui)
  GL_FUNC_DECL(glProgramUniform2ui)
  GL_FUNC_DECL(glProgramUniform3ui)
  GL_FUNC_DECL(glProgramUniform4ui)
  GL_FUNC_DECL(glProgramUniform1f)
  GL_FUNC_DECL(glProgramUniform2f)
  GL_FUNC_DECL(glProgramUniform3f)
  GL_FUNC_DECL(glProgramUniform4f)
  GL_FUNC_DECL(glProgramUniform1iv)
  GL_FUNC_DECL(glProgramUniform2iv)
  GL_FUNC_DECL(glProgramUniform3iv)
  GL_FUNC_DECL(glProgramUniform4iv)
  GL_FUNC_DECL(glProgramUniform1uiv)
  GL_FUNC_DECL(glProgramUniform2uiv)
  GL_FUNC_DECL(glProgramUniform3uiv)
  GL_FUNC_DECL(glProgramUniform4uiv)
  GL_FUNC_DECL(glProgramUniform1fv)
  GL_FUNC_DECL(glProgramUniform2fv)
  GL_FUNC_DECL(glProgramUniform3fv)
  GL_FUNC_DECL(glProgramUniform4fv)
  GL_FUNC_DECL(glProgramUniformMatrix2fv)
  GL_FUNC_DECL(glProgramUniformMatrix3fv)
  GL_FUNC_DECL(glProgramUniformMatrix4fv)
  GL_FUNC_DECL(glProgramUniformMatrix2x3fv)
  GL_FUNC_DECL(glProgramUniformMatrix3x2fv)
  GL_FUNC_DECL(glProgramUniformMatrix2x4fv)
  GL_FUNC_DECL(glProgramUniformMatrix4x2fv)
  GL_FUNC_DECL(glProgramUniformMatrix3x4fv)
  GL_FUNC_DECL(glProgramUniformMatrix4x3fv)
  GL_FUNC_DECL(glValidateProgramPipeline)
  GL_FUNC_DECL(glGetProgramPipelineInfoLog)
  GL_FUNC_DECL(glBindImageTexture)
  GL_FUNC_DECL(glGetBooleani_v)
  GL_FUNC_DECL(glMemoryBarrier)
  GL_FUNC_DECL(glMemoryBarrierByRegion)
  GL_FUNC_DECL(glTexStorage2DMultisample)
  GL_FUNC_DECL(glGetMultisamplefv)
  GL_FUNC_DECL(glSampleMaski)
  GL_FUNC_DECL(glGetTexLevelParameteriv)
  GL_FUNC_DECL(glGetTexLevelParameterfv)
  GL_FUNC_DECL(glBindVertexBuffer)
  GL_FUNC_DECL(glVertexAttribFormat)
  GL_FUNC_DECL(glVertexAttribIFormat)
  GL_FUNC_DECL(glVertexAttribBinding)
  GL_FUNC_DECL(glVertexBindingDivisor)
  GL_FUNC_DECL(glBlendBarrier)
  GL_FUNC_DECL(glCopyImageSubData)
  GL_FUNC_DECL(glDebugMessageControl)
  GL_FUNC_DECL(glDebugMessageInsert)
  GL_FUNC_DECL(glDebugMessageCallback)
  GL_FUNC_DECL(glGetDebugMessageLog)
  GL_FUNC_DECL(glPushDebugGroup)
  GL_FUNC_DECL(glPopDebugGroup)
  GL_FUNC_DECL(glObjectLabel)
  GL_FUNC_DECL(glGetObjectLabel)
  GL_FUNC_DECL(glObjectPtrLabel)
  GL_FUNC_DECL(glGetObjectPtrLabel)
  GL_FUNC_DECL(glGetPointerv)
  GL_FUNC_DECL(glEnablei)
  GL_FUNC_DECL(glDisablei)
  GL_FUNC_DECL(glBlendEquationi)
  GL_FUNC_DECL(glBlendEquationSeparatei)
  GL_FUNC_DECL(glBlendFunci)
  GL_FUNC_DECL(glBlendFuncSeparatei)
  GL_FUNC_DECL(glColorMaski)
  GL_FUNC_DECL(glIsEnabledi)
  GL_FUNC_DECL(glDrawElementsBaseVertex)
  GL_FUNC_DECL(glDrawRangeElementsBaseVertex)
  GL_FUNC_DECL(glDrawElementsInstancedBaseVertex)
  GL_FUNC_DECL(glFramebufferTexture)
  GL_FUNC_DECL(glPrimitiveBoundingBox)
  GL_FUNC_DECL(glGetGraphicsResetStatus)
  GL_FUNC_DECL(glReadnPixels)
  GL_FUNC_DECL(glGetnUniformfv)
  GL_FUNC_DECL(glGetnUniformiv)
  GL_FUNC_DECL(glGetnUniformuiv)
  GL_FUNC_DECL(glMinSampleShading)
  GL_FUNC_DECL(glPatchParameteri)
  GL_FUNC_DECL(glTexParameterIiv)
  GL_FUNC_DECL(glTexParameterIuiv)
  GL_FUNC_DECL(glGetTexParameterIiv)
  GL_FUNC_DECL(glGetTexParameterIuiv)
  GL_FUNC_DECL(glSamplerParameterIiv)
  GL_FUNC_DECL(glSamplerParameterIuiv)
  GL_FUNC_DECL(glGetSamplerParameterIiv)
  GL_FUNC_DECL(glGetSamplerParameterIuiv)
  GL_FUNC_DECL(glTexBuffer)
  GL_FUNC_DECL(glTexBufferRange)
  GL_FUNC_DECL(glTexStorage3DMultisample)
  GL_FUNC_DECL(glMapBufferRange)
  GL_FUNC_DECL(glBufferStorageEXT)
  GL_FUNC_DECL(glGetQueryObjectivEXT)
  GL_FUNC_DECL(glGetQueryObjecti64vEXT)
  GL_FUNC_DECL(glBindFragDataLocationEXT)
  GL_FUNC_DECL(glMapBufferOES)

  GL_FUNC_DECL(glMultiDrawArraysIndirectEXT)
  GL_FUNC_DECL(glMultiDrawElementsIndirectEXT)
  GL_FUNC_DECL(glMultiDrawElementsBaseVertexEXT)

  GL_FUNC_DECL(glBruh)
};

extern struct gles_func_t g_gles_func;

#define GLES g_gles_func

#ifdef __cplusplus
}
#endif

#endif // MOBILEGLUES_GLES_H
