
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

