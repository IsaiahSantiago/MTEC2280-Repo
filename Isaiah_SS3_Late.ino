/* Isaiah.S 3/17/26
SHORT SKETCH #3: DUE 3/18
Use a single hardware analog sensor to control a software p5.js sketch. 
You may use either a photocell/LDR or Potentiometer as your sensor. 
The p5.js sketch must include:

use of analog sensor data to control multiple elements of your P5 sketch. 
For example:
fill color, background color, shape size, shape location, etc.
use of map() function
use of declared variables
use of background()
use of fill()
at least three graphics primitives
display window width: max of 1080, min of 400
display window height: max of 720, min of 400

References:
https://www.youtube.com/watch?v=jsXLMm-FnSY 
https://editor.p5js.org/shfitz/sketches/n42x2dg8R
https://medium.com/@yyyyyyyuan/tutorial-serial-communication-with-arduino-and-p5-js-cd39b3ac10ce
https://github.com/IsaiahSantiago/MTEC2280-Repo/blob/master/MIDTERM_IsaiahS_Final.ino
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S07-Serial_Arduino_to_P5/Arduino_Serial_Write/Arduino_Serial_Write.ino


*/

//List of Variables: 

// int number = 0; 

// const int pinRGB = 38;    //built-in rgb for testing potentiometer
// // int reading[numReads];    //array of integers with length of numReads
// // int readingCount = 0; //Tracking the reading

// const int buttonPin = 1; //ButtonPin #
// bool buttonState = 0;     //current button statea
// bool lastButtonState = 0; //Prev button state
// // bool toggle = 0;          //toogle bool for rising edge
// // bool fallToggle = 0;      //toggle bool for falling edge

// const int potPin = 9;     //potentiometer pin

// const int ledA = 4;  //constant int se tot LED pin#
// const int ledB = 5;  //constant int se tot LED pin#
// const int ledC = 6;  //constant int se tot LED pin#
// const int ledD = 7;  //constant int se tot LED pin# 
// const int adcPin = 15;

// bool ledState = 0;
// // const int ledState = LOW;

// // const int leds[] = {9, 10, 11, 12};
// // const int ledCount = 4;

// int ms = 500;

// //Timer setup
// int currentTime = 0; //Store current MS
// int lastTime = 0; //store millis at moment of event
// int timeInterval = 1000; //Amount of ms for comparison
// //software timer variables
// let lastTime = 0;
// let currentTime = 0;
// let timerInterval = 2;
// const int adcPin = 1; //sensor hooked up to GPIO Pin 1
// let adcRead = 0;  //variable to store our Analog-to-Digital Conversion value


let serial; //Variable for serial subject
let latestData = 0; //Variable used to hold data
let portName = '0COM10';
let options = {baudRate: 9600};
let inData;

//Pot Pin and Variable
let adcPin_1 = 1;
let adcRead_1 = 0;

//Software Timer Variables
let lastTime = 0;
let currentTime = 0;
let timerInterval = 5; //milliseconds

let radius = 100;
//Different to Int in arduino C code

function setup() 
{
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

  createCanvas(450, 450);
  textSize(75);
  textAlign(CENTER, CENTER);
 



}

function draw() 
{
  background(0, 100, 255);
  // fillStyle = "#ff0000";
  // color = #red;

  let diameter = map(inData, 10, 255, 255, width - 10); // scale incoming data from 0 to 255 into circle diameter
  // circle(width/2, height/2, diameter);  // draw circle in center of canvas with diameter based on serial data

  fill(0);  // set fill color to black 
  text(inData, width/4, height - height/4); // display incoming serial data on canvas

  fill(inData); // set fill color using incoming serial data

  stroke(255, 0, 0, 127);
  strokeWeight(2);
  fill(10, 255, 255);

  // line(0, 0, mouseX, mouseY);
  line(175, 100, 225, 100);

  strokeWeight(1); 
  circle(width/2, height/2, 300);

  arc(200, 250, 125, 3, 20); 

  stroke(0, 255, 20);
  strokeWeight(2);
  triangle(200, 175, 225, 220, 200, 220);

  rect(125, 80, 50, 50);
  rect(225, 80, 50, 50);



  
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





//=======================================================================================

// //Reading potentiometer values
//   int potValue = analogRead(potPin); //Returns a value from 0

//   pinMode(buttonPin, INPUT_PULLUP);
//   pinMode(ledA, OUTPUT);
//   pinMode(ledB, OUTPUT);
//   pinMode(ledC, OUTPUT);
//   pinMode(ledD, OUTPUT);
//   // analogReadResolution(10); //Gives Range of 0-1023 bytes
//   // analogReadResolution(12);  //Increase ADC bit depth to 11-bits
//   // Or we could use analogReadResolution(12);   //12-bit = ADC resolution [0-4095]
//   analogReadResolution(12);  

//   //Brightness value of the LED's based on Potentiometer Value and mapping.
//   int brightness = map(potValue,  0, 2047, 0, 255);
//   // int brightness = map(potValue, 0, 4095,0 ,255);


// //Reading the button and state to create an on and off state.
//   buttonState = digitalRead(buttonPin);

//   Serial.println(potValue);
//   Serial.println("SETUP is Running");

// }

// void loop() 
// {
  
//   lastButtonState = buttonState;
//   buttonState = digitalRead(buttonPin);

//   // analogWrite(ledA, brightness);
//   // analogWrite(ledB, brightness);
//   // analogWrite(ledC, brightness);
//   // analogWrite(ledD, brightness);


//   currentTime = millis(); //store current time in milliseconds 
//   timeInterval = map(analogRead(adcPin), 0, 1023, 10, 2000); //map ADC read from 0-1023 to 10-2000 bytes

//   if(currentTime - lastTime >= timeInterval)
//   {
//     lastTime = currentTime; //
//     ledState = !ledState; //Turns LED on \ Goes from 1 to 0
//     Serial.println("Timer Triggered");

//   }
  
//   digitalWrite(ledA, ledState); 
//   digitalWrite(ledB, ledState);
//   digitalWrite(ledC, ledState);
//   digitalWrite(ledD, ledState);
//     // digitalWrite(ledD, LOW);
//   // delay(ms);

// //Remember that digitalWrite to LEDpins writes to the ledState to turn them all on.  

// Serial.printf("LED STATE: %i \t Timer Interval = %i ", ledState, timeInterval);


// // Lets try if/else if statements to turn on a specific number of LEDs based on -
// //- the potentiometer's ranges un bytes (0–1000, 2000-3000, 3000-4000);


//   // if((brightness < 0 && brightness > 1000))
//   // {
//   //   digitalWrite(ledA, HIGH);
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, LOW);
//   // }
  
