#include "ABCJSBBridge.h"
 
// include platform specific implement class
// #if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
 
// #include "ABCJSBBridge-apple.h"
// #define JSBBridgeImpl  JSBBridgeApple
 
// #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
 
 
// 实现了android的
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
 
#include "ABCJSBBridge-android.h"
#define JSBBridgeImpl  ABCJSBBridge_android
 
#endif
 #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 
 
#include "ABCJSBBridge-win32.h"
#define JSBBridgeImpl  ABCJSBBridge_win32
 
#endif
namespace abc
{
    // singleton stuff
    static JSBBridge *s_SharedJSBBridge = nullptr;
 
    JSBBridge::JSBBridge()
    {
        DLLOG("Construct JSBBridge %p", this);
        init();
    }
 
    JSBBridge::~JSBBridge()
    {
        DLLOG("Destruct JSBBridge %p", this);
        s_SharedJSBBridge = nullptr;
    }
 
    JSBBridge* JSBBridge::getInstance()
    {
        if (!s_SharedJSBBridge)
        {
            DLLOG("getInstance JSBBridge ");
            s_SharedJSBBridge = new (std::nothrow) JSBBridge();
            CCASSERT(s_SharedJSBBridge, "FATAL: Not enough memory for create JSBBridge");
        }
 
        return s_SharedJSBBridge;
    }
 
    bool JSBBridge::init(void)
    {
        DLLOG("init JSBBridge ");
        _impl.reset(new JSBBridgeImpl());
        return true; // 原来没加上的
    }
 
    void JSBBridge::abcLog(const int level, const std::string& tag, const std::string& msg)
    {
        _impl->abcLog(level, tag, msg);
    }
    void JSBBridge::getFrame(const std::string& msg)
    {
        _impl->getFrame(msg);
    }
}