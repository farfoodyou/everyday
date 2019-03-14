#!/bin/bash

g++ $1.cpp -std=gnu++11 && cat $1.in | ./a.out >> out.txt 
echo "\n==============\n" >> out.txt
date >> out.txt