//   // else if ((brightness < 1000 && brightness > 2000))
//   // {
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, HIGH);
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, LOW);
//   // }

//   // else if ((brightness < 2000 && brightness > 3000))
//   // {
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, HIGH);
//   //   digitalWrite(ledA, LOW);
//   // }
//   // else if ((brightness < 3000 && brightness > 4000))
//   // {
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, LOW);
//   //   digitalWrite(ledA, HIGH);
//   // }


// // if (lastButtonState == HIGH && currentButtonState == LOW) 
// // { Serial.print ("Button Pressed");
// // // toggle state of LED
// //   if (ledState == LOW) 
// //   {
// //   ledState = HIGH; //Turns LED on
// //   }

// // }
// // else 
// // {
// //   ledState = LOW; ///Turn back off
// // }



//   Serial.println(buttonPin);


//   delay(ms); // this speeds up the simulation


// }//=======================================================================================

/* 

  "SERIAL COMMS INTRO - BASIC UART"

  - DEMO FOR SENDING SERIAL DATA FROM ARDUINO TO P5.JS
  - READS ANALOG SENSOR AND WRITES 8-BIT VALUE TO SERIAL PORT
  - IMPLEMENTS REPEATING SOFTWARE TIMER TO STABILIZE SERIAL COMMS

  NOTE:
  - You must DISCONNECT (or exit) p5.serialcontrol Sketch before uploading to MCU.
  - Otherwise, the UART port used for code upload will be blocked by UART comms to P5.


const int adcPin = 1; //sensor hooked up to GPIO Pin 1
int adcRead = 0;  //variable to store our Analog-to-Digital Conversion value

//software timer variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 2;

void setup() 
{
  Serial.begin(9600);     // Start serial communication @ 9600 baud rate
  analogReadResolution(8);  //adjust adc read range to 0-255, 1-byte, 8-bit
}

void loop() 
{
  //we don't want or need to send updates to serial port so often, so use a timer:
  currentTime = millis(); //read current elapsed time
  if (currentTime - lastTime >= timerInterval)  //if we have reached our timer interval...
  {
    lastTime = currentTime; //store current time as last time so we know when timer last occured
    adcRead = analogRead(adcPin); //read sensor and assign to variable called adcRead

    /*
      NOTE: Uncomment Serial.println() OR Serial.write(), but not both!
    

    //Serial. println(adcRead); //to send human-readable data to Arduino Serial Monitor
    Serial.write(adcRead);  //to send binary data to UART

    //code in here will only run every 2ms, freeing up our CPU for other tasks
  }
  //anything you add here will run more frequently than code inside of above if statement
}

*/

// }//=======================================================================================

/*
P5.JS SERIAL READ

An example p5.js sketch that uses the p5.serialport library to read an 8-bit (1-byte) value from the serial port.
The size and fill color of a circle changes according to the received value, which is also displayed on the canvas.

This code is designed to work with the "Arduino_Serial_Write" example sketch.

NOTES:
- You must run and establish a serial connection with p5.serialcontrol app to use this code:
  https://github.com/p5-serial/p5.serialcontrol/releases/tag/0.1.2

- Remember to add the p5.serialport library to your index.html file. Add this line below <script src="libraries/p5.min.js"></script>:

    <script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>

- Make sure the baud rate in options matches the baud rate in your Arduino code.
- Remember to change the portName variable to match your own serial port.


let serial; //that is a variable for an instance of serialPort Library.
// let portName = 'COM9';
let portName = '0COM9';
// let portName = '/dev/tty.usbserial-213320';  // fill in your serial port name here

let options = {baudRate: 9600};

let inData;


function setup() 
{

  //Serial port Setup
  Serial = new p5.SerialPort(); 
  Serial.on('list', printList);
  Serial.on('connected', serverConnected);
  Serial.on('open', portOpen);
  Serial.on('error', serialError);
  Serial.on('close', portClose);

  Serial.list();
  Serial.open(portName, options);


  createCanvas(800, 800);
  textSize(72);
  textAlign(CENTER, CENTER);

}


function draw()
{
  background(0, 0, 255);
  // fill(inData);
  // let diameter = map(inData, 0, 255, 10, width - 10); // scale incoming data from 0 to 255 into circle diameter

  // fill(0); // set fill color to black for text
  // text(inData, width/2, height - height / 8);// display incoming serial data on canvas

  fill(inData); // set fill color using incoming serial data
  let diameter = map(inData, 0, 255, 10, width - 10); // scale incoming data from 0 to 255 into circle diameter
  circle(width/2, height/2, diameter);  // draw circle in center of canvas with diameter based on serial data

  fill(0);  // set fill color to black for text
  text(inData, width/2, height - height/8); // display incoming serial data on canvas


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


*/














