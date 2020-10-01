/*
Author: Nameer Waqas
Date : 01/10/2020
Title : Two way linear search algorithm
Time complexity: O(n/2)
Test case : arr=[1,5,2,7,3,8,9], valToSearch=7
*/

function twoWayLinear(arr=[],valToSearch){
    let check = false;    
    if(arr.length==0) return check
    if(valToSearch=='') return check
    else{
        for(var i = 0, j=arr.length-1;i<=parseInt(arr.length/2);i++,j--){
            if(valToSearch==arr[i]){
                check = true;
                return check
            }
            else if(valToSearch == arr[j]){
                check=true;
                return check
            }
            else{
                continue
            }
        }
        return check
    }
}

twoWayLinear([1,5,2,7,3,8,9],7);
// true