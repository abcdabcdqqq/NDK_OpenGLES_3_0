//
// Created by hwj on 2016/10/27.
//

#ifndef LAUNCHER_LOG_H
#define LAUNCHER_LOG_H
#include <android/log.h>

#include <unistd.h>
#include <libgen.h>

#define  LOG_TAG    "JNI_XXX"
#define isDebug true
#if  0
#define  LOGV(...)  if(isDebug){__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__);}
#define  LOGD(...)  if(isDebug){__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);}
#define  LOGI(...)  if(isDebug){__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);}
#define  LOGW(...)  if(isDebug){__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__);}
#define  LOGE(...)  if(isDebug){__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);}
#else

#define    LOGV(FMT, ...) if(isDebug){__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "[%d*%s:%d:%s]:" FMT, \
							gettid(), basename(__FILE__), __LINE__, __FUNCTION__, ## __VA_ARGS__);}

#define    LOGD(FMT, ...) if(isDebug){__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "[%d*%s:%d:%s]:" FMT, \
							gettid(), basename(__FILE__), __LINE__, __FUNCTION__, ## __VA_ARGS__);}

#define    LOGI(FMT, ...) if(isDebug){__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "[%d*%s:%d:%s]:" FMT, \
							gettid(), basename(__FILE__), __LINE__, __FUNCTION__, ## __VA_ARGS__);}


#define    LOGW(FMT, ...) if(isDebug){__android_log_print(ANDROID_LOG_WARN, LOG_TAG, "[%d*%s:%d:%s]:" FMT, \
							gettid(), basename(__FILE__), __LINE__, __FUNCTION__, ## __VA_ARGS__);}

#define    LOGE(FMT, ...) if(isDebug){__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "[%d*%s:%d:%s]:" FMT, \
							gettid(), basename(__FILE__), __LINE__, __FUNCTION__, ## __VA_ARGS__);}
#endif


#endif //LAUNCHER_LOG_H
