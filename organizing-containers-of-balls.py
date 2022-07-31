#!/bin/python3
"https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem"
import math
import os
import random
import re
import sys

#
# Complete the 'organizingContainers' function below.
#
# The function is expected to return a STRING.
# The function accepts 2D_INTEGER_ARRAY container as parameter.
#

def organizingContainers(arr):
    cons = []
    types = []
    for i in range(len(arr)):
        cons.append(sum(arr[i]))  # con 1
        
    
    for i in range(len(arr)):
        sum_col = 0
        for j in range(len(arr[i])):
            sum_col+=arr[j][i]
        types.append(sum_col)

    cons.sort()
    types.sort()
    for k in range(len(arr)):
        if cons[k]!=types[k]:
            return "Impossible"
        
    return "Possible"
            
            
            
    

if __name__ == '__main__':
    print("enter the input : \n")
    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        print(result)

   
"""
1
9
993263231 806455183 972467746 761846174 226680660 667393859 815298761 790313908 997845516
873142072 579210472 996344520 999601755 904458846 663577990 980240637 713052540 963408591
551159221 873763794 752756532 798803609 670921889 995259612 981339960 763904498 499472207
975980611 999974039 729219884 834636710 973988213 969888254 846967495 687204298 511348404
993232608 998103218 857820670 995587240 817798750 773950980 824882180 797565274 887424441
847857578 768853671 916073200 982234748 986511977 733420232 997714976 819799716 891570083
733197334 985682497 612123868 971798655 999905357 710092446 997494889 683312998 850074746
799093993 543648222 944524289 814951921 981087922 997222915 506561779 997697933 652807674
989362549 973516812 891706714 786904549 982329176 376575034 993535504 984745483 777613376
"""
