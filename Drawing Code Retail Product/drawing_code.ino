
/* 

Code for team 4-7 Line-Following Robot Mr. Line Retail Product 

Group includes Aidan Guenther, Peter Bast, and Brian Simons 

A few functions and pin setups were created with the help of 
the ardumoto setupcode on Sparkfun (https://learn.sparkfun.com/tutorials/ardumoto-kit-hookup-guide/all)

Navigation loop structure contains four conditions that are continously monitored for:
stopping, straight, left, and right.

Robot starts track with a straight face, travels the line, stops, and then smiles  

Mr. Line stops at finish line when all three sensors see black 

*/

// Initialize variables, 

//servo initialization
#include <Servo.h>
Servo Rservo;  // create servo object to control the right servo
Servo Lservo;  // create servo object to control the left servo

//sets IR variables equal to analog 4 and analog 5 
int phototransA0 = A0; /* left sensor A0 */
int phototransA1 =  A1; /* middle sensor A1 */
int phototransA2 = A2; /* right sensor A2 */

// creates variables for left, middle, and right IR sensors.
int left_sensor_value;
int middle_sensor_value;
int right_sensor_value; 


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
    Rservo.attach(10);  // attaches the right servo on pin 13 to the servo object
    Lservo.attach(9); // attaches the left servo on pin 12 to the servo object

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
 


// Straightline code

  if(left_sensor_value <100 && right_sensor_value <100 && middle_sensor_value >100)
  {
    driveArdumoto(MOTOR_B, FORWARD, 120);
    driveArdumoto(MOTOR_A, FORWARD, 120);
      
   }

  // Right sensor detects black, robot turns right
  
  if (right_sensor_value > 150)
  {
    driveArdumoto(MOTOR_A, FORWARD, 120);
    driveArdumoto(MOTOR_B, REVERSE, 60);
    
    }
   
  // Left sensor detects black, robot turns left
  
  if (left_sensor_value > 150)
   {
    driveArdumoto(MOTOR_A, REVERSE, 60);
    driveArdumoto(MOTOR_B, FORWARD, 120);
    
   }

    //Stopping code 
    //all three sensors see black at finish line 
  if(left_sensor_value >200 && right_sensor_value >200 && middle_sensor_value >200)
  {
    stopArdumoto(MOTOR_A);
    stopArdumoto(MOTOR_B);
    Rservo.write(60);              // tell servo to go from smiling to straight
    Lservo.write(120);
    delay(2000);
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
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
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