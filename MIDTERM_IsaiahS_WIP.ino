/* Isaiah.S Midterm Wip Mtec 2280
Must include the following:
HARDWARE:
A- t least one analog sensor:
potentiometer
LDR / photocell
touch point
- At least one digital input:
button
- At least one analog output:
LED PWM
Piezo Buzzer
Servo Motor
At least one digital output:
LED

SOFTWARE:
digitalRead()
digitalWrite()
analogRead()
analogWrite()
user-declared variables
use of an array[]
conditional statements [IF/ELSE]
logical operator [AND, OR, NOT, etc]
timer using millis() instead of delay()
For Loop implementation

References: 
https://www.youtube.com/watch?v=IRAXPR1i2Mg 
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S05-AnalogRead_Mapped/S05-AnalogRead_Mapped.ino 
https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/ 
https://www.youtube.com/watch?v=0jFgo7_d0y0 
https://www.youtube.com/watch?v=VdB4GWeVkvY&list=TLPQMDQwMzIwMjbx9SQQcgLS7g&index=3


*/

// int number = 0; 

const int pinRGB = 38;    //built-in rgb for testing potentiometer
// int reading[numReads];    //array of integers with length of numReads
// int readingCount = 0; //Tracking the reading

const int buttonPin = 13; //ButtonPin #
bool buttonState = 0;     //current button statea
bool lastButtonState = 0; //Prev button state
// bool toggle = 0;          //toogle bool for rising edge
// bool fallToggle = 0;      //toggle bool for falling edge

const int potPin = 46;     //potentiometer pin

const int ledA = 9;  //constant int se tot LED pin#
const int ledB = 10;  //constant int se tot LED pin#
const int ledC = 11;  //constant int se tot LED pin#
const int ledD = 12;  //constant int se tot LED pin#
bool ledState = 0;
int ledState = LOW;

// const int leds[] = {9, 10, 11, 12};
// const int ledCount = 4;

int ms = 500;



void setup() 
{
  Serial.begin(115200);
  // analogReadResolution(12);   //12-bit = ADC resolution [0-4095]

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);

  int potValue = analogRead(potPin); //Returns a vallue from 0


  int brightness map(potValue);

  buttonState = digitalRead(buttonPin);

  Serial.println(potValue);
  Serial.println("SETUP is Running");

}

void loop() 
{
  
  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  int brightness = map(potValue, 0, 4095,0 ,255);


  analogWrite(ledA, brightness);
  analogWrite(ledB, brightness);
  analogWrite(ledC, brightness);
  analogWrite(ledD, brightness);


  // digitalWrite(ledA, LOW);
  // digitalWrite(ledB, LOW);
  // digitalWrite(ledC, LOW);
  // digitalWrite(ledD, LOW);
  // delay(ms);


if (lastButtonState== HIGH && currentButtonState== LOW) 
{ Serial.print ("Button Pressed");
// toggle state of LED
  if (ledState == LOW) 
  {
  ledState = HIGH; //Turns LED on
  }

}
else 
{
  ledState = LOW; ///Turn back off
}

// control LED arccoding to the Button states
  digitalWrite (ledA, ledState); //turns the LED on or off based on the int variables
  digitalWrite (ledB, ledState);
  digitalWrite (ledC, ledState);
  digitalWrite (ledD, ledState);



  Serial.println(buttonPin);


  delay(ms); // this speeds up the simulation


}








 












