

#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

const int relay1 =D0;
const int relay2 =D1;

//bool Value2= HIGH;
//bool Value1= HIGH;
#define BLYNK_AUTH_TOKEN""

char auth[]=BLYNK_AUTH_TOKEN;
char ssid[]="";
char pass[]="";

BLYNK_WRITE(V0)
{
  bool Value1=param.asInt();
  if (Value1 == 1)
  {
    digitalWrite(relay1, LOW);
  }
  else
  {
    digitalWrite(relay2, HIGH);
  }
}

BLYNK_WRITE(V1)
{
  bool Value2 = param.asInt();
  if(Value2 == 1)
  {
    digitalWrite(relay1, LOW);
    }
    else
    {
      digitalWrite(relay2 , HIGH);
    }
}

void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  Blynk.begin(auth,ssid,pass);
}

void loop()
{
  Blynk.run();
  
}
