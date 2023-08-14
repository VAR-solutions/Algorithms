import simd

let message = "ACT"
let key = "GYBNQKURP"

// Set Key Matrix
let keyAsciiMapped = key.map { $0.asciiValue! % 65 }
var keyMatrix = simd_float3x3()
for i in 0..<3 {
    for j in 0..<3 {
        keyMatrix[i][j] = Float(keyAsciiMapped[i*3 + j])
    }
}

// Set Message Vector
let messageAsciiMaped = message.map { Float($0.asciiValue! % 65) }
let messageVector = simd_float3(messageAsciiMaped)

// Helper Function: get String from simd vector
func getString(from vector: simd_float3) -> String {
    var string = ""
    for i in 0..<vector.scalarCount {
        let mappedValue = Int(Float(vector[i].description)!) % 26
        string.append(Character(UnicodeScalar(mappedValue + 65)!))
    }
    return string
}

// MARK: - Hill Cipher
func hillCipher() {
    let cipherVector = simd_mul(messageVector, keyMatrix)
    let cipherText = getString(from: cipherVector)
    print("Cipher Text: \(cipherText)")
}

// MARK: - Decipher
func decipher() {
    let message = simd_mul(messageVector, keyMatrix) * keyMatrix.inverse
    let decipherText = getString(from: message)
    print("Decipher Text: \(decipherText)")
}

// MARK: - Usage
hillCipher()
decipher()
