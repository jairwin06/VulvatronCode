

int analogValue = analogRead(A0);   //read voltage value from pin A0

const int led = 5;      //the LED goes in to Pin 5 on the arduino (or any PWM pin)
int brightness = 0;     //variable for writing the brightness value to the LED
int sensorVal = 0;      //variable for reading the values coming in from the sensor (0-1023)

void setup() {
  Serial.begin(9600);  //set the baud rate to 9600 bits/second

  pinMode(led, OUTPUT);   //sets pin 5 as an output
}

void loop() {

  //FIRST TEST THE VOLTAGE//
  /* 
  comment out the rest of the code below when running this
  can use this to test how much resistance to add to the circuit; can also test with multimeter
  
  sensorVal = analogRead(analogValue);
  float voltage = sensorVal * (5.0/1023.0);
  Serial.println(voltage);
  */

  sensorVal = analogRead(analogValue);
  //  Serial.println(sensorVal);    //will print between 0 and 1023;
  //the readings I was getting were between ~187 (~0.9 volts) and 1023 (5 volts)

  brightness = map(sensorVal, 180, 1023, 0, 255);   //I had this start at 180, which was the lowest reading I was getting
  Serial.println(brightness);       //will print between 0 and 255;

  analogWrite(led, brightness);    //dim the LED according to the sensor value
}
