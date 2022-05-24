#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_abc_JSBBridge_proto;
extern se::Class* __jsb_abc_JSBBridge_class;

bool js_register_abc_JSBBridge(se::Object* obj);
bool register_all_cocos2dx_test(se::Object* obj);
SE_DECLARE_FUNC(js_cocos2dx_test_JSBBridge_abcLog);
SE_DECLARE_FUNC(js_cocos2dx_test_JSBBridge_getFrame);
SE_DECLARE_FUNC(js_cocos2dx_test_JSBBridge_getInstance);

