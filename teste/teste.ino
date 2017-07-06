const int LDR = 0;
int ValorLido = 0;
int BOTAO = 2;
int val_botao = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT);
}
void loop() {
ValorLido = analogRead(LDR);
val_botao = digitalRead(BOTAO);

//Serial.print("Valor lido pelo LDR = ");
//Serial.println(ValorLido);
Serial.print("/n Valor Botao = ");
Serial.println(val_botao);
delay(100);
}
