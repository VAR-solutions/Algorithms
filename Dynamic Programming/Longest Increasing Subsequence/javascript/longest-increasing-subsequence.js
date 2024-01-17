function LongestIncreasingSubsequence(input) {
    
    const longestArr = Array(input.length).fill(1);

    let prev = 0;
    let curr = 1;
    let aux = [],result = [];
    let ans = 0;
    while (curr < input.length) {
        while(prev<curr)
        {
            if (input[prev] < input[curr]) {
                const l = longestArr[prev] + 1;
                if (l > longestArr[curr]) {
                    longestArr[curr] = l;
                    aux.push(input[prev]);
                }
            }
            prev += 1;
        }
        if(aux.length===0 || input[curr]>aux[aux.length-1])
        {
            aux.push(input[curr]);
        }
        if(longestArr[curr]>ans) 
        {
            ans=longestArr[curr];
            result = aux;
        }
        aux=[];
        curr += 1;
        prev = 0;
    }
    obj = {'array':input,'length':ans, 'subarray':result};
    return obj;
}

var x = LongestIncreasingSubsequence([0, 7, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]);
x = LongestIncreasingSubsequence([0,0,0,0,0,0,1,1,1,1,2,3,0,0,0,1,1,0,1,1,0,1,0,3]);
console.log('Longest Increasing Subsequence Length is ',x.length);
console.log('Original Array is\n',x.array);
console.log('One of the subarrays satisfyng longest increasing subsequence is\n',x.subarray);