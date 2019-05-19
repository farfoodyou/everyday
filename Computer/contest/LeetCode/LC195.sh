# head -n 10 file.txt | tail -n 1   # 不足10行会输出最后一行
awk 'NR==10' file.txt