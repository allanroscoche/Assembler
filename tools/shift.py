#!/usr/bin/env python

import sys

if len(sys.argv) > 3:
    f=open(sys.argv[1],'r')
    seq = ""
    for line in f:
        if line[0] != '>':
            seq += line
    size = len(seq)
    chop = int(sys.argv[2])
    shift = int(sys.argv[3])
    for i in range(0,(size-chop)/shift):
        des = i*shift
        print seq[des:(des+chop)]

