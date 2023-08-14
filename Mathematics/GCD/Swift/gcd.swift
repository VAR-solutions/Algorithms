func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

// Usage
let x = gcd(12, 8)
print(x)    // equal to 4
