#!/bin/bash
# This script is tool can add project, commit stage, push project.
# start of script

git add ./
date_str=`date`
if [ $# == 1 ];then
    git commit -m "$1"
else
    git commit -m "default commit infomation at $date_str"
fi

git push

# end of script