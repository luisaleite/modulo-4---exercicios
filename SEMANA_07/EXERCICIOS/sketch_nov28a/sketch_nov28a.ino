//adicionamos a biblioteca
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <ESPmDNS.h>

//definimos as portas dos led e botoes
#define botao1 18
#define led1 4
#define botao2 46
#define led2 7

//definimos as variaveis globais x e y
int x=0;
int y=0;

const char* ssid = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

//webserver com numro 80 pois e padrao pra pagina web
WebServer server (80);


void setup(void) {
  //relacionado ao 9600 com relação ao serial monitor
  Serial.begin(9600);

  //printa no serial monitor quando meu esp conecta na rede
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  //define que enquanto o esp estiver se conectado vai printando um ponto final
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //printa o enderço de ip
  Serial.println("");
  Serial.println("Wifi connected");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());


  //aqui definimos os endereços
  server.on("/", handleRoot);
  server.on("/on", handleOn);




  server.onNotFound(handleNotFound);

  server.begin();

  pinMode(botao1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);

  pinMode(botao2, INPUT_PULLUP);
  pinMode(led2, OUTPUT);

}

void handleRoot(){
  //html da minha pagina e botão
  String html = "";
  html+= "<style>a (font-size:40px; background-color: #CCCCCC;)</style>";
  html+= "<meta charset='UTF-8'>";
  html+= "<h1>Quem apertar primeiro 20 vezes o botao vence.<h1/>";
  html+= "<a href=\"/on\">Clique aqui para começar o jogo</a>";
  server.send(200, "text/html", html);

}

void jogadorB(){
  //html da minha pagina e quando jogador branco venceu
  String html = "";
  html+= "<style>a (font-size:40px; background-color: #CCCCCC;)</style>";
  html+= "<meta charset='UTF-8'>";
  html+= "<h1>Quem apertar primeiro 20 vezes o botao vence.<h1/>";
  html+= "<a href=\"/on\">Clique aqui para começar o jogo</a>";
  html+= "<h1>Jogador branco venceu<h1/>";
  server.send(200, "text/html", html);

}

void jogaodorA(){
  //html da minha pagina e quando jogador amarelo venceu
  String html = "";
  html+= "<style>a (font-size:40px; background-color: #CCCCCC;)</style>";
  html+= "<meta charset='UTF-8'>";
  html+= "<h1>Quem apertar primeiro 20 vezes o botao vence.<h1/>";
  html+= "<a href=\"/on\">Clique aqui para começar o jogo</a>";
  html+= "<h1>Jogador amarelo venceu<h1/>";
  server.send(200, "text/html", html);

}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void handleOn(){
  // quando o botão on for apertado ele roda essa funcao

  //inicialmente eu usei so if e o cogido (dos botaos e led) so funcionava no momento em que eu apertava o botao
  // mudei para while entao quando o botao for apertado essa funcao começa e so 
  //termina quando minha variavel x ou y chega a 20 e depois voltas a 0 nas duas
  while(true){
  if (!digitalRead (botao1)){
    x++;
      if(x==20){
        digitalWrite(led1,HIGH);
        delay(4000);
        digitalWrite(led1, LOW);
        x=0;
        y=0;
        jogaodorA(); //aqui estou chamando a funcao que muda meu html e mostra que o jogador amarelo venceu
        break;
      }
    Serial.print("botao1: ");
    Serial.println(x);
    delay(400);
  }

  if (!digitalRead (botao2)){
    y++;
      if(y==20){
        digitalWrite(led2,HIGH);
        delay(4000);
        digitalWrite(led2, LOW);
        y=0;
        x=0;
        jogadorB(); //aqui estou chamando a funcao que muda meu html e mostra que o jogador branco venceu
        break;
      }
    Serial.print("botao2: ");
    Serial.println(y);
    delay(400);
  }
  }
  handleRoot();
}

void loop(void) {
  server.handleClient();
  delay(2); 
}

