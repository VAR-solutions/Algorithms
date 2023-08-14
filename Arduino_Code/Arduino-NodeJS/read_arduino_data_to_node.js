var SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline')

var serialPort = new SerialPort('/dev/ttyACM0', {
    baudRate: 9600,
    // parser: SerialPort.parsers.readline("\n")
});
const parser = new Readline()
serialPort.pipe(parser)
parser.on('data', console.log)

// const parser = serialPort.pipe(new Readline({ delimiter: '\r\n' }))

// parser.on('data', console.log(serialPort.read()))

// serialPort.on('readable', function () {
//     console.log('Data:', serialPort.read())
//   })
