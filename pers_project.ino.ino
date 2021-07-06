#include<Stepper.h>
#include<Servo.h>

int const servoPin = 3;
int const ledPin1 = 13;
int const ledPin2 = 6;
int const trigPin1 = 7;
int const echoPin1 = 8;
int const trigPin2 = 9;
int const echoPin2 = 10;
int const trigPin3 = 11;
int const echoPin3 = 12;
Servo servo1;

void setup() {
  servo1.attach(servoPin);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  long duration, distincm;
  int i = 0;
  bool d1, d2 , d3 = false;
  while (d1 = false) {
    digitalWrite(trigPin1, HIGH);
    delay(1);
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distincm = (duration) * 0.034 / 2;
    if (distincm < 15 && distincm > 2) {
      d1 = true;
    }
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  while (d2 = false) {
    digitalWrite(trigPin2,HIGH);
    delay(1);
    digitalWrite(trigPin2,LOW);
    duration = pulseIn(echoPin2,HIGH);
    distincm = (duration)*0.034/2;
    if(distincm < 100 && distincm>10){
      d2 = true;
    }
  }
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  for (int pos = 0; pos <= 90; pos += 1) {
    servo1.write(pos);
    delay(1);
  }
  while (d3 = false) {
    digitalWrite(trigPin3,HIGH);
    delay(1);
    digitalWrite(trigPin3,LOW);
    duration = pulseIn(echoPin3,HIGH);
    distincm = (duration)*0.034/2;
    if(distincm < 100 && distincm>10){
      d3 = true;
    }
  }
  for (int pos = 90; pos >= 0; pos -= 1) {
    servo1.write(pos);
    delay(1);
  }
  i++;
  Serial.print("No. of People inside= ");
  Serial.print(i);
  Serial.println("");
}
