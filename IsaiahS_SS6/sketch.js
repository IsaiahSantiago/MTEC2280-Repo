/*
SHORT SKETCH #6: DUE 4/22
Create a software p5.js sketch and arduino sketch that implements Serial Handshaking (Call & Response). 
You may use any combination of sensors and actuators, but they should be controlled (or control) via serial. 
This assignment is more open-ended, as we have now learned to communicate in both directions in the same project! 
The content and approach are completely up to you, but it needs to implement serial handshaking.

Must Include:

use of at least 2 hardware actuators controlled by interaction with your P5 sketch,
or at least 2 sensors controlling some aspect of your P5 sketch.
at least 2 different modes of behavior: for example, our "P5_Serial_Servo" sketch has a "sweep" mode and a "follow" mode.
at least three graphics primitives.
dynamic elements in your P5 sketch (don't just draw a static canvas, animate something!).
display window width: max of 1080, min of 400
display window height: max of 720, min of 400
Upload your completed code (both arduino & p5.js) to your repo before the beginnning of next class session.
Remember, the arduino .ino file must go in folder of same name, and the p5.js project must include its entire project folder and it contents.
Have your project (both hardware and software aspects) ready to present at the next class critique.


References:
https://github.com/IsaiahSantiago/MTEC2280-Repo/blob/master/IsaiahS_SS5/sketch.js


*/


//For connecting with Serial monitor operations and my computer port 
let serial;
let portName = 'COM10';
let options = {baudRate: 9600};
let outByte = 0;  // 8-bit data to sends to microcontroller ESP32S3 Dev module via Serial port


//Remember this is how we know we're sending data to the microcontroller board when we input A or B, 
// making the conversation between P5JS and Arduino start =>
let rxFlag = false; // flag to indicate when new data has been received
let firstContact = false; // flag to indicate when the first contact has been made with the serial port

//Sensors = Buttons and Potentiometer
let sensors = [0, 0, 0, 0]; // declare array to hold incoming sensor data, and initialize with zeros
let pot1 = 0; // variable to hold potentiometer value
let button1 = 0; // variable to hold 1st button value
let button2 = 0; // variable to hold 2nd button value
let button3 = 0; // variable to hold 3rd button value






function setup() 
{
  createCanvas(720, 400);
  strokeWeight(4);
  stroke(127);//Helps to seperate shape from the background in testing


//Necessary Serial port Setup Block
  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port

  // serial.println(rxFlag); //To make sure we're sending data to the ESP32 Dev module with this code

}


function draw() 
{
  background(0,150,220);

//> Hey try making it so you have to click on a specific part of the page like the Serial LED code from before <

//Starting screen that listens for mouse click:
  
  if (!firstContact)  //if we have not yet received any data...
  {
    //display a waiting page 
    background(0, 0, 127);
    fill(255);
    stroke(1);
    textSize(15);
    text("Thanks for participating, to start", width/3 + 35, height/4 - 20);
    text("simply click the Circle to Begin", width/3 + 35, height/3 -15);
    circle(width/2, height/2, 140);
    noStroke();
    fill(0);
    text("START RX", width/2 - 40, height/2);
    text("SS6 Test", width/2 - 40, height/2 + 15);


  }


//The actual Graphic / True interaction page:
  else 
  {
    //potentiometer indicator outline
    fill(pot1);
    rect(width/8, height/4, 60, 255);
    
    //potentiometer indicator
    fill(0, pot1, 0);
    rect(width/8, height/4, 60, pot1);

    // //draw rectangular areas
    // fill(200);
    // rect(0, width/2, width, height);
    // fill(255, 255, 0);
    // rect(0, 0, width/2, height);
    // //fill(0, 255, 0);
    // //rect(width/2, 0, width/2, height/2);


    //button indicators 
    fill(button1, 0, 0);
    rect(width/2 - 100, height/4, 50, 50);
    fill(0, button2, 0);
    rect(width/2 - 20, height/4, 50, 50);
    fill(0, 0, button3);
    rect(width/2 + 60, height/4, 50, 50);

    //pause button
    fill(200);
    circle(width/2, height/2 + 30, 140);


    // if rxFlag is true, we are receiving data, so...
    if (rxFlag) 
    {
      fill(0);
      noStroke();
      text("PAUSE RX", width/2 - 40, height/2 + 35);  // display "PAUSE RX" on the button
    }
    else  //if rxFlag is false, we are not receiving data, so...
    {
      fill(255, 0, 0 );
      noStroke();
      text("PAUSED", width/2 - 35, height/2 + 20);  //display "PAUSED" on the button
    }

  }


}



