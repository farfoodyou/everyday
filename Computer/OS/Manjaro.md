
# After installed

sudo pacman-mirrors -i -c China -m rank

# Soft 
> 这些都是常用的软件
Zsh (简体中文) - ArchWiki
Oh My Zsh
annie
cgdb
gdb
ddd   // 太强了, 居然这个软件都能装成功
annie
BaiduPCS-Go
virtualbox
giteye
smartgit
proxychains
eclipse-cpp
### eclipse-cpp
:: There are 6 providers available for eclipse:
:: Repository community
    1) eclipse-cpp 2) eclipse-java 3) eclipse-javascript 4) eclipse-jee 5) eclipse-php 6) eclipse-rust 

### proxy
export http_proxy=socks5h://localhost:1080
export https_proxy=socks5h://localhost:1080


### 命令
screenfetch
不仅可以展示logo，还能显示一些基本的硬件信息
KSysGuard
任务管理器
### ddd 字体问题
手动装下helvetica字体就能解决
tiny_rm(box) = font(box, "-*-helvetica-medium-r-*-*-*-80-*-*-*-*-iso8859-*");
rm(box) = font(box, "-*-lucidatypewriter-medium-r-*-*-*-120-*-*-*-*-iso8859-*");

xorg-fonts-100dpi

###　yay -S virtualbox
yay -S virtualbox
好像只要77mb就够了,这就是有依赖的好处吧

### shadowsocks-qt5

system setting need this pac

```
$ sudo pip install genpac
$ pip install --upgrade genpac
```
genpac -p "SOCKS5 127.0.0.1:1080" --output="autoproxy.pac"



### giteye
感觉感应速度有些有些慢, 还得手动刷新的话
那我还不如直接用VScode来得痛快
花了半个晚上下载的git可视化工具却不好使
这就有点蛋疼了

好像是得点击窗口的刷新才行
这...对比起来除了git flow还新鲜也没别的优势了
add 还不大好用, 有时可以, 有时又不行....
不会只有一个文件的时候不好用吧
测一测, 好像有时候可以有时候不行....
只有菜单栏的是可以用的, 右键不行
侧边栏好像也可以就是Git Files窗口右键不行
那也废了,这软件基本上 
staged 里面没有的文件才能add, 
有一点小改动就不让,在窗口里add了, 
感觉是个坑

这个flow 好像feature完成之后直接合入dev分支了
连merge信息都没有

有个squash选项好像能合并所有的commit成一个?
如果不选保留分之会被删除么? 

