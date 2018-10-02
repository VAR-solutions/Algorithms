def merge(A,B):
    (C,m,n) = ([],len(A),len(B))
    (i,j) = (0,0)
    while i+j < m+n:
        if i == m:
            C.append(B[j])
            j += 1
        elif j == n:
            C.append(A[i])
            i += 1
        elif A[i] <= B[j]:
            C.append(A[i])
            i += 1
        elif A[i] > B[j]:
            C.append(B[j])
            j += 1
    return(C)

def mergeSort(A,left,right):    
    if right - left <= 1:
        return(A[left:right])
    
    mid = (left+right)//2
    mergeSort(A,left,mid)
    mergeSort(A,mid,left)

    return(merge(L,R))
