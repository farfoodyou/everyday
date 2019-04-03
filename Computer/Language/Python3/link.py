#!/usr/bin/env python
#coding=utf-8

from FT import From

print(From((1,2,3,4))
    .filter(lambda it:it % 2==0)
    .map(lambda it:it*2).toList())
'''
结果:
[4,8]
'''

print(From((1,2,3,4))
    .filter(lambda it:it % 2==0)
    .map(lambda it:it*2).reduce(lambda acc,it:acc+it))
#加幺元
print(From((1,2,3,4))
    .filter(lambda it:it % 2==0)
    .map(lambda it:it*2).reduce(lambda acc,it:acc+it, 1))
'''
结果:
12
12
'''

testgroupdata=[{"id":1,"name":"wwb"},{"id":1,"name":"wxa"},{"id":1,"name":"wxb"},{"id":2,"name":"wxc"},{"id":2,"name":"wxd"}]

print(From(testgroupdata).groupby(lambda it:it['id']).toList())

