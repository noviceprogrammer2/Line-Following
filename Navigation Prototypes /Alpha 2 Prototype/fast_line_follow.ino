

/* 
Utilizing Ardumoto example code for the setupArdumoto and stopArdumoto functions as well as ardumoto pin assignments
void Loop structure and setupIR function are both my creation 
*/
// Initialize variables, 

//sets IR variables equal to analog 4 and analog 5 
int phototransA0 = A0; /* left sensor A0 */
int phototransA1 =  A1; /* middle sensor A1 */
int phototransA2 = A2; /* right sensor A2 */

// creates left_sensor_value, middle_sensor_value, and right_sensor_value to be used in loop statement
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

}

void loop()
{

  // sets left sensor and right sensor values equal to analog inputs from the phototrans variables (left sensor is in A4 slot, right sensor in A5)
  left_sensor_value = analogRead(phototransA0);
  middle_sensor_value = analogRead(phototransA1);
  right_sensor_value = analogRead(phototransA2);


//Straightline code

  if(left_sensor_value <75 && right_sensor_value <75 && middle_sensor_value >75)
  {
    driveArdumoto(MOTOR_B, FORWARD, 150);
    driveArdumoto(MOTOR_A, FORWARD, 150);
      
   }

// Right detects black code 
  
  if (right_sensor_value > 75)
  {
    driveArdumoto(MOTOR_A, FORWARD, 150);
    driveArdumoto(MOTOR_B, FORWARD, 0);
    
    }
   
//Left detects black code 
  
  if (left_sensor_value > 75)
   {
    driveArdumoto(MOTOR_A, FORWARD, 0);
    driveArdumoto(MOTOR_B, FORWARD, 150);
    
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
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

void setupIR()
{

pinMode(phototransA0, INPUT);
pinMode(phototransA1, INPUT);
pinMode(phototransA2, INPUT);

}
