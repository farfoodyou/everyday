import threading
from time import ctime,sleep

def shadow(num):
    print('产生了第{}个分身...'.format(num))
    sleep(7-num)
    print('第{}个分身...消失了'.format(num))

def music(func):
    for i in range(2):
        print("I was listening to {}. {}".format(func,ctime()))
        sleep(1)

def move(func):
    for i in range(2):
        print( "I was at the {}! {}".format(func,ctime()))
        sleep(5)



threads = []
t1 = threading.Thread(target=music,args=(u'爱情买卖',))
threads.append(t1)
t2 = threading.Thread(target=move,args=(u'阿凡达',))
threads.append(t2)
print(threading.currentThread().getName())

if __name__ == '__main__':
    for i in range(1, 6):
        t = threading.Thread(target=shadow, args=(i,))
        t.start()
        #t.join()
    for t in threads:
        #t.setDaemon(True)
        t.start()
        #t.join()
    print("over")
    #sleep(3)