#include <Servo.h>
const int inputPin_1 = 2; // choose input pin (for Infrared sensor) 
const int inputPin_2 = 3; // choose input pin (for Infrared sensor)

const int inputPin_3 = 4; // choose input pin (for Infrared sensor)
const int inputPin_4 = 5; // choose input pin (for Infrared sensor)

 
Servo servo_1;
Servo servo_2;

void setup() {
  servo_1.attach(11);
  servo_1.write(0);
  servo_2.attach(10);
  servo_2.write(0);
  // declare LED as output 

  pinMode(inputPin_1, INPUT); // declare Infrared sensor as input
  pinMode(inputPin_2, INPUT); // declare Infrared sensor as input
  pinMode(inputPin_3, INPUT); // declare Infrared sensor as input
  pinMode(inputPin_4, INPUT); // declare Infrared sensor as input
}

void loop(){
  if((digitalRead(inputPin_1) == HIGH)&&(digitalRead(inputPin_2) == HIGH)&& (digitalRead(inputPin_3) == LOW)&&(digitalRead(inputPin_4) == LOW)){
    servo_1.write(90);
    delay(100);
    servo_2.write(90);
    delay(100);
  }
  if((digitalRead(inputPin_1) == LOW)&&(digitalRead(inputPin_2) == LOW)&& (digitalRead(inputPin_3) == HIGH)&&(digitalRead(inputPin_4) == HIGH)){
    servo_1.write(0);
    delay(100);
    servo_2.write(0);
    delay(100);
  }
}

