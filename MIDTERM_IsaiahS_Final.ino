/* Isaiah.S Midterm Final Mtec 2280
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
http://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/ 
https://forum.arduino.cc/t/how-to-define-a-range-in-an-if-statement/212627 
https://www.youtube.com/watch?v=JghpLbCtnUU&list=TLPQMTEwMzIwMjaeT08LfBZOSg&index=5
 
*/

// int number = 0; 

const int pinRGB = 38;    //built-in rgb for testing potentiometer
// int reading[numReads];    //array of integers with length of numReads
// int readingCount = 0; //Tracking the reading

const int buttonPin = 1; //ButtonPin #
bool buttonState = 0;     //current button statea
bool lastButtonState = 0; //Prev button state
// bool toggle = 0;          //toogle bool for rising edge
// bool fallToggle = 0;      //toggle bool for falling edge

const int potPin = 9;     //potentiometer pin

const int ledA = 4;  //constant int se tot LED pin#
const int ledB = 5;  //constant int se tot LED pin#
const int ledC = 6;  //constant int se tot LED pin#
const int ledD = 8;  //constant int se tot LED pin#
const int adcPin = 15;

bool ledState = 0;
// const int ledState = LOW;

// const int leds[] = {9, 10, 11, 12};
// const int ledCount = 4;

int ms = 500;

//Timer setup
int currentTime = 0; //Store current MS
int lastTime = 0; //store millis at moment of event
int timeInterval = 1000; //Amount of ms for comparison


void setup() 
{
  Serial.begin(115200);

//Reading potentiometer values
  int potValue = analogRead(potPin); //Returns a value from 0

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  // analogReadResolution(10); //Gives Range of 0-1023 bytes
  // analogReadResolution(12);  //Increase ADC bit depth to 11-bits
  // Or we could use analogReadResolution(12);   //12-bit = ADC resolution [0-4095]
  analogReadResolution(12);  

  //Brightness value of the LED's based on Potentiometer Value and mapping.
  int brightness = map(potValue,  0, 2047, 0, 255);
  // int brightness = map(potValue, 0, 4095,0 ,255);


//Reading the button and state to create an on and off state.
  buttonState = digitalRead(buttonPin);

  Serial.println(potValue);
  Serial.println("SETUP is Running");

}

void loop() 
{
  
  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  // analogWrite(ledA, brightness);
  // analogWrite(ledB, brightness);
  // analogWrite(ledC, brightness);
  // analogWrite(ledD, brightness);


  currentTime = millis(); //store current time in milliseconds 
  timeInterval = map(analogRead(adcPin), 0, 1023, 10, 2000); //map ADC read from 0-1023 to 10-2000 bytes

  if(currentTime - lastTime >= timeInterval)
  {
    lastTime = currentTime; //
    ledState = !ledState; //Turns LED on \ Goes from 1 to 0
    Serial.println("Timer Triggered");

  }
  
  digitalWrite(ledA, ledState); 
  digitalWrite(ledB, ledState);
  digitalWrite(ledC, ledState);
  digitalWrite(ledD, ledState);
    // digitalWrite(ledD, LOW);
  // delay(ms);

//Remember that digitalWrite to LEDpins writes to the ledState to turn them all on.  

Serial.printf("LED STATE: %i \t Timer Interval = %i ", ledState, timeInterval);


// Lets try if/else if statements to turn on a specific number of LEDs based on -
//- the potentiometer's ranges un bytes (0–1000, 2000-3000, 3000-4000);


  // if((brightness < 0 && brightness > 1000))
  // {
  //   digitalWrite(ledA, HIGH);
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, LOW);
  // }
  
  // else if ((brightness < 1000 && brightness > 2000))
  // {
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, HIGH);
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, LOW);
  // }

  // else if ((brightness < 2000 && brightness > 3000))
  // {
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, HIGH);
  //   digitalWrite(ledA, LOW);
  // }
  // else if ((brightness < 3000 && brightness > 4000))
  // {
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, LOW);
  //   digitalWrite(ledA, HIGH);
  // }


// if (lastButtonState == HIGH && currentButtonState == LOW) 
// { Serial.print ("Button Pressed");
// // toggle state of LED
//   if (ledState == LOW) 
//   {
//   ledState = HIGH; //Turns LED on
//   }

// }
// else 
// {
//   ledState = LOW; ///Turn back off
// }



  Serial.println(buttonPin);


  delay(ms); // this speeds up the simulation


}






/*



*/
















