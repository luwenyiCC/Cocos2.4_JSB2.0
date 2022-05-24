#include <string>

#ifndef PROJ_ANDROID_STUDIO_CCIABCJSBBRIDGEIML_H
#define PROJ_ANDROID_STUDIO_CCIABCJSBBRIDGEIML_H

#endif //PROJ_ANDROID_STUDIO_CCIABCJSBBRIDGEIML_H

#define DLLOG(format, ...)      cocos2d::log(format, ##__VA_ARGS__)

namespace abc
{
    class IABCJSBBridgeImpl
    {
    public:
        virtual ~IABCJSBBridgeImpl(){}
        virtual void abcLog(const int level, const std::string& tag, const std::string& msg) = 0;
        virtual void getFrame(const std::string& msg) = 0;
    };
}