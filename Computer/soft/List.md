

Shell: bash。它结合了 csh 和 ksh 的优点，并且有 readline 功能，你可以随意绑定自己的键盘。

编辑器： VIM, Emacs。

程序开发： GCC, make, ld, Scheme48, j2sdk, Perl, Python, Tcl/Tk ...

论文，幻灯工具：LaTeX, ConTeXt

绘图工具：MetaPost。这个语言太强了，以至于我只用它了。你不熟悉的话可以用 xfig, dia 来画一些流程图之类的图片。

图像处理：ImageMagick。其中的 import 程序可以屏幕抓图，convert 程序可以转换图像格式，display 可以显示图片和简单编辑(缩放，换质量，转格式，简单绘图，简单虑镜)。通常我就这么点需要。如果你要更强大的图像工具可以用 Gimp, 它几乎和 Photoshop 差不多。

自动管理工具：make。我可以用make来自动编译程序，自动编译文档，自动更新插图…… 全自动，而且不会重复劳动。

数值计算程序：SciLab。这个程序基本上可以代替 Matlab。

代数计算程序：MAXIMA。这个程序基于世界上最老的计算机代数系统之一: 由美国能源部(DOE)发行的 MIT Macsyma 系统。它是用 Common Lisp 实现的。很多现在的符号计算程序比如 Maple 都从 MAXIMA 身上学到很多东西。它现在经过 DOE 批准以 GPL发行，永远是一个自由软件。

加密程序：GnuPG。我的 PGP 密钥就是它搞出来的。

打包，压缩程序。什么都有: tar, gzip, bzip2, zip, rar, ...

虚拟光驱程序。Linux 不需要虚拟光驱程序，直接 mount 就行了。

ftp 服务器：proftpd, vsftpd。proftpd 功能很强，但是我只用了最简单的一种设置。

WWW 服务器：apache。(我一般没有开)

ftp 客户程序：lftp，ncftp。它们都是文本方式操作的，但是比起图形界面的方便的多。比如 lftp 几乎具有 bash 的所有方便功能，Tab 补全，bookmark, queue, 后台下载，镜像…… Linux 也有图形界面的 ftp 客户程序，但是大多不稳定，有很多问题。这就是很多人抱怨 Linux 不如 Windows 的一个小原因。还有很多人用 Wine 模拟 Windows 的 leapftp，其实 lftp 比 leapftp 好很多，你需要的只是适应一下。

自动下载工具：wget。它非常稳定，有一次我下载一个程序，用 IE 和 Mozilla 下载回来的文件都是坏的，最后还是 wget 可靠的传输了数据。用它甚至可以镜像整个网站，比起 WebZip 这样的 Windows 程序强多了，而且不会因为你不付钱就在下载回来的网页里强制插入广告。

虚拟终端：rxvt, xterm, gnome-terminal, mlterm, ...

X server: XFree86 [14]

窗口管理器：FVWM。编译加入了 libstroke。

中文输入：XSIM。被我修改过以适应 FVWM 的需要。另外推荐你还可以用 SCIM。

email 处理：Mutt + Postfix + fetchmail

看 PDF, PS, DJVU 文件：Acrobat Reader, xpdf, GhostScript, gv, djvu工具包和 netscape 插件。

看CAJ文档。我从来不看CAJ之类的文档，如果找不到PDF或PS，直接去图书馆借最好。

看网页：Mozilla, Phoenix, lynx。Mozilla-Xft 的显示效果比 IE 好很多。

英汉字典：IBM智能词典，星际译王。

编辑网页：我用 VIM 直接写 HTML。你如果想要图形方式的可以用其它的比如 screem, BlueFish。

登录其它 UNIX, Linux 机器：openSSH, telnet。 我喜欢用 openSSH 把其它机器的 X 程序通过 ssh 加密的隧道传到我机器上显示。

登录 Windows2000 server 的 display service: rdesktop，...我有一天试了一下，不错。后来就没有用过了。

同步程序：rsync。我用 rsync 通过 ssh 来跟某些机器同步数据，或者做自己机器上不同目录间的同步。

上BBS：rxvt(或任何一种终端) + telnet + chatbot(helloooo 机器人的程序)

QQ, ICQ: 我没有 QQ[15] 或 ICQ。不过你可以用 Gaim, 它同时支持 QQ, ICQ 和很多其它的即时通信方式。ICQ 用户也可以用 Licq。

放录像：MPlayer, RealPlayer。MPlayer 太好了，直接就可以放 VCD, DVD, divx, wma, wmv ... 用 Windows 的同学都很羡慕我，说 Windows 要放这个需要大堆插件。 rm 最好还是用 realplayer 放，它也是免费的。

放音乐： xmms(mp3,ogg都可以), mpg321(放mp3), ogg123(放ogg)。mpg321 不如 xmms 管理音乐文件那么方便，但是有时我还是用 mpg321 放 mp3 作为背景音乐，因为懒得开一个xmms窗口 :)