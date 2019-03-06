#!/bin/bash
tmp_file="tmp"
log_file="data"
while true
do
   tail -500000 $log_file|grep"keyword">$tmp_file
   total_count=`cat $tmp_file|wc -l`
   tp99=$[$total_count/100]
   tp999=$[$total_count/1000]
   tp9999=$[$total_count/10000]
   echo "total_count:"$total_count
    cat$tmp_file|awk-F "invoke_time:"'{print $2}'|sort-n -r|awk-v tp99="$tp99"-v tp999="$tp999"-v tp9999="$tp9999"'BEGIN{count=0;}{ if(count==tp99){print "tp99:"$0;} else if(count==tp999){print "tp999:"$0;} else if(count==tp9999){print "tp9999:"$0;};count=count+1;}'

 sleep 1
 echo ..........
done
