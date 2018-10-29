import math
#Function: Bucket sort
#Input: Array of n elements (numbers)
#Output: Array containing input array elements but sorted
def bucketSort(arr):
    #Get the size, max element and min element of the input array
    arrSize, maximum, minimum = len(arr), max(arr), min(arr)
    #Create buckets
    bucketsNumber = math.ceil(arrSize/2)
    buckets = [[] for _ in range(bucketsNumber)]
    #calculate the bucket range
    bucketRange = (float(maximum)-float(minimum)+1.0)/float(bucketsNumber)
    for i in arr:
        #Distribute the elements in buckets
        buckets[int((i-minimum)/bucketRange)].append(i)

    for bucket in buckets:
        #Sort each bucket (normally using insertion sort,
        #here list.sort() is used instead)
        bucket.sort()

    #create result list
    sorted = []
    for bucket in buckets:
        #pop each element from each bucket, this will populate
        #the sorted output list
        while len(bucket)>0:
            sorted.append(bucket.pop(0))

    return sorted

myarr = [0.25, 0.36, 0.58, 0.41, 0.29, 0.22, 0.45, 0.79, 0.01, 0.69]
mySortedArr = [0.01, 0.22, 0.25, 0.29, 0.36, 0.41, 0.45, 0.58, 0.69, 0.79]
print("input array:\n",myarr,"\nsorted array:\n",bucketSort(myarr))
print("should be:\n", mySortedArr)

myarr = [8, 5, 3, 1, 9, 6, 0, 7, 4, 2, 5]
mySortedArr = [0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9]
print("input array:\n",myarr,"\nsorted array:\n",bucketSort(myarr))
print("should be:\n", mySortedArr)

myarr = [80, 50, 30, 10, 90, 60, 0, 70, 40, 20, 50]
mySortedArr = [0, 10, 20, 30, 40, 50, 50, 60, 70, 80, 90]
print("input array:\n",myarr,"\nsorted array:\n",bucketSort(myarr))
print("should be:\n", mySortedArr)
