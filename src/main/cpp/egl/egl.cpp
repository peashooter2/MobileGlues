//
// Created by Swung0x48 on 2024/10/10.
//

#include "egl.h"
#include "loader.h"
#include "../gles/loader.h"
#include "../gl/FSR1/FSR1.h"
#include "../glx/lookup.h"
#include "../config/settings.h"

#define DEBUG 0

extern "C" {
#define EGL_API __attribute__((visibility("default")))
    EGL_API EGLint eglGetError(void) {
		LOG_D("eglGetError");
        LOAD_EGL(eglGetError)
    
        return egl_eglGetError();
    }

    EGL_API EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id) {
		LOG_D("eglGetDisplay, display_id: %p", display_id);
        LOAD_EGL(eglGetDisplay)
        return egl_eglGetDisplay(display_id);
    }

    EGL_API EGLBoolean eglInitialize(EGLDisplay dpy, EGLint* major, EGLint* minor) {
		LOG_D("eglInitialize, dpy: %p, major: %p, minor: %p", dpy, major, minor);
        LOAD_EGL(eglInitialize)
        return egl_eglInitialize(dpy, major, minor);
    }

    EGL_API EGLBoolean eglTerminate(EGLDisplay dpy) {
		LOG_D("eglTerminate, dpy: %p", dpy);
        LOAD_EGL(eglTerminate)
        return egl_eglTerminate(dpy);
    }

    EGL_API const char* eglQueryString(EGLDisplay dpy, EGLint name) {
		LOG_D("eglQueryString, dpy: %p, name: %d", dpy, name);
        LOAD_EGL(eglQueryString)
        return egl_eglQueryString(dpy, name);
    }

    EGL_API EGLBoolean eglGetConfigs(EGLDisplay dpy, EGLConfig* configs, EGLint config_size, EGLint* num_config) {
		LOG_D("eglGetConfigs, dpy: %p, configs: %p, config_size: %d, num_config: %p", dpy, configs, config_size, num_config);
        LOAD_EGL(eglGetConfigs)
        return egl_eglGetConfigs(dpy, configs, config_size, num_config);
    }

    EGL_API EGLBoolean eglChooseConfig(EGLDisplay dpy, const EGLint* attrib_list, EGLConfig* configs, EGLint config_size, EGLint* num_config) {
		LOG_D("eglChooseConfig, dpy: %p, attrib_list: %p, configs: %p, config_size: %d, num_config: %p", dpy, attrib_list, configs, config_size, num_config);
        LOAD_EGL(eglChooseConfig)
        return egl_eglChooseConfig(dpy, attrib_list, configs, config_size, num_config);
    }

    EGL_API EGLBoolean eglGetConfigAttrib(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint* value) {
		LOG_D("eglGetConfigAttrib, dpy: %p, config: %p, attribute: %d, value: %p", dpy, config, attribute, value);
        LOAD_EGL(eglGetConfigAttrib)
        return egl_eglGetConfigAttrib(dpy, config, attribute, value);
    }

    EGL_API EGLSurface eglCreateWindowSurface(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint* attrib_list) {
		LOG_D("eglCreateWindowSurface, dpy: %p, config: %p, win: %p, attrib_list: %p", dpy, config, win, attrib_list);
        LOAD_EGL(eglCreateWindowSurface)
        return egl_eglCreateWindowSurface(dpy, config, win, attrib_list);
    }

    EGL_API EGLSurface eglCreatePbufferSurface(EGLDisplay dpy, EGLConfig config, const EGLint* attrib_list) {
		LOG_D("eglCreatePbufferSurface, dpy: %p, config: %p, attrib_list: %p", dpy, config, attrib_list);
        LOAD_EGL(eglCreatePbufferSurface)
        return egl_eglCreatePbufferSurface(dpy, config, attrib_list);
    }

    EGL_API EGLSurface eglCreatePixmapSurface(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint* attrib_list) {
		LOG_D("eglCreatePixmapSurface, dpy: %p, config: %p, pixmap: %p, attrib_list: %p", dpy, config, pixmap, attrib_list);
        LOAD_EGL(eglCreatePixmapSurface)
        return egl_eglCreatePixmapSurface(dpy, config, pixmap, attrib_list);
    }

    EGL_API EGLBoolean eglDestroySurface(EGLDisplay dpy, EGLSurface surface) {
		LOG_D("eglDestroySurface, dpy: %p, surface: %p", dpy, surface);
        LOAD_EGL(eglDestroySurface)
        return egl_eglDestroySurface(dpy, surface);
    }

    EGL_API EGLBoolean eglQuerySurface(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint* value) {
		LOG_D("eglQuerySurface, dpy: %p, surface: %p, attribute: %d, value: %p", dpy, surface, attribute, value);
        LOAD_EGL(eglQuerySurface)
        return egl_eglQuerySurface(dpy, surface, attribute, value);
    }

    EGL_API EGLBoolean eglBindAPI(EGLenum api) {
		LOG_D("eglBindAPI, api: %d", api);
        LOAD_EGL(eglBindAPI)
        return egl_eglBindAPI(api);
    }

    EGL_API EGLenum eglQueryAPI(void) {
		LOG_D("eglQueryAPI");
        LOAD_EGL(eglQueryAPI)
        return egl_eglQueryAPI();
    }

    EGL_API EGLBoolean eglWaitClient(void) {
		LOG_D("eglWaitClient");
        LOAD_EGL(eglWaitClient)
        return egl_eglWaitClient();
    }

    EGL_API EGLBoolean eglReleaseThread(void) {
		LOG_D("eglReleaseThread");
        LOAD_EGL(eglReleaseThread)
        return egl_eglReleaseThread();
    }

    EGL_API EGLSurface eglCreatePbufferFromClientBuffer(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint* attrib_list) {
		LOG_D("eglCreatePbufferFromClientBuffer, dpy: %p, buftype: %d, buffer: %p, config: %p, attrib_list: %p", dpy, buftype, buffer, config, attrib_list);
        LOAD_EGL(eglCreatePbufferFromClientBuffer)
        return egl_eglCreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
    }

    EGL_API EGLBoolean eglSurfaceAttrib(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value) {
		LOG_D("eglSurfaceAttrib, dpy: %p, surface: %p, attribute: %d, value: %d", dpy, surface, attribute, value);
        LOAD_EGL(eglSurfaceAttrib)
        return egl_eglSurfaceAttrib(dpy, surface, attribute, value);
    }

    EGL_API EGLBoolean eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer) {
		LOG_D("eglBindTexImage, dpy: %p, surface: %p, buffer: %d", dpy, surface, buffer);
        LOAD_EGL(eglBindTexImage)
        return egl_eglBindTexImage(dpy, surface, buffer);
    }

    EGL_API EGLBoolean eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer) {
		LOG_D("eglReleaseTexImage, dpy: %p, surface: %p, buffer: %d", dpy, surface, buffer);
        LOAD_EGL(eglReleaseTexImage)
        return egl_eglReleaseTexImage(dpy, surface, buffer);
    }

    EGL_API EGLBoolean eglSwapInterval(EGLDisplay dpy, EGLint interval) {
		LOG_D("eglSwapInterval, dpy: %p, interval: %d", dpy, interval);
        LOAD_EGL(eglSwapInterval)
        return egl_eglSwapInterval(dpy, interval);
    }

    EGL_API EGLContext eglCreateContext(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint* attrib_list) {
		LOG_D("eglCreateContext, dpy: %p, config: %p, share_context: %p, attrib_list: %p", dpy, config, share_context, attrib_list);
        LOAD_EGL(eglCreateContext)
        return egl_eglCreateContext(dpy, config, share_context, attrib_list);
    }

    EGL_API EGLBoolean eglDestroyContext(EGLDisplay dpy, EGLContext ctx) {
		LOG_D("eglDestroyContext, dpy: %p, ctx: %p", dpy, ctx);
        LOAD_EGL(eglDestroyContext)
        return egl_eglDestroyContext(dpy, ctx);
    }

    EGL_API EGLBoolean eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx) {
		LOG_D("eglMakeCurrent, dpy: %p, draw: %p, read: %p, ctx: %p", dpy, draw, read, ctx);
        LOAD_EGL(eglMakeCurrent)
        return egl_eglMakeCurrent(dpy, draw, read, ctx);
    }

    EGL_API EGLContext eglGetCurrentContext(void) {
		LOG_D("eglGetCurrentContext");
        LOAD_EGL(eglGetCurrentContext)
        return egl_eglGetCurrentContext();
    }

    EGL_API EGLSurface eglGetCurrentSurface(EGLint readdraw) {
		LOG_D("eglGetCurrentSurface, readdraw: %d", readdraw);
        LOAD_EGL(eglGetCurrentSurface)
        return egl_eglGetCurrentSurface(readdraw);
    }

    EGL_API EGLDisplay eglGetCurrentDisplay(void) {
		LOG_D("eglGetCurrentDisplay");
        LOAD_EGL(eglGetCurrentDisplay)
        return egl_eglGetCurrentDisplay();
    }

    EGL_API EGLBoolean eglQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint* value) {
		LOG_D("eglQueryContext, dpy: %p, ctx: %p, attribute: %d, value: %p", dpy, ctx, attribute, value);
        LOAD_EGL(eglQueryContext)
        return egl_eglQueryContext(dpy, ctx, attribute, value);
    }

    EGL_API EGLBoolean eglWaitGL(void) {
		LOG_D("eglWaitGL");
        LOAD_EGL(eglWaitGL)
        return egl_eglWaitGL();
    }

    EGL_API EGLBoolean eglWaitNative(EGLint engine) {
		LOG_D("eglWaitNative, engine: %d", engine);
        LOAD_EGL(eglWaitNative)
        return egl_eglWaitNative(engine);
    }

    EGL_API EGLBoolean eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
		LOG_D("eglSwapBuffers, dpy: %p, surface: %p", dpy, surface);
        LOAD_EGL(eglSwapBuffers)
        EGLBoolean result;
        if (global_settings.fsr1_setting != FSR1_Quality_Preset::Disabled) {
            ApplyFSR();
            result = egl_eglSwapBuffers(dpy, surface);
            CheckResolutionChange();
        } else {
            result = egl_eglSwapBuffers(dpy, surface);
        }
		return result;
    }

    EGL_API EGLBoolean eglCopyBuffers(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target) {
		LOG_D("eglCopyBuffers, dpy: %p, surface: %p, target: %p", dpy, surface, target);
        LOAD_EGL(eglCopyBuffers)
        return egl_eglCopyBuffers(dpy, surface, target);
    }

    EGL_API EGLDisplay eglGetPlatformDisplay(EGLenum platform, void* native_display, const EGLAttrib* attrib_list) {
		LOG_D("eglGetPlatformDisplay, platform: %d, native_display: %p, attrib_list: %p", platform, native_display, attrib_list);
        LOAD_EGL(eglGetPlatformDisplay)
        return egl_eglGetPlatformDisplay(platform, native_display, (const EGLint*)attrib_list);
    }

    EGL_API EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress(const char* procname) {
        return reinterpret_cast<__eglMustCastToProperFunctionPointerType>(glXGetProcAddress((const GLubyte*)procname));
    }
}