//Lets establish some interactive measures using the mouse if it is left-clicked
  function mousePressed() 
  {
  // if mouse postion is within the radius of the starting soon screen button then activate...

    if(dist(mouseX, mouseY, width/2, height/2) < 70) 
      {
        rxFlag = !rxFlag; // toggle the rxFlag to essentially turn on sending data to the microcontroller
        if(rxFlag)
          {
            serial.write("A"); // send 'A' to the serial port to indicate that we want to receive data
          }
        else
          {
            serial.write("B"); //if rxFlag is false, we want to pause receiving data, so...
          }
      }
    }


    
function mouseIsPressed() 
{
  //check mouse position when mouse is clicked
    if (dist(mouseX, mouseY, width, height) < 170)
  {
    outByte = 0;
  }
  else if (mouseX < width/2 - 100 && mouseX > 0 && mouseY < height/4) // top left quadrant
  {
    outByte = 1;
  }
  else if (mouseX > width/2 - 20 && mouseX < width && mouseY < height/4) // top right quadrant
  {
    outByte = 2;
  }
    else if (width/2 + 60 && mouseX < width && mouseY < height/4) // top right quadrant
  {
    outByte = 3;
  }
  else  // default case
  {
    outByte = 0;
  }


  serial.write(outByte); //send outByte across serial port
}



//==========================================


function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}

function portClose() //gets called when the serial port closes
{
  print("SERIAL PORT CLOSED");
}

function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serialEvent() // gets called when new serial data arrives
{
  if (!firstContact)  //if we have not yet received any data, this is our first contact with the serial port, so...
  {
    print("FIRST CONTACT"); //print "FIRST CONTACT" to the console
    firstContact = true;  //set firstContact flag to true
  }
  
if(rxFlag)  //if rxFlag is true, we want to receive data, so...
  {
    let inString = serial.readStringUntil('\n'); // read the incoming string until you get a newline character
    if (inString.length > 0) 
    {
      print("Rx String: " + inString); // print the incoming string to the console
      sensors = split(inString, ','); // split the string into an array of sensor values
    
      if(sensors.length >= 4) // check if we have all 4 sensor values before trying to access them
      {
        print(sensors); // print the array of sensor values to the console

        button1 = Number(sensors[0]); // convert the first sensor value to an integer
        button1 = map(button1, 0, 1, 0, 255); // map the button value from boolean true/false to 0-255

        button2 = Number(sensors[1]); // convert the second sensor value to an integer
        button2 = map(button2, 0, 1, 0, 255); // map the button value from boolean true/false to 0-255
        
        button3 = Number(sensors[2]); // convert the second sensor value to an integer
        button3 = map(button3, 0, 1, 0, 255); // map the button value from boolean true/false to 0-255
        

        pot1 = Number(sensors[3]); // convert the third sensor value to an integer
        pot1 = map(pot1, 0, 1023, 0, 255); // map the potentiometer value from 0-1023 to 0-255
        pot1 = floor(pot1); // round the potentiometer value to an integer

        // pot2 = Number(sensors[3]); // convert the fourth sensor value to an integer
        // pot2 = map(pot2, 0, 1023, 0, 255); // map the potentiometer value from 0-1023 to 0-255
        // pot2 = floor(pot2); // round the potentiometer value to an integer

        
        print("Button 1: " + button1 + " Button 2: " + button2 + " Button 3: " + button3 + " Pot 1: " + pot1);  //print mapped sensor values to the console

        //now that we're done processing the incoming data, we can "call out" to our microcontroller, which respond with latest sensor data.
        serial.write('A');  // send 'A' to the serial port to indicate that we want the latest sensor data
      }
    }
  }
  else
  {
    let inString = serial.readStringUntil('\n'); // read the incoming string until you get a newline character
    print(inString); // print the incoming string to the console
  }
}

function serialError(err) //gets called when there's an error
{
  print('SERIAL ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERIAL SERVER");
}









