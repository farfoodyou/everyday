#!/bin/bash
# This script is tool can add project, commit stage, push project.
# start of script

git status
git add ./
date_str=`date`
if [ $# == 1 ];then
    git commit -m "$1 at $date_str"
else
    git commit -m "Default commit infomation at $date_str"
fi

git push

# end of script