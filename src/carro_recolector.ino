#include <Servo.h>

// --- Pines Motores (Tracción) ---
const int enA = 5;  const int in1 = 2;  const int in2 = 4;
const int enB = 6;  const int in3 = 7;  const int in4 = 8;

// --- Pines Sensor Ultrasónico ---
const int trigPin = 12; 
const int echoPin = 11;
const int pinServoUltra = 3; 
Servo servoUltra;

// --- Pines Brazo Robótico ---
const int pinBase = A0;
const int pinHombro = A1;
const int pinAlcance = A2;
Servo servoBase;
Servo servoHombro;
Servo servoAlcance;

// --- Variables Globales ---
int velTraccion = 180;       // Velocidad de los motores amarillos
int posHombroActual = 90;    // Rastreador para suavizado del hombro
int posAlcanceActual = 90;   // Rastreador para suavizado del alcance

void setup() {
  Serial.begin(9600);
  
  // Configuración Llantas
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  
  // Configuración Ultrasónico
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  // Inicializar Servos
  servoUltra.attach(pinServoUltra);
  servoBase.attach(pinBase);
  servoHombro.attach(pinHombro);
  servoAlcance.attach(pinAlcance);

  // Posiciones Seguras de Arranque
  servoUltra.write(90); // Mirar al frente
  servoBase.write(90);  // Brazo centrado
  servoHombro.write(posHombroActual);
  servoAlcance.write(posAlcanceActual);
  
  Serial.println("SISTEMA INICIADO: Calibrando...");
  delay(3000); // Dar tiempo para colocar el coche en el piso
}

void loop() {
  int distancia = leerDistancia();

  // --- CASO 1: OBJETO MUY CERCA (RECOLECCIÓN) ---
  if (distancia > 0 && distancia <= 10) {
    frenar();
    Serial.println("OBJETO DETECTADO: Iniciando Recolección...");
    delay(1000); // Esperar a que pase la inercia y se estabilice la corriente
    rutinaRecoger();
  } 
  // --- CASO 2: OBSTÁCULO (EVASIÓN) ---
  else if (distancia > 10 && distancia <= 25) {
    frenar();
    Serial.println("Obstáculo. Buscando ruta...");
    delay(400); // Pausa eléctrica antes de mover el servo del sensor
    
    int distDer = mirarDerecha();
    int distIzq = mirarIzquierda();

    if (distDer >= distIzq) {
      girarDerecha();
    } else {
      girarIzquierda();
    }
    delay(500); // Tiempo que duran girando las llantas
    frenar();
    delay(200);
  } 
  // --- CASO 3: CAMINO LIBRE ---
  else {
    avanzar();
  }
  
  delay(50); // Pequeña pausa para estabilidad del procesador
}

// ==========================================
//        FUNCIONES DEL BRAZO ROBÓTICO
// ==========================================

void rutinaRecoger() {
  // 1. Bajar el brazo para "barrer" o empujar el objeto
  // Ajusta estos valores (ej. 60 y 130) según la calibración física de tu ensamble
  moverLaterales(60, 130, 25); 
  delay(800);
  
  // 2. Levantar la carga 
  moverLaterales(130, 60, 25); 
  delay(800);
  
  // 3. Girar la base simulando dejar el objeto a un lado
  servoBase.write(150); 
  delay(1200);
  
  // 4. Regresar el brazo a su posición compacta de transporte
  moverLaterales(90, 90, 20); 
  delay(500);
  servoBase.write(90); 
  delay(1000); // Listo para volver a avanzar
}

void moverLaterales(int hDest, int aDest, int velocidad) {
  while (posHombroActual != hDest || posAlcanceActual != aDest) {
    if (posHombroActual < hDest) posHombroActual++;
    else if (posHombroActual > hDest) posHombroActual--;
    
    if (posAlcanceActual < aDest) posAlcanceActual++;
    else if (posAlcanceActual > aDest) posAlcanceActual--;
    
    servoHombro.write(posHombroActual);
    servoAlcance.write(posAlcanceActual);
    delay(velocidad);
  }
}

// ==========================================
//        FUNCIONES DE SENSORES Y TRACCIÓN
// ==========================================

int leerDistancia() {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long d = pulseIn(echoPin, HIGH, 30000);
  return d * 0.034 / 2;
}

int mirarDerecha() {
  servoUltra.write(20); 
  delay(600);
  int d = leerDistancia();
  servoUltra.write(90); 
  return d;
}

int mirarIzquierda() {
  servoUltra.write(160); 
  delay(600);
  int d = leerDistancia();
  servoUltra.write(90); 
  return d;
}

void avanzar() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, velTraccion); analogWrite(enB, velTraccion);
}

void frenar() {
  analogWrite(enA, 0); analogWrite(enB, 0);
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}

void girarDerecha() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  analogWrite(enA, velTraccion); analogWrite(enB, velTraccion);
}

void girarIzquierda() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, velTraccion); analogWrite(enB, velTraccion);
}
