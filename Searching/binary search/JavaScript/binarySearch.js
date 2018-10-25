const innerBinarySearch = (arr, key, from, to) => {
    if (from > to) {
        return -1;
    }

    const middleIndex = Math.trunc((from + to) / 2);

    if (arr[middleIndex] > key) {
        return innerBinarySearch(arr, key, from, middleIndex - 1);
    } else if (arr[middleIndex] < key) {
        return innerBinarySearch(arr, key, middleIndex + 1, to);
    }

    return middleIndex;
};

const iterativeBinarySearch = (arr, key) => {
    let start = 0;
    let end = arr.length - 1;
    let indexToReturn = -1;

    while (start <= end) {
        const middleIndex = ((start + end) / 2) | 0;
        if (arr[middleIndex] < key) {
            start = middleIndex + 1;
        } else if (arr[middleIndex] > key) {
            end = middleIndex - 1;
        } else {
            indexToReturn = middleIndex;
            break;
        }
    }

    return indexToReturn;
};