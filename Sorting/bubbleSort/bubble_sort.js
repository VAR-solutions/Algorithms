function bubble_sort(arr)
{
    for (let i = 0; i < arr.length; i++)
    {
        for (let j = i; j < arr.length; j++)
        {
            if (arr[i] > arr[j])
            {
                let temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

let arr = [3, 1, 2, 5, 4];

console.log(bubble_sort(arr));
