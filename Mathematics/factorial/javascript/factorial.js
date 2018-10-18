function factorial (num) {
    if (num < 0 ) {
        return
    } 
    
    if (num === 1) {
        return 1;
    }

    return num*factorial(num-1)
}

console.log(factorial(5))
