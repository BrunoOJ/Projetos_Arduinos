#include <Servo.h>
#include <LiquidCrystal.h>


# define pino2 2
Servo servo;
int angulo;

const int PinoAnalogico = A6;
int valorSensor = 0;
int valorconvertido = 0;

// Definindo os pinos do LCD e do buzzer
int rs = 13, e = 14, d4 = 15, d5 = 16, d6 = 17, d7 = 18;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int buzzi = 19;

void setup() {
  angulo = 0;
  servo.write(angulo);
  servo.attach(pino2);
  lcd.begin(16, 2);
  pinMode(buzzi, OUTPUT);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SEM CHUVA!");
}

void loop() {
  valorSensor = analogRead(PinoAnalogico);
  valorconvertido = map(valorSensor, 0, 1023, 0, 100);
  lcd.setCursor(14, 0);
  lcd.print(valorconvertido);
  delay(300);

  if (valorconvertido>50){
    angulo = 180;
    servo.write(angulo);
    servo.attach(pino2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CHUVENDO!");
    lcd.setCursor(14, 0);
    lcd.print(valorconvertido);
    lcd.setCursor(0, 1);
    lcd.print("Varal Recolhido!");
    delay(300);
    tone(buzzi,300,300);
    delay(500);
    tone(buzzi,300,300);
    delay(500);
  }else{
    angulo = 0;
    servo.write(angulo);
    servo.attach(pino2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SEM CHUVA!");
  }
}
