int phototransD1 = 1;
int phototransD2 = 2; 
int phototransA4 = A4;
int phototransA5 = A5;

int val = 0;
int aval=0;
int val2 = 0;
int aval2 = 0;
void setup() {
  // put your setup code here, to run once:
//setting input pins
pinMode(phototransD1, INPUT);
pinMode(phototransA4, INPUT);
pinMode(phototransD2, INPUT);
pinMode(phototransA5, INPUT);

//initialize serial port
Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(phototransD1);
aval= analogRead(phototransA4);
val2 = digitalRead(phototransD2);
aval2= analogRead(phototransA5);


Serial.println(aval2);
delay(250);

}
