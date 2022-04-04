int phototransL = A0 ;// the analog input pin
int phototransM = A1 ;// the analog input pin
int phototransR = A2 ;// the analog input pin
// decrlaring variables to store the input values
int Lval =0;
int Mval =0;
int Rval =0;
// the setup routine runs once when you press reset :
void setup() {
  // set input pins
pinMode ( phototransL , INPUT ) ;
pinMode ( phototransM , INPUT ) ;
pinMode ( phototransR , INPUT ) ;
// initialize serial port
Serial . begin (9600) ;
}

void loop() {
  // read the input values from the digital and analog pins
Lval = analogRead ( phototransL ) ;
Mval = analogRead ( phototransM ) ;
Rval = analogRead ( phototransR ) ;
 // publish the analog value to the serial port
 Serial.print(Lval) ;
 Serial.print(" , ");
 Serial.print(Mval);
 Serial.print(" , ");
 Serial.println(Rval);
 delay (1000) ; // wait for a second
}
