const selectionSort = (arr) => {
    for (let i = 0; i < arr.length - 1; i += 1) {
        let iMin = i;
        for (let j = i + 1; j < arr.length; j += 1) {
            if (arr[iMin] > arr[j]) {
                iMin = j;
            }
        }
        if (iMin !== i) {
            [arr[iMin], arr[i]] = [arr[i], arr[iMin]];
        }
    }
};