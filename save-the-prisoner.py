#!/bin/python3

import math
import os
import random
import re
import sys

#
#  -------                                  https://www.hackerrank.com/challenges/save-the-prisoner/problem  ----------
# Complete the 'saveThePrisoner' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#  3. INTEGER s
#

def saveThePrisoner(n, m, s):
    """
    Brut force algo
    one_round = True
    counter = 0
    if n==s:
        return n
    for i in range(m):
        for j in range(1,n+1):
            if j < s and i==0:
                continue
            else:
                counter+=1
            if counter == m:
                return j
            
            
    """
    
    return  n if (m+s-1)%n==0 else (m+s-1)%n
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        s = int(first_multiple_input[2])

        result = saveThePrisoner(n, m, s)

        fptr.write(str(result) + '\n')

    fptr.close()
