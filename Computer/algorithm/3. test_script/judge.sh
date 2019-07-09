#!/bin/bash

# Flag is ok
isOk=0

c++ -std=c++11 -g $1

inputFiles=`ls *.in`
# 对比所有 *.in
for inputFile in $inputFiles;do
    ./a.out < $inputFile > ${inputFile}_tmp
    diff ${inputFile}_tmp ${inputFile}_out > /dev/null
    if [ $? == 0 ]; then
        echo -e "\033[32mOK\033[0m"
    else 
        echo -e "\033[31mFAILED\033[0m" ${inputFile}
    fi
    rm ${inputFile}_tmp
done
