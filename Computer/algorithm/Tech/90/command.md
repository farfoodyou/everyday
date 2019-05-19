一条命令算90分位点.
cat fork.log.2019041711 | grep _print_notice_log | perl -ne 'if(/ums_cost:(\d+)/){print $1,"\n"}' | sort -n -r > /tmp/xx ; total=$(wc -l /tmp/xx|awk '{print int($1)}'); num=`echo "${total}/10" | bc`; head -n $num /tmp/xx | tail -n 1
