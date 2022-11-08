#include <iostream>
#include <string>

int pushbutton1 = 6;
bool estadoLdr = 0;
const int ldr = 11;

int leitura_ldr = 0;
int normalizado;

int valoresNormalizados[15]; // criei por conta para toca a musica conforme o valor
int contador = 0;

int binario[4];

int pushbutton2 = 16;

int LED = 10;
int LED2 = 9;
int LED3 = 46;
int LED4 = 3;

int buzzer = 37;



void setup() {

  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(pushbutton1, INPUT_PULLUP);
  pinMode(pushbutton2, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);


  pinMode(ldr, INPUT);
  Serial.begin(9600);

}

void loop()
{
   int buttonPress1 = digitalRead(pushbutton1);
   delay(30);
   int buttonPress2 = digitalRead(pushbutton2);	
   delay(30);
   if (buttonPress1 == 0){
   	leitura();
 
   }
   
   if (buttonPress2 == 0){
     for (int i = 0; i < contador; i++)
     {
        transformaBinario(valoresNormalizados[i]);
        acenderLed();
        musica(valoresNormalizados[i]);
     }

     contador = 0;
   }


}

void leitura(){
  leitura_ldr = analogRead(ldr);
  Serial.print("tensao LDR: ");
  Serial.println(leitura_ldr);

  normalizado = (leitura_ldr * 15) / 4075;
  Serial.print("Valor Normalizado: ");
  Serial.println(normalizado);

  transformaBinario(normalizado);
  valoresNormalizados[contador] = normalizado;
  contador += 1;

  acenderLed();
  musica(normalizado);

  Serial.println("Numero binario: ");

  for (int i = 3; i >= 0; i--){
    Serial.println(binario[i]);
  }

}

void transformaBinario(int decimal)
{
  for(int i = 0; i < 4; i++){
    binario[i] = decimal % 2;
    decimal /= 2;
  }
}

void acenderLed(){
  digitalWrite(LED, binario[3]);
  digitalWrite(LED2, binario[2]);
  digitalWrite(LED3, binario[1]);
  digitalWrite(LED4, binario[0]);
  
  delay(200);

  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  binario[0] = 0;
  binario[1] = 0;
  binario[2] = 0;
  binario[3] = 0;
}


void frequencia_duracao(char pino, int frequencia, int duracao){
  float periodo = 1000.0/frequencia; //Periodo em ms
  for (int i = 0; i< duracao/(periodo);i++){ //Executa a rotina de dentro o tanta de vezes que a frequencia desejada cabe dentro da duracao
    digitalWrite(pino,HIGH);
    delayMicroseconds(periodo*500); //Metade do periodo em ms
    digitalWrite(pino, LOW);
    delayMicroseconds(periodo*500);
  }
}

void musica(int valor){
  if (valor == 0){
    frequencia_duracao(buzzer, 100, 300);
    delay(1000);
  }
  else if (valor == 1){ 
    frequencia_duracao(buzzer, 400, 300);
    delay(1000);
  }  
  else if (valor == 2){
    frequencia_duracao(buzzer, 800, 300);
    delay(1000);
  }
  else if (valor == 3){
    frequencia_duracao(buzzer, 1100, 300);
    delay(1000);
  }
  else if (valor == 4){
    frequencia_duracao(buzzer, 1400, 300);
    delay(1000);
  }
  else if (valor == 5){
    frequencia_duracao(buzzer, 1700, 300);
    delay(1000);
  }
  else if (valor == 6){
    frequencia_duracao(buzzer, 2000, 300);
    delay(1000);
  }
  else if (valor == 7){
    frequencia_duracao(buzzer, 2300, 300);
    delay(1000); 
  }
  else if (valor == 8){
    frequencia_duracao(buzzer, 2600, 300);
    delay(1000);
  }
  else if (valor == 9){
    frequencia_duracao(buzzer, 2900, 300);
    delay(1000);
  }
  else if (valor == 10){
    frequencia_duracao(buzzer, 3200, 300);
    delay(1000);
  }
  else if (valor == 11){
    frequencia_duracao(buzzer, 3500, 300);
    delay(1000);
  }
  else if (valor == 12){
    frequencia_duracao(buzzer, 3800, 300);
    delay(1000);
  }
  else if (valor == 13){
    frequencia_duracao(buzzer, 4100, 300);
    delay(1000);
  }
  else if (valor == 14){
    frequencia_duracao(buzzer, 4400, 300);
    delay(1000);
  }
  else{
    frequencia_duracao(buzzer, 4700, 300);
    delay(1000);
  }
}
