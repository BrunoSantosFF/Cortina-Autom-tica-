#include <Servo.h> //Incluindo a biblioteca servo.
#include <ESP8266WiFi.h>//Incluindo a biblioteca da esp8266.
#include <BlynkSimpleEsp8266.h>//Incluindo a biblioteca da Blynk.

#define servo D7 //pino da entrada do servo.
#define button D6 //pino do botão que está ligado no container de botão do app Blynk.

Servo motor; //Variavel do servo motor.
int atv = 0; //ativador para estado do botao.
int test = 0; //ativador secundario.

char auth[] = "cF432HVUBz-GOTK4J5JoOsJIUbXtmFHa"; //Caracteres utilizados para que o servidor Blynk direcione as informações entre o aplicativo e a plataforma.
char ssid[] = "SANTOS_2Ghz"; //Nome da Rede WiFi.
char pass[] = "12345678"; //Senha da Rede WiFi.

void setup()
{
  
  Serial.begin(9600); //Velocidade e inicializção do monitor serial.
  Blynk.begin(auth, ssid, pass); //Ligação das informações para o app Blynk.
  motor.attach(servo); //Entrada do pino do servo motor.
  
}

void loop()
{
 Blynk.run();
  if (digitalRead(button)== 1){ //ligado ( está se levantando(abrindo))
    if (atv == 1){
      AbrirCortina();
      atv = 0;
      test = 1;
   
    }
   
  }
  else {
    if (atv == 0 && test == 0){ //A cortina está abaixada de começo entao tem que está parada e fechada.
      motor.detach(); //deixando o motor da  parada.
      atv = 1;
    }
    else if (atv == 0){
      FecharCortina();
      atv = 1;
      
    }
   
  }
  
   
   delay(500);
}
void AbrirCortina(){ //funçao para abrir a cortina.
  motor.attach(servo); //Serve para declarar a pinagem quando ela ser despinar nas funções.
  motor.write(180); //colocando o sentido para o motor com a função de abrir.
  delay(19000); //tempo de duraçao para a  abrir.
  motor.detach(); //despinagem do pino que esta ligado o motor.
  
}
void FecharCortina(){ //funçao para abrir a cortina.
  motor.attach(servo); //Serve para declarar a pinagem quando ela ser despinar nas funções.
  motor.write(0); //colocando o sentido para o motor com a função de fechar.
  delay(19000); //tempo de duraçao para a  abrir.
  motor.detach(); //despinagem do pino que esta ligado o motor.
  
}