//Autor: Azael Pérez González
//Fecha 15/05/2026
//PRUEBA DE BRAZO No. 1

#include <Servo.h>

// Pines Motores y Ultrasonico (los mismos)
const int enA = 5; const int in1 = 2; const int in2 = 4;
const int enB = 6; const int in3 = 7; const int in4 = 8;
const int trigPin = 12; const int echoPin = 11;

// Pines para los 4 Servos del Brazo (Nuevos)
Servo sBase; Servo sHombro; Servo sCodo; Servo sPinza;
const int pBase=3, pHombro=9, pCodo=10, pPinza=A0; // El pin 10 y A0 están libres

int velocidadBase = 200; 

void setup() {
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  
  // Attach de los servos del brazo
  sBase.attach(pBase); sHombro.attach(pHombro); sCodo.attach(pCodo); sPinza.attach(pPinza);
  
  plegarBrazo(); // Posición de reposo al iniciar
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  int distancia = leerDistancia();
  
  // Lógica de Exploración (Evitar Obstáculos)
  if (distancia > 0 && distancia < 25) {
    frenar();
    delay(200);
    // ... (Aquí pones la lógica de mirar a los lados y girar, igual que antes)
    detener();
  } 
  
  // Lógica de Recolección (Si detecta algo muy cerca, ej. 8cm)
  else if (distancia > 0 && distancia < 8) { 
    detener();
    pitidoAlerta(); // Poner buzzer si quieres
    delay(500);
    recolectarObjeto();
  }
  
  else {
    avanzar();
  }
}

// --- Funciones del Brazo (Nuevas) ---
void plegarBrazo() {
  // Posiciones de reposo (ajustar según tu armado físico)
  sBase.write(90); sHombro.write(40); sCodo.write(150); sPinza.write(0); // Pinza abierta
}

void recolectarObjeto() {
  Serial.println("INICIANDO RECOLECCIÓN");
  sBase.write(90); delay(500); // Centrar
  sPinza.write(0); delay(500); // Abrir pinza
  sHombro.write(90); sCodo.write(90); delay(1000); // Extender
  sPinza.write(180); delay(500); // Cerrar pinza (agarrar)
  sHombro.write(40); delay(1000); // Levantar objeto
  // sBase.write(180); delay(1000); // Girar para depositar (opcional)
  sPinza.write(0); delay(500); // Soltar objeto
  plegarBrazo(); // Volver a reposo
  Serial.println("RECOLECCIÓN FINALIZADA");
}

// ... (Funciones de movimiento y leerDistancia iguales que antes)
