#include <Ticker.h> 
#include <OneWire.h>                
#include <DallasTemperature.h>  


#define Led 2  
#define sensor  3

void isr_led(void); 
void isr_sensor(void);

volatile static bool estado_led;
volatile static bool estado_sensor;

Ticker isr_accion_led(isr_led, 250); 
Ticker isr_accion_sensor(isr_sensor, 1000);
OneWire ourWire(2);               
DallasTemperature sensors(&ourWire); 


void setup() {
Serial.begin(9600);
pinMode(Led,OUTPUT);
digitalWrite(Led,LOW);
isr_accion_led.start();
isr_accion_sensor.start();
sensors.begin();
estado_led = LOW;
}

void loop() {
isr_accion_led.update();
isr_accion_sensor.update();
}


void isr_led(void)
{
sensors.requestTemperatures();   
float tempC= sensors.getTempCByIndex(0); 
float tempF= sensors.getTempFByIndex(0); 
estado_led = digitalRead(Led); 
digitalWrite(Led, !estado_led);
Serial.println(tempC);
}

void isr_sensor(void)
{
pinMode(sensor,INPUT);
bool estado_s1= digitalRead(sensor);
if(estado_s1==HIGH)
{
Serial.println("El sensor se encuentra activo");
}
if(estado_s1==LOW)
{
Serial.println("El sensor se encuentra inactivo");
}
}
