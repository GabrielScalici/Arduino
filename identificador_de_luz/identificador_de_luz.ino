
const int LDR = 0;
const int Led = 6;
int iluminacao = 0;
       
void setup() {
   //Colocando o identificador para o led 
   Serial.begin(9600);    
   pinMode(Led, OUTPUT);
        
}
       
void loop() {
  //variavel que pega o valor do identificar de luminosidade
  iluminacao = analogRead(LDR);

  //Mostrando qual o valor lido
  Serial.print("Iluminacao = ");
  Serial.println(iluminacao);
  delay(500);

  //Logica para ligar o led quando passar de um determinado valor
  if (iluminacao < 200){
    analogWrite(Led, HIGH);
  }
  else{
    //desligar o led
    digitalWrite(Led, LOW);
    
    }
    
delay(500);
}
