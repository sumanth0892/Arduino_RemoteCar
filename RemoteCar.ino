#include <Servo.h>

#include <IRremote.h>

const int irReceivePin = 2; //This pin is connected to IR detector output
Irrecv irrecv(irReceivePin); //Create the IR library
decode_results results; //IR results stored here

const int rightMotorPin = 9;
const int leftMotorPin = 10;

Servo rightServo;
Servo leftServo;
int rightSpeed=90;
int leftSpeed=90;

long keyCode=0;

void setup() {
Serial.begin(9600); //Start communication
irrecv.enableIRIn(); //This starts the IR Receiver  
leftServo.attach(9);
rightServo.attach(10);
pinMode(rightMotorPin,OUTPUT);
pinMode(leftMotorPin,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)){
    showReceivedData();
    irrecv.resume(); //Receive the next value
  
  keyCode=results.value;
  if (keycode!=1)
  {
    switch (keyCode) {
      case 'a':
      Serial.println ("Forward"); //Start moving forward
      leftSpeed-=1;
      rightSpeed+=1;
      break;

      case 'b':
      Serial.println ("Backward"); //Opposite values propel backwards
      leftSpeed+=1;
      rightSpeed-=1;
      break;

      case 'c':
      Serial.println ("Stop!"); //A Value of 90 stops the servo motors
      leftSpeed=90;
      rightSpeed=90;
      break;

      case 'd':
      Serial.println ("Turn Left");
      leftSpeed-=1; //Wheels start to move in opposite directions 
      rightSpeed+=1;
      break;

      case 'e':
      Serial.println ("Turn Right"); //Wheels move in opposite directions
      leftSpeed-=1;
      rightSpeed+=1;
      break;

      case 'f':
      Serial.println ("TURBO!");
      leftSpeed=leftSpeed-50;
      rightSpeed=rightSpeed+50;
      break;
    }
    }
  }
  updateMotors();
  delay(250);
}

void showReceivedData()
{
  if (results.decode_type==UNKNOWN)
  {
    Serial.println("Could not decode message");
  }
  else {
    if (results.decode_type==NEC){
      Serial.print("- decoded NEC: ");}
      
      else if (results.decode_type==SONY){
        Serial.print("- decoded SONY: ");}

        else if (results.decode_type==RC5){
        Serial.print("- decoded RC5: ");}

        else if (results.decode_type==RC6){
        Serial.print("- decoded RC6: ");}
        Serial.print("Value = ");
        Serial.println(results.value,DEC);
}
  }

void updateMotors(){
  leftServo.write(leftSpeed);
  rightServo.write(rightSpeed);
}

