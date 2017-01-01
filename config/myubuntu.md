# 说一说Ubuntu下必须要装的几个软件

1. Atom         
 >  //谁用谁知道，反正我觉得它是神器一般的存在
2. 有道云音乐
3. chromium浏览器 
> //配置了插件的chromium类浏览器简直就是移动操作系统
4. 有道词典   
> //简直就是积累词汇和看文档的福音啊
5. 搜狗输入法  
> //原始的中文输入法虽然可用但是不好用
5. wine1.8.5和环境中的软件
  1. QQ轻聊版  //和wins下效果基本一毛一样
  2. 迅雷精简版 //下载速度还可以
6. mplayer   //源码安装功能强大，但是配置麻烦
7. Kazam    可视化的视频录制软件
8. WPS //ubuntu自带的文字处理软件简直就是。。。
9. calibre      gitbook


terminal下
1. 用python配置有道翻译API，实现终端翻译
// 我兴奋地快要睡不着了，原来终端还可以这么使用
![youdao](/images/demo/youdao.png)

2. sox   
命令行音乐播放器，如果要编写按照crontab计划播放提示音的话用这个比较合适。  

3. mplayer  
其实这个是命令行式的但是加上皮肤可以可视化。  
4. byzanz截取动态效果图工具
 - sudo apt-get install byzanz   
 - xwininfo查询要录制的窗口位置、宽度和高度
 - byzanz-record -x 506 -y 132 -w 1019 -h 616  -d 10 --delay=3 -c test.gif   
5. xdotool
 - xdotool getmouselocation  //获取鼠标位置


Ubuntu下ｚｉｐ中文乱码用  
unar packname  
就可以了。

卸载软件的命令  
Linux下彻底卸载LibreOffice方法
终端中输入命令：  
对所有基于 Debian 的发行版（Debian、Ubuntu、Kubuntu、Xubuntu、*buntu、Sidux 等）：   
sudo apt-get purge libreoffice?  
或  
sudo aptitude purge libreoffice?  
不要漏掉通配符“?”，否则无法清除/卸载全部 LibreOffice 软件包  
或者  
sudo apt-get remove --purge libreoffice*

