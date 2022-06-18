int sensor1 = 9; 
int sensor2 = 8;            
int val1 = 0; 
int val2 = 0; 
int p=0;
int pos=0;

#include<Servo.h>
Servo Myservo;
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  Myservo.attach(10);
  Serial.begin(9600);        
}

void loop()
{
  val1 = digitalRead(sensor1);
  val2 = digitalRead(sensor2);
  if(val1==HIGH || val2 == HIGH)
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    //rotate(0);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}


void rotate(int p)
{
  for(pos=p;pos<=90;pos++)
    {
      Myservo.write(pos);
      delay(15);
    }

    if((sensor1 == HIGH || sensor2 == HIGH) && pos==90)
    {
      Myservo.write(90);
    }
    else
    {
      delay(5000);
    for(pos=90;pos<=0;pos--)
       {
        Myservo.write(pos);
        delay(15);
        }
  }
}
