/*
This code is made to specifically label a pin by INT number and allowing it to blink per hald second via MS 
(Milisecond) built in function.

Line 37 of the ESP32S3 board has a 0-255 RGB color LED built in that can be changed using code similar to the one below.

Credit to https://www.youtube.com/watch?v=vOmfGrvxPNc 
*/
const int ledA = 9;  //constant int se tot LED pin#
const int ledB = 10;  //constant int se tot LED pin#
const int ledC = 11;  //constant int se tot LED pin#
const int ledD = 12;  //constant int se tot LED pin#

const int leds[] = {9, 10, 11, 12};
const int ledCount = 4;

int ms = 500;
bool ledState = 0;

void setup() 
{
  // pinMode(ledA, OUTPUT);
  // pinMode(ledB, OUTPUT);
  // pinMode(ledC, OUTPUT);
  // pinMode(ledD, OUTPUT);

  // pinMode(9, OUTPUT);
  // pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);
  // pinMode(12, OUTPUT);

  // pinMode(ledA, OUTPUT);


  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  } 


  Serial.begin(115200);
}


void loop() 
{
  // // digitalWrite(ledPin, HIGH);
  // digitalWrite(ledA, HIGH);
  // // digitalWrite(ledB, HIGH);
  // // digitalWrite(ledC, HIGH);
  // // digitalWrite(ledD, HIGH);


  // delay(ms);
  // // digitalWrite(ledPin, LOW);
  // digitalWrite(ledA, LOW);
  // // digitalWrite(ledB, LOW);
  // // digitalWrite(ledC, LOW);
  // // digitalWrite(ledD, LOW);

  // delay(ms);

 
  // if(ledA != LOW)
  // {
  //   if(ledB = HIGH)
  //   {
  //     digitalWrite.random(leds[]);
  //   }

  // }

  int randomLED = random(0, ledCount);

  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], LOW);
  } 
  delay(ms);

  digitalWrite(leds[randomLED], HIGH);
  delay(ms);


/*
if(ledA != LOW)
{
  digitalWrite.random(ledB, ledC, ledD, low);
  // delay(ms);
}


*/


/*
  ranNum = random(6, 9);

  digitalWrite(ranNum, HIGH);

  delay(ms);

  
  digitalWrite(ranNum, LOW);  

*/


}







