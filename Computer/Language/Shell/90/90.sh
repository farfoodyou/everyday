#!/bin/bash

cat data| cut -f 2 -d ' ' | sort -nr  | head -n 1 | tail -n 1 > 90.out