// TODO: move stuff below into glx_egl_wrapper.cpp
// GLX-to-EGL compatibility wrapper: export GLX API, internally call EGL.

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <map>
#include <vector>
#include <GL/glx.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <dlfcn.h>

#ifndef GLX_API
# define GLX_API __attribute__((visibility("default")))
#endif

static EGLDisplay eglDisplay = EGL_NO_DISPLAY;
static std::vector<EGLConfig> eglConfigs;
static bool eglInitialized = false;

struct ContextInfo {
    EGLContext ctx;
    EGLSurface draw;
    EGLSurface read;
    EGLConfig config;
};
static std::map<GLXContext, ContextInfo> contextMap;

static std::map<GLXFBConfig, EGLConfig> fbConfigMap;

#define LOAD_XLIB_FUNC(name) \
    static auto real_##name = (decltype(&::name))dlsym(RTLD_NEXT, #name); \
    if (!real_##name) { \
        fprintf(stderr, "Failed to load Xlib function: %s\n", #name); \
        return; \
    }

static void convertAttribs(const int* glx_attribs, std::vector<EGLint>& egl_attribs) {
    if (!glx_attribs) return;

    for (int i = 0; glx_attribs[i] != None; i += 2) {
        int attr = glx_attribs[i];
        int value = glx_attribs[i+1];

        switch (attr) {
            case GLX_RED_SIZE:         egl_attribs.push_back(EGL_RED_SIZE); break;
            case GLX_GREEN_SIZE:       egl_attribs.push_back(EGL_GREEN_SIZE); break;
            case GLX_BLUE_SIZE:        egl_attribs.push_back(EGL_BLUE_SIZE); break;
            case GLX_ALPHA_SIZE:       egl_attribs.push_back(EGL_ALPHA_SIZE); break;
            case GLX_DEPTH_SIZE:       egl_attribs.push_back(EGL_DEPTH_SIZE); break;
            case GLX_STENCIL_SIZE:     egl_attribs.push_back(EGL_STENCIL_SIZE); break;
            case GLX_SAMPLE_BUFFERS:   egl_attribs.push_back(EGL_SAMPLE_BUFFERS); break;
            case GLX_SAMPLES:          egl_attribs.push_back(EGL_SAMPLES); break;
            case GLX_RENDER_TYPE:
                egl_attribs.push_back(EGL_RENDERABLE_TYPE);
                egl_attribs.push_back(EGL_OPENGL_BIT);
                continue;
            case GLX_DOUBLEBUFFER:
                egl_attribs.push_back(EGL_SURFACE_TYPE);
                egl_attribs.push_back(value ? EGL_WINDOW_BIT : EGL_PBUFFER_BIT);
                continue;
            case GLX_DRAWABLE_TYPE:
                egl_attribs.push_back(EGL_SURFACE_TYPE);
                if (value & GLX_WINDOW_BIT) egl_attribs.back() |= EGL_WINDOW_BIT;
                if (value & GLX_PBUFFER_BIT) egl_attribs.back() |= EGL_PBUFFER_BIT;
                continue;
            default:
                continue;
        }
        egl_attribs.push_back(value);
    }
    egl_attribs.push_back(EGL_NONE);
}

static void ensureEGL(Display *dpy) {
    if (eglInitialized) return;
    eglDisplay = eglGetDisplay((EGLNativeDisplayType)dpy);
    if (eglDisplay == EGL_NO_DISPLAY) {
        fprintf(stderr, "Failed to get EGL display\n");
        return;
    }

    EGLint maj, min;
    if (!eglInitialize(eglDisplay, &maj, &min)) {
        fprintf(stderr, "Failed to initialize EGL\n");
        return;
    }

    const EGLint attribs[] = {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_STENCIL_SIZE, 8,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT | EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_NONE
    };

    EGLint count = 0;
    if (!eglChooseConfig(eglDisplay, attribs, nullptr, 0, &count) || count == 0) {
        fprintf(stderr, "No EGL configs found\n");
        return;
    }

    eglConfigs.resize(count);
    if (!eglChooseConfig(eglDisplay, attribs, eglConfigs.data(), count, &count)) {
        fprintf(stderr, "Failed to get EGL configs\n");
        return;
    }

    for (int i = 0; i < count; ++i) {
        GLXFBConfig glxCfg = reinterpret_cast<GLXFBConfig>(eglConfigs[i]);
        fbConfigMap[glxCfg] = eglConfigs[i];
    }

    eglInitialized = true;
}

extern "C" {

GLX_API const char* glXQueryExtensionsString(Display *dpy, int screen) {
    static std::string extensions;

    if (extensions.empty()) {
        ensureEGL(dpy);
        const char* eglExts = eglQueryString(eglDisplay, EGL_EXTENSIONS);

        extensions = "GLX_ARB_create_context "
                     "GLX_ARB_create_context_profile "
                     "GLX_ARB_fbconfig_float "
                     "GLX_ARB_multisample "
                     "GLX_EXT_swap_control "
                     "GLX_EXT_fbconfig_packed_float "
                     "GLX_EXT_texture_from_pixmap";

        if (eglExts && strstr(eglExts, "EGL_KHR_create_context")) {
            extensions += " GLX_ARB_create_context_robustness";
        }
    }

    return extensions.c_str();
}

GLX_API const char *glXGetClientString(Display *dpy, int name) {
    ensureEGL(dpy);
    if (name == GLX_VENDOR) return "EGL Vendor";
    if (name == GLX_VERSION) return "1.4";
    return "";
}

GLX_API const char *glXQueryServerString(Display *dpy, int screen, int name) {
    return glXGetClientString(dpy, name);
}

GLX_API Bool glXIsDirect(Display *dpy, GLXContext ctx) {
    ensureEGL(dpy);
    return True;
}

GLX_API GLXFBConfig *glXGetFBConfigs(Display *dpy, int screen, int *nelements) {
    ensureEGL(dpy);
    int n = eglConfigs.size();
    GLXFBConfig *list = (GLXFBConfig*)malloc(n * sizeof(GLXFBConfig));

    for (int i = 0; i < n; ++i) {
        list[i] = reinterpret_cast<GLXFBConfig>(eglConfigs[i]);
    }

    if (nelements) *nelements = n;
    return list;
}

GLX_API GLXFBConfig* glXChooseFBConfig(Display *dpy, int screen,
                              const int *attrib_list, int *nelements) {
    ensureEGL(dpy);
    std::vector<GLXFBConfig> matchingConfigs;

    if (!attrib_list || attrib_list[0] == None) {
        for (EGLConfig cfg : eglConfigs) {
            matchingConfigs.push_back(reinterpret_cast<GLXFBConfig>(cfg));
        }
    } else {
        for (EGLConfig cfg : eglConfigs) {
            GLXFBConfig config = reinterpret_cast<GLXFBConfig>(cfg);
            bool matches = true;

            // 解析属性列表
            for (int j = 0; attrib_list[j] != None; j += 2) {
                int attrib = attrib_list[j];
                int value = attrib_list[j+1];
                int actualValue = 0;

                if (value == GLX_DONT_CARE) continue;

                if (!glXGetFBConfigAttrib(dpy, config, attrib, &actualValue)) {
                    matches = false;
                    break;
                }

                if (attrib == GLX_RENDER_TYPE || attrib == GLX_DRAWABLE_TYPE) {
                    if ((actualValue & value) != value) {
                        matches = false;
                        break;
                    }
                } else {
                    if (actualValue != value) {
                        matches = false;
                        break;
                    }
                }
            }

            if (matches) {
                matchingConfigs.push_back(config);
            }
        }
    }

    if (matchingConfigs.empty()) {
        *nelements = 0;
        return nullptr;
    }

    GLXFBConfig* result = new GLXFBConfig[matchingConfigs.size()];
    std::copy(matchingConfigs.begin(), matchingConfigs.end(), result);
    *nelements = matchingConfigs.size();
    return result;
}

GLX_API int glXGetFBConfigAttrib(Display *dpy, GLXFBConfig config,
                                int attribute, int *value) {
    ensureEGL(dpy);

    if (fbConfigMap.find(config) == fbConfigMap.end()) {
        fprintf(stderr, "Invalid FBConfig handle: %p\n", config);
        return 0;
    }
    EGLConfig eglCfg = fbConfigMap[config];
    EGLint eglValue = 0;

    switch (attribute) {
        case GLX_BUFFER_SIZE: {
            EGLint r, g, b, a;
            eglGetConfigAttrib(eglDisplay, eglCfg, EGL_RED_SIZE, &r);
            eglGetConfigAttrib(eglDisplay, eglCfg, EGL_GREEN_SIZE, &g);
            eglGetConfigAttrib(eglDisplay, eglCfg, EGL_BLUE_SIZE, &b);
            eglGetConfigAttrib(eglDisplay, eglCfg, EGL_ALPHA_SIZE, &a);
            *value = r + g + b + a;
            return 1;
        }
        case GLX_DOUBLEBUFFER:
            *value = True;
            return 1;
        case GLX_SAMPLE_BUFFERS:
            if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_SAMPLE_BUFFERS, &eglValue)) {
                *value = 0;
                return 1;
            }
            *value = static_cast<int>(eglValue);
            return 1;
        case GLX_TRANSPARENT_TYPE:
            *value = GLX_NONE;
            return 1;
        case GLX_X_RENDERABLE:
            *value = True;
            return 1;
        case GLX_DRAWABLE_TYPE: {
            EGLint surfaceType;
            if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_SURFACE_TYPE, &surfaceType)) {
                *value = 0;
                return 0;
            }

            int drawableType = 0;
            if (surfaceType & EGL_WINDOW_BIT) drawableType |= GLX_WINDOW_BIT;
            if (surfaceType & EGL_PBUFFER_BIT) drawableType |= GLX_PBUFFER_BIT;
            if (surfaceType & EGL_PIXMAP_BIT) drawableType |= GLX_PIXMAP_BIT;

            *value = drawableType;
            return 1;
        }
        case GLX_LEVEL:
            *value = 0;
            return 1;
        case GLX_STEREO:
            *value = False;
            return 1;
        case GLX_AUX_BUFFERS:
            *value = 0;
            return 1;
        case GLX_VISUAL_ID:
            if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_NATIVE_VISUAL_ID, value)) {
                *value = 0;
                return 0;
            }
            return 1;
        case GLX_X_VISUAL_TYPE:
            *value = GLX_TRUE_COLOR;
            return 1;
        case GLX_CONFIG_CAVEAT: {
            EGLint caveat;
            if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_CONFIG_CAVEAT, &caveat)) {
                *value = GLX_NONE;
                return 1;
            }
            *value = (caveat == EGL_SLOW_CONFIG) ? GLX_SLOW_CONFIG : GLX_NONE;
            return 1;
        }
        case GLX_RENDER_TYPE: {
            EGLint renderableType;
            if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_RENDERABLE_TYPE, &renderableType)) {
                *value = 0;
                return 0;
            }

            int renderType = 0;
            if (renderableType & EGL_OPENGL_BIT) {
                renderType |= GLX_RGBA_BIT;
            }
            if (renderableType & EGL_OPENGL_ES_BIT) {
                renderType |= GLX_RGBA_BIT;
            }
            if (renderableType & EGL_OPENGL_ES2_BIT) {
                renderType |= GLX_RGBA_BIT;
            }
            if (renderableType & EGL_OPENGL_ES3_BIT) {
                renderType |= GLX_RGBA_BIT;
            }
            *value = renderType;
            return 1;
        }
        case GLX_FBCONFIG_ID: {
            EGLint configId;
            if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_CONFIG_ID, &configId)) {
                return 0;
            }
            *value = static_cast<int>(configId);
            return 1;
        }
    }

    static const std::map<int, EGLint> attrMap = {
        {GLX_RED_SIZE,         EGL_RED_SIZE},
        {GLX_GREEN_SIZE,       EGL_GREEN_SIZE},
        {GLX_BLUE_SIZE,        EGL_BLUE_SIZE},
        {GLX_ALPHA_SIZE,       EGL_ALPHA_SIZE},
        {GLX_DEPTH_SIZE,       EGL_DEPTH_SIZE},
        {GLX_STENCIL_SIZE,     EGL_STENCIL_SIZE},
        {GLX_SAMPLES,          EGL_SAMPLES},
        {GLX_CONFIG_CAVEAT,    EGL_CONFIG_CAVEAT},
        {GLX_VISUAL_ID,        EGL_NATIVE_VISUAL_ID},
        {GLX_TRANSPARENT_TYPE, EGL_TRANSPARENT_TYPE},
        {GLX_TRANSPARENT_RED_VALUE,   EGL_TRANSPARENT_RED_VALUE},
        {GLX_TRANSPARENT_GREEN_VALUE, EGL_TRANSPARENT_GREEN_VALUE},
        {GLX_TRANSPARENT_BLUE_VALUE,  EGL_TRANSPARENT_BLUE_VALUE},
        {GLX_BUFFER_SIZE,      EGL_BUFFER_SIZE},
        {GLX_MAX_PBUFFER_WIDTH,     EGL_MAX_PBUFFER_WIDTH},
        {GLX_MAX_PBUFFER_HEIGHT,    EGL_MAX_PBUFFER_HEIGHT},
        {GLX_MAX_PBUFFER_PIXELS,    EGL_MAX_PBUFFER_PIXELS}
    };

    if (attrMap.count(attribute)) {
        if (eglGetConfigAttrib(eglDisplay, eglCfg, attrMap.at(attribute), &eglValue)) {
            *value = static_cast<int>(eglValue);
            return 1;
        }
    }

    fprintf(stderr, "Unsupported attribute: 0x%x\n", attribute);
    return 0;
}

