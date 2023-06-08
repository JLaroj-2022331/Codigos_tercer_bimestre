#define potenciometro_pwm A0    
#define pwmLedR 3  
#define pwmLedG 5
#define pwmLedB 9

//Variables
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


void loop() {
  potenciometro = analogRead(potenciometro_pwm); //leo el canal analogico A0
  tiempovariable= map(potenciometro, 0, 1023,100,1000);
  delay(tiempovariable);
  analogWrite(pwmLedG, 92);
  analogWrite(pwmLedR, 174);
  analogWrite(pwmLedB, 230);
  delay(tiempovariable);
  delay(tiempovariable);
  analogWrite(pwmLedG, 255);
  analogWrite(pwmLedR, 255);
  analogWrite(pwmLedB, 255);
  delay(tiempovariable);
  Serial.println(tiempovariable);
}
