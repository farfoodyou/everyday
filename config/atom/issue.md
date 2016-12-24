# atom issue

### Description
![issue](/images/issue/editor_crashed.png)

没错莫名其妙就错误了，然后我还关不掉。
我在终端里，top查看了一下pid然后kill掉。
可能是kill的时候什么东西没保存。。。不过没kill之前就已经关不掉了，我也没有办法啊。

### 解决方案
我最后把文件夹复制了一份，然后再打开就好了。

### <font color = red >注意事项</font>
如果编辑器发生了什么错误
在千万不要在编辑器显示空白的时候点击保存
我刚刚看了一下myplus.md变得空白了。

可能atom在关闭的时候会保存和工作文件夹相关的内容。
这些内容是和工作文件夹的**路径**有关的。

最后我用git reset --hard Hash
回到了昨天晚上的状态。<br/>
这种失而复得的感觉比永远失去那些文档好多了。




