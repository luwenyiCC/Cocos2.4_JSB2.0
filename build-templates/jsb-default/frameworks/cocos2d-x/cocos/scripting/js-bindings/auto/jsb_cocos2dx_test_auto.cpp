#include "scripting/js-bindings/auto/jsb_cocos2dx_test_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "test/ABCJSBBridge.h"

se::Object* __jsb_abc_JSBBridge_proto = nullptr;
se::Class* __jsb_abc_JSBBridge_class = nullptr;

static bool js_cocos2dx_test_JSBBridge_abcLog(se::State& s)
{
    abc::JSBBridge* cobj = (abc::JSBBridge*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_test_JSBBridge_abcLog : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        std::string arg2;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[0], &tmp); arg0 = (int)tmp; } while(false);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_test_JSBBridge_abcLog : Error processing arguments");
        cobj->abcLog(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_test_JSBBridge_abcLog)

static bool js_cocos2dx_test_JSBBridge_getFrame(se::State& s)
{
    abc::JSBBridge* cobj = (abc::JSBBridge*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_test_JSBBridge_getFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_test_JSBBridge_getFrame : Error processing arguments");
        cobj->getFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_test_JSBBridge_getFrame)

static bool js_cocos2dx_test_JSBBridge_getInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        abc::JSBBridge* result = abc::JSBBridge::getInstance();
        ok &= native_ptr_to_seval<abc::JSBBridge>((abc::JSBBridge*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_test_JSBBridge_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_test_JSBBridge_getInstance)




bool js_register_cocos2dx_test_JSBBridge(se::Object* obj)
{
    auto cls = se::Class::create("JSBBridge", obj, nullptr, nullptr);

    cls->defineFunction("abcLog", _SE(js_cocos2dx_test_JSBBridge_abcLog));
    cls->defineFunction("getFrame", _SE(js_cocos2dx_test_JSBBridge_getFrame));
    cls->defineStaticFunction("getInstance", _SE(js_cocos2dx_test_JSBBridge_getInstance));
    cls->install();
    JSBClassType::registerClass<abc::JSBBridge>(cls);

    __jsb_abc_JSBBridge_proto = cls->getProto();
    __jsb_abc_JSBBridge_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_cocos2dx_test(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("abc", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("abc", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_test_JSBBridge(ns);
    return true;
}

