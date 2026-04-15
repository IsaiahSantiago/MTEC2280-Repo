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


References: 
 https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S07-Serial_Arduino_to_P5/P5_Serial_Read/sketch.js
 https://editor.p5js.org/jt4269/sketches/M0eV1a1r5#:~:text=Arduino%20code%20is%20at%20the,//%20variables%20for%20oscillator
http://youtube.com/watch?v=jEwAMgcCgOA&list=TLPQMTQwNDIwMjbVBrld3vayRg&index=4 
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/tree/main/examples/S08-Serial_Arduino_to_P5_MultiSensor
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S06_frequencyTone/S06_frequencyTone.ino


*/

//Define Pins
const int adcPin_1 = 1;
const int piezoPin = 1; //piezo buzzer connected to pin 1

//Pot Variables
int adcRead_1 = 0;

bool intro = 0; //boolean variable to track whether we've played the intro melody yet

int octave = 2; //octave variable. we can multiply this by the base frequency to shift the pitch up or down by octaves. 
// for example: 110 * octave will be 110Hz in octave 1, 220Hz in octave 2, 440Hz in octave 4, etc.

//Software Timer Variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 5; //milliseconds


void setup() 
{
    analogReadResolution(10); //set ADC read to 10-bit (0-1023) range
  Serial.begin(9600);  //start serial comm @ 9600 baud rate
}

void loop() 
{
  //read analog pot value
  adcRead_1 = analogRead(adcPin_1);
  //read current elapsed time
  currentTime = millis(); 


  //tone(pin, frequency in Hz, duration in millisecond)
  if(!intro)  //if we haven't played intro yet...
  { 
    //play intro melody. 
    tone(piezoPin, 1000, 100);
    tone(piezoPin, 1100, 100);
    tone(piezoPin, 1200, 100);
    tone(piezoPin, 1300, 100);
    tone(piezoPin, 1000, 100);
    tone(piezoPin, 1800, 100);
    tone(piezoPin, 2000, 100);
    tone(piezoPin, 2200, 200);
    tone(piezoPin, 1400, 100);
    tone(piezoPin, 1500, 100);
    tone(piezoPin, 1400, 100);
    tone(piezoPin, 1300, 100);
    tone(piezoPin, 1200, 100);
    tone(piezoPin, 1100, 100);
    tone(piezoPin, 1200, 100);
    tone(piezoPin, 1400, 100);
    tone(piezoPin, 1600, 100);
    tone(piezoPin, 2400, 300);
    tone(piezoPin, 2600, 400);
    tone(piezoPin, 2800, 500);
    tone(piezoPin, 2600, 600);
    tone(piezoPin, 2400, 700);
    
    intro = 1;  //set intro to true so it doesn't play again

  }



  if (currentTime - lastTime >= timerInterval)  //if we have reached our timer interval...
  {
    lastTime = currentTime;  //store current time as lastTime so we know when timer last triggered

    //Send Data to P5.JS Sketch via Serial UART using print() and Comma Separation
    Serial.print(buttonState_1);  //send 1st message
    Serial.print(',');            //send comma character
    Serial.print(buttonState_2);  //send 2nd message
    Serial.print(',');            //send comma character
    Serial.print(adcRead_1);      //send 3rd message
    Serial.print(',');            //send comma character
    Serial.print(adcRead_2);      //send 4th message
    Serial.print('\n');           //send "Line Feed", or "New Line" character, or use println() instead.
  }




  //main melody
  tone(piezoPin, 90 * octave, 250);
  tone(piezoPin, 100 * octave, 500);
  tone(piezoPin, 110 * octave, 200);

  tone(piezoPin, 110 * octave, 300);
  tone(piezoPin, 220 * octave, 700);
  tone(piezoPin, 110 * octave, 400);
  tone(piezoPin, 440 * octave, 500);
  tone(piezoPin, 660 * octave, 200);
  tone(piezoPin, 220 * octave, 700);

  tone(piezoPin, 110 * octave, 500);
  tone(piezoPin, 100 * octave, 500);
  tone(piezoPin, 90 * octave, 500);
}















