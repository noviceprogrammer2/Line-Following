

/* 
Utilizing Ardumoto example code for the setupArdumoto and stopArdumoto functions as well as ardumoto pin assignments

void Loop structure and setupIR function are both my creation 
*/
// Initialize variables, 

//sets IR variables equal to analog 4 and analog 5 
int phototransA4 = A4;
int phototransA5 = A5;

// creates left_sensor_value and right_sensor_value to be used in loop statement
int left_sensor_value;
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

  // sets left sensor and right sensor values equal to analog inputs from the phototrans variables (left sensor is in A4 slot, right sensro in A5)
  left_sensor_value = analogRead(phototransA4);
  right_sensor_value = analogRead(phototransA5);


//Straightline code

  if (left_sensor_value < 30 && right_sensor_value < 30)
  {
    driveArdumoto(MOTOR_B, FORWARD, 127.5);
    driveArdumoto(MOTOR_A, FORWARD, 127.5);
    delay(1000); //drives straight for a bit then delays 
    stopArdumoto(MOTOR_B);
    stopArdumoto(MOTOR_A);
      
   }

// Right detects black code 
  
  if (right_sensor_value > 30 && left_sensor_value < 30)
  {
    driveArdumoto(MOTOR_B, FORWARD, 127.5);
    delay(1000);
    stopArdumoto(MOTOR_B);
    }
   
//Left detects black code 
  
  if (left_sensor_value > 30 && right_sensor_value <30 )
   {
    driveArdumoto(MOTOR_A, FORWARD, 127.5);
    delay (1000);
    stopArdumoto(MOTOR_A);
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

pinMode(phototransA4, INPUT);

pinMode(phototransA5, INPUT);

}
