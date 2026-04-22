
const int adcPin_1 = 1;
const int buttonPin_1 = 4;
const int buttonPin_2 = 5;
const int buttonPin_3 = 6;

const int LED1 = 7;
const int LED2 = 15;
const int LED3 = 16;

byte val; // store byte received from serial port


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

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT); // set pin as output
  pinMode(LED3, OUTPUT); // set pin as output

  digitalWrite(LED1, 0);
  digitalWrite(LED2, 0);
  digitalWrite(LED3, 0);
    
  analogReadResolution(10); //set ADC from 0 to 1023 range 
  Serial.begin(9600); //open serial port at 9600bps 

}


void loop() 
{
  if(Serial.available()) //if serial buffer is greater than zero
  {
    val = Serial.read(); // read it and store it in val
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



      
  if (val == 0) 
  { // If 0 received
    digitalWrite(LED1, LOW); // LEDs 1, 2, 3 off
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

  }
  else if (val == 1) 
  { // If 1 received
    digitalWrite(LED1, LOW); // LED 1 off
    digitalWrite(LED2, HIGH); // LED 2 on
    digitalWrite(LED3, LOW); // LED 3 off


  }
  else if (val == 2) 
  { // If 2 received
    digitalWrite(LED2, LOW); // LED 2 off
    digitalWrite(LED2, LOW); // LED 2 off
    digitalWrite(LED3, HIGH); // LED 3 on

  }


    }

    else if(inByte == 'B') //if incoming byte is 'B'...
    {
      digitalWrite(LED1, 0);
      digitalWrite(LED2, 0);
      digitalWrite(LED3, 0);

      Serial.println("Sensor Update Paused..."); //Println means we're adding a new line after a \n printed data set.
      //using Serial.println adds a newline after each print, so no need for Serial.print('/n')

    }

    else //if incoming byte is neither 'A' nor 'B'...
    {
      digitalWrite(LED1, 0);  //turn LED OFF
      digitalWrite(LED2, 0);
      digitalWrite(LED3, 0);
      Serial.println("Rx Byte is neither 'A' nor 'B'"); //send status message
    }





  }


}












