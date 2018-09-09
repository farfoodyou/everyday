#!/bin/bash
os=$(uname -s)
days=(15 7 4 2 1)
res=()
for i in {0..4}
do
    
    if [[ "$os" == "Linux" ]]; then
        res[$i]=`date -d "${days[$i]} days ago"  "+%Y-%m-%d"`
    elif [[ "$os" == "Darwin" ]]; then
        res[$i]=`date -v -${days[$i]}d +%Y-%m-%d`
    else
        echo "unknown OS"
        exit 1
    fi
done
for data in ${res[@]}  
do  
    echo ${data}  
done  