GLX_API XVisualInfo *glXGetVisualFromFBConfig(Display *dpy, GLXFBConfig config) {
    ensureEGL(dpy);
    if (fbConfigMap.find(config) == fbConfigMap.end()) {
        fprintf(stderr, "Invalid FBConfig in glXGetVisualFromFBConfig\n");
        return nullptr;
    }

    EGLConfig eglCfg = fbConfigMap[config];
    EGLint native_visual_id;
    if (!eglGetConfigAttrib(eglDisplay, eglCfg, EGL_NATIVE_VISUAL_ID, &native_visual_id)) {
        fprintf(stderr, "Failed to get EGL_NATIVE_VISUAL_ID\n");
        return nullptr;
    }

    static auto realXGetVisualInfo = (XVisualInfo*(*)(Display*, long, XVisualInfo*, int*))dlsym(RTLD_NEXT, "XGetVisualInfo");
    if (!realXGetVisualInfo) {
        fprintf(stderr, "Failed to load XGetVisualInfo\n");
        return nullptr;
    }

    XVisualInfo templ;
    memset(&templ, 0, sizeof(templ));
    templ.visualid = native_visual_id;
    templ.screen = DefaultScreen(dpy);

    int count = 0;
    XVisualInfo* visList = realXGetVisualInfo(dpy, VisualIDMask | VisualScreenMask, &templ, &count);
    if (count > 0) {
        return visList;
    }

    return nullptr;
}

