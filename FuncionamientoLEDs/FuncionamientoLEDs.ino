// C++ code
//
int Distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
//RED (0,255,255)
void red40() {
  analogWrite(2, 0);
  analogWrite(3, 255);
  analogWrite(4, 255);
}

void red30() {
  analogWrite(5, 0);
  analogWrite(6, 255);
  analogWrite(7, 255);
}

void red20() {
  analogWrite(8, 0);
  analogWrite(9, 255);
  analogWrite(10, 255);
}

//WHITE (150,150,150)
void white40() {
  analogWrite(2, 128);
  analogWrite(3, 128);
  analogWrite(4, 128);
}

void white30() {
  analogWrite(5, 128);
  analogWrite(6, 128);
  analogWrite(7, 128);
}

void white20() {
  analogWrite(8, 128);
  analogWrite(9, 128);
  analogWrite(10, 128);
}

void loop() {
  Distancia = 0.01723 * readUltrasonicDistance(1, 0);
  if (Distancia <= 40) {
    red40();
  }

  if (Distancia > 40) {
    white40();
  }

  if (Distancia <= 30) {
    red30();
    red20();
  }

  if (Distancia > 30) {
    white30();
  }

  if (Distancia <= 20) {
    red20();
  }

  if (Distancia > 20 && Distancia <= 30) {
    red30();
    red20();
  }else {
    white20();
  }

  if (Distancia <= 10) {
  }
  if (Distancia > 10) {
  }
  digitalWrite(13, HIGH);
  delay(500);  // Wait for 500 millisecond(s)
  digitalWrite(13, LOW);
  delay(500);  // Wait for 500 millisecond(s)
}