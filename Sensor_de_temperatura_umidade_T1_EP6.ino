#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

// Definindo os pinos para o sensor DHT
#define DHTPIN 2     // Pino de dados do sensor DHT
#define DHTTYPE DHT11   // Tipo de sensor DHT (pode ser DHT11, DHT22, etc.)
DHT dht(DHTPIN, DHTTYPE);

// Definindo os pinos do LCD e do buzzer
int rs = 13, e = 14, d4 = 15, d5 = 16, d6 = 17, d7 = 18;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int buzzi = 19;

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(buzzi, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Temp & Umidade");
}
void loop() {
  // Lê a temperatura e a umidade do sensor DHT
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Verifica se as leituras são válidas
  if (isnan(temperatura) || isnan(umidade)) {
    lcd.setCursor(0, 1);
    lcd.print("Erro na leitura");
    return;
  }
  // Exibe a temperatura e a umidade no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Umidade: ");
  lcd.print(umidade);
  lcd.print(" %");
  
  // Aciona o buzzer se a temperatura for maior que 30 graus Celsius
  if (temperatura > 28.00) {
    digitalWrite(buzzi, HIGH);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Temp Maxima: ");
    lcd.setCursor(5, 1);
    lcd.print(temperatura);
  } else {
    digitalWrite(buzzi, LOW);
  }
  // Atualiza a cada 2 segundos
  delay(1000);
}
