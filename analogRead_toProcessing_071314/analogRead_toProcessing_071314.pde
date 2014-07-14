/*
The Vulvatron - serial reading test
 Code adapted from Tom Igoe, Making Things Talk 
 
 Julia Irwin
 07/13/14
 */

///Make sure the arduino code has been uploaded to your board
///and that you quit out of the Arduino program

import processing.serial.*;

Serial myPort;
String resultString;   

void setup() {
  size(480, 130);
  println(Serial.list());    //list all the available serial ports
  
//get the name of your port from the serial list and change the number inside the []
//to the serial port to which your microcontroller is attached

String portName = Serial.list()[4];
//open the serial port;
myPort = new Serial(this, portName, 9600);

//read bytes into a buffer until you get a linefeed (ASCII 10):
myPort.bufferUntil('\n');
}

void draw() {
  background(#044f6f);
  fill(#ffffff);

  if (resultString != null) {
    text(resultString, 10, height/2);
  }
}

void serialEvent(Serial myPort) {
  //read the serial buffer:
  String inputString = myPort.readStringUntil('\n'); 

  //trim the carriage return and linefeed from the input string:
  inputString = trim(inputString);
  //clear the resultString:
  resultString = "";

  //split the input string at the commas and convert sections into integers:
  //int sensor = int(split(inputString, ','));

  String sensor = inputString;

  //add the values to the result string:
  resultString += "LED value: " + sensor;
  //resultString += sensor + "\t";

  //print the results to the console:
  println(resultString);
}

