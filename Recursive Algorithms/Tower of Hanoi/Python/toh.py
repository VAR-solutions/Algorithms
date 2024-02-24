# -*- coding: utf-8 -*-
"""
Created on Thu Oct  1 18:24:00 2020

@author: KayDee
"""

def towerOfHanoi(source,aux,destination,disk):
    #base case
    if disk == 1:
        print("Move disk",disk,"from",source,"to",destination)
        return
    
    
    #call function using aux as destination and vice-versa
    towerOfHanoi(source,destination,aux,disk-1)
    
    #print step
    print("Move disk",disk,"from",source,"to",destination)
    
    #use aux as source and move disks to destination
    towerOfHanoi(aux,source,destination,disk-1)




n = int(input("Enter the number of disks : "))
towerOfHanoi("source","aux","destination",n)