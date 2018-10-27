function factorial(num) {
    if (num < 0 ) throw new Error("Negative numbers aren't allowed")
    if (num % 1 !== 0 ) throw new Error("Number should be an integer")

    // Seperating the test logic from core logic
    
    function compute(num) {
      if (num === 1 || num === 0) return 1
      return num * compute(num -1)
    }
    return compute(num)
}

console.log(factorial(5))
