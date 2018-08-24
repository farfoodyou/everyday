# coding:utf-8
import sys
import json
import re
import time
import traceback

t = time.time()
dt = time.strftime("%m%d%H%M", time.localtime(t))
path = r"./"+sys.argv[1]
respath = r"./"+sys.argv[1]+'.'+dt
errpath = r"./"+sys.argv[1]+'.'+dt+".wf"
#传入要读的文件路径

file = open(path,"r",encoding="utf-8",errors="ignore")
resFile = open(respath,"w+",encoding="utf-8",errors="ignore")

i=0
while True:
    mystr = file.readline()#表示一次读取一行
    i+=1
    if not mystr:
    #读到数据最后跳出，结束循环。数据的最后也就是读不到数据了，mystr为空的时候
        break
    if i - 1 > 80000:
        break
    js = ''
    o = ''
    id = ''
    cuido=''
    try:
        p2 = re.compile(r'"user_id":(.*?)}',re.S)
        l2 = re.findall(p2, mystr)
        if len(l2):
            id_s = l2[0]+'}'
        else:
            resFile.write("%s %s\n" % (0 ,0))
            continue

        cuido = json.loads(id_s)
        p1 = re.compile(r'\\\"attention_short\\\":(.*?)}',re.S)
        l1 = re.findall(p1, mystr)
        if len(l1):
            js = l1[0]+'}'
        else:
            id = cuido['cuid']
            resFile.write("%s %s\n" % (id,0))
            continue
        js = js.replace('\\','')
        o = json.loads(js)
    except IndexError:
        print(l1 , i)
        wf = open(errpath,"w+",encoding="utf-8",errors="ignore")
        traceback.print_exc()
        wf.write(mystr)
        wf.close
        exit(-1)
    except json.decoder.JSONDecodeError:
        print("o str JSONDecodeError ",i)
        traceback.print_exc()
        wf = open(errpath,"w+",encoding="utf-8",errors="ignore")
        wf.write(js)
        wf.close
        #exit(-1)
    except KeyError:
        print("o KeyError ",i)
  
    try:
        id = cuido['cuid']
        num = len(o['attentions'])
        resFile.write("%s %s\n" % (id,num))
    except KeyError:
        print("v KeyError")
        resFile.write("\n")
    except TypeError:
        print("v TypeError")
        traceback.print_exc()
        resFile.write("\n")
    except json.decoder.JSONDecodeError:
        print("v JSONDecodeError")
        resFile.write("\n")
    #else:
        #print("finish" ,i)

print("Finish")
file.close()
resFile.close()
