
对于行的逻辑运算
感觉有这几组就够用了.
awk '/bc/&&/a/' data
awk '/bc/||/a/' data
awk '/bc|a/' data
awk '!/bc&a/' data

正则表达式,这个有捕获组了就挺好使了.
echo -e "xxx=a yyy=234b zzz=c\n yyy=32" | awk '{match($0,"yyy=([0-9]+)",a); print a[1] }'
其他:
echo "456methodqwe789lmn"| grep -Po '(?<=method)\D+(?=\d)'
cat 50850210.log | awk -F 'method=' '{print $2}' | awk -F '&' '{print $1}'
perl的正则捕获组
cat fork.log.2019041711 | grep _print_notice_log | perl -ne 'if(/ums_cost:(\d+)/){print $1,"\n"}' | sort -n -r > /tmp/xx ; total=$(wc -l /tmp/xx|awk '{print int($1)}'); num=`echo "${total}/10" | bc`; head -n $num /tmp/xx | tail -n 1

