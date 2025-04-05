#ifndef _GL4ES_LOADER_H_
#define _GL4ES_LOADER_H_

#include <stdbool.h>
#include "gl4es.h"
#include "gles.h"
#include "logs.h"

#include "../../../gles/gles.h"

#ifndef NOEGL
//Typedef for egl to be able to call LOAD_EGL...
#include <EGL/egl.h>
#include <EGL/eglext.h>
void* APIENTRY_GL4ES gl4es_proc_address(void *lib, const char *name);
typedef EGLBoolean (*eglBindAPI_PTR_GL4ES)(EGLenum api);
typedef EGLBoolean (*eglBindTexImage_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
typedef EGLBoolean (*eglChooseConfig_PTR_GL4ES)(EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config);
typedef EGLBoolean (*eglCopyBuffers_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
typedef EGLContext (*eglCreateContext_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePbufferFromClientBuffer_PTR_GL4ES)(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePbufferSurface_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePixmapSurface_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePlatformWindowSurface_PTR_GL4ES)(EGLDisplay display, EGLConfig config, void * native_window, const EGLint * attrib_list);
typedef EGLSurface (*eglCreateWindowSurface_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list);
typedef EGLBoolean (*eglDestroyContext_PTR_GL4ES)(EGLDisplay dpy, EGLContext ctx);
typedef EGLBoolean (*eglDestroySurface_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface);
typedef EGLBoolean (*eglGetConfigAttrib_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value);
typedef EGLBoolean (*eglGetConfigs_PTR_GL4ES)(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config);
typedef EGLContext (*eglGetCurrentContext_PTR_GL4ES)();
typedef EGLDisplay (*eglGetCurrentDisplay_PTR_GL4ES)();
typedef EGLSurface (*eglGetCurrentSurface_PTR_GL4ES)(EGLint readdraw);
typedef EGLDisplay (*eglGetDisplay_PTR_GL4ES)(EGLNativeDisplayType display_id);
typedef EGLDisplay (*eglGetPlatformDisplay_PTR_GL4ES)(EGLenum platform, void * native_display, const EGLint * attrib_list);
typedef EGLint (*eglGetError_PTR_GL4ES)();
typedef __eglMustCastToProperFunctionPointerType (*eglGetProcAddress_PTR_GL4ES)(const char * procname);
typedef EGLBoolean (*eglInitialize_PTR_GL4ES)(EGLDisplay dpy, EGLint * major, EGLint * minor);
typedef EGLBoolean (*eglMakeCurrent_PTR_GL4ES)(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
typedef EGLenum (*eglQueryAPI_PTR_GL4ES)();
typedef EGLBoolean (*eglQueryContext_PTR_GL4ES)(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value);
typedef const char * (*eglQueryString_PTR_GL4ES)(EGLDisplay dpy, EGLint name);
typedef EGLBoolean (*eglQuerySurface_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value);
typedef EGLBoolean (*eglReleaseTexImage_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
typedef EGLBoolean (*eglReleaseThread_PTR_GL4ES)();
typedef EGLBoolean (*eglSurfaceAttrib_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
typedef EGLBoolean (*eglSwapBuffers_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface);
typedef EGLBoolean (*eglSwapBuffersWithDamageEXT_PTR_GL4ES)(EGLDisplay dpy, EGLSurface surface, EGLint * rects, EGLint n_rects);
typedef EGLBoolean (*eglSwapInterval_PTR_GL4ES)(EGLDisplay dpy, EGLint interval);
typedef EGLBoolean (*eglTerminate_PTR_GL4ES)(EGLDisplay dpy);
typedef EGLBoolean (*eglUnlockSurfaceKHR_PTR_GL4ES)(EGLDisplay display, EGLSurface surface);
typedef EGLBoolean (*eglWaitClient_PTR_GL4ES)();
typedef EGLBoolean (*eglWaitGL_PTR_GL4ES)();
typedef EGLBoolean (*eglWaitNative_PTR_GL4ES)(EGLint engine);
typedef EGLSyncKHR (*eglCreateSyncKHR_PTR_GL4ES)(EGLDisplay dpy, EGLenum type, const EGLint * attrib_list);
typedef EGLSyncKHR (*eglDestroySyncKHR_PTR_GL4ES)(EGLDisplay dpy, EGLSyncKHR sync);
typedef EGLint (*eglClientWaitSyncKHR_PTR_GL4ES)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags, EGLTimeKHR timeout);

typedef NativePixmapType (*egl_create_pixmap_ID_mapping_PTR_GL4ES)(void *pixmap);
typedef NativePixmapType (*egl_destroy_pixmap_ID_mapping_PTR_GL4ES)(int id);
#ifdef TEXSTREAM
typedef EGLSurface (*eglCreatePixmapSurfaceHI_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, struct EGLClientPixmapHI * pixmap);
typedef EGLBoolean (*eglDestroyImageKHR_PTR_GL4ES)(EGLDisplay dpy, EGLImageKHR image);
typedef EGLBoolean (*eglDestroyStreamKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLImageKHR (*eglCreateImageKHR_PTR_GL4ES)(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint * attrib_list);
typedef EGLStreamKHR (*eglCreateStreamFromFileDescriptorKHR_PTR_GL4ES)(EGLDisplay dpy, EGLNativeFileDescriptorKHR file_descriptor);
typedef EGLStreamKHR (*eglCreateStreamKHR_PTR_GL4ES)(EGLDisplay dpy, const EGLint * attrib_list);
typedef EGLSyncKHR (*eglDestroySyncKHR_PTR_GL4ES)(EGLDisplay dpy, EGLSyncKHR sync);
typedef EGLBoolean (*eglSignalSyncKHR_PTR_GL4ES)(EGLDisplay dpy, EGLSyncKHR sync, EGLenum mode);
typedef EGLBoolean (*eglGetSyncAttribKHR_PTR_GL4ES)(EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint * value);
typedef EGLBoolean (*eglStreamAttribKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint value);
typedef EGLBoolean (*eglStreamConsumerAcquireKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglStreamConsumerGLTextureExternalKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglStreamConsumerReleaseKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglLockSurfaceKHR_PTR_GL4ES)(EGLDisplay display, EGLSurface surface, const EGLint * attrib_list);
typedef EGLNativeFileDescriptorKHR (*eglGetStreamFileDescriptorKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglQueryStreamKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint * value);
typedef EGLBoolean (*eglQueryStreamTimeKHR_PTR_GL4ES)(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR * value);
typedef EGLint (*eglWaitSyncKHR_PTR_GL4ES)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
typedef EGLSurface (*eglCreateStreamProducerSurfaceKHR_PTR_GL4ES)(EGLDisplay dpy, EGLConfig config, EGLStreamKHR stream, const EGLint * attrib_list);
#endif // TEXSTREAM
#endif // NOEGL

#ifdef AMIGAOS4
#include "../agl/amigaos.h"
#elif !defined(_WIN32)
#include <dlfcn.h>
#else
#ifndef _WINBASE_
typedef struct HISTANCE__* HISTANCE;
typedef intptr_t (__stdcall* FPROC)();
__declspec(dllimport)
FPROC __stdcall GetProcAddress(HISTANCE, const char*);
#endif
#ifdef _MSC_VER
__forceinline
#elif defined(__GNUC__)
__attribute__((always_inline)) __inline
#endif
static void* dlsym(void* __restrict handle, const char* __restrict symbol)
{ return (void*)GetProcAddress(handle, symbol); }
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../glx/hardext.h"
extern void* (APIENTRY_GL4ES *gles_getProcAddress)(const char *name);
extern void (APIENTRY_GL4ES *gl4es_getMainFBSize)(GLint* width, GLint* height);
NonAliasExportDecl(void*,gl4es_proc_address,(void *lib, const char *name));
// will become references to dlopen'd gles and egl
extern void *gl4es_gles, *bcm_host, *vcos, *gbm, *drm;
EXPORT extern void *gl4es_egl;
#if defined __APPLE__ || defined __EMSCRIPTEN__
#define NO_LOADER
#endif

#define WARN_NULL(name) if (name == NULL) LOGD("MobileGlues-gl4es: warning, %s line %d function %s: " #name " is NULL\n", __FILE__, __LINE__, __func__);

#define MSVC_SPC(MACRO, ARGS) MACRO ARGS

#define PUSH_IF_COMPILING_EXT(nam, ...)             \
    if (glstate->list.active) {                     \
        if (!glstate->list.pending) { \
            NewStage(glstate->list.active, STAGE_GLCALL);   \
            MSVC_SPC(push_##nam, (__VA_ARGS__));            \
            noerrorShim();							\
            return (nam##_RETURN)0;                 \
        }                                           \
        else gl4es_flush();                               \
    }

#define PUSH_IF_COMPILING(name) PUSH_IF_COMPILING_EXT(name, name##_ARG_NAMES)

#define DEFINE_RAW(lib, name) static name##_PTR_GL4ES lib##_##name = NULL
#define LOAD_RAW(lib, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR_GL4ES)__VA_ARGS__; \
            } \
            WARN_NULL(lib##_##name); \
        } \
    }

#define LOAD_RAW_3(lib, name, fnc1, fnc2, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR_GL4ES)fnc1; \
                if(! lib##_##name) \
                    lib##_##name = (name##_PTR_GL4ES)fnc2; \
                if(! lib##_##name) { \
                    __VA_ARGS__ \
                } \
            } \
        } \
    }

#define LOAD_RAW_SILENT(lib, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR_GL4ES)__VA_ARGS__; \
            } \
        } \
    }

