func fib(_ N: Int) -> Int {
    var a = 0, b = 1

    for _ in 0 ..< N {
        b += a
        a = b - a
    }

    return a
}

// Usage
let x = fib(4)
// x = 3
