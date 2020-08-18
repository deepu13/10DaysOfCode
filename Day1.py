

import math
import os
import random
import re
import sys

def solve(a,d):
    i=d%len(a)
    return (a[i:]+a[:i])

if __name__ == '__main__':
    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))

    z = solve(a,d)


    for y in z:
        print(y, end = " ")

