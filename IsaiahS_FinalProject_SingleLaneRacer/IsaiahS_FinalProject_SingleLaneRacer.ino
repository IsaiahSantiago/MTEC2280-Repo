/* isaiahS 5/16/26
FinalProject
-Keep Baud rate at 9600 not 115200
-Remember that a majority of the work is done in unity but to try your best at debugging because there's almost
too many problems with running both Arduino.IDE and the Serial Code monitor with unity at the same time.


*/



#define adcPin 1 //Accelerate 
#define buttonPin_1 4 //Turn Left
#define buttonPin_2 5 //Break
#define buttonPin_3 6 //Turn Right
#define buttonPin_4 7 //Reset Game Button

int inByte = 0;


//Button Variables
bool buttonState_1 = 0;
bool buttonState_2 = 0;
bool buttonState_3 = 0;
bool buttonState_4 = 0;

//Pot Variable
int adcRead = 0;


//Ref https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/ 
// int rawValue = analogRead(A0);           // Read from analog pin A0
// float scaledValue = rawValue / 1023.0;   // Divide by 1023.0 to get 0.0 to 1.0


//Software Timer Variables in case we need to change delay to  unity transition
int lastTime = 0;
int currentTime = 0;
int timerInterval = 5; //milliseconds



void setup() 
{

  // analogReadResolution(12); //default ADC resolution for ESP32 is 12-bit [range of 0-4095]
  analogReadResolution(10); //set adcRead to 10-bit (0-1023) range same as in out unity code 

  //Ok and now we set up our potentiometer Input
  pinMode(adcPin, INPUT);


  //we're using the Input Pullup method for the buttons
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);
  pinMode(buttonPin_4, INPUT_PULLUP);

  // potRead(adcPin_1, OUT);


  Serial.begin(9600);

}

void loop() 
{


  // Print a heartbeat and test if Arduino is communicating with Unity
    if (millis() > last_time + 2000)
    {
        Serial.println("Arduino is alive!!");
        last_time = millis();
    }

     // Send some message when I receive an 'A' or a 'Z'.
    switch (Serial.read())
    {
        case 'A':
            Serial.println("That's the first letter of the abecedarium.");
            break;
        case 'Z':
            Serial.println("That's the last letter of the abecedarium.");
            break;
    }





  //creating a set of boolean per input for storing current state of each button:
  bool buttonState_1 = digitalRead(buttonPin_1);  
  bool buttonState_2 = digitalRead(buttonPin_2);  
  bool buttonState_3 = digitalRead(buttonPin_3);  
  bool buttonState_4 = digitalRead(buttonPin_4);  

  //Read the Analog Pot value
  adcRead = analogRead(adcPin);

 //[NOTE that the 'logic' for the buttons is inverted due to Pullup config] therefore we need to read button states for each of the pins 
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);
  buttonState_3 = !digitalRead(buttonPin_3);
  buttonState_4 = !digitalRead(buttonPin_4);

  // Serial.println(buttonState);  //print state of buttons


 currentTime = millis();  //read the current ongoing time in milliseconds 
  if (currentTime - lastTime >= timerInterval)  //So now if we have reached our timer interval or past it we will then:
  {
    lastTime = currentTime;  // We know when timer last triggered because of storing (currentTime as lastTime)

    /*
    Originally this block of code was meant Send Data to P5.JS Sketch via Serial UART in our dev modules using print()
    and Comma Separation but now it may be able to connect to our unity scripts and game from here therefore Unity
    will read and print these values in its console instead if my theory is correct.s
    */
    Serial.print(buttonState_1);  //send 1st message
    Serial.print(',');            //send comma character
    Serial.print(buttonState_2);  //send 2nd message
    Serial.print(',');            //send comma character
    Serial.print(buttonState_3);      //send 3rd message
    Serial.print(',');            //send comma character
    Serial.print(adcRead);      //send 4th message
    Serial.print('\n');           //send "Line Feed", or "New Line" character, or use println() instead.

  }

}












