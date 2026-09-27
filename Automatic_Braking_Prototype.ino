#include <LiquidCrystal_I2C.h>
#include <Servo.h>

int TRIG_FRONT=5;
int ECHO_FRONT=18;

int TRIG_REAR=19;
int ECHO_REAR=23;

int servoPin=25;

int buzzer=14;

int green=27;
int yellow=26;
int red=33;

LiquidCrystal_I2C lcd(0x27,16,2);

Servo brake;

float getDistance(int trigPin,int echoPin)
{
  unsigned long duration;
  float distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH,30000);

  if(duration==0)
  {
    distance=500;
  }
  else
  {
    distance=duration*0.0343/2;
  }

  return distance;
}

int lastStatus=-1;

unsigned long previousTime20=0;
unsigned long previousTime50=0;

bool buzzerState=false;

void setup()
{
  pinMode(TRIG_FRONT,OUTPUT);
  pinMode(ECHO_FRONT,INPUT);

  pinMode(TRIG_REAR,OUTPUT);
  pinMode(ECHO_REAR,INPUT);

  pinMode(buzzer,OUTPUT);

  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);

  lcd.init();
  lcd.backlight();

  brake.attach(servoPin);
  brake.write(0);
}

void loop()
{
  float distanceFront=getDistance(TRIG_FRONT,ECHO_FRONT);
  float distanceRear=getDistance(TRIG_REAR,ECHO_REAR);

  if(distanceFront<10 || distanceRear<10)
  {
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);

    brake.write(90);

    tone(buzzer,1000);
    buzzerState=true;

    if(lastStatus!=0)
    {
      lcd.clear();
      lcd.print("AUTO BRAKING");
      lcd.setCursor(0,1);
      lcd.print("STOP VEHICLE");
      lastStatus=0;
    }
  }

  else if(distanceFront<20 || distanceRear<20)
  {
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);

    brake.write(70);

    if(lastStatus!=1)
    {
      buzzerState=false;
      noTone(buzzer);
      previousTime20=millis();

      lcd.clear();
      lcd.print("BRAKE READY");
      lcd.setCursor(0,1);
      lcd.print("CRITICAL");
      lastStatus=1;
    }

    if(millis()-previousTime20>=500)
    {
      previousTime20=millis();

      buzzerState=!buzzerState;

      if(buzzerState)
      {
        tone(buzzer,500);
      }
      else
      {
        noTone(buzzer);
      }
    }
  }

  else if(distanceFront<50 || distanceRear<50)
  {
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);

    brake.write(45);

    if(lastStatus!=2)
    {
      buzzerState=false;
      noTone(buzzer);
      previousTime50=millis();

      lcd.clear();
      lcd.print("OBSTACLE AHEAD");
      lcd.setCursor(0,1);
      lcd.print("SLOW DOWN");
      lastStatus=2;
    }

    if(millis()-previousTime50>=1000)
    {
      previousTime50=millis();

      buzzerState=!buzzerState;

      if(buzzerState)
      {
        tone(buzzer,300);
      }
      else
      {
        noTone(buzzer);
      }
    }
  }

  else
  {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);

    noTone(buzzer);
    buzzerState=false;

    brake.write(0);

    if(lastStatus!=3)
    {
      lcd.clear();
      lcd.print("SYSTEM SAFE");
      lcd.setCursor(0,1);
      lcd.print("Distance:OK");
      lastStatus=3;
    }
  }
}
