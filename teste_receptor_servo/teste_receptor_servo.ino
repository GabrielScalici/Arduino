#include <Servo.h>
#include <IRremote.h>

//Servos
Servo servo;
Servo servo2;

//Receptor
IRrecv ir_recebe(11);
decode_results codigo_recebido;

//Variaveis
int pos_a = 0;
int pos_d = 0;
int pos_w = 0;
int pos_s = 0;


void setup(){
  //Pinagem dos servos
  servo.attach(3);
  servo2.attach(4);
  //Receptor
  ir_recebe.enableIRIn();
  Serial.begin(9600);
  
}


void loop() {  
   //Verificando os valores lidos 
   if (ir_recebe.decode(&codigo_recebido)) {  
   
   //Mostrando os valores lidos
   if (codigo_recebido.value != 0 ){   
   Serial.println(codigo_recebido.value, HEX); //mostra no serial o resultado    
   }   

    /*
     * Movimentos Horizontais
     */
       
   if ((codigo_recebido.value == 0xE17AD827)){// verifica se foi pressionado o numero 1 dos controles    
      //A - E17AD827
      pos_a += 20;
      
      if(pos_a >= 180){
        pos_a = 180;  
      }
      pos_d = pos_a;
      servo.write(pos_a); 
  
   }   
   if ((codigo_recebido.value == 0xE17A38C7)){// verifica se foi pressionado o numero 1 dos controles    
      //D - E17A38C7
      pos_d -= 20;
      
      if(pos_d <= 0){
        pos_d = 0;  
      }
      pos_a = pos_d;
      servo.write(pos_d); 
  
   }


    /*
     * Movimentos Verticais
     */
       
   if ((codigo_recebido.value == 0xE17AD02F)){// verifica se foi pressionado o numero 1 dos controles    
      //W - E17AD02F
       pos_w += 45;
      
      if(pos_w >= 180){
        pos_w = 180;  
      }
      pos_s = pos_w;
      servo2.write(pos_w); 

   }   
   if ((codigo_recebido.value == 0xE17A30CF)){// verifica se foi pressionado o numero 1 dos controles    
      //S - E17A30CF
      pos_s -= 45;
      
      if(pos_s <= 0){
        pos_s = 0;  
      }
      pos_w = pos_s;
      servo2.write(pos_s); 

   }

   




          
   //recebendo os dados
   ir_recebe.resume(); // recebe o próximo código   
   delay(10);    
  }    
}   
