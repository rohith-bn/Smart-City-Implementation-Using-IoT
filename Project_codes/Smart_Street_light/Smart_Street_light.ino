/*
 * Interface InfraRed Sensor Using NodeMCU
 * By TheCircuit
 * Red :     5V
 * Brown: Sensor output
 * Black : Ground
*/

const int ledPin_1 = 6; // choose pin for the LED
const int ledPin_2 = 9; // choose pin for the LED
const int ledPin_3 = 10; // choose pin for the LED
const int ledPin_4 = 11; // choose pin for the LED
const int inputPin_1 = 2; // choose input pin (for Infrared sensor) 
const int inputPin_2 = 3; // choose input pin (for Infrared sensor)
const int inputPin_3 = 4; // choose input pin (for Infrared sensor)
const int inputPin_4 = 5; // choose input pin (for Infrared sensor)
const int ldrpin = 7;
int val_1 = 0; // variable for reading the pin status
int val_2 = 0; // variable for reading the pin status 
int val_3 = 0; // variable for reading the pin status 
int val_4 = 0; // variable for reading the pin status 

int time1 = 1 ;
int time2 = 1 ;
int time3 = 1 ;
int time4 = 1 ;
int time1n = 0 ;
int time2n = 0 ;
int time3n = 0 ;
int time4n = 0 ;
void setup() 
{ 

   pinMode(ledPin_1, OUTPUT); // declare LED as output 
    pinMode(ledPin_2, OUTPUT); // declare LED as output
     pinMode(ledPin_3, OUTPUT); // declare LED as output
      pinMode(ledPin_4, OUTPUT); // declare LED as output
   pinMode(inputPin_1, INPUT); // declare Infrared sensor as input
    pinMode(inputPin_2, INPUT); // declare Infrared sensor as input
     pinMode(inputPin_3, INPUT); // declare Infrared sensor as input
      pinMode(inputPin_4, INPUT); // declare Infrared sensor as input
      pinMode(ldrpin,INPUT);
} 
void loop()
{ 
  if(digitalRead(ldrpin) == HIGH){
   val_1 = digitalRead(inputPin_1); // read input value 
   val_2 = digitalRead(inputPin_2); // read input value
   val_3 = digitalRead(inputPin_3); // read input value
   val_4 = digitalRead(inputPin_4); // read input value
   
   if (val_1 == HIGH && (time1 = millis()) > time1n)
   { // check if the input is HIGH
      analogWrite(ledPin_2, 5); // turn LED OFF  
   } 
   if(val_1 == LOW)
   { 
      analogWrite(ledPin_2, 250); // turn LED ON
      time1 = millis();
      time1n =time1+3000;
   } 
     if (val_2 == HIGH && (time2 = millis()) > time2n)
   { // check if the input is HIGH
      analogWrite(ledPin_3, 5); // turn LED OFF  
   } 
   if(val_2 == LOW)
   { 
    time2 = millis();
      time2n =time2+3000;
      analogWrite(ledPin_3, 250); // turn LED ON
      
   } 
     if (val_3 == HIGH && (time3 = millis()) > time3n)
   { // check if the input is HIGH
      analogWrite(ledPin_4, 5); // turn LED OFF  
   } 
   if(val_3 == LOW)
   { 
      analogWrite(ledPin_4, 250); // turn LED ON
      time3 = millis();
      time3n =time3+3000;
   } 
     if (val_4 == HIGH && (time4 = millis()) > time4n)
   { // check if the input is HIGH
      analogWrite(ledPin_1, 5); // turn LED OFF  
   } 
   if(val_4 == LOW)
   { 
      analogWrite(ledPin_1, 250); // turn LED ON
      time4 = millis();
      time4n =time4+3000;
   } 
  }

  if(digitalRead(ldrpin) == LOW){
   analogWrite(ledPin_1, 0); 
   analogWrite(ledPin_2, 0);
   analogWrite(ledPin_3, 0);
   analogWrite(ledPin_4, 0);
  }
}
