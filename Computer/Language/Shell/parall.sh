#!/bin/bash

mysleep(){
    local timeNum=$1
    echo "fun is begin.timeNum:$timeNum"
    sleep $timeNum &
    wait #这个只等待wait前面sleep
    echo "fun is end.timeNum:$timeNum"
}

mysleep 2 &
mysleep 3 &
mysleep 4 &

wait

echo "all is ending"
