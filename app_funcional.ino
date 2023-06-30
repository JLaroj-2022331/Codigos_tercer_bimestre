#include <SoftwareSerial.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#define led 2
#define dataPin 3

OneWire ourWire(dataPin);       
DallasTemperature sensors(&ourWire);          
SoftwareSerial ok(10, 11);
char jaja;

int Temp;

void setup() 
{
ok.begin(9600);
Serial.begin(9600);
Serial.println("vamos a verlo");
pinMode(led, OUTPUT);
sensors.begin();
}

void loop() 
{
sensors.requestTemperatures();   
float tempC= sensors.getTempCByIndex(0); 

if(tempC >=1.00 && tempC <=40.00)
{
Serial.println(tempC);
ok.print(tempC);
delay(10000);

}

if(ok.available())
{
jaja = ok.read();
switch(jaja)
{
case '1':
digitalWrite(led, HIGH);
break;

case '2':
digitalWrite(led, LOW);
break;
}

}
}
