/* 

Code for team 4-7 Line-Following Robot Outdoor Track

Group includes Aidan Guenther, Peter Bast, and Brian Simons 

A few functions and pin setups were created with the help of 
the ardumoto setupcode on Sparkfun (https://learn.sparkfun.com/tutorials/ardumoto-kit-hookup-guide/all)

Navigation loop structure contains four conditions that are continously monitored for:
stopping, straight, left, and right.

Robot starts track with a straight face, travels the line, stops, and then smiles  

Through the use of two timer variables, robot is able to continously monitor for tracks that end and stop accordingly 

*/

// Initialize variables 

//servo initialization
#include <Servo.h>
Servo Rservo;  
Servo Lservo;  

int phototransA0 = A0; /* left sensor A0 */
int phototransA1 =  A1; /* middle sensor A1 */
int phototransA2 = A2; /* right sensor A2 */

// creates variables for left, middle, and right IR sensors.
int left_sensor_value;
int middle_sensor_value;
int right_sensor_value; 

unsigned long time1;
unsigned long time2;

// Clockwise and counter-clockwise definitions for motors.

#define FORWARD  0
#define REVERSE 1

// Motor definitions
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
//Default pins:
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B



void setup()
{
  
  setupArdumoto(); // Sets motor pins as outputs
  setupIR(); //setups pins for IR as inputs 

  Serial.begin(9600);
  
  // setting servos to appropriate pins
  Rservo.attach(10);   
  Lservo.attach(9); 
  
  // assigning servos to default straight face position 
  Rservo.write(0); 
  Lservo.write(180);

}

void loop()
{

  // sets left, middle, and right sensors to proper analog values for readings
  left_sensor_value = analogRead(phototransA0);
  middle_sensor_value = analogRead(phototransA1);
  right_sensor_value = analogRead(phototransA2);
    
  //initialiazes timer that runs while robot is navigating track
  time1 = millis();

  //straight line navigation  
  if(left_sensor_value <120 && right_sensor_value <120 && middle_sensor_value >120)  ]
  {
    time2 = millis();
    driveArdumoto(MOTOR_B, FORWARD, 250);
    driveArdumoto(MOTOR_A, FORWARD, 250);
        
  }

  // Right sensor detects black, robot turns right
  if(right_sensor_value > 150){
    time2 = millis();
    driveArdumoto(MOTOR_A, FORWARD, 250);
    driveArdumoto(MOTOR_B, REVERSE, 100 );
    }
  
  // Left sensor detects black, robot turns left
  if (left_sensor_value > 150)
   {
    time2 = millis();
    driveArdumoto(MOTOR_A, REVERSE, 100);
    driveArdumoto(MOTOR_B, FORWARD, 250);
    
   }
  
  //Automated robot stopping for the robot 
  if(left_sensor_value <200 && right_sensor_value <200 && middle_sensor_value <200) //initial condition if all three sensors see white
  { 
    if (time1 - time2 >= 300) //if the difference between the timer for the track and the timer for the last action (turn, or traveling straight) is greater than value
    {
      //stops both motors 
      stopArdumoto(MOTOR_A);
      stopArdumoto(MOTOR_B);
      
      //sets servos to smile once robot is stopped 
      Rservo.write(60);               
      Lservo.write(120);
      //exits the program 
      exit(0);
    }
  } 
}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}
// setupArdumoto initialize all pins
void setupArdumoto()
{
  // All pins are set as outputs 
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // all pins are initially set to low 
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

//creates motor stopping function for robot 
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

//setup IR sensors function to map sensors 
void setupIR()
{

  pinMode(phototransA0, INPUT);
  pinMode(phototransA1, INPUT);
  pinMode(phototransA2, INPUT);

}
