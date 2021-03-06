#!/usr/local/bin/python3
'''
这是python快速手册
Created at 2018/08/14
'''

# 1. 数字、字符串
number1 = 3
number2 = 3.0
number3 = 2 + 3j
string1 = 'this is string1.'
string2 = "this is string2."
print(number3)
print(string2)

# 2. 列表、元组、集合、字典
list1 = ['Google', 'Runoob', 1997, 2000]
list2 = [1, 2, 3, 4, 5 ]
list3 = ["a", "b", "c", "d"]
print ("list1[0]: ", list1[0])
print ("list2[1:5]: ", list2[1:5])
print ("原始列表 : ", list2)
del list2[2]
print ("删除第三个元素 : ", list2)
    
tup1 = ('Google', 'Runoob', 1997, 2000)
tup2 = "a", "b", "c", "d"
print ("tup1[0]: ", tup1[0])
print ("tup2[1:5]: ", tup2[1:5])
#元组不允许修改
tup3 = tup1 + tup2
print (tup3)

dict = {'Name': 'Runoob', 'Age': 7, 'Class': 'First'}
print ("dict['Name']: ", dict['Name'])
dict['Age'] = 32
print ("dict['Age']: ", dict['Age'])

    #可以使用大括号 { } 或者 set() 函数创建集合
st = set()
a = set('abracadabra')
b = set('alacazam')
a.update(dict)
b.update(list1)
print(a)                              
print(a - b)        # 集合a中包含元素
print(a | b)        # 集合a或b中包含的所有元素
print(a & b)        # 集合a和b中都包含了的元素
print(a ^ b)        # 不同时包含于a和b的元素
print('a' in b) 
print('a' not in b) 

# 3. 分支
boolean = True
isin = 2000 in list1 
# in 是区别类型的 
# '2000' in list1 = False 
#  2000 in list1 = True
if (boolean):
    pass
else:
    pass

# 4. 循环
for value in list1:
    print(value)
for k,v in enumerate(list1):
    print(k,v)
# 5. 函数
def functionname( parameters ):
    "函数_文档字符串"
    print("xx")
    return 1
# 6. 对象

# 7. exec
## time
import time
t = time.time()
dt = time.strftime("%Y%m%d%H%M%S", time.localtime(t))

import datetime
(datetime.datetime.now() + datetime.timedelta(days=1)).strftime("%Y/%m/%d %H:%M:%S")

## exec
import os
os.system('ls -l')

result = os.popen('ps aux')
res = result.read()
for line in res.splitlines():
    print line

## Json
import json
o = {}
o['name'] = 'testObject'
o['key'] = 'value'
o['list'] = [2,3,4,5]
JsonStr = json.dumps(o)
print(JsonStr)
oB = json.loads(JsonStr)
print(oB)

## requests
import requests
r = requests.put('http://httpbin.org/put', data = {'key':'value'})
r = requests.delete('http://httpbin.org/delete')
r = requests.head('http://httpbin.org/get')
r = requests.options('http://httpbin.org/get')

