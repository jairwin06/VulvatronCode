
int switchPin = 2;
int leftFSR_thresh = 700;
int centerRFSR_thresh = 500; 
int rightFSR_thresh = 300;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  establishContact();
}

void loop() {

  if (Serial.available() > 0){
    int inByte = Serial.read();

    // read the sensor:
    int leftFSR = analogRead(A0);
    int centerFSR = analogRead(A1);
    int rightFSR = analogRead(A2);

    // print the results:
    //Serial.print(lefFSR);

    if (leftFSR >= leftFSR_thresh){
      leftFSR = 1;
    }

    else if (leftFSR < leftFSR_thresh) {
      leftFSR = 0;
    }

    if (centerFSR >= centerRFSR_thresh){
      centerFSR = 1;
    }

    else if (centerFSR < centerRFSR_thresh) {
      centerFSR = 0; 
    }

    if (rightFSR >= rightFSR_thresh){
      rightFSR = 1;
    }

    else if (rightFSR < rightFSR_thresh) {
      rightFSR = 0; 
    }

    Serial.print(leftFSR);
    Serial.print(",");
    Serial.print(centerFSR);
    Serial.print(",");
    Serial.println(rightFSR);

    // delay(300);

  }
}

void establishContact(){
  while(Serial.available() <= 0) {
    Serial.println("nothing");
    delay(300);
  } 
}



