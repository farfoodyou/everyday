<style type = "text/css">
p {
  color:rgb(80, 219, 107);
}
li {
  color:rgb(226, 224, 46)
}
</style>


# OS 复习资料总结

## Introduction

1. conception
2. goals
3. Development process
4. Basic characteristics   


A program(程序) that acts as an intermediary between a user of a computer and the computer hardware.  


Resource allocator(资源分配器) – manages and allocates resources.  
Control program (控制程序) – controls the execution of user programs and operations of I/O devices .  
Kernel (内核) – the one program running at all times (all else being application programs).  

#### Operating system goals:
- 有效性:Execute user programs and make solving user  problems easier (validity), namely, Use the computer hardware in an efficient manner. 
 -  (1) 提高系统资源利用率。  
 -  (2) 提高系统的吞吐量。  
- 方便性:Make the computer system convenient to use (convenience ).  
- 可扩充性: expandability   
- 开放性:openess  

#### Development process

Historical review:
- Batch systems(批处理)
- Multiprogrammed Systems(多道批处理系统)
- Time-Sharing Systems(分时系统)

Simple Batch System
- (1) 自动性
- (2) 顺序性
- (3) 单道性  

Multiprogrammed Systems  
- (1) 提高CPU的利用率。  
- (2) 可提高内存和I/O设备利用率。  
- (3) 增加系统吞吐量。  

多道批处理系统的优缺点
- (1) 资源利用率高。
- (2) 系统吞吐量大。
- (3) 平均周转时间长。
- (4) 无交互能力。

Time-Sharing Systems–Interactive Computing 

Time-sharing system (分时系统)allows many users to share the computer simultaneously (同时). As the system switches rapidly from one user to the next, each user feels that entire computer system is dedicated(满足)to her use.
- Time slice (时间片) for each jobs  
- Effective (高效)   
- Rapid response time (响应时间)   

分时系统关键问题  
 (1) 及时接收。
 (2) 及时处理。  
分时系统的特征  
(1) 多路性。
(2) 独立性。
(3) 及时性。
(4) 交互性。 

Distributed Systems（分布式系统）  
Real-Time Systems（实时系统）  
Handheld Systems（手持系统）  
#### Basic characteristics of the operating system（基本特性）   
1、 并发性（Concurrency ）  
- 并行（parallel）与并发
- 进程（process）
- 线程（thread）    

2、 共享性（Sharing ）  
- 互斥共享方式（Mutex ）
- 同时访问方式

3、虚拟技术  
- 时分复用技术（Time division multiplexing technology ）  
　　时分复用，亦即分时使用方式，将一条物理信道虚拟为多条逻辑信道，将每条信道供一对用户通话。  
- 空分复用技术（ Space division multiplexing technology ）
 - virtual disk
 - virtual memory
 
4、异步性（ Asynchronism ）
1. 基本输入输出系统:BIOS  
2. 提供最基本的I/O和硬盘访问功能；  
3. 执行POST（上电后系统自检）；  
4. 从CMOS中读取系统配置参数；  
5. 各I/O设备初始化；  
6. 实现操作系统的载入。  
7. BIOS写在一块只读半导体芯片（ROM）中，通电后CPU自动执行其中的程序。
8. CMOS：通过主板锂电池可长期保留数据的一块可读写内存芯片。  
 
 
 
 
