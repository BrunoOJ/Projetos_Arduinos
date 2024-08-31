#include <LiquidCrystal.h>

#define echopino 2
#define trigpino 3
long duracao, distancia;

int buzzi = 19;
int rs = 13, e = 14, d4 = 15, d5 = 16, d6 = 17, d7 = 18; 
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trigpino, OUTPUT);
  pinMode(echopino, INPUT);
  pinMode(buzzi, OUTPUT);
}

void loop() {
  digitalWrite(trigpino, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpino, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpino, LOW);

  duracao = pulseIn(echopino, HIGH);
  Serial.println(duracao);
  distancia = ((10*duracao)-780)/310;

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("DISTANCIA");
  lcd.setCursor(1, 1);
  lcd.print(distancia);
  lcd.setCursor(6, 1);
  lcd.print("Centimetro");
  if (distancia<3){
    digitalWrite(buzzi, HIGH);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("SINAL SONORO");
  }
  else{
    digitalWrite(buzzi, LOW);
  }
  delay(50);
}
