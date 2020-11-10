#define BLINKER_PRINT Serial
#define BLINKER_BLE

#include <Servo.h>
#include <Blinker.h>

const int TrigPin = 3; 
const int EchoPin = 4; 
float distance;

Servo myservo;
int pos = 0;

//左上
int Motor1 = 5;
int Motor2 = 6;
//右上
int Motor3 = 7;
int Motor4 = 8;
//左下
int Motor5 = 9;
int Motor6 = 10;
//右下
int Motor7 = 11;
int Motor8 = 12;

BlinkerButton Forward("");
BlinkerButton Back("");
BlinkerButton Right("");
BlinkerButton Left("");
BlinkerButton Open("");
BlinkerButton Close("");

void Forward_callback(const String & state)
    {
      BLINKER_LOG("get button state: ", state);
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, HIGH);
      digitalWrite(Motor4, LOW);
      digitalWrite(Motor5, HIGH);
      digitalWrite(Motor6, LOW);
      digitalWrite(Motor7, HIGH);
      digitalWrite(Motor8, LOW);

      Blinker.vibrate();
      }

void Back_callback(const String & state)
    {
      BLINKER_LOG("get button state: ", state);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(Motor5, LOW);
      digitalWrite(Motor6, HIGH);
      digitalWrite(Motor7, LOW);
      digitalWrite(Motor8, HIGH);

      Blinker.vibrate();
      }

void Right_callback(const String & state)
    {
      BLINKER_LOG("get button state: ", state);
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, LOW);
      digitalWrite(Motor5, HIGH);
      digitalWrite(Motor6, LOW);
      digitalWrite(Motor7, LOW);
      digitalWrite(Motor8, LOW);

      Blinker.vibrate();
      }

void Left_callback(const String & state)
    {
      BLINKER_LOG("get button state: ", state);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, HIGH);
      digitalWrite(Motor4, LOW);
      digitalWrite(Motor5, LOW);
      digitalWrite(Motor6, LOW);
      digitalWrite(Motor7, HIGH);
      digitalWrite(Motor8, LOW);

      Blinker.vibrate();
      }

void Open_callback(const String & state)
    {
      BLINKER_LOG("get button state: ", state);
      for (pos = 0; pos <= 90; pos ++) 
          { 
           myservo.write(pos);
           delay(5); 
            }

      Blinker.vibrate();
      }

void Close_callback(const String & state)
    {
      BLINKER_LOG("get button state: ", state);
      for (pos = 90; pos >= 0; pos --) 
          {
           myservo.write(pos);
           delay(5);
           }

      Blinker.vibrate();
      }

void setup() {
  myservo.attach(2);
  
  pinMode(TrigPin, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  pinMode(Motor5, OUTPUT);
  pinMode(Motor6, OUTPUT);
  pinMode(Motor7, OUTPUT);
  pinMode(Motor8, OUTPUT);

  Blinker.begin();
  Forward.attach(Forward_callback);
  Back.attach(Back_callback);
  Right.attach(Right_callback);
  Left.attach(Left_callback);
  Open.attach(Open_callback);
  Close.attach(Close_callback);

}

void loop() { 
  for (pos = 0; pos <= 90; pos ++) 
    { 
    myservo.write(pos);
    delay(5); 
     }
  for (pos = 90; pos >= 0; pos --) 
    {
    myservo.write(pos);
    delay(5);
     }
  
  digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  distance = pulseIn(EchoPin, HIGH) / 58.00;
  Serial.print(distance); 
  Serial.print("cm"); 
  Serial.println(); 
  delay(1000);
  
  Blinker.run();
}
