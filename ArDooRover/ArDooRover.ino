/*
ArDooRover
https://github.com/doothings/ardurover

*/
#include <IRremote.h>

int RECV_PIN = 15;

//Arduino Pin   //IC PIN  
/*Left Motor*/
int in1Pin = 2; //2 RED
int in2Pin = 3; //3 BLACK
/*Right Motor*/
int in3Pin = 4; //4 RED
int in4Pin = 5; //5 BLACK


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  flushValues();
}

void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value)
    {
       case 752 : //up
         moveForward();
         break;
       case 2800 : //down
         moveBackward();
         break;

       case 3280 : //right
         turnRight();
         break;
 
       case 720  : //left
         turnLeft();
         break;
         
       case 2672  : //stop
         flushValues();
         break;  

    }
      
      delay(500);
      //flushValues();
      irrecv.resume(); // Receive the next value
  }
}


void moveForward()
{
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  
}

void moveBackward()
{
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
}

void turnLeft()
{
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
}

void turnRight()
{
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
}

void flushValues()
{
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin,LOW);
}
