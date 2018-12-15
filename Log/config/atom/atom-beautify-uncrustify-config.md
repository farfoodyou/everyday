# atom : Could not find 'uncrustify'. The program may not be installed.

> sudo apt install linuxbrew-wrapper brew install homebrew/php/php-cs-fixer

Warning: /home/farfood/.linuxbrew/bin is not in your PATH. 结果是

```
==> Installing php-cs-fixer from homebrew/php
Error: undefined method `rebuild' for #<BottleSpecification:0x0000000228e180>
Please report this bug:
    https://github.com/Linuxbrew/linuxbrew/blob/master/share/doc/homebrew/Troubleshooting.md#troubleshooting
```

> sudo apt-get install uncrustify

问题还是没有解决：在atom中运行beautify还是出现了如下<font color=red>错误</font>；

Parsing: /tmp/input1161122-11997-c8z7uo.scb10dx6r as language CPP /tmp/input1161122-11997-c8z7uo.scb10dx6r:6 Garbage in col 9: 201c /tmp/input1161122-11997-c8z7uo.scb10dx6r:6 Garbage in col 26: 5c /tmp/input1161122-11997-c8z7uo.scb10dx6r:6 Garbage in col 28: 201d

<font color=yellow>我猜测可能是ubuntu安装的uncrustify版本太旧了</font>
所以我要去下载一个新的试试。
> git clone https://github.com/uncrustify/uncrustify.git<br/>
> cd uncrustify/<br/>
> cmake -DCMAKE_BUILD_TYPE=Release<br/>

遇到了**问题**

CMake Error at CMakeLists.txt:6 (message):
  

      In-source builds are not supported, please remove the `CMakeFiles'
      folder and `CMakeCache.txt', and create a folder for the build:
      mkdir build; cd build; cmake ..

按照提示删除相应文件，然后输入。
```
mkdir build 
cd build
cmke .. -DCMAKE_BUILD_TYPE=Release
make
```

which uncrustify
却没有反应
```
sudo make install
[100%] Built target uncrustify
Install the project...
-- Install configuration: "Release"
-- Installing: /usr/local/bin/uncrustify
-- Installing: /usr/local/share/man/man1/uncrustify.1
which uncrustify 
/usr/local/bin/uncrustify
```
结果还是出现了一些问题。
我看了看官网文档
把官方默认的配置加入了～/.uncrustify
(⊙o⊙)…，过了一会就好了

不过还有问题：
ubuntu16.04按下ctrl-alt-b出现小键盘
那就不能使用atom-beautify的快捷键了。
解决方案
有人说使用fn+ESC就好了。
我试了下，不行，然后找到了下面的：
```
1. 在搜狗拼音输入法选择设置
2. 高级设置
3. 高级设置最底部，找到fcitx设置
4. 打开fcitx设置，选择Addon选项卡，取消选择虚拟键盘
5. 注销或重启电脑
```
我觉得应该时可以了的。

第二天打开发现，快捷键可以用了，而且对于java也可以支持了。

ubuntu下的卸载：
apt-get remove --purge xxx # 移除应用及配置
apt-get autoremove # 移除没用的包