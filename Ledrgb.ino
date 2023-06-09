/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Josue David Antonio Laroj Gallina
 * Carnet: 2022331
 * Proyecto: LedRgb - Bimestre III
*/

#define potenciometro_pwm A0    
#define pwmLedR 3  
#define pwmLedG 5
#define pwmLedB 9

unsigned int potenciometro = 0;
unsigned int tiempovariable=0;
unsigned int Tiempo =0;

void setup()
{
 Serial.begin(9600);  
 pinMode(potenciometro_pwm, INPUT); 
 pinMode(pwmLedR, OUTPUT);  
 pinMode(pwmLedB, OUTPUT); 
 pinMode(pwmLedG, OUTPUT);  
}

void loop() 
{
potenciometro = analogRead(potenciometro_pwm); 
tiempovariable= map(potenciometro, 0, 1022,100,1000);
  analogWrite(pwmLedG, 92);
  analogWrite(pwmLedR, 174);
  analogWrite(pwmLedB, 230);
  delay(tiempovariable);
  analogWrite(pwmLedG, 255);
  analogWrite(pwmLedR, 255);
  analogWrite(pwmLedB, 255);
  delay(tiempovariable);
  analogWrite(pwmLedG, 255);
  analogWrite(pwmLedR, 0);
  analogWrite(pwmLedB, 255);
  delay(tiempovariable);
  analogWrite(pwmLedG, 174);
  analogWrite(pwmLedR, 189);
  analogWrite(pwmLedB, 20);
  delay(tiempovariable);
  analogWrite(pwmLedG, 87);
  analogWrite(pwmLedR, 225);
  analogWrite(pwmLedB, 35);
  Serial.println(tiempovariable);
}
