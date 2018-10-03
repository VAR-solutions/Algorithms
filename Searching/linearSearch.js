function linearSearch(array, match){
    for(var i = 0; i < array.length; i++){
        if(array[i] === match) {
            return i;
        }
    }
    return -1;
}