GLX_API void glXDestroyContext(Display *dpy, GLXContext ctx) {
    ensureEGL(dpy);
    auto it = contextMap.find(ctx);
    if (it != contextMap.end()) {
        eglDestroyContext(eglDisplay, it->second.ctx);
        contextMap.erase(it);
    }
}

GLX_API Bool glXMakeCurrent(Display *dpy, GLXDrawable drawable,
                             GLXContext ctx) {
    ensureEGL(dpy);
    if (!ctx) {
        return eglMakeCurrent(eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    }

    auto it = contextMap.find(ctx);
    if (it == contextMap.end()) return False;

    auto &ci = it->second;
    if (ci.draw == EGL_NO_SURFACE && drawable) {
        ci.draw = eglCreateWindowSurface(eglDisplay, ci.config,
                                         (EGLNativeWindowType)drawable, nullptr);
        if (ci.draw == EGL_NO_SURFACE) {
            fprintf(stderr, "eglCreateWindowSurface failed: 0x%x\n", eglGetError());
            return False;
        }
        ci.read = ci.draw;
    }

    return eglMakeCurrent(eglDisplay, ci.draw, ci.read, ci.ctx);
}

GLX_API GLXContext glXGetCurrentContext() {
    EGLContext cur = eglGetCurrentContext();
    for (auto &p : contextMap)
        if (p.second.ctx == cur) return p.first;
    return nullptr;
}

GLX_API GLXDrawable glXGetCurrentDrawable() {
    EGLSurface surf = eglGetCurrentSurface(EGL_DRAW);
    return (GLXDrawable)surf;
}

GLX_API GLXContext glXCreateContextAttribsARB(Display *dpy, GLXFBConfig config,
                                     GLXContext share_context, Bool direct,
                                     const int *attrib_list) {
    ensureEGL(dpy);

    if (fbConfigMap.find(config) == fbConfigMap.end()) {
        fprintf(stderr, "Invalid FBConfig handle\n");
        return nullptr;
    }

    EGLConfig eglCfg = fbConfigMap[config];


    EGLint contextAttribs[32];
    int attribIndex = 0;
    int majorVersion = 1;
    int minorVersion = 0;
    int profileMask = 0;
    int flags = 0;

    EGLint contextFlags = 0;
    if (attrib_list) {
        for (int i = 0; attrib_list[i] != None; i += 2) {
            switch (attrib_list[i]) {
                case GLX_CONTEXT_MAJOR_VERSION_ARB:
                    majorVersion = attrib_list[i+1];
                    break;
                case GLX_CONTEXT_MINOR_VERSION_ARB:
                    minorVersion = attrib_list[i+1];
                    break;
                case GLX_CONTEXT_PROFILE_MASK_ARB:
                    profileMask = attrib_list[i+1];
                    break;
                case GLX_CONTEXT_FLAGS_ARB:
                    flags = attrib_list[i+1];
                    break;
            }
        }
    }


    contextAttribs[attribIndex++] = EGL_CONTEXT_MAJOR_VERSION;
    contextAttribs[attribIndex++] = majorVersion;
    contextAttribs[attribIndex++] = EGL_CONTEXT_MINOR_VERSION;
    contextAttribs[attribIndex++] = minorVersion;

    if (profileMask & GLX_CONTEXT_CORE_PROFILE_BIT_ARB) {
        contextAttribs[attribIndex++] = EGL_CONTEXT_OPENGL_PROFILE_MASK;
        contextAttribs[attribIndex++] = EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT;
    } else if (profileMask & GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB) {
        contextAttribs[attribIndex++] = EGL_CONTEXT_OPENGL_PROFILE_MASK;
        contextAttribs[attribIndex++] = EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT;
    }

    if (flags & GLX_CONTEXT_DEBUG_BIT_ARB) {
        contextFlags |= EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR;
    }
    if (flags & GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB) {
        contextFlags |= EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR;
    }
    if (contextFlags != 0) {
        contextAttribs[attribIndex++] = EGL_CONTEXT_FLAGS_KHR;
        contextAttribs[attribIndex++] = contextFlags;
    }
    contextAttribs[attribIndex] = EGL_NONE;

    eglBindAPI(EGL_OPENGL_ES_API);

    EGLContext shareCtx = share_context ? contextMap[share_context].ctx : EGL_NO_CONTEXT;
    EGLContext eglCtx = eglCreateContext(eglDisplay, eglCfg, shareCtx, contextAttribs);

    if (eglCtx != EGL_NO_CONTEXT) {
        GLXContext glxCtx = reinterpret_cast<GLXContext>(eglCtx);
        contextMap[glxCtx] = { eglCtx, EGL_NO_SURFACE, EGL_NO_SURFACE, eglCfg };
        return glxCtx;
    }

    fprintf(stderr, "eglCreateContext failed: 0x%x\n", eglGetError());
    return nullptr;
}

GLX_API Bool glXMakeContextCurrent(Display *dpy, GLXDrawable draw,
                                    GLXDrawable read, GLXContext ctx) {
    ensureEGL(dpy);
    if (!ctx) {
        return eglMakeCurrent(eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    }

    auto it = contextMap.find(ctx);
    if (it == contextMap.end()) return False;

    auto &ci = it->second;
    if (ci.draw == EGL_NO_SURFACE && draw) {
        ci.draw = eglCreateWindowSurface(eglDisplay, ci.config,
                                         (EGLNativeWindowType)draw, nullptr);
        if (ci.draw == EGL_NO_SURFACE) {
            fprintf(stderr, "eglCreateWindowSurface (draw) failed: 0x%x\n", eglGetError());
            return False;
        }
    }

    if (read) {
        ci.read = eglCreateWindowSurface(eglDisplay, ci.config,
                                         (EGLNativeWindowType)read, nullptr);
        if (ci.read == EGL_NO_SURFACE) {
            fprintf(stderr, "eglCreateWindowSurface (read) failed: 0x%x\n", eglGetError());
            return False;
        }
    } else {
        ci.read = ci.draw;
    }

    return eglMakeCurrent(eglDisplay, ci.draw, ci.read, ci.ctx);
}

GLX_API GLXDrawable glXGetCurrentReadDrawable() {
    EGLSurface surf = eglGetCurrentSurface(EGL_READ);
    return (GLXDrawable)surf;
}

GLX_API void glXSwapBuffers(Display *dpy, GLXDrawable drawable) {
    ensureEGL(dpy);
    eglSwapBuffers(eglDisplay, (EGLSurface)drawable);
}

GLX_API GLXPbuffer glXCreatePbuffer(Display *dpy, GLXFBConfig config,
                                     const int *attrib_list) {
    ensureEGL(dpy);
    if (fbConfigMap.find(config) == fbConfigMap.end())
        return 0;

    std::vector<EGLint> attr;
    for (int i = 0; attrib_list && attrib_list[i] != None; i += 2) {
        attr.push_back(attrib_list[i]);
        attr.push_back(attrib_list[i+1]);
    }
    attr.push_back(EGL_NONE);

    EGLSurface surf = eglCreatePbufferSurface(eglDisplay,
                                              fbConfigMap[config],
                                              attr.data());
    return (GLXPbuffer)surf;
}

GLX_API void glXDestroyPbuffer(Display *dpy, GLXPbuffer pbuf) {
    ensureEGL(dpy);
    eglDestroySurface(eglDisplay, (EGLSurface)pbuf);
}

GLX_API void glXQueryDrawable(Display *dpy, GLXDrawable draw,
                               int attribute, unsigned int *value) {
    ensureEGL(dpy);
    EGLint v;
    eglQuerySurface(eglDisplay, (EGLSurface)draw, attribute, &v);
    if (value) *value = static_cast<unsigned int>(v);
}

GLX_API void glXWaitGL()    { eglWaitGL(); }
GLX_API void glXWaitX()     { eglWaitNative(EGL_CORE_NATIVE_ENGINE); }
GLX_API void glXUseXFont(Font font, int first, int count, int list) { /* no-op */ }

GLX_API GLXContext glXCreateNewContext(Display *dpy, GLXFBConfig config,
                                        int renderType,
                                        GLXContext share_list,
                                        Bool direct) {
    ensureEGL(dpy);
    if (!eglInitialized || fbConfigMap.find(config) == fbConfigMap.end())
        return nullptr;

    EGLConfig eglCfg = fbConfigMap[config];

    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint attribs[] = { EGL_NONE };
    EGLContext shared = share_list ? contextMap[share_list].ctx : EGL_NO_CONTEXT;
    EGLContext ctx = eglCreateContext(eglDisplay, eglCfg, shared, attribs);
    if (ctx == EGL_NO_CONTEXT) {
        fprintf(stderr, "eglCreateContext (legacy) failed: 0x%x\n", eglGetError());
        return nullptr;
    }

    GLXContext fake = (GLXContext)ctx;
    contextMap[fake] = { ctx, EGL_NO_SURFACE, EGL_NO_SURFACE, eglCfg };
    return fake;
}

GLX_API GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis,
                                     GLXContext share_list, Bool direct) {
    ensureEGL(dpy);
    if (!eglInitialized) return nullptr;

    EGLConfig config = EGL_NO_CONFIG_KHR;
    for (int i = 0; i < eglConfigs.size(); i++) {
        EGLint native_visual_id;
        if (eglGetConfigAttrib(eglDisplay, eglConfigs[i], EGL_NATIVE_VISUAL_ID, &native_visual_id) &&
            native_visual_id == (EGLint)vis->visualid) {
            config = eglConfigs[i];
            break;
        }
    }
    if (config == EGL_NO_CONFIG_KHR) {
        config = eglConfigs[0];
    }

    eglBindAPI(EGL_OPENGL_API);

    const EGLint attribs[] = { EGL_NONE };
    EGLContext shared = share_list ? contextMap[share_list].ctx : EGL_NO_CONTEXT;
    EGLContext ctx = eglCreateContext(eglDisplay, config, shared, attribs);
    if (ctx == EGL_NO_CONTEXT) {
        fprintf(stderr, "eglCreateContext (compat) failed: 0x%x\n", eglGetError());
        return nullptr;
    }

    GLXContext fake = (GLXContext)ctx;
    contextMap[fake] = { ctx, EGL_NO_SURFACE, EGL_NO_SURFACE, config };
    return fake;
}

GLX_API void glXDestroyDrawable(Display *dpy, GLXDrawable drawable) {
    ensureEGL(dpy);
    eglDestroySurface(eglDisplay, (EGLSurface)drawable);
}

GLX_API Bool glXQueryVersion(Display *dpy, int *major, int *minor) {
    ensureEGL(dpy);
    if (!eglInitialized) return False;

    EGLint maj, min;
    eglInitialize(eglDisplay, &maj, &min);
    if (major) *major = maj;
    if (minor) *minor = min;
    return True;
}

GLX_API int glXGetConfig(Display *dpy, XVisualInfo *vis, int attrib, int *value) {
    ensureEGL(dpy);
    if (!eglInitialized || !vis || !value) return 0;

    EGLConfig matchedConfig = EGL_NO_CONFIG_KHR;
    for (auto& cfg : eglConfigs) {
        EGLint native_visual_id;
        if (eglGetConfigAttrib(eglDisplay, cfg, EGL_NATIVE_VISUAL_ID, &native_visual_id) &&
            native_visual_id == (EGLint)vis->visualid) {
            matchedConfig = cfg;
            break;
        }
    }

    if (matchedConfig == EGL_NO_CONFIG_KHR) {
        matchedConfig = eglConfigs[0];
    }

    EGLint eglValue = 0;
    Bool result = True;

    switch (attrib) {
        case GLX_USE_GL:
            *value = True;
            return result;
        case GLX_BUFFER_SIZE: {
            EGLint r, g, b, a;
            eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_RED_SIZE, &r);
            eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_GREEN_SIZE, &g);
            eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_BLUE_SIZE, &b);
            eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_ALPHA_SIZE, &a);
            *value = r + g + b + a;
            return result;
        }
        case GLX_LEVEL:
            *value = 0;
            return result;
        case GLX_RGBA:
            *value = True;
            return result;
        case GLX_DOUBLEBUFFER:
            *value = True;
            return result;
        case GLX_STEREO:
            *value = False;
            return result;
        case GLX_AUX_BUFFERS:
            *value = 0;
            return result;
        case GLX_RED_SIZE:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_RED_SIZE, &eglValue);
            break;
        case GLX_GREEN_SIZE:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_GREEN_SIZE, &eglValue);
            break;
        case GLX_BLUE_SIZE:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_BLUE_SIZE, &eglValue);
            break;
        case GLX_ALPHA_SIZE:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_ALPHA_SIZE, &eglValue);
            break;
        case GLX_DEPTH_SIZE:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_DEPTH_SIZE, &eglValue);
            break;
        case GLX_STENCIL_SIZE:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_STENCIL_SIZE, &eglValue);
            break;
        case GLX_ACCUM_RED_SIZE:
        case GLX_ACCUM_GREEN_SIZE:
        case GLX_ACCUM_BLUE_SIZE:
        case GLX_ACCUM_ALPHA_SIZE:
            *value = 0;
            return result;
        case GLX_CONFIG_CAVEAT:
            *value = GLX_NONE;
            return result;
        case GLX_X_VISUAL_TYPE:
            *value = GLX_TRUE_COLOR;
            return result;
        case GLX_TRANSPARENT_TYPE:
            *value = GLX_NONE;
            return result;
        case GLX_TRANSPARENT_INDEX_VALUE:
        case GLX_TRANSPARENT_RED_VALUE:
        case GLX_TRANSPARENT_GREEN_VALUE:
        case GLX_TRANSPARENT_BLUE_VALUE:
        case GLX_TRANSPARENT_ALPHA_VALUE:
            *value = 0;
            return result;
        case GLX_DRAWABLE_TYPE:
            *value = GLX_WINDOW_BIT | GLX_PBUFFER_BIT;
            return result;
        case GLX_RENDER_TYPE:
            *value = GLX_RGBA_BIT;
            return result;
        case GLX_X_RENDERABLE:
            *value = True;
            return result;
        case GLX_FBCONFIG_ID: {
            EGLint configId;
            result = eglGetConfigAttrib(eglDisplay, matchedConfig, EGL_CONFIG_ID, &configId);
            eglValue = configId;
            break;
        }
        case GLX_MAX_PBUFFER_WIDTH:
        case GLX_MAX_PBUFFER_HEIGHT:
        case GLX_MAX_PBUFFER_PIXELS:
            result = eglGetConfigAttrib(eglDisplay, matchedConfig,
                                       (attrib == GLX_MAX_PBUFFER_WIDTH) ? EGL_MAX_PBUFFER_WIDTH :
                                       (attrib == GLX_MAX_PBUFFER_HEIGHT) ? EGL_MAX_PBUFFER_HEIGHT :
                                       EGL_MAX_PBUFFER_PIXELS, &eglValue);
            break;
        case GLX_VISUAL_ID:
            *value = vis->visualid;
            return result;
        case GLX_SCREEN:
            *value = vis->screen;
            return result;
        default:
            return 0;
    }

    if (result) {
        *value = static_cast<int>(eglValue);
        return 1;
    }

    return 0;
}

