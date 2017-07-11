
#include <Servo.h>
 
Servo servo; /*Cria um objeto servo*/
Servo servo2;
int portCom; /*Cria uma variável para armazenar dados do Joystick*/
int servoPin = 4; /*Pino digital 11 conectado no servo*/
int servoPin2 = 3;
 
void setup(){
  servo.attach(servoPin);
  servo2.attach(servoPin2); 
  servo.write(90);  /*Inicia o servo em 90 graus*/
  servo2.write(90);
}
 
void loop(){
  portCom = analogRead(0); /*Pino X do Joystick para receber dados*/
  portCom = map(portCom, 0, 1023, 0, 180); /*Faz um mapeamento dos dados recebidos*/
  servo.write(portCom); /*O servo se movimenta de acordo com a posição do Joystick*/
  delay(15); /*Tempo leitura do pino analogico A0*/

  portCom = analogRead(1); /*Pino X do Joystick para receber dados*/
  portCom = map(portCom, 0, 1023, 0, 180); /*Faz um mapeamento dos dados recebidos*/
  servo2.write(portCom); /*O servo se movimenta de acordo com a posição do Joystick*/
  delay(15); /*Tempo leitura do pino analogico A0*/
  
}
