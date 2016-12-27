# Process Management

1. concept
2. Process control(进程控制)
3. Semaphores(信号量)
4. Classical Problems of Synchronization(经典同步问题)

前趋图(Precedence Graph)是一个有向无循环图，记为DAG(Directed Acyclic Graph)

程序顺序执行时的特征
(1) 顺序性
(2) 封闭性
(3) 可再现性

程序并发执行时的特征
1) 间断性
2) 失去封闭性
3) 不可再现性

Process Control Block (PCB)  

Process State：  
As a process executes, it changes state
new:  The process is being created.
running:  Instructions are being executed.
Waiting(阻塞):  The process is waiting for some event to occur.
Ready(就绪):  The process is waiting to be assigned to a process.
terminated:  The process has finished execution.


Process Scheduling Queue

Job queue (工作队列)– set of all processes in the system.  
Ready queue (准备队列)– set of all processes residing in main memory, ready and waiting to execute.  
Device queues (设备队列)– set of processes waiting for an I/O device.  
Process migration between the various queues.

三、Process Synchronization(进程同步)  
1. 临界资源(Critical Resouce)
诸进程间应采取互斥方式，实现对这种资源的共享,如打印机、磁带机。  
2．临界区(Critical section or Race condition)
在每个进程中访问临界资源的那段代码称为临界区。

Bounded-Buffer （有限缓冲区）  
concurrent



Classical Problems of Synchronization(经典同步问题)
Bounded-Buffer Problem(有限缓冲区)
Producer-consumer Problem(生成者和消费者)
Readers and Writers Problem(读者和写者)
Dining-Philosophers Problem(哲学家进餐)

