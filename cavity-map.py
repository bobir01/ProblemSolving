#!/bin/python3

import math
import os
import random
import re
import sys
import copy
#
# Complete the 'cavityMap' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY grid as parameter.
#
"""
--------------------- LINK -------------------
https://www.hackerrank.com/challenges/cavity-map/problem
"""

def cavityMap(grid):
    c_grid = copy.copy(grid)

    
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if i!=0 and i!=len(grid)-1 and j!=0 and j!= len(grid[i])-1:
                top = grid[i-1][j]
                left = grid[i][j-1]
                right = grid[i][j+1]
                down = grid[i+1][j]
                
                center = grid[i][j]
                if( top < center) and (left < center ) and (right< center )and (down< center):
                    ch = list(c_grid[i])
                    ch[j]= "X"
                    c_grid[i]="".join(ch)
             
    return c_grid
    
        
        
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    result = cavityMap(grid)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    
    fptr.close()