GLX_API XVisualInfo* glXChooseVisual(Display *dpy, int screen, int *attribList) {
    ensureEGL(dpy);
    if (!dpy || !attribList) return nullptr;

    std::vector<EGLint> eglAttribs;
    for (int i = 0; attribList[i] != None; i += 2) {
        int attr = attribList[i];
        int value = attribList[i+1];

        switch (attr) {
            case GLX_RGBA:
                break;
            case GLX_RED_SIZE:
                eglAttribs.push_back(EGL_RED_SIZE);
                eglAttribs.push_back(value);
                break;
            case GLX_GREEN_SIZE:
                eglAttribs.push_back(EGL_GREEN_SIZE);
                eglAttribs.push_back(value);
                break;
            case GLX_BLUE_SIZE:
                eglAttribs.push_back(EGL_BLUE_SIZE);
                eglAttribs.push_back(value);
                break;
            case GLX_ALPHA_SIZE:
                eglAttribs.push_back(EGL_ALPHA_SIZE);
                eglAttribs.push_back(value);
                break;
            case GLX_DEPTH_SIZE:
                eglAttribs.push_back(EGL_DEPTH_SIZE);
                eglAttribs.push_back(value);
                break;
            case GLX_STENCIL_SIZE:
                eglAttribs.push_back(EGL_STENCIL_SIZE);
                eglAttribs.push_back(value);
                break;
            case GLX_DOUBLEBUFFER:
                eglAttribs.push_back(EGL_SURFACE_TYPE);
                eglAttribs.push_back(value ? EGL_WINDOW_BIT : EGL_PBUFFER_BIT);
                break;
        }
    }

    eglAttribs.push_back(EGL_RENDERABLE_TYPE);
    eglAttribs.push_back(EGL_OPENGL_BIT);
    eglAttribs.push_back(EGL_NONE);

    EGLConfig config;
    EGLint numConfigs;
    if (!eglChooseConfig(eglDisplay, eglAttribs.data(), &config, 1, &numConfigs) || numConfigs == 0) {
        fprintf(stderr, "No matching EGL config found for visual\n");
        return nullptr;
    }

    EGLint native_visual_id;
    if (!eglGetConfigAttrib(eglDisplay, config, EGL_NATIVE_VISUAL_ID, &native_visual_id)) {
        fprintf(stderr, "Failed to get EGL_NATIVE_VISUAL_ID\n");
        return nullptr;
    }

    static auto realXGetVisualInfo = (XVisualInfo*(*)(Display*, long, XVisualInfo*, int*))dlsym(RTLD_NEXT, "XGetVisualInfo");
    if (!realXGetVisualInfo) {
        fprintf(stderr, "Failed to load XGetVisualInfo\n");
        return nullptr;
    }

    XVisualInfo templ;
    memset(&templ, 0, sizeof(templ));
    templ.visualid = native_visual_id;
    templ.screen = screen;

    int count = 0;
    return realXGetVisualInfo(dpy, VisualIDMask | VisualScreenMask, &templ, &count);
}

} // extern "C"

