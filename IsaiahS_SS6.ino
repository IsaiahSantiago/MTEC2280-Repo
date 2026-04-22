
const int adcPin_1 = 1;
const int buttonPin_1 = 4;
const int buttonPin_2 = 5;
const int buttonPin_3 = 6;

const int ledPin = 7;
const int ledPin = 8;
const int ledPin = 9;



bool buttonState_1 = 0;
bool buttonState_2 = 0;
bool buttonState_3 = 0;


int adcRead_1 = 0;
int inByte = 0;



void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  analogReadResolution(10); //set ADC from 0 to 1023 range 
  Serial.begin(9600); //open serial port at 9600bps 

}


void loop() 
{
  if(Serial.available()) //if serial buffer is greater than zero
  {
    inByte = Serial.read(); //Store incoming byte
    if(inByte == 'A')
    {
      digitalWrite(ledPin, 1);
      adcRead_1 = analogRead(adcPin_1); //read pot 1
      buttonState_1 = !digitalRead(buttonPin_1);
      buttonState_2 = !digitalRead(buttonPin_2);
      buttonState_3 = !digitalRead(buttonPin_3);

      //Send sensor data
      Serial.print(buttonState_1);
      Serial.print(',');
      Serial.print(buttonState_2);
      Serial.print(',');
      Serial.print(buttonState_3);
      Serial.print(',');
      Serial.print(adcRead_1);
      Serial.print('\n');


    }

    else if(inByte == 'B') //if incoming byte is 'B'...
    {
      digitalWrite(ledPin, 0);
      Serial.println("Sensor Update Paused..."); //Println means we're adding a new line after a \n printed data set.
      //using Serial.println adds a newline after each print, so no need for Serial.print('/n')

    }

    else //if incoming byte is neither 'A' nor 'B'...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Rx Byte is neither 'A' nor 'B'"); //send status message
    }





  }


}












