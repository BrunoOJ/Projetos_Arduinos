#include <LiquidCrystal.h>

int verde = 2;
int amarelo = 3;
int vermelho = 4;
int buzzi = 19;
int liga_desliga = 7;  

int estado_botao = 0;
bool status_semaforo = false;
long tempo_milli = 0;
long intervalo = 1000;  
int contador = 9;  

int rs = 13, e = 14, d4 = 15, d5 = 16, d6 = 17, d7 = 18; 
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(buzzi, OUTPUT);
  pinMode(liga_desliga, INPUT_PULLUP);  
}

void loop() {
  estado_botao = digitalRead(liga_desliga);
  if (estado_botao == LOW) {
    status_semaforo = !status_semaforo; 
    contador = 9; 
    delay(200);  
  }

  if (status_semaforo) {
    long tempo_corrente = millis();
    if (tempo_corrente - tempo_milli >= intervalo) {
      tempo_milli = tempo_corrente;

      if (contador > 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SINAL VERDE");
        lcd.setCursor(0, 1);
        lcd.print("SIGA");
        digitalWrite(verde, HIGH);
        digitalWrite(amarelo, LOW);
        digitalWrite(vermelho, LOW);
        lcd.setCursor(15, 1);
        lcd.print(contador);
        contador--;
        digitalWrite(buzzi, HIGH);
        delay(100);  
        digitalWrite(buzzi, LOW);
      } else {
        digitalWrite(verde, LOW);
        digitalWrite(amarelo, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SINAL AMARELO");
        lcd.setCursor(0, 1);
        lcd.print("ATENCAO");
        delay(3000); 
        digitalWrite(amarelo, LOW);
        digitalWrite(vermelho, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SINAL VERMELHO");
        lcd.setCursor(0, 1);
        lcd.print("PARE");
        delay(6000);  
        digitalWrite(vermelho, LOW);
        contador = 9;  
      }
    }
  } else {
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("SEMAFORO");
    lcd.setCursor(4, 1);
    lcd.print("DESLIGADO");
    delay(200);  
  }
}

