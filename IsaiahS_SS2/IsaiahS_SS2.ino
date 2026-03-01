/*
Must include:
a circuit with a minimum of 4 LEDs, including current limiting resistors.
declaration and use of at least 3 variables.
use of at least two conditional [if / else] statements.
use of logical comparator in at least one conditional statement.
at least one pushbutton.
use of digitalRead(), digitalWrite(), and pinMode() functions.
display of at least 6 unique LED patterns.

Idea: Create a button that would activate either;
-As an On or Off button for a randomly lit up LED kit.
-As a switch for 2 or more kinds of LED random algorithms so the 
lights blink differently per button press or isPressed action.

Reference:
https://www.youtube.com/watch?v=tSuG19pyAu4&list=TLPQMjgwMjIwMjYetJKmLF7rZA&index=5 
https://github.com/entertainmenttechnology/Pokorny-MTEC2280_D01-Spring2026/blob/main/examples/S04-Button_Toggle/S04-Button_Toggle.ino 
https://www.youtube.com/watch?v=htmmRL6rhyE&list=TLPQMjgwMjIwMjYetJKmLF7rZA&index=9

*/

int number = 0;

const int buttonPin = 13; //ButtonPin #

bool buttonState = 0;     //current button state
bool lastButtonState = 0; //Prev button state
bool toggle = 0;          //toogle bool for rising edge
bool fallToggle = 0;      //toggle bool for falling edge


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
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  if(buttonState > lastButtonState)
  {
    toggle = !toggle; //flip toggle [true or false || 1 n 0] using !NOT 
  }

/*  if (buttonState && !lastButtonState) //if button went from LOW to HIGH
//   {
//     toggle = !toggle; //flip toggle bool using NOT logic
    // buttonState = true;
   }
 //FALLING EDGE DETECTION
  //Detects the RELEASE of a button
  if (!buttonState && lastButtonState) //if button went from HIGH to LOW
  {
    fallToggle = !fallToggle; //flip fallToggle bool using NOT logic
  }

*/


  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  } 


  randomSeed(analogRead(A0)); // Random Number seed generator

  Serial.begin(115200);
  Serial.println("Begin pinMode and if Statements");
}


void loop() 
{

  buttonState = !digitalRead(buttonPin); /* (RED, Rising edge detection) -
 - Detects the push of the button */


  if(digitalRead(buttonPin) == HIGH) // && !ButtonState)
  {
    number = random(1, 6);
    // number = random(ledCount);

    switch(number)
    {
      case 1:
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
      delay(ms);

    break;

      case 2:
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
      delay(ms);

    break;

            case 3:
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
      delay(ms);

    break;

            case 4:
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
      delay(ms);

    break;

          case 5:
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
      delay(ms);

    break;

      case 6:
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
      delay(ms);

    break;

    }

  delay(ms);

  }

  int randomLED = random(0, ledCount);

  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], LOW);

    if(!buttonState && !toggle)
  {
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[randomLED], LOW);
  }




  } 
  delay(ms);

  digitalWrite(leds[randomLED], HIGH);
  delay(ms);




  // digitalWrite(leds[randomLED], HIGH);
  // delay(ms);

  // if (!buttonState && lastButtonState) //if button went from HIGH to LOW
  // {
  //   fallToggle = !fallToggle; //flip fallToggle bool using NOT logic
  // }
  


}







