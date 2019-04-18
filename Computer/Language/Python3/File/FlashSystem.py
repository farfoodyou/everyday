#!/usr/bin/env python
# -*- coding:utf8 -*-

import os, random, shutil

import sys, getopt

res_path='codes/test/flash_res'

def main(argv):
    inputfile = ''
    outputfile = ''
    try:
        opts, args = getopt.getopt(argv,"ha:i:o:",["ifile=","ofile=","add="])
    except getopt.GetoptError:
        print 'python FlashSystem.py -h show the usage.'
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print 'test.py -i <inputfile> -o <outputfile>'
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg
        elif opt in ("-a", "--add"):
            targetFile = os.path.expanduser('~')+'/'+res_path +'/'+arg
            shutil.copyfile(arg, targetFile)
            print '已添加：', targetFile

if __name__ == "__main__":
   main(sys.argv[1:])