#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
#include <Dabble.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);  // RX, TX

char comando;
int i;
int velocidade = 6;

int motor1_F = 10;
int motor1_T = 9;
int motor2_F = 11;
int motor2_T = 12;
int velocidade1 = 240;
int foto2 = 2;
int foto5 = 5;


void setup() {
  pinMode(motor1_F, OUTPUT);
  pinMode(motor1_T, OUTPUT);
  pinMode(motor2_F, OUTPUT);
  pinMode(motor2_T, OUTPUT);
  pinMode(velocidade, OUTPUT);

  Serial.begin(9600);   
  bluetooth.begin(9600);
  Dabble.begin(bluetooth);
  pinMode(foto2, 2);
  pinMode(foto5, 5);
}

void loop() {
  Dabble.processInput();  

  if (Terminal.available()) {
    comando = Terminal.read();

    switch (comando) {
      case 'w':
        analogWrite(velocidade, 255);
        analogWrite(motor1_F, velocidade1); 
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, HIGH);
        digitalWrite(motor2_T, LOW);

        Terminal.println("Andando pra frente");
        break;

      case 's':
        analogWrite(velocidade, 255);
        digitalWrite(motor1_F, LOW);
        analogWrite(motor1_T, velocidade1);
        digitalWrite(motor2_F, LOW);
        digitalWrite(motor2_T, HIGH);

        Terminal.println("Andando pra tras");
        break;

      case 'd':
        analogWrite(velocidade, 255);
        analogWrite(motor1_F, velocidade1);
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, LOW);
        digitalWrite(motor2_T, LOW);

        Terminal.println("Andando pra direita");
        break;

      case 'a':
        analogWrite(velocidade, 255);
        digitalWrite(motor1_F, LOW);
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, HIGH);
        digitalWrite(motor2_T, LOW);

        Terminal.println("Andando pra esquerda");
        break;

      case 'e':
        analogWrite(velocidade, 255);
        digitalWrite(motor1_F, LOW);
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, LOW);
        digitalWrite(motor2_T, LOW);

        Terminal.println("Desligando os motores");
        break;
}}}