[返回首页](../README.md)

# JSB2.0 自动绑定 配置 详解
[官方文档](https://docs.cocos.com/creator/2.4/manual/zh/advanced-topics/jsb-auto-binding.html)

[第三方参考文档](https://blog.csdn.net/springleaf2/article/details/122690211)

## 构建模板介绍 build-templates
[官方文档](https://docs.cocos.com/creator/2.4/manual/zh/publish/custom-project-build-template.html)
### 构建模板简介：
> 构建结束的时候，build-templates 目录下所有的文件都会自动按照对应的目录结构复制到构建生成的工程里。

# 现在让我们从 run_genbindings_custom.bat 开始一步步理解 如何配置

## 0. tools这个文件夹从哪里来的？
### tools 文件夹是从引擎的 cocos2d-x 文件夹中拷贝过来的

目录参考：
> C:\CocosDashboard_1.1.1\resources\.editors\Creator\2.4.3\resources\cocos2d-x\tools

## 1. run_genbindings_custom.bat
这个 bat 文件是用于执行 genbindings_custom.py 脚本

## 2. genbindings_custom.py 是从哪来的？

拷贝于当前目录的 genbindings.py 文件

## 3. genbindings_custom.py 中配置什么？
配置读取哪些 ini 文件
```
cmd_args = {
    'cocos2dx_custom.ini':('cocos2dx_test', 'jsb_cocos2dx_test_auto'),
}
```

## 4. cocos2dx_custom.ini 中配置了什么？（文件内有详细的注释）
 [官方文档](https://docs.cocos.com/creator/2.4/manual/zh/advanced-topics/JSB2.0-learning.html#%E9%85%8D%E7%BD%AE%E6%A8%A1%E5%9D%97-ini-%E6%96%87%E4%BB%B6)

- [cocos2dx_test] 
- prefix = cocos2dx_test \# 前缀，函数名称组合 js + prefix + 头文件中函数名称
- target_namespace = abc \# 命名空间
- headers = %(cocosdir)s/cocos/test/ABCJSBBridge.h \# 需要被绑定的头文件列表 以空格分隔
- classes = JSBBridge \# 需要被绑定的类名列表 以空格分隔

## 5. 自动绑定 生成成功后，需要干什么？
需要修改Android.mk文件，告诉编译器cpp文件位置。

在90行左右添加：
```
test/ABCJSBBridge.cpp \
test/ABCJSBBridge-android.cpp \
scripting/js-bindings/auto/jsb_cocos2dx_test_auto.cpp \
```
## 6 修改完 Android.mk文件后，需要干什么？
需要修改 jsb_module_register.cpp 文件 注册 jsb module

文件路径：
> build-templates\jsb-default\frameworks\runtime-src\Classes\jsb_module_register.cpp

在 100 行左右添加了：
```
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)


#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_test_auto.hpp"


#endif
```
在 130 行左右添加了：
```
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    se->addRegisterCallback(register_all_cocos2dx_test);
#endif
```

## 7. cpp文件里面写了啥？
参考官方文档

---
# Over