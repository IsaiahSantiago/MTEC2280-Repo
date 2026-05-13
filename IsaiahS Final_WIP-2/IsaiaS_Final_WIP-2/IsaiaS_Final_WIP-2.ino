/* isaiahS 5/10/26
Final_WIP-2
-Keep Baud rate at 115200
-Remember that a majority of the work is done in unity  


*/



#define adcPin_1 1 //Accelerate 
#define buttonPin_1 4 //Turn Left
#define buttonPin_2 5 //Break
#define buttonPin_3 6 //Turn Right
#define buttonPin_4 7 //Reset Game Button

void setup() 
{

  analogReadResolution(12); //Reading 1 - 4026 bit value for Potentiometer


  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);
  pinMode(buttonPin_4, INPUT_PULLUP);

  potRead(adcPin_1, OUT);


  Serial.begin(115200);

}

void loop() 
{

  //creating a set of boolean per input for storing current state of each button:
  bool buttonState = digitalRead(buttonPin_1);  
  bool buttonState = digitalRead(buttonPin_2);  
  bool buttonState = digitalRead(buttonPin_3);  
  bool buttonState = digitalRead(buttonPin_4);  





  Serial.println(buttonState);  //print state of buttons




}












