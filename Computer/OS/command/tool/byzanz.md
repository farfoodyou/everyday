#  byzanz主要的参数选项有
```
  -d, --duration=SECS    动画的时间 (默认：10 秒)
  -e, --exec=COMMAND      Command to execute and time
  --delay=SECS            开始之前的延时(默认：1 秒)
  -c, --cursor            录制鼠标光标
  -a, --audio            录音
  -x, --x=像素            要录制矩形的 X 坐标
  -y, --y=像素            要录制矩形的 Y 坐标
  -w, --width=像素        录制矩形的宽度
  -h, --height=像素      录制矩形的高度
  -v, --verbose          详细
  --display=显示          要使用的 X 显示
```

- sudo apt-get install byzanz   
- xwininfo查询要录制的窗口位置、宽度和高度
- byzanz-record -x 506 -y 132 -w 1019 -h 616  -d 10 --delay=3 -c test.gif   




