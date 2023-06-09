/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Josue David Antonio Laroj Gallina
 * Carnet: 2022331
 * Proyecto: Medidor Resistencias - III Bimestre
*/
#include <LiquidCrystal.h>
#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define divisor_v A0 
int medicionR();

LiquidCrystal lcd(RS, Enable, D4, D5, D6, D7); 

  void setup()
{
  lcd.begin(16,2); 
  Serial.begin(9600);
  pinMode(divisor_v, INPUT);
}
void loop() {
  lcd.setCursor(0,0);
  lcd.print("  Resistencia  ");
  unsigned long int ohms = medicionR();
  lcd.setCursor(10,9);
  lcd.print("k");

}
 int medicionR(){
    int lectura = 0;   
    int Ve = 5;  
    float VR2 = 0;    
    float R1 = 10000;    
    float R2 = 0;        
    float relacion = 0;
     lectura = analogRead(divisor_v);
   if(lectura) 
  {
    relacion = lectura * Ve; 
    VR2 = (relacion)/1023.0;  
  relacion = (Ve/VR2) -1;   
    R2= (R1 * relacion)-10;  
    lcd.print("el valor es de :");
    delay(500);
    lcd.setCursor(0,1);
    Serial.println(R2);
    lcd.print(R2);

    return R2;
  } else {
    Serial.println("no hay resistencia");
    return 0;
    }
  }
