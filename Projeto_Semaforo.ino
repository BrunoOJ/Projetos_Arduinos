int verde = 2;
int amarelo = 3;
int vermelho = 4;
void setup() {
  pinMode(verde,OUTPUT);
  pinMode(amarelo,OUTPUT);
  pinMode(vermelho,OUTPUT);
}

void loop() {
  digitalWrite(verde,HIGH);
  digitalWrite(amarelo,LOW);
  digitalWrite(vermelho,LOW);
  delay(5000);
  digitalWrite(verde,LOW);
  digitalWrite(amarelo,HIGH);
  digitalWrite(vermelho,LOW);
  delay(2000);
  digitalWrite(verde,LOW);
  digitalWrite(amarelo,LOW);
  digitalWrite(vermelho,HIGH);
  delay(4000);
}
