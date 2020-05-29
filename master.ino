#include <Servo.h>

//Otopark Giriş-Çıkış Pinleri
const int ldrEntrance = A0;
const int ldrExit = A5;

//Otopark Park Yeri Pinleri
const int ldrPark1 = A1;
const int ledPark1R = 6;
const int ledPark1G = 8;
const int ledPark1B = 7;
const int usTrigPark1 = 3;
const int usEchoPark1 = 4;
const int buzzerPark1 = 5;
const int ledWarningPark1 = 9;

int distance = 0;

//Servo Motorlar
Servo motorEntrance;
Servo motorExit;

int ReadUSDistance(int pinTrig, int pinEcho)
{
  pinMode(pinTrig, OUTPUT);
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  pinMode(usEchoPark1, INPUT);

  return pulseIn(usEchoPark1, HIGH);
}

void setup()
{
  pinMode(ldrEntrance, INPUT);
  pinMode(ldrExit, INPUT);
  pinMode(ldrPark1, INPUT);
  pinMode(buzzerPark1, OUTPUT);
  pinMode(ledWarningPark1, OUTPUT);

  motorEntrance.attach(13);
  motorExit.attach(2);

  Serial.begin(9600);
}

void loop()
{
  int ldrEntranceValue = analogRead(ldrEntrance);
  int ldrExitValue = analogRead(ldrExit);
  int ldrPark1Value = analogRead(ldrPark1);

  //Giriş Kapısının Açılıp Kapanmasını Sağlar
  if (ldrEntranceValue > 500 && ldrPark1Value < 500)
  {
    motorEntrance.write(90);
  }
  else
  {
    motorEntrance.write(0);
  }

  //Çıkış Kapısının Açılıp Kapanmasını Sağlar
  if (ldrExitValue > 500)
  {
    motorExit.write(90);
  }
  else
  {
    motorExit.write(0);
  }

  //Giriş Kapısının Açılıp Kapanmasını Sağlar
  if (ldrPark1Value > 500)
  {
    analogWrite(ledPark1R, 255);
    analogWrite(ledPark1G, 0);
    analogWrite(ledPark1B, 0);
    distance = 0.01723 * ReadUSDistance(usTrigPark1, usEchoPark1);
    if (distance <= 30)
    {
      digitalWrite(buzzerPark1, HIGH);
      digitalWrite(ledWarningPark1, HIGH);
    }
    else
    {
      digitalWrite(buzzerPark1, LOW);
      digitalWrite(ledWarningPark1, LOW);
    }
  }
  else
  {
    Serial.write(ldrPark1Value);
    analogWrite(ledPark1R, 0);
    analogWrite(ledPark1G, 255);
    analogWrite(ledPark1B, 0);
  }

  delay(100);
}