#define LOAD_RAW_ALT(lib, alt, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR_GL4ES)__VA_ARGS__; \
            } \
            if(lib##_##name == NULL) \
                lib##_##name = alt##_##name; \
        } \
    }

#define LOAD_LIB(lib, name) DEFINE_RAW(lib, name); LOAD_RAW(lib, name, gl4es_proc_address(lib, #name))
#define LOAD_LIB_SILENT(lib, name) DEFINE_RAW(lib, name); LOAD_RAW_SILENT(lib, name, gl4es_proc_address(lib, #name))
#define LOAD_LIB_ALT(lib, alt, name) DEFINE_RAW(lib, name); LOAD_RAW_ALT(lib, alt, name, gl4es_proc_address(lib, #name))

#define LOAD_GLES(name)         LOAD_LIB(gl4es_gles, name)
#define LOAD_GLES2(name)        LOAD_LIB_SILENT(gl4es_gles, name)
#define LOAD_GLES_OR_FPE(name)  LOAD_LIB_ALT(gl4es_gles, fpe, name)

#define LOAD_GLES_FPE(name) \
    DEFINE_RAW(gl4es_gles, name); \
    if(hardext.esversion==1) { \
        LOAD_RAW(gl4es_gles, name, gl4es_proc_address(gl4es_gles, #name)); \
    } else { \
        gl4es_gles_##name = fpe_##name; \
    }

#define LOAD_EGL(name) LOAD_LIB(gl4es_egl, name)

#define LOAD_GBM(name) LOAD_LIB(gbm, name)

#if defined(AMIGAOS4) || defined(NOEGL) || defined(__EMSCRIPTEN__)
#define LOAD_GLES_OES(name) \
    DEFINE_RAW(gl4es_gles, name); \
    { \
        LOAD_RAW(gl4es_gles, name, gl4es_proc_address(gl4es_gles, #name"OES")); \
    }

#define LOAD_GLES_EXT(name) \
    DEFINE_RAW(gl4es_gles, name); \
    { \
        LOAD_RAW(gl4es_gles, name, gl4es_proc_address(gl4es_gles, #name"EXT")); \
    }

#define LOAD_GLES2_OR_OES(name) \
    DEFINE_RAW(gl4es_gles, name); \
    { \
        LOAD_RAW_SILENT(gl4es_gles, name, gl4es_proc_address(gl4es_gles, #name)); \
    }

#else // defined(AMIGAOS4) || defined(NOEGL)

#define LOAD_EGL_EXT(name) \
    DEFINE_RAW(egl, name); \
    LOAD_RAW_3(egl, name, gl4es_proc_address(egl, #name), gl4es_proc_address(egl, #name "EXT"), LOAD_EGL(eglGetProcAddress); LOAD_RAW(egl, name, gl4es_egl_eglGetProcAddress(#name "EXT")); )

#define LOAD_GLES_OES(name) \
    DEFINE_RAW(gl4es_gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW(gl4es_gles, name, gl4es_egl_eglGetProcAddress(#name"OES")); \
    }

#define LOAD_GLES_EXT(name) \
    DEFINE_RAW(gl4es_gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW(gl4es_gles, name, gl4es_egl_eglGetProcAddress(#name"EXT")); \
    }

#define LOAD_GLES2_OR_OES(name) \
    DEFINE_RAW(gl4es_gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW_SILENT(gl4es_gles, name, ((hardext.esversion==1)?((void*)gl4es_egl_eglGetProcAddress(#name"OES")):((void*)dlsym(gl4es_gles, #name)))); \
        if (gl4es_gles_##name == NULL) {LOGD("gl4es nullfunc: %s", #name);}                        \
    }
#endif // defined(AMIGAOS4) || defined(NOEGL)

#endif // _GL4ES_LOADER_H_
