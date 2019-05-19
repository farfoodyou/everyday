# gdb

## gdb 8.2 can't recognized executable file on macOS Mojave 10.14

https://stackoverflow.com/questions/52529838/gdb-8-2-cant-recognized-executable-file-on-macos-mojave-10-14

BFD: /Users/username/Codes/demo: unknown load command 0x32
"/Users/username/Codes/./demo": not in executable format: File format not recognized

从 10.13 升级到 10.14 之后要把 brew 也升级下

## gdbgui
This tool is powerful. And it is so beautiful.

Install:
`pip3 install gdbgui`
gdbgui -p 9091, run with port 9091

show the source old_path
`info source`
change source old_path to real path
`set substitute-path from_path  to_path`
## gdb command
```
list	l	显示多行源代码
break	b	设置断点
break if	b if	当满足某个条件时停止
delete	d	删除断点
disable	 	禁用断点
enable	 	允许断点
info	i	描述程序状态，比如： i break 显示有哪些断点
run	r	开始运行程序
display	disp	跟踪查看某个变量，每次停下来都显示其值
print	p      打印内部变量值
watch	 	监视变量值新旧的变化
step	s	执行下一条语句，如果该语句为函数调用，则进入函数执行第一条语句
next	n	执行下一条语句,如果该语句为函数调用,不会进入函数内部执行(即不会一步步地调试函数内部语句）
continue	c	继续程序的运行，直到遇到下一个断点
finish	 	如果进入了某个函数，返回到调用调用它的函数，jump out
set var name = v 	 	设置变量的值
backtrace	bt	查看函数调用信息（堆栈）
start	st	开始执行程序，在main函数中的第一条语句前停下
frame	f	查看栈帧，比如 frame 1 查看1号栈帧
quit	q	离开gdb
edit	 	在gdb中进行编辑
whatis	 	查看变量的类型
search	 	搜索源文件中的文本
file	 	装入需要调试的程序
kill	k	终止正在调试的程序
```