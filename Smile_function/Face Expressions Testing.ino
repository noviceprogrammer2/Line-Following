#include <Servo.h>
Servo Rservo;  // create servo object to control the right servo
Servo Lservo;  // create servo object to control the left servo
// twelve servo objects can be created on most boards

//int pos = 0;    // variable to store the servo position

void setup() {
Serial.begin(9600);
  Rservo.attach(9);  // attaches the right servo on pin 9 to the servo object
  Lservo.attach(10); // attaches the left servo on pin 10 to the servo object

  Rservo.write(0); //set initial positions
  Lservo.write(180);
  Serial.println("initialized"); //print status
  delay(7000);         //wait 7 sec
}

void loop() {
  //for (pos = 0; pos <= 180; pos += 1) { // for condition: following line
    // in steps of 1 degree
    Rservo.write(60);              // tell servo to go from smiling to straight
    Lservo.write(120);
    Serial.println("straight");      //print status
    delay(5000);                     // waits 5 sec
  //}
  //for (pos = 180; pos >= 0; pos -= 1) { // for condition: reach end of track
    Rservo.write(0); //set initial positions
    Lservo.write(180);
    Serial.println("smile"); //print status
    delay(5000);         //wait 5 sec
}
