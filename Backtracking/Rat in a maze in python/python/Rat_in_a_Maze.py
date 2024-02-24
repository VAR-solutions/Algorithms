# -*- coding: utf-8 -*-
"""
Created on Fri oct 1 10:09:42 2020

@author: Sam
"""
"""
A Maze is given as N*N binary matrix of blocks where source block is 
the upper left most block i.e., maze[0][0] and destination block is lower 
rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to
reach the destination. The rat can move only in two directions: forward and down.
"""

"""
This is a python solution for Rat in a maze proble using backtracking
"""
"""
This is a function for printing the solution matrix
"""
def printsolution(solution,n):
    print("One of the different path is:")
    for i in range(n):
        print()
        for j in range(n):
            
            print(solution[i][j],end=' ')
    print('\n')
"""
This is the main backtracking function
"""
def backtrack(arr,solution,x,y,n):
    """
    executing condition if rat reaches the end of the matrix
    """
    if x == n-1 and y == n-1:
        printsolution(solution,n)
        solution[x][y]=1
        return
    """
    All the base conditions to make sure every path is different and rat doesn't go out of the maze'
    """
    if x < 0 or y<0 or x >= n or y >= n or arr[x][y] == 0 or solution[x][y]==1:
        return
    #Mark the step as one
    solution[x][y] = 1
    #The move in which the rat moves up
    backtrack(arr,solution,x+1,y,n)
    #The move in which the rat moves down
    backtrack(arr,solution,x-1,y,n)
    #The move in which the rat moves right
    backtrack(arr,solution,x,y+1,n)
    #The move in which the rat moves left
    backtrack(arr,solution,x,y-1,n)
    #Mark the step as 0 to backtrack
    solution[x][y] = 0
"""
The driver code
Note: this program prints all the possible paths that exist from the top to the end for the rat.
"""
def findPath(arr, n):
    solution = [[0 for i in range(n)]for j in range(n)]
    backtrack(arr,solution,0,0,n)
#To take the input
n = int(input())
#To make the n*n matrix
arr = [[1 for x in range(n)]for y in range(n)]
#To check the code is output
findPath(arr,n)