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

//Define Pins
const int adcPin_1 = 1;
const int buttonPin_1 = 7;
const int buttonPin_2 = 8;
const int buttonPin_3 = 9;

//Button Variables
bool buttonState_1 = 0;
bool buttonState_2 = 0;
bool buttonState_3 = 0;


//Pot Variables
int adcRead_1 = 0;

//Software Timer Variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 5; //milliseconds

void setup() 
{
  //set button pin modes to Input with internal Pullup resistors
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);

  analogReadResolution(8); //set ADC read to 8 bit 0-255
  Serial.begin(9600);  //start serial comm @ 9600 baud rate
}

void loop() 
{
  //read analog pot value
  adcRead_1 = analogRead(adcPin_1);

  //read button state on pins [NOTE: logic is inverted due to Pullup config]
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);
  buttonState_3 = !digitalRead(buttonPin_3);

  

  currentTime = millis(); //read current elapsed time in milliseconds
  if (currentTime - lastTime >= timerInterval) //Timer interval reached
  {
    lastTime = currentTime;  //store current time as lastTime so we know when timer last triggered every time

    //Send Data to P5.JS Sketch via Serial UART using print() and Comma Separation
    //This is done via data conversion.
    Serial.print(buttonState_1);  //send 1st command
    Serial.print(',');            //send comma character
    Serial.print(buttonState_2);  //send 2nd command
    Serial.print(',');            //send comma character
    Serial.print(buttonState_3);      //send 3rd command
    Serial.print(',');            //send comma character
    Serial.print(adcRead_1);      //send 4th Reading
    Serial.print('\n');           //send "Line Feed", or "New Line" character, or use println() instead.


  }
}