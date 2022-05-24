#include <string>

#ifndef PROJ_ANDROID_STUDIO_ABCJSBBRIDGE_H
#define PROJ_ANDROID_STUDIO_ABCJSBBRIDGE_H
#define DLLOG(format, ...)      cocos2d::log(format, ##__VA_ARGS__)
#endif //PROJ_ANDROID_STUDIO_ABCJSBBRIDGE_H

namespace abc
{
    class IABCJSBBridgeImpl;
    class JSBBridge
    {
    public:
        void abcLog(const int level, const std::string& tag, const std::string& msg);
        void getFrame(const std::string& msg);
        /**
        * Returns a shared instance of the director.
        * @js _getInstance
        */
        static JSBBridge* getInstance();

        /** @private */
        JSBBridge();
        /** @private */
        ~JSBBridge();
        bool init();

    private:
        std::unique_ptr<IABCJSBBridgeImpl> _impl;
    };
}