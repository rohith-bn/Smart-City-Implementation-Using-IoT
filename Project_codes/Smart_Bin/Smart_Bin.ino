

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;



// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
  
// utlrasonic pinout
#define ULTRASONIC_TRIG_PIN     D1   // pin TRIG 
#define ULTRASONIC_ECHO_PIN     D2 // pin ECHO

char auth[] = "ad332939060c468fa507945a413fd2b7";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "roh";
char pass[] = "guru1997";
int ultra;

WidgetLCD lcd(V1);

void setup(){
  // initialize LCD

  // ultraonic setup 
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  Blynk.begin(auth, ssid, pass);
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm");
}

void loop(){
  lcd.clear();
  lcd.print(0, 0, "Distance in cm");
  long duration, distance;
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  // set cursor to first column, first row
 ultra = distance;
  if( ultra == 3 ){
    Blynk.notify("road 2 Garbage full");
    delay(1000);
  }
 
  // print message
  Serial.print(distance);
  
  // clears the display to print new message
Serial.println("Cm");
  // set cursor to first column, second row
  lcd.print(7, 1, distance);
  Blynk.run();
}

 
