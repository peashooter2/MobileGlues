#ifndef _GL4ES_LOGS_H_
#define _GL4ES_LOGS_H_
//----------------------------------------------------------------------------
#include <stdio.h>
#include "init.h"
#include "attributes.h"
#include <android/log.h>
//----------------------------------------------------------------------------
void LogPrintf_NoPrefix(const char *fmt,...);
void LogFPrintf(FILE *fp,const char *fmt,...);
EXPORT void LogPrintf(const char *fmt,...);
void write_log(const char *format, ...);
//----------------------------------------------------------------------------
#define SHUT_LOGD(...) {__android_log_print(ANDROID_LOG_DEBUG, "MobileGlues-gl4es", __VA_ARGS__);printf(__VA_ARGS__);printf("MobileGlues-gl4es: \n");write_log(__VA_ARGS__);}
#define SHUT_LOGD_NOPREFIX(...) {__android_log_print(ANDROID_LOG_DEBUG, "MobileGlues-gl4es", __VA_ARGS__);printf(__VA_ARGS__);printf("MobileGlues-gl4es: \n");write_log(__VA_ARGS__);}
#define SHUT_LOGE(...) {__android_log_print(ANDROID_LOG_DEBUG, "MobileGlues-gl4es", __VA_ARGS__);printf(__VA_ARGS__);printf("MobileGlues-gl4es: \n");write_log(__VA_ARGS__);}
//----------------------------------------------------------------------------
#define LOGD(...) {__android_log_print(ANDROID_LOG_DEBUG, "MobileGlues-gl4es", __VA_ARGS__);printf(__VA_ARGS__);printf("MobileGlues-gl4es: \n");write_log(__VA_ARGS__);}
#define LOGE(...) {__android_log_print(ANDROID_LOG_DEBUG, "MobileGlues-gl4es", __VA_ARGS__);printf(__VA_ARGS__);printf("MobileGlues-gl4es: \n");write_log(__VA_ARGS__);}
//----------------------------------------------------------------------------
#endif // _GL4ES_LOGS_H_
