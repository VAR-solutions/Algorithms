// Random Number Generator using swift 4.0

func random(_ range:Range<Int>) -> Int {
    return range.lowerBound + Int(arc4random_uniform(UInt32(range.upperBound - range.lowerBound)))  
}
