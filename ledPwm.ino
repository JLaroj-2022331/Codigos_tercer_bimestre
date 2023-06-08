/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: msensor de temperatura  
   Dev: Josue David Antonio Laroj Gallina
   Fecha: 8 de Junio
*/


#define potenciometro_pwm A0     //canal 0 
#define pwmLed 3  


//Variables
unsigned int potenciometro = 0;
unsigned int iluminacionLed = 0;

void setup()
{
 Serial.begin(9600);  
 pinMode(potenciometro_pwm, INPUT); 
 pinMode(pwmLed, OUTPUT);  
}

void loop() {
  potenciometro = analogRead(potenciometro_pwm); //leo el canal analogico A0
  iluminacionLed = map(potenciometro, 0, 1023, 0, 255);
  analogWrite(pwmLed, iluminacionLed);
  delay(100);
  Serial.println(iluminacionLed);
}
