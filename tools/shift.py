#!/usr/bin/env python

import sys
import random

if len(sys.argv) > 3:
    f=open(sys.argv[1],'r')
    seq = ""
    for line in f:
        if line[0] != '>':
            seq += line.rstrip('\n')
    size = len(seq)
    chop = int(sys.argv[2])
    shift = int(sys.argv[3])

    saida = [];
    for i in range(0,(size-chop)/shift):
        des = i*shift
        saida.append( seq[des:(des+chop)])

    if len(sys.argv)==5 :
        if sys.argv[4]=="sample" :
            for linha in saida:
                print random.choice(saida)
        elif sys.argv[4]=="full":
            random.shuffle(saida)
            for linha in saida:
                print linha
    else:
        for linha in saida:
            print linha

else:
    print "Usage: ./shift arquivo deslocamento modo"
