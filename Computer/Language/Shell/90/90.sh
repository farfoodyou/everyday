#!/bin/bash

cat data| cut -f 2 -d ' ' | sort -nr  | head -n 1 | tail -n 1 > 90.out

cat fork.log.2019041711 | grep _print_notice_log | perl -ne 'if(/bsp_game, T_Node_recall_bs, \d+, (\d+), \d+/){print $1,"\n"}' | sort -n -r > /tmp/xx ; total=$(wc -l /tmp/xx|awk '{print int($1)}'); num=`echo "${total}/10" | bc`; head -n $num /tmp/xx | tail -n 1

for i in `seq -w 0 23`; do  grep -e 'storage redis use'  fork.log.20190427$i >> /tmp/cost ; done
for i in `seq -w 0 23`; do  grep -e 'call relation service failed, ErrorCode='  fork.log.wf.20190427$i >> /tmp/wf_re ; done

perl -ne 'if(/bsp_game, T_TOTAL, \d+, (\d+), \d+/){print "$1\n"}'  fork.log.2019042720 > /tmp/total;
cd /tmp;
rawfile='ps_cost';file='tmp';
sort -n -r $rawfile > $file;
total=$(wc -l /tmp/$file |awk '{print int($1)}'); 
num99=`echo "${total}/100" | bc`;
num90=`echo "${total}/10" | bc`;
num80=`echo "${total}/5" | bc`;
sed -n "$num99"p $file;
sed -n "$num90"p $file;
sed -n "$num80"p $file;
awk '{sum+=$1} END {print sum/NR}' $file;

perl -ne 'if(/bs_cost:(\d+).*game/){print "$1\n"}' cost > bs_mp_raw
perl -ne 'if(/ums_cost:(\d+).*game/){print "$1\n"}' cost > fs_mp_raw
perl -ne 'if(/ps_cost:(\d+).*game/){print "$1\n"}' cost > ps_mp_raw
perl -ne 'if(/ucf_cost:(\d+).*game/){print "$1\n"}' cost > ucf_mp_raw
perl -ne 'if(/prelation_cost:(\d+).*bsp_personal/){print "$1\n"}' cost > re_mp_raw

perl -ne 'if(/get_ps_score, \d+, (\d+), \d+.*game/){print "$1\n"}' total > ps_

sort -n -r fs_mp_raw > fs_mp

grep '_print_notice_log' 



perl -ne 'if(/bsp_game, T_TOTAL, \d+, (\d+), \d+/){print "$1\n"}'  > total_game


for i in `seq -w 0 23`; do  grep -e 'call relation service failed, ErrorCode='  fork.log.wf.20190427$i >> /tmp/wf_re ; done
for i in `seq -w 0 23`; do  grep -e 'prelation_cost'  fork.log.20190427$i >> /tmp/relation ; done

```
percent99=0.99
percent999=0.999
aa=`awk -v x=$line -v y="$percent99" 'BEGIN{printf "%.2d\n",x*y}'`
bb=`awk -v x=$line -v y="$percent999" 'BEGIN{printf "%.2d\n",x*y}'`
echo "99%: " `sed -n "$aa"p sort_timeCostDetails.log` "ms"
echo "99.9%: " `sed -n "$bb"p sort_timeCostDetails.log` "ms"
```
storage redis use " << COST_TOTAL_storage_game_cache << "ms

perl -ne 'if(/storage redis use (\d+).*ms/){print "$1\n"}'  fork.log.2019042711 >/tmp/redis | wc -l




#reids
grep 'redis:' fork.log.wf.20190427* > /tmp/redis_emp

#关注中心:
perl -ne 'if(/prelation_cost:(\d+)/){print "$1\n"}' cost > re_mp_raw
grep 'call relation service failed, ErrorCode=' 

# ps error
for i in {7..8};do  grep 'T_TOTAL' fork.log.2019042"$i"21 | wc -l; done
for i in {7..8};do  grep 'call ps failed' fork.log.wf.2019042"$i"20 | wc -l; done
