 
 
#include "platform/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
 
// #include "../platform/CCCommon.h" ??
#include "ABCJSBBridge-android.h"
#include <android/log.h>
#include "../platform/android/jni/JniHelper.h"
#include "../platform/CCFileUtils.h"
 
#define  LOG_TAG    "ABCJSBBridge-android.cpp"
#define  LOGD(level,tag, ...)  __android_log_print(level,tag,__VA_ARGS__)
 
 
#include "base/ccMacros.h"
#include "base/ccTypes.h"
 
 
ABCJSBBridge_android::ABCJSBBridge_android()
{
}
 
ABCJSBBridge_android::~ABCJSBBridge_android()
{
}
 
 
void ABCJSBBridge_android::abcLog(const int level, const std::string& tag, const std::string& msg) {
// void abcLog(const int level, const std::string& tag, ...) {
	 LOGD(level, tag.c_str(), msg.c_str(), NULL);
}
void ABCJSBBridge_android::getFrame(const std::string& msg) {
	//return true;
}
 
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID