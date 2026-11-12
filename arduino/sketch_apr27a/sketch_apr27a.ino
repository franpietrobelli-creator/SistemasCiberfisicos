

// Display de 7 segmentos - Cátodo Comum 

const int a = 8; 
const int b = 7; 
const int c = 11; 
const int d = 12; 
const int e = 13; 
const int f = 9; 
const int g = 10; 
int tempo_ =800; 

void setup() { 
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT); 
  pinMode(g, OUTPUT); } 

void loop() { 
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
  digitalWrite(e, LOW); 
  digitalWrite(f, LOW); 
  digitalWrite(g, HIGH); }
