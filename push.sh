#!/bin/bash

git add ./
date_str=`date`
git commit -m "$date_str"
git push