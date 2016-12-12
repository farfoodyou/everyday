#关于mplayer command的介绍
在终端输入mplayer dvd.mp4就可以使用mplayer播放了。

MPlayer 1.3.0 (C) 2000-2016 MPlayer Team
用法：            mplayer [选项] [URL|路径/]文件名

基本选项：        （完整列表参见手册页）
 -vo <drv>        选择视频输出驱动程序（查看驱动程序列表用“-vo help”）
 -ao <drv>        选择音频输出驱动程序（查看驱动程序列表用“-ao help”）
 vcd://<曲目号>   播放 (S)VCD（超级VCD）曲目（无格式设备，无需装载）
 -alang/-slang    选择 DVD 音频/字幕的语言（使用两字符的国家代号）
 -ss <位置>       定位至给定的（秒数或时:分:秒 - hh:mm:ss）位置
 -nosound         不播放声音
 -fs              全屏播放（或用 -vm、-zoom，详见手册相关页面）
 -x <x> -y <y>    设置显示的分辨率（用以与 -vm 或 -zoom 一起使用）
 -sub <文件>      指定所使用的字幕文件（另见 -subfps、-subdelay）
 -playlist <文件> 指定播放列表文件
 -vid x -aid y    选择播放视频流（x）和音频流（y）
 -fps x -srate y  改变视频帧率为 x（fps），音频采样率为 y（Hz）
 -pp <质量>       启用后期处理过滤器（详见于手册相关页面）
 -framedrop       启用丢帧（用于运行慢的机器）

基本控制键：      （完整列表见手册相关页面，也请查阅 input.conf）
 <-  或  ->       后退/快进 10 秒
 上 或 下         后退/快进 1 分钟
 pgdown 或 pgup   后退/快进 10 分钟
 < 或 >           跳到播放列表中的前一个/后一个
 p 或 空格键      暂停影片（按任意键继续）
 q 或 ESC         停止播放并退出程序
 + 或 -           音频延迟 +/- 0.1 秒
 o                循环切换 OSD 模式：无/定位条/定位条加计时器
 * 或 /           增加或减少 PCM 音量
 x 或 z           字幕延迟 +/- 0.1 秒
 r 或 t           字幕位置上移/下移，另见“-vf expand”

