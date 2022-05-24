 
#ifndef __CC_ABCJSBBRIDGE_ANDROID_H__
#define __CC_ABCJSBBRIDGE_ANDROID_H__
 
#include "platform/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
 
#include "test/CCIABCJSBBridgeIml.h"
#include "base/ccMacros.h"
#include "base/ccTypes.h"
#include <string>
#include <vector>
#include "jni.h"
 
//! @brief  Helper class to handle file operations
class CC_DLL ABCJSBBridge_android : public abc::IABCJSBBridgeImpl
{
public:
    ABCJSBBridge_android();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~ABCJSBBridge_android();
    void abcLog(const int level, const std::string& tag, const std::string& msg);
    void getFrame(const std::string& msg);
    // void abcLog(const int level, const std::string& tag, ...);
};
 
// end of platform group
/// @}
 
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
 
#endif // __CC_ABCJSBBRIDGE_ANDROID_H__