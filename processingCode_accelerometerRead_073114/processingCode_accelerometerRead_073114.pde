
import processing.serial.*;     // import the Processing serial library
Serial myPort;                  // The serial port

void setup() {
  // List all the available serial ports
  println(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  Arduino module, so I open Serial.list()[0].
  // Change the 0 to the appropriate number of the serial port
  // that your microcontroller is attached to.
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
}

void serialEvent(Serial myPort) {
  String myString = myPort.readStringUntil('\n');
  if (myString != null) {
    myString = trim(myString);
    int sensors[] = int(split(myString, ','));
    for(int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
     print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t"); 
    }
    println();
  }
}

