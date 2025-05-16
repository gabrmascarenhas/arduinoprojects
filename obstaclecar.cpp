#include <Servo.h>

int cm = 0;
int dist0 = 0;
int dist90 = 0;
int dist180 = 0;
int maior;

Servo servo;
int motor = 13;

int motor1_F = 10;
int motor1_T = 9;
int motor2_F = 11;
int motor2_T = 12;

int velocidade1 = 240;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);

  pinMode(motor1_F, OUTPUT);
  pinMode(motor1_T, OUTPUT);
  pinMode(motor2_F, OUTPUT);
  pinMode(motor2_T, OUTPUT);

  servo.attach(motor);
  Serial.begin(9600);
  servo.write(90); 
}

void loop() {
      digitalWrite(motor1_F, HIGH);
      digitalWrite(motor1_T, LOW);
      digitalWrite(motor2_F, HIGH);
      digitalWrite(motor2_T, LOW);

  cm = 0.01723 * readUltrasonicDistance(A0, A1);
  Serial.print("Ditância à frente: ");
  Serial.println(cm);
  delay(500);

  if (cm < 40) {
    digitalWrite(motor1_F, LOW);
    digitalWrite(motor1_T, LOW);
    digitalWrite(motor2_F, LOW);
    digitalWrite(motor2_T, LOW);

    servo.write(90);
    delay(1000);
    dist90 = 0.01723 * readUltrasonicDistance(A0, A1); // Frente

    servo.write(0);
    delay(1000);
    dist0 = 0.01723 * readUltrasonicDistance(A0, A1);  // Direita

    servo.write(180);
    delay(1000);
    dist180 = 0.01723 * readUltrasonicDistance(A0, A1); // Esquerda

    servo.write(90);

    // Para consulta no Arduino IDE:
    Serial.println("Distâncias:");
    Serial.print("Direita (0): "); Serial.println(dist0);
    Serial.print("Frente (90): "); Serial.println(dist90);
    Serial.print("Esquerda (180): "); Serial.println(dist180);

    if (dist0 > dist90) {
      if (dist0 > dist180) {
        maior = 0; 
      } else {
        maior = 180; 
      }
    } else {
      if (dist90 > dist180) {
        maior = 90;
      } else {
        maior = 180; 
      }
    }

    if (maior == 0) {
      Serial.println("Virando para DIREITA");
      digitalWrite(motor1_F, HIGH);
      digitalWrite(motor1_T, LOW);
      digitalWrite(motor2_F, LOW);
      digitalWrite(motor2_T, HIGH);
      delay(500);
      digitalWrite(motor1_F, HIGH);
      digitalWrite(motor1_T, LOW);
      digitalWrite(motor2_F, HIGH);
      digitalWrite(motor2_T, LOW);
    } else if (maior == 90) {
      Serial.println("Indo em FRENTE");
      digitalWrite(motor1_F, HIGH);
      digitalWrite(motor1_T, LOW);
      digitalWrite(motor2_F, HIGH);
      digitalWrite(motor2_T, LOW);
      delay(700);
    } else {
      Serial.println("Virando para ESQUERDA");
      digitalWrite(motor1_F, LOW);
      digitalWrite(motor1_T, HIGH);
      digitalWrite(motor2_F, HIGH);
      digitalWrite(motor2_T, LOW);
      delay(500);
      digitalWrite(motor1_F, HIGH);
      digitalWrite(motor1_T, LOW);
      digitalWrite(motor2_F, HIGH);
      digitalWrite(motor2_T, LOW);
    }

  } else {
    digitalWrite(motor1_F, HIGH);
    digitalWrite(motor1_T, LOW);
    digitalWrite(motor2_F, HIGH);
    digitalWrite(motor2_T, LOW);
  }

  delay(200);
}