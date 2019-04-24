#!/bin/bash

cat data| cut -f 2 -d ' ' | sort -nr  | head -n 1 | tail -n 1 > 90.out

cat fork.log.2019041711 | grep _print_notice_log | perl -ne 'if(/bsp_game, T_Node_recall_bs, \d+, (\d+), \d+/){print $1,"\n"}' | sort -n -r > /tmp/xx ; total=$(wc -l /tmp/xx|awk '{print int($1)}'); num=`echo "${total}/10" | bc`; head -n $num /tmp/xx | tail -n 1
