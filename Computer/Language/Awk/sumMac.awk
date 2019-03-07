#!/usr/bin/env awk  -f
#运行前
BEGIN {
    FS="(title:|startTime:|endTime:)"
    sum = 0
    num = 0
    printf "  NO.   TIME        TITLE \n"
    printf "---------------------------------------------\n"
}
#运行中
/^####/{
    "date -j -f '%Y-%m-%d %H:%M:%S' "$4" '+%s'"|getline endTime;
    "date -j -f '%Y-%m-%d %H:%M:%S' "$3" '+%s'"|getline startTime;
    delta = (endTime-startTime)/60 + 1
    sum += delta
    num += 1
    printf "%4d %4d 分钟 %s\n", num, delta, $2
}
#运行后
END {
    printf "---------------------------------------------\n"
    printf "  TOTAL:%10d 分钟\n", sum
    printf "AVERAGE:%10.2f 分钟\n", sum/num
}