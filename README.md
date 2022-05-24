# Cocos2.4_JSB2.0
Cocos Create2.4.3 call c++ use JSB2.0 Building

# Cocos Create 2.4.3 JSB2.0 自动绑定 例子

## 一、安装Pyhton
我用的是Pyhton 2.7.16 [下载地址](https://www.python.org/downloads/release/python-2716/) 安装到 C:\Python27

## 二、配置Python环境变量
#### 在系统变量中新建添加：
> 变量名：PYTHON_BIN <br/>
变量值：C:\Python27\python.exe\

#### 在系统变量 Path 中新建添加：
> C:\Python27

> C:\Python27\Scripts

## 三、安装 PyYAML 和 Cheetah
```
pip install PyYAML
pip install Cheetah
```
> 之前配置的环境变量 C:\Python27\Scripts 中包含pip.exe,所以我们可以直接使用pip命令

## 四、下载 NDK
官方文档推荐下载 14b

Window 下载地址：
[android-ndk-r14b-windows-x86_64](https://dl.google.com/android/repository/android-ndk-r14b-windows-x86_64.zip)

下载完成后解压到 D:\Android\android-ndk-r14b

## 五、配置NDK环境变量

> 变量名：NDK_ROOT<br/>
变量值：D:\Android\android-ndk-r14b\

系统变量 Path 中新建添加

> %NDK_ROOT%

## 六、下载安装 LLVM
window 下载地址：LLVM-5.0.0-win64
下载后在安装目录的 bin 文件夹下找到 libclang.dll
我的地址是：C:\Program Files\LLVM\bin
把 libclang.dll 拷贝替换到：
> 引擎根目录\resources\cocos2d-x\tools\bindings-generator\libclang\

## 七、运行自动绑定
目录：
> build-templates\jsb-default\frameworks\cocos2d-x\tools\tojs\run_genbindings_custom.bat

最后输出这个就代表自动绑定大功告成了
```
----------------------------------------
Generating javascript bindings succeeds.
----------------------------------------
```

## 八、配置Android打包环境
### 1. 安装Android Studio
[下载链接](https://developer.android.google.cn/studio)
安装好后下载SDK API Level 30，步骤如下：
> File>Settings...>搜索sdk>勾选Android11.0(R)>点击右下角的Apply>等待下载完成

## 2. 下载打包用NDK
打包的NDK版本我用的是r20b [下载链接](https://dl.google.com/android/repository/android-ndk-r20b-windows-x86_64.zip)

下载后解压到
> D:\Android\android-ndk-r20b

## 3. 设置Cocos原生开发环境
> 菜单：文件 > 设置 > 原生开发环境

NDK 路径：
> D:\Android\android-ndk-r20b

Android SDK 路径：
> C:\Users\Administrator\AppData\Local\Android\Sdk

## 九、构建发布
> 菜单：项目 > 构建发布...

1. 发布平台 > Android
2. 模板 > default
3. APP ABI > arm64-v8a
4. 调试模式 > true (方便查看日志)
5. 点击构建，等待成功
6. 点击编译，等待成功
7. 连上手机，点击运行

### 在 Window 下如果编译失败有可能是你目录太深，实测超过2层目录就编译失败，解决方法有两个：
1. 移动项目到磁盘根目录。
2. 使用 junction.exe 软链目录（在git项目根目录），执行命令如下：
    > junction "D:\新目录" "D:\N层\你项目的目录"


## 十、成功运行，真机调试，查看日志
### Chrome url 中输入如下链接，进行真机调试
```
devtools://devtools/bundled/js_app.html?v8only=true&ws=(你的手机内网ip地址，例：192.168.1.10):6086/00010002-0003-4004-8005-000600070008
```
### 在Chrome devtools 中无法查看 Android 的日志输出，如果要看 Android 原生的日志输出，需要打开 Android Studio > Logcat 查看日志

---
## 到这里，第一步就大功告成了
接下来，我们来看如何配置绑定：

[JSB2.0自动绑定配置说明](doc/ConfigJSB2.0.md)
