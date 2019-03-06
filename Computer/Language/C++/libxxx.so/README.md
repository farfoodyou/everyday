# 动态链接库练习

源文件(.h .cpp) -> 预编译 -> 编译 -> 汇编 -> 链接 -> 可执行文件

创建动态库
`g++ -fPIC -shared -o libecho.so Echo.cpp`
链接动态库
`g++ -o main main.cpp -L./    -lecho`
