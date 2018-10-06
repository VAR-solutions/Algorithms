# Author Shubham Bindal

# Counting sort is efficient if the range of input data is not
# significantly greater than the number of objects to be sorted.
# Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.

def counting_sort(array): 
  
    # creating and initialising output_arr array
    output_arr = [0 for i in range(256)] 
  
    # Creating and initialising count_arr array to store count_arr of inidividul 
    count_arr = [0 for i in range(256)] 
  
    # creating and initialising ans_arr array 
    ans = ["" for i in array] 
  
    # Store count_arr of each character 
    for i in array: 
        count_arr[ord(i)] += 1

    for i in range(256): 
        count_arr[i] += count_arr[i-1] 
  
    
    for i in range(len(array)): 
        output_arr[count_arr[ord(array[i])]-1] = array[i] 
        count_arr[ord(array[i])] -= 1
  
   #Given a string of length one, return an integer representing the unicode
    for i in range(len(array)): 
        ans[i] = output_arr[i] 
    return ans

# Driver program 
array = input("ENTER THE ELEMENTS OF CHARACTER ARRAY WHICH YOU WANT TO SEARCH\n")

ans = counting_sort(array)

print ("\nSorted character array is " + "".join(ans)) 
  
