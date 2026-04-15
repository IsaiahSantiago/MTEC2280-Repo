/*
SHORT SKETCH #5: DUE 4/15
Create a software p5.js sketch that controls at least one hardware actuator via serial. 
You may use an LED, Servo Motor, or Piezo Buzzer as your actuator. 
The p5.js sketch must include:

use of at least 1 hardware actuator controlled by interaction with your P5 sketch.
at least 2 different modes of behavior: for example, our "P5_Serial_Servo" sketch has 
a "sweep" mode and a "follow" mode.
at least three graphics primitives.
dynamic elements in your P5 sketch (don't just draw a static canvas, animate something!).
display window width: max of 1080, min of 400
display window height: max of 720, min of 400
Feel free to use images, sound library, etc. 
The content is completely up to you, but it needs to be controlled by Serial UART 
from your P5.JS Sketch.

Upload your completed code (both arduino & p5.js) to your repo before the beginnning 
of next class session.
Remember, the arduino .ino file must go in folder of same name, and the p5.js 
project must include its entire project folder and it contents.
Have your project (both hardware and software aspects) ready to present at the next class 
critique.

REMEMBER to add the p5.serialport library to the index.html file of your p5.js projects:

> Lets play with a Piezo Buzzar and try to make a melody or tune, or some way to change the 
"music" maybe with the Potentiometer and LED(s)'s can showcase the level of volume like a DJ board.
> New idea: Piezo can't be controlled directly through P5JS code HOWEVER graphic visuals can be 
changed with sounds so therefore P5JS can be used to be reactionary to sound from the buzzer that's
controlled through Arduino code.

References: 
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S07-Serial_Arduino_to_P5/P5_Serial_Read/sketch.js
https://editor.p5js.org/jt4269/sketches/M0eV1a1r5#:~:text=Arduino%20code%20is%20at%20the,//%20variables%20for%20oscillator
http://youtube.com/watch?v=jEwAMgcCgOA&list=TLPQMTQwNDIwMjbVBrld3vayRg&index=4 
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/tree/main/examples/S08-Serial_Arduino_to_P5_MultiSensor
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S06_frequencyTone/S06_frequencyTone.ino
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S08-Serial_Arduino_to_P5_MultiSensor/Arduino_Serial_Multi_String/Arduino_Serial_Multi_String.ino
https://editor.p5js.org/codingtrain/sketches/goeU3RUbU
https://www.youtube.com/watch?v=q2IDNkUws-A&list=PLRqwX-V7Uu6aFcVjlDAkkGIixw70s7jpW&index=8


*/

//For connecting with Serial monitor operations and my computer port 
let serial;
let portName = '0COM10';
let options = {baudRate: 9600};
let outByte = 0;  // 8-bit data to sends to microcontroller ESP33 remember?

// --let sensors = [0, 1, 1, 1]; // array for: [pot, butt1, butt2, butt3]--
let sensor = [0]; //We can simply use one sensor for the potentiometer right?

// let r, g, b; // variables for background colors
let color;
let diameter = 100; // initial diameter of Center circle for Graphic reference 

//Variables for piezo buzzer 
let piezoPin = 1; //piezo buzzer connected to pin 1
// let osc, playing, freq, amp;
let music;
let mic;




function preload()
{
  music = loadSound('Chip Beat 1.mp3');
}


function setup() 
{
  createCanvas(400, 720);
  music.play();  
  mic = new p5.AudioIn();
  mic.start();

  amp = new p5.Amplitude();
  


  textAlign(CENTER, CENTER); //Text should be in the center top of the page like a presentation
  textSize(46); //Make it big but not big enough to block the screen of course. 
  fill(156, 10, 10); //Give it a red-ish tint -
  stroke(3); //- and a nice outline to differentiate it from the Background.
  











  //The GOTO P5 SerialPort Setup from the examples:
  serial = new p5.SerialPort();             // make a new instance of the serialport library so we
  // can use the index properly without error this time hopefully. 
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port
  //Remember to use print(whatever the error line is); to find if P5JS code actually sending data.



}

function draw() 
{
  // background(0);
  // let volume;
  // let vol = amp.getLevel(); 

  let vol = mic.getLevel();

  fill(0, 35, 225);
  ellipse(100, 100, 200, vol * 200);

  color = map(sensor[0], 0, 1023, 0, 255); //mapping potentiometer to color values

  background(10, 20, 15 * sensor[0]);  // fill frame w/ background color effecting blue




  for (let i = 0; i < width; i++)
  {
    let c = map(i, 0, width, 0, 255);  //map i to 0-255 range for color
    stroke(0, c, c * 3);    //change stroke color for each x position, blue is scaled to 3x
    line(i, 0, i, height);  //draw vertical line for each x position
  }
  
  //display text
  fill(255);
  text ("DIMMER", width/4, height/2);
  fill(0);
  text ("BRIGHTER", width-width/4, height/2);
  
  //mouse position indicator
  fill(0, 100, 255, 155);
  stroke(1);
  circle(mouseX, mouseY, 20);


}






function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}
 
function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}
 
function serialEvent() //gets called when new data arrives
{
  inData = Number(serial.read()); //Store incoming data as a number
  //print(inData);
}
 
function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}
 
function portClose() //gets called when the serial port closes
{
  print("*____SERIAL PORT CLOSED");
}






