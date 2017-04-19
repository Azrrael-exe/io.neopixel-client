var io = require("socket.io-client")
var socket = io('https://io-neopixel.herokuapp.com/');
var SerialPort = require('serialport');
var port = new SerialPort('COM3',{
  baudrate : 115200
});

port.on('open', function(){
  console.log("SerialPort open!")
});

socket.on('connect', function(){
  console.log(socket.id);
  socket.emit('register', {
    socketName : 'SocketTest',
    socketId : socket.id
  })
  socket.emit('user-command', {
    socketName : 'SocketTest',
    payload : {
      red : 100,
      green : 0,
      blue : 100
    }
  })
});

socket.on('device-command', function(msg){
  port.write(JSON.stringify(msg), function(err){
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log({'Serial-OUT':JSON.stringify(msg)});
  });
})
