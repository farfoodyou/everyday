
# 统计90分位点
cat data | awk -F ' ' '{print $1}' | sort -n | awk 'NR==3{print $0}'

# 用正则表达式作为分隔符
awk -F '(time:|end:)' '{print $3-$2}' testdata 