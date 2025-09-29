const int sensor1 = 2;
const int sensor2 = 3;
const int sensor3 = 4;

const int LED =13;

const int red_1 = 22;
const int yellow_1 = 24;
const int green_1 = 26;

const int red_2 = 28;
const int yellow_2 = 30;
const int green_2 = 32;

const int red_3 = 34;
const int yellow_3 = 36;
const int green_3 = 38;
int value = 0;

void setup(){
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(red_1,OUTPUT);
  pinMode(yellow_1,OUTPUT);
  pinMode(green_1,OUTPUT);
  
  pinMode(red_2,OUTPUT);
  pinMode(yellow_2,OUTPUT);
  pinMode(green_2,OUTPUT);
  
  pinMode(red_3,OUTPUT);
  pinMode(yellow_3,OUTPUT);
  pinMode(green_3,OUTPUT);
  
  Serial.begin(9600); 
}
void loop(){
  digitalWrite(red_1,HIGH);
  digitalWrite(red_2,HIGH);
  digitalWrite(red_3,HIGH);
  delay(3000);
  traffic_1();
}

void traffic_1(){
  value = digitalRead(sensor1);
  if (value == 1)
  {
    digitalWrite(yellow_1,HIGH);
   digitalWrite(red_1,LOW);
   delay(1000);
   digitalWrite(yellow_1,LOW);
   digitalWrite(green_1,HIGH);
   delay(5000);
   digitalWrite(green_1,LOW);
   digitalWrite(red_1,HIGH);
  }

  if (value == 0){
    digitalWrite(yellow_1,HIGH);
   digitalWrite(red_1,LOW);
   delay(1000);
   digitalWrite(yellow_1,LOW);
   digitalWrite(green_1,HIGH);
   delay(10000);
   digitalWrite(green_1,LOW);
   digitalWrite(red_1,HIGH);
  }
  delay(3000);
  traffic_2();
}

void traffic_2(){
  value = digitalRead(sensor2);
  if (value == 1) 
 {
    digitalWrite(yellow_2,HIGH);
   digitalWrite(red_2,LOW);
   delay(2000);
   digitalWrite(yellow_2,LOW);
   digitalWrite(green_2,HIGH);
   delay(5000);
   digitalWrite(green_2,LOW);
   digitalWrite(red_2,HIGH);
  }

  if (value == 0){
    digitalWrite(yellow_2,HIGH);
   digitalWrite(red_2,LOW);
   delay(2000);
   digitalWrite(yellow_2,LOW);
   digitalWrite(green_2,HIGH);
   delay(10000);
   digitalWrite(green_2,LOW);
   digitalWrite(red_2,HIGH);
  }
  delay(3000);
  traffic_3();
}

void traffic_3(){
  value = digitalRead(sensor3);
  if (value == 1)
 {
    digitalWrite(yellow_3,HIGH);
   digitalWrite(red_3,LOW);
   delay(2000);
   digitalWrite(yellow_3,LOW);
   digitalWrite(green_3,HIGH);
   delay(5000);
   digitalWrite(green_3,LOW);
   digitalWrite(red_3,HIGH);
  }
  if (value == 0){
    digitalWrite(yellow_3,HIGH);
   digitalWrite(red_3,LOW);
   delay(2000);
   digitalWrite(yellow_3,LOW);
   digitalWrite(green_3,HIGH);
   delay(10000);
   digitalWrite(green_3,LOW);
   digitalWrite(red_3,HIGH);
  }
  delay(3000);
  traffic_1();
}
