const int GasPin = D1;
const int FirePin = D2;
// D0 is set for button
const int servooff = D4;
const int water_pos = D5;
const int water_neg = D6;
int valueGAS;
int valueFIRE;

SimpleTimer timer;



void setup() {
Serial.begin(9600);
pinMode(GasPin,INPUT);
pinMode(FirePin,INPUT);
pinMode(servooff,INPUT);
pinMode(water_pos,OUTPUT);
pinMode(water_neg,OUTPUT);

myservo.attach(0); //D3
myservo.write(0);
Blynk.begin(auth, ssid, pass);

timer.setInterval(2500L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}


void sendSensor(){
  
  valueGAS = digitalRead(GasPin);
  valueFIRE = digitalRead(FirePin);
  if ( digitalRead(servooff) == 1)
  {
    myservo.write(0);
  }
  if( valueGAS == 0){
    Blynk.notify("GAS LEAKAGE");
    myservo.write(180);
    delay(100);
  }

  if( valueFIRE == 0){
    Blynk.notify("FIRE Detected");
    digitalWrite(water_pos,HIGH);
    digitalWrite(water_neg,LOW);
    delay(1000);
  }
  if( valueFIRE == 1){

    digitalWrite(water_pos,LOW);
    digitalWrite(water_neg,LOW);
    delay(1000);
  }
  
}

