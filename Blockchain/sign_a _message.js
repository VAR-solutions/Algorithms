var bitcoin = require('bitcoinjs-lib') // v4.x.x
var bitcoinMessage = require('bitcoinjs-message')

var keyPair = bitcoin.ECPair.fromWIF('L4rK1yDtCWekvXuE6oXD9jCYfFNV2cWRpVuPLBcCU2z8TrisoyY1')
var privateKey = keyPair.privateKey
var message = 'This is an example of a signed message.'

var signature = bitcoinMessage.sign(message, privateKey, keyPair.compressed)
console.log(signature.toString('base64'))
// => 'H9L5yLFjti0QTHhPyFrZCT1V/MMnBtXKmoiKDZ78NDBjERki6ZTQZdSMCtkgoNmp17By9ItJr8o7ChX0XxY91nk='

// verify the message 

var address = '1F3sAm6ZtwLAUnj7d38pGFxtP3RVEvtsbV'

console.log(bitcoinMessage.verify(message, address, signature))
// => true
