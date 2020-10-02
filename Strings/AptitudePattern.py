n = int(input())
for i in range(0,n):
    diff = 6
    if (i+1)%2!=0:
        j = i+1
        for i in range(n-i):
            print(j,end=" ")
            j += diff
            diff -= 1
        print()       
                
    else:
        j = i+1
        for i in range(n-i):
            print(j,end=" ")
            j += diff
            diff += 1
        print()    
