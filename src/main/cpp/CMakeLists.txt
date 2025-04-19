cmake_minimum_required(VERSION 3.22.1)

project("mobileglues")

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -fvisibility=hidden -funwind-tables -g -D_THREAD_SAFE -fPIC -stdlib=libc++")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w -g -std=gnu99 -funwind-tables -O3 -fvisibility=hidden")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

set(CMAKE_ANDROID_STL_TYPE c++_static)

set(CMAKE_BUILD_TYPE Release)

set(PROFILING OFF)

find_library(GLSLANG_LIB glslang PATHS ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/)

add_library(${CMAKE_PROJECT_NAME} SHARED
        init.cpp
        main.cpp
        gl/gl_stub.cpp
        gl/gl_native.cpp
        gl/gl.cpp
        gl/envvars.cpp
        gl/log.cpp
        gl/program.cpp
        gl/shader.cpp
        gl/framebuffer.cpp
        gl/texture.cpp
        gl/drawing.cpp
        gl/mg.cpp
        gl/buffer.cpp
        gl/getter.cpp
        gl/pixel.cpp
        gl/glsl/glsl_for_es.cpp
        gl/glsl/cache.cpp
        gl/glsl/preConvertedGlsl.cpp
        gl/vertexattrib.cpp
        glx/lookup.cpp
        egl/egl.c
        egl/loader.cpp
        gles/loader.cpp
        config/cJSON.c
        config/config.cpp
        config/gpu_utils.cpp
        config/settings.cpp
        gl/glsl/glslconv_gl4es.cpp

        gl/gl4es/gl/vgpu/shaderconv.c
        gl/gl4es/gl/string_utils.c
        gl/gl4es/gl/arbconverter.c
        gl/gl4es/gl/arbgenerator.c
        gl/gl4es/gl/arbhelper.c
        gl/gl4es/gl/arbparser.c
        gl/gl4es/gl/array.c
        gl/gl4es/gl/blend.c
        gl/gl4es/gl/blit.c
        gl/gl4es/gl/buffers.c
        gl/gl4es/gl/build_info.c
        gl/gl4es/gl/debug.c
        gl/gl4es/gl/decompress.c
        gl/gl4es/gl/depth.c
        gl/gl4es/gl/directstate.c
        gl/gl4es/gl/drawing.c
        gl/gl4es/gl/enable.c
        gl/gl4es/gl/envvars.c
        gl/gl4es/gl/eval.c
        gl/gl4es/gl/face.c
        gl/gl4es/gl/fog.c
        gl/gl4es/gl/fpe.c
        gl/gl4es/gl/fpe_cache.c
        gl/gl4es/gl/fpe_shader.c
        gl/gl4es/gl/framebuffers.c
        gl/gl4es/gl/gl_lookup.c
        gl/gl4es/gl/getter.c
        gl/gl4es/gl/gl4es.c
        gl/gl4es/gl/glstate.c
        gl/gl4es/gl/hint.c
        gl/gl4es/gl/init.c
        gl/gl4es/gl/light.c
        gl/gl4es/gl/line.c
        gl/gl4es/gl/list.c
        gl/gl4es/gl/listdraw.c
        gl/gl4es/gl/listrl.c
        gl/gl4es/gl/loader.c
        gl/gl4es/gl/logs.c
        gl/gl4es/gl/matrix.c
        gl/gl4es/gl/matvec.c
        gl/gl4es/gl/oldprogram.c
        gl/gl4es/gl/pixel.c
        gl/gl4es/gl/planes.c
        gl/gl4es/gl/pointsprite.c
        gl/gl4es/gl/preproc.c
        gl/gl4es/gl/program.c
        gl/gl4es/gl/queries.c
        gl/gl4es/gl/raster.c
        gl/gl4es/gl/render.c
        gl/gl4es/gl/shader.c
        gl/gl4es/gl/shaderconv.c
        gl/gl4es/gl/shader_hacks.c
        gl/gl4es/gl/stack.c
        gl/gl4es/gl/stencil.c
        gl/gl4es/gl/stubs.c
        gl/gl4es/gl/texenv.c
        gl/gl4es/gl/texgen.c
        gl/gl4es/gl/texture.c
        gl/gl4es/gl/texture_compressed.c
        gl/gl4es/gl/texture_params.c
        gl/gl4es/gl/texture_read.c
        gl/gl4es/gl/texture_3d.c
        gl/gl4es/gl/uniform.c
        gl/gl4es/gl/vertexattrib.c
        gl/gl4es/gl/wrap/gl4eswraps.c
        gl/gl4es/gl/wrap/gles.c
        gl/gl4es/gl/wrap/glstub.c
        gl/gl4es/gl/math/matheval.c
        gl/gl4es/glx/hardext.c
        gl/gl4es/glx/glx.c
        gl/gl4es/glx/lookup.c
        gl/gl4es/glx/gbm.c
        gl/gl4es/glx/streaming.c
        gl/gl4es/gl/samplers.c
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ./includes)

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libglslang.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libspirv-cross-c-shared.so
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libshaderconv.so
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libGenericCodeGen.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libglslang-default-resource-limits.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libMachineIndependent.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libOSDependent.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-diff.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-link.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-lint.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-opt.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-reduce.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPVRemapper.a
        android
        log
        EGL
)

target_include_directories(mobileglues PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        )


if (PROFILING)
        find_package(Threads)
        include_directories(${CMAKE_SOURCE_DIR}/3rdparty/perfetto/sdk)
        add_library(perfetto STATIC ${CMAKE_SOURCE_DIR}/3rdparty/perfetto/sdk/perfetto.cc)
        target_link_libraries(mobileglues perfetto ${CMAKE_THREAD_LIBS_INIT})
        target_compile_definitions(mobileglues PUBLIC PROFILING=1)
endif()