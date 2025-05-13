int velocidade1 = 163;
int velocidade2 = 170;
int motor1_F = 9;
int motor1_T = 10;
int motor2_F = 11;
int motor2_T = 12;

int foto2 = 2; // sensor motor2
int foto5 = 5; // sensor motor1

void setup() {
  pinMode(motor1_F, OUTPUT);
  pinMode(motor1_T, OUTPUT);
  pinMode(motor2_F, OUTPUT);
  pinMode(motor2_T, OUTPUT);

  pinMode(foto2, INPUT);
  pinMode(foto5, INPUT);

  Serial.begin(9600);
}

void loop() {
  int luminosidade2 = analogRead(foto2);
  int luminosidade5 = analogRead(foto5);

  Serial.print("L2: ");
  Serial.print(luminosidade2);
  Serial.print(" | L5: ");
  Serial.println(luminosidade5);

  // Ambos sensores no preto 
  if (luminosidade2 <= 200 && luminosidade5 <= 200) {
    analogWrite(motor1_F, velocidade1);
    digitalWrite(motor1_T, LOW);
    analogWrite(motor2_F, velocidade2);
    digitalWrite(motor2_T, LOW);
  }
  // Sensor2 no preto e sensor5 no branco 
  else if (luminosidade2 <= 200 && luminosidade5 > 200) {
    digitalWrite(motor1_F, LOW);
    digitalWrite(motor1_T, LOW);
    analogWrite(motor2_F, velocidade2);
    digitalWrite(motor2_T, LOW);
  }
  // Sensor2 no branco e sensor5 no preto 
  else if (luminosidade2 > 200 && luminosidade5 <= 200) {
    analogWrite(motor1_F, velocidade1);
    digitalWrite(motor1_T, LOW);
    digitalWrite(motor2_F, LOW);
    digitalWrite(motor2_T, LOW);
  }
  // Ambos sensores no branco
  else {
    digitalWrite(motor1_F, LOW);
    digitalWrite(motor1_T, LOW);
    digitalWrite(motor2_F, LOW);
    digitalWrite(motor2_T, LOW);
  }
}
