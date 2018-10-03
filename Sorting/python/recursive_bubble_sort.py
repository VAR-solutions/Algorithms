 
# Author Shubham Bindal 
  
def bubble_sort(list_): 
    for i, num in enumerate(list_): 
        try: 
            if list_[i+1] < num: 
                list_[i] = list_[i+1] 
                list_[i+1] = num 
                bubble_sort(list_) 
        except IndexError: 
            pass
    return list_ 

list_=list(map(int,input("Enter the numbers to be sorted\n").split()))

bubble_sort(list_) 
  
print("Sorted array:");

for i in range(0, len(list_)):
    
    print(list_[i], end=' ') 
  
  
