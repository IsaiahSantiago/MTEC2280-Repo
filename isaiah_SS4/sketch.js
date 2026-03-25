/*
SHORT SKETCH #4: DUE 3/25
Use (at least) 4 hardware sensors to control a P5.JS sketch. You may use any combination of buttons, potentiometers, photocell, or touch points as your sensor. The P5 sketch must include:

use of sensor data (transmitted via UART) to control multiple elements of your P5 sketch.
use of map() function
use of data type conversion such as Integar to Ascii and back to integar values for our Serial port data
use of declared variables
use of background()
use of fill()
at least three graphics primitives
display window width: max of 1080, min of 400
display window height: max of 720, min of 400
Feel free to use images, sound library, etc. The content is completely up to you, but it needs to be controlled by Serial UART from Microcontroller.

Upload your completed code (both arduino & p5.js) to your repo before the beginnning of next class session. Remember, the arduino .ino file must go in folder of same name, and the p5.js project must include its entire project folder and it contents.
Have your project (both hardware and software aspects) ready to present at the next class critique.

References:
https://youtu.be/gSag3HmyOgE?si=HZQjh0vL-xK_RCLW 
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S08-Serial_Arduino_to_P5_MultiSensor/Arduino_Serial_Multi_String/Arduino_Serial_Multi_String.ino
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S08-Serial_Arduino_to_P5_MultiSensor/P5_Serial_Read_String/sketch.js
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S05-AnalogRead_Mapped/S05-AnalogRead_Mapped.ino

*/


let Serial; //Var for serial subject
let latestData = 0; //Var used to hold data
let portName = '0COM10'; //Changes typically in the Serial monitor app
let options = {baudRate: 9600}; //Baudrate for port detection
// let inData;
let inData = 0; // Var for storing incoming serial data
let sensors = [0, 0, 0, 0]; //sensor values: [button1, button2, Button3, pot2]

//Pot Pin and Variable
let adcPin_1 = 1;
let adcRead_1 = 0;

let buttonState = 0; 

//Software Timer Variables
let lastTime = 0;
let currentTime = 0;
let timerInterval = 5; //milliseconds

// variables for RGB color button changes
let r, g, b; 


function setup() 
{
  createCanvas(720, 400);

 // put your setup code here, to run once:
  Serial.begin(9600);

  //Serial port Setup code
  Serial = new p5.SerialPort(); 
  Serial.on('list', printList);
  Serial.on('connected', serverConnected);
  Serial.on('open', portOpen);
  Serial.on('error', serialError);
  Serial.on('close', portClose); 

  Serial.list();
  Serial.open(portName, options);

  textSize(50);
  textAlign(70, 70);
  text(inData, width/4, height - height/4); // display incoming serial data on canvas


}


function draw() 
{

  //For controlling RGB with buttons
  r = sensors[0] * 55; // map button 1 to value (0 or 55)
  g = sensors[1] * 127; // map button 2 to value (0 - 127)
  b = sensors[2] * 255; // map button 3 to value (0 - 255)s
  //sensors[3] is reserved for Potentiometer

  background(r * !sensors[0], g * !sensors[1], b); 
  // fill frame w/ background color, also using buttons to turn off color components.
  // background(220);

  let diameter = map(inData, 10, 255, 255, width - 10); // scale incoming data from 0 to 255 into circle diameter

  fill(0, 0, 255);  // set fill color to Blue 



  let circleSize = map(sensors[3], 0, 0, 0, 500);
  ellipse(width / 2, height / 2, circleSize, circleSize);

  fill(255 * !sensors[2]); // set fill color to black if button 3 is pressed, otherwise white






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














