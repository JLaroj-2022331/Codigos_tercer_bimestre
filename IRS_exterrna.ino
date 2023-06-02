/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Josue David Antonio Laroj Gallina
 * Carnet: 2022331
 * Proyecto: Contador - Bimestre III
*/


#define btn_rising  2      
#define btn_falling 3
#define a 4
#define b 5
#define c 6
#define d 7
#define a2 8
#define b2 9
#define c2 10
#define d2 11
void funcion_A(void);
void funcion_B(void);
int contadorUnidades = 0;
int contadorDecenas = 0;

void setup() 
{
  Serial.begin(19200);
  pinMode(btn_rising, INPUT);  
  pinMode(btn_falling, INPUT); 
  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_A,RISING);   
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_B,FALLING); 
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
}

void loop() 
{
switch(contadorUnidades)
{
case 0: 
   digitalWrite(a2, LOW);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, LOW);  
break;
case 1: 
   digitalWrite(a2, HIGH);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, LOW);  
break;
case 2: 
   digitalWrite(a2, LOW);  
   digitalWrite(b2, HIGH);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, LOW);  
break;
case 3: 
   digitalWrite(a2, HIGH);  
   digitalWrite(b2, HIGH);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, LOW);  
break;
case 4: 
   digitalWrite(a2, LOW);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, HIGH); 
   digitalWrite(d2, LOW);  
break;
case 5:  
   digitalWrite(a2, HIGH);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, HIGH); 
   digitalWrite(d2, LOW);  
break;
case 6:  
   digitalWrite(a2, LOW);  
   digitalWrite(b2, HIGH);  
   digitalWrite(c2, HIGH); 
   digitalWrite(d2, LOW);  
break;
case 7:
   digitalWrite(a2, HIGH);  
   digitalWrite(b2, HIGH);  
   digitalWrite(c2, HIGH); 
   digitalWrite(d2, LOW);  
break;
case 8: 
   digitalWrite(a2, LOW);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, HIGH);  
break;
case 9:
   digitalWrite(a2, HIGH);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, HIGH);  
break;
case 10:
   digitalWrite(a2, HIGH);  
   digitalWrite(b2, LOW);  
   digitalWrite(c2, LOW); 
   digitalWrite(d2, HIGH);  
break;
}
switch(contadorDecenas)
{
case 0: 
   digitalWrite(a, LOW);  
   digitalWrite(b, LOW);  
   digitalWrite(c, LOW); 
   digitalWrite(d, LOW);  
break;
case 1:
   digitalWrite(a, LOW);  
   digitalWrite(b, LOW);  
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);   
break;
case 2:
   digitalWrite(a, LOW);  
   digitalWrite(b, LOW);  
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);    
break;
case 3:
   digitalWrite(a, LOW);  
   digitalWrite(b, LOW);  
   digitalWrite(c, HIGH);
   digitalWrite(d, HIGH);   
break;
case 4:
   digitalWrite(a, LOW);  
   digitalWrite(b, HIGH);  
   digitalWrite(c, LOW);
   digitalWrite(d, LOW);   
break;
case 5:
   digitalWrite(a, LOW);  
   digitalWrite(b, HIGH);  
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);   
break;
}
}
void funcion_A(void)
{
  contadorUnidades = contadorUnidades +1;

  if(contadorUnidades == 10)
  {
   contadorUnidades = 0; 
   contadorDecenas = contadorDecenas +1;
  }
}
void funcion_B(void)
{
     contadorUnidades = contadorUnidades - 1;
    if (contadorUnidades < 0)
        {contadorUnidades = 10;  
        contadorDecenas = contadorDecenas - 1;
        }
        if (contadorDecenas < 0)
           { contadorDecenas = 5;
             contadorUnidades = 0;
           }}
