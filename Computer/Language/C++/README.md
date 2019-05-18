### 单一入口单一出口
因为函数里有多个出口. 

这样子可以避免多出口导致,资源没有释放的问题.
第一种办法 goto, 但是这个关键字容易被滥用.
第二种办法 如果函数体里有循环就没法直接跳到出口.
do {
    if (xxx) {
        break;
    }
}while(0)

可以用宏:
```
#define FUNCTION_BEGIN do {
#define FUNCTION_END }while(0)
#define GOTO_END break;
```

一入多出的话, 可以再外面再加一层来控制资源,例如:锁的释放等
