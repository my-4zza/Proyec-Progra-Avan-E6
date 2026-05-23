//Modificador: Alegría Ponce Jose Santiago
//Fecha: 23/mayo/2026
//Descripción: Integración de electroiman en la punta del brazo

#include <Servo.h>

// --- Pines Motores (Tracción) ---
const int enA = 5;  const int in1 = 2;  const int in2 = 4;
const int enB = 6;  const int in3 = 7;  const int in4 = 8;

// --- Pines Sensor Ultrasónico ---
const int trigPin = 12; 
const int echoPin = 11;
const int pinServoUltra = 3; 
Servo servoUltra;

// --- Pines Brazo Robótico (MeArm) ---
const int pinBase = A0;
const int pinHombro = A1;
const int pinAlcance = A2;
Servo servoBase;
Servo servoHombro;
Servo servoAlcance;

// --- Pin Electroimán ---
const int pinIman = 13;

// --- Variables Globales ---
int velTraccion = 180;       

// Posición de transporte con la máxima altura y repliegue para liberar el sensor
int posHombroActual = 140;   // Hombro al máximo arriba (guardia alta)
int posAlcanceActual = 50;    // Alcance completamente retraído hacia atrás

void setup() {
  Serial.begin(9600);
  
  // Configuración Llantas
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  
  // Configuración Ultrasónico
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  // Configuración Electroimán
  pinMode(pinIman, OUTPUT);
  digitalWrite(pinIman, LOW); 
  
  // Inicializar Servos
  servoUltra.attach(pinServoUltra);
  servoBase.attach(pinBase);
  servoHombro.attach(pinHombro);
  servoAlcance.attach(pinAlcance);

  // El brazo arranca plegado arriba para no obstruir la primera lectura
  servoUltra.write(90); 
  servoBase.write(90);  
  servoHombro.write(posHombroActual);
  servoAlcance.write(posAlcanceActual);
  
  delay(3000); 
}

void loop() {
  int distancia = leerDistancia();

  // --- CASO 1: OBJETO MUY CERCA (RECOLECCIÓN) ---
  if (distancia > 0 && distancia <= 10) {
    frenar();
    delay(1000); 
    rutinaRecoger();
  } 
  // --- CASO 2: OBSTÁCULO (EVASIÓN) ---
  else if (distancia > 10 && distancia <= 25) {
    frenar();
    delay(400); 
    
    int distDer = mirarDerecha();
    int distIzq = mirarIzquierda();

    if (distDer >= distIzq) {
      girarDerecha();
    } else {
      girarIzquierda();
    }
    delay(500); 
    frenar();
    delay(200);
  } 
  // --- CASO 3: CAMINO LIBRE ---
  else {
    avanzar();
  }
  
  delay(50); 
}

// ==========================================
//        FUNCIONES DEL BRAZO Y MAGNETISMO
// ==========================================

void rutinaRecoger() {
  // 1. Bajar el brazo desde las alturas hacia el objeto
  moverLaterales(60, 130, 25); 
  delay(800);
  
  // 2. ACTIVAR ELECTROIMÁN (Atrapar objeto)
  digitalWrite(pinIman, HIGH);
  delay(500); 
  
  // 3. Levantar la carga a una posición alta intermedia para el viaje
  moverLaterales(120, 70, 25); 
  delay(800);
  
  // 4. Girar la base a un lado para descargar (150 grados)
  servoBase.write(150); 
  delay(1200);
  
  // 5. DESACTIVAR ELECTROIMÁN (Soltar objeto en contenedor lateral)
  digitalWrite(pinIman, LOW);
  delay(500); 
  
  // 6. REPLIEGUE CRÍTICO: Antes de volver al centro, encogemos el brazo al Máximo Alto posible
  // Esto asegura que el imán suba por completo mientras sigue apuntando a un lado
  moverLaterales(140, 50, 20); 
  delay(600);
  
  // 7. REGRESO SEGURO: Con el brazo ya empotrado arriba, la base vuelve al frente (90 grados)
  // El electroimán pasa por encima del cono del ultrasónico sin estorbarle
  servoBase.write(90); 
  delay(1000); // El carro ahora tiene el frente 100% despejado para avanzar
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
