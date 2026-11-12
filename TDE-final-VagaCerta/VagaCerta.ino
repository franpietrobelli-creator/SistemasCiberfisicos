/* Definição dos pinos do Arduino
PINO Analogico A4 - SDA do Display LCD
PINO Analogico A5 - SDL do Display LCD
PINO Digital 13 - LED Vermelho Vaga 01
PINO Digital 12 - Trigger do Sensor ultrassom Vaga 01
PINO Digital 11 - Pino ECHO do Sensor Ultrassom Vaga 01
PINO Digital 10 - LED Verde Vaga 01
PINO DIGITAL 8 - Trigger do Sensor Ultrassom Vaga 02
PINO DIGITAL 9 - Pino ECHO do Sensor Ultrassok Vaga 02
PINO DIGITAL 7 - LED Vermelho Vaga 02
PINO DIGITAL 6 - LED Verde Vaga 02
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <NewPing.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

#define TRIGGER_PIN 12 
#define ECHO_PIN 11 
#define MAX_DISTANCE 20 
#define TRIGGER_PIN2 8  
#define ECHO_PIN2 9 
int vaga = 0; 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); 

void setup() {
 
  int x; 
  pinMode(13, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(6, OUTPUT); 
  Serial.begin(9600); 
  lcd.init(); 
  lcd.clear(); 
  lcd.backlight();
  lcd.setCursor(16,0); 
  for (x = 16; x >= 0; x--) {
    lcd.setCursor(x+1, 0);
    lcd.print(" ");
    lcd.setCursor(x, 0);
    lcd.print("G");
    delay (50);
  }
    for (x = 16; x >= 1; x--) {
    lcd.setCursor(x+1, 0);
    lcd.print(" ");
    lcd.setCursor(x, 0);
    lcd.print("r");
    delay (50);
  }
      for (x = 16; x >= 2; x--) {
    lcd.setCursor(x+1, 0);
    lcd.print(" ");
    lcd.setCursor(x, 0);
    lcd.print("u");
    delay (50);
  }
        for (x = 16; x >= 3; x--) {
    lcd.setCursor(x+1, 0);
    lcd.print(" ");
    lcd.setCursor(x, 0);
    lcd.print("p");
    delay (50);
  }
          for (x = 16; x >= 4; x--) {
    lcd.setCursor(x+1, 0);
    lcd.print(" ");
    lcd.setCursor(x, 0);
    lcd.print("o");
    delay (50);
  }
  
  lcd.setCursor(0,0); 
  lcd.print("Grupo da Pizza"); 
  for (x = 0; x <=5; x++){
    lcd.setCursor(0, 1);
    lcd.print("VAGA CERTA");
    delay (500);
    lcd.setCursor(0,1);
    lcd.print("                "); 
    delay (200);
  }
}

void loop() {
  
  vaga = 0;
  delay (50); 
  if (sonar.ping_cm() > 0)  { 
    digitalWrite(13, 1); 
    digitalWrite(10, 0); 
    if (vaga != 0) { vaga --;} 
  } else {
    digitalWrite(13, 0); o
    digitalWrite(10, 1); 
    vaga ++; 
  }
  //Verifica Estado da Vaga 02
    if (sonar2.ping_cm() > 0)  { 
    digitalWrite(7, 1); 
    digitalWrite(6, 0); 
    if (vaga > 1)  { vaga --; } 
  } else {
    digitalWrite(7, 0); 
    digitalWrite(6, 1); 
    vaga ++; 
  }
  lcd.setCursor(0, 1);
  lcd.print("VAGAS LIVRES: ");
  lcd.setCursor(14,1);
  lcd.print("   ");
  lcd.setCursor(14,1);
  lcd.print(vaga); 
}