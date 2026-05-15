//Autor:Antonio Portilla
//Fecha:15/05/2026
//Version: 1.1.0
// Descripción: En este codigo el carro con la ayuda del sensor ultrasonico es capaz de evitar paredes protegiendo su integridad.

#include <Servo.h>

const int enA = 5;  const int in1 = 2;  const int in2 = 4;
const int enB = 6;  const int in3 = 7;  const int in4 = 8;
const int trigPin = 12; const int echoPin = 11;
const int pinServo = 3;

Servo miServo;
int velocidadBase = 200; 

void setup() {
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  
  miServo.attach(pinServo);
  miServo.write(90); 
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  int distancia = leerDistancia();
  
  if (distancia > 0 && distancia < 25) {
    detener();
    delay(200);
    
    int dDer = mirarDerecha();
    delay(400);
    int dIzq = mirarIzquierda();
    delay(400);
    
    if (dDer > dIzq) {
      girarDerecha();
    } else {
      girarIzquierda();
    }
    delay(600); 
    detener();
  } else {
    avanzar();
  }
}

void avanzar() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, velocidadBase);
  analogWrite(enB, velocidadBase);
}

void detener() {
  analogWrite(enA, 0); analogWrite(enB, 0);
}

void girarDerecha() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  analogWrite(enA, 180); analogWrite(enB, 180);
}

void girarIzquierda() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 180); analogWrite(enB, 180);
}

int leerDistancia() {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long d = pulseIn(echoPin, HIGH, 30000);
  return d * 0.034 / 2;
}

int mirarDerecha() {
  miServo.write(20); delay(500);
  int d = leerDistancia();
  miServo.write(90); return d;
}

int mirarIzquierda() {
  miServo.write(160); delay(500);
  int d = leerDistancia();
  miServo.write(90); return d;
}
