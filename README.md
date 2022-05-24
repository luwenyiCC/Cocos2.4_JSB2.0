# Cocos2.4_JSB2.0
Cocos Create2.4.3 call c++ use JSB2.0 Building

# Cocos Create 2.4.3 JSB绑定2.0 例子

### 一、安装Pyhton
我用的是Pyhton 2.7.16 [下载地址](https://www.python.org/downloads/release/python-2716/) 安装到 C:\Python27

### 二、配置Python环境变量
> 变量名：PYTHON_BIN <br/>
变量值：C:\Python27\python.exe\

#### 在系统变量 Path 中新建添加：
> C:\Python27

> C:\Python27\Scripts

### 三、安装 PyYAML 和 Cheetah
```
pip install PyYAML
pip install Cheetah
```
> C:\Python27\Scripts 中包含pip.exe,所以我们配置好环境变量后就可以使用pip命令了

### 四、下载 NDK
官方文档推荐下载 14b

Window 下载地址：
[android-ndk-r14b-windows-x86_64](https://dl.google.com/android/repository/android-ndk-r14b-windows-x86_64.zip)

下载完成后解压到 D:\Android\android-ndk-r14b

### 五、配置NDK环境变量

> 变量名：NDK_ROOT<br/>
变量值：D:\Android\android-ndk-r14b\

系统变量 Path 中新建添加

> %NDK_ROOT%

### 六、下载安装 LLVM
window 下载地址：LLVM-5.0.0-win64
下载后在安装目录的 bin 文件夹下找到 libclang.dll
我的地址是：C:\Program Files\LLVM\bin
把 libclang.dll 拷贝替换到：
> 引擎根目录\resources\cocos2d-x\tools\bindings-generator\libclang\

### 七、运行自动绑定
目录：
> build-templates\jsb-default\frameworks\cocos2d-x\tools\tojs\run_genbindings_test.bat

最后输出这个就代表大功告成了
```
----------------------------------------
Generating javascript bindings succeeds.
----------------------------------------
```