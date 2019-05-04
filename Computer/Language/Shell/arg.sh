#!/bin/bash
while [ "$1" != "" ]; do
    case $1 in
        -s  )   shift  
        SERVER=$1 ;;  
        -d  )   shift
        DATE=$1 ;;
    --paramter|p ) shift
        PARAMETER=$1;;
        -h|help  )   usage # function call
                exit ;;
        * )     usage # All other parameters
                exit 1
    esac
    shift
done

echo $SERVER,$DATE