function binarySearch(array, match) {
    var low = 0;
    var high = array.length - 1;
    var mid;

    while(low <= high) {
        mid = Math.floor((low + high) / 2);
        if(array[mid] === match) {
            console.log("Index: " + mid);
            return mid;
        }
        if(match < array[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    console.log("Not found.");
    return null;
}
