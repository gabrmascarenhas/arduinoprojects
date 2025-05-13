#include <SoftwareSerial.h>
#define FORWARD 'F' 
#define BACKWARD 'B' 
#define LEFT 'L' 
#define RIGHT 'R' 
#define CIRCLE 'C' 
#define CROSS 'X' 
#define TRIANGLE 'T' 
#define SQUARE 'S' 
#define START 'A' 
#define PAUSE 'P' 
SoftwareSerial bluetooth(2, 3);  // RX, TX


int i;
int velocidade = 6;

int motor1_F = 10;
int motor1_T = 9;
int motor2_F = 11;
int motor2_T = 12;
int velocidade1 = 250;


void setup() {
  pinMode(motor1_F, OUTPUT);
  pinMode(motor1_T, OUTPUT);
  pinMode(motor2_F, OUTPUT);
  pinMode(motor2_T, OUTPUT);
  pinMode(velocidade, OUTPUT);

  Serial.begin(9600); 
  bluetooth.begin(9600);

}

void loop() {
char command = bluetooth.read();
executeCommand(command);
}

void executeCommand(char command){
    switch (command) {
      case FORWARD :
        analogWrite(velocidade, 255);
        analogWrite(motor1_F, velocidade1); 
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, HIGH);
        digitalWrite(motor2_T, LOW);

        break;

      case BACKWARD :
        analogWrite(velocidade, 255);
        digitalWrite(motor1_F, LOW);
        analogWrite(motor1_T, velocidade1);
        digitalWrite(motor2_F, LOW);
        digitalWrite(motor2_T, HIGH);


        break;

      case RIGHT :
        analogWrite(velocidade, 255);
        analogWrite(motor1_F, velocidade1);
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, LOW);
        digitalWrite(motor2_T, LOW);

        break;

      case LEFT :
        analogWrite(velocidade, 255);
        digitalWrite(motor1_F, LOW);
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, HIGH);
        digitalWrite(motor2_T, LOW);


        break;

      case CROSS :
        analogWrite(velocidade, 255);
        digitalWrite(motor1_F, LOW);
        digitalWrite(motor1_T, LOW);
        digitalWrite(motor2_F, LOW);
        digitalWrite(motor2_T, LOW);


        break;
}}