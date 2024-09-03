#include <LiquidCrystal.h>

#define echopino 2
#define trigpino 3
long duracao, distancia;
long distancia_anterior = 0;

int contador = 0;
int buzzi = 19;
int rs = 13, e = 14, d4 = 15, d5 = 16, d6 = 17, d7 = 18; 
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(trigpino, OUTPUT);
  pinMode(echopino, INPUT);
  pinMode(buzzi, OUTPUT);
  lcd.setCursor(2, 0);
  lcd.print("CONTADOR");
  lcd.setCursor(0, 1);
  lcd.print("pecas: ");
  lcd.print(contador);
}

void loop() {
  // Aciona o sensor ultrassônico
  digitalWrite(trigpino, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpino, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpino, LOW);

  // Lê o eco e calcula a distância
  duracao = pulseIn(echopino, HIGH);
  distancia = ((10*duracao)-780)/310;
  
  // Detecta a passagem
  if (distancia < 5 && distancia_anterior >= 5) {
    contador++;

    // Verifica se o contador atingiu 5
    if (contador == 6) {
      contador = 0; // Zera o contador
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("ZEREI");
      lcd.setCursor(0, 1);
      lcd.print("Pecas: ");
      lcd.print(contador);
      digitalWrite(buzzi, HIGH);
      delay(500); // Buzzer soa por 500ms
      digitalWrite(buzzi, LOW);
    } else {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("CONTADOR");
      lcd.setCursor(0, 1);
      lcd.print("Pecas: ");
      lcd.print(contador);
      digitalWrite(buzzi, HIGH);
      delay(200); // Buzzer soa por 200ms
      digitalWrite(buzzi, LOW);
    }
  }

  // Armazena a distância anterior
  distancia_anterior = distancia;

  delay(100);
}