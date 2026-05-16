// Autor: Azael Pérez González
// Fecha: 15/05/2026
// PRUEBA DE BRAZO No. 2

#include <Servo.h>

// Definición de los 3 servos en pines analógicos
Servo servoBase;
Servo servoHombro;
Servo servoPinza;

const int pinBase = A0;
const int pinHombro = A1;
const int pinPinza = A2;

void setup() {
  // Inicializar comunicación para ver el estado en la PC
  Serial.begin(9600);
  Serial.println("--- Inicio de prueba mecánica del brazo ---");

  // Asociar los servos a los pines analógicos
  servoBase.attach(pinBase);
  servoHombro.attach(pinHombro);
  servoPinza.attach(pinPinza);

  // Posición inicial de seguridad al arrancar
  Serial.println("Posición de reposo inicial...");
  servoBase.write(90);    // Centrado
  servoHombro.write(150); // Retraído (arriba/atrás)
  servoPinza.write(10);   // Pinza abierta
  delay(2000);            // Espera de 2 segundos antes de empezar el bucle
}

void loop() {
  Serial.println("1. Desplegando brazo hacia el frente...");
  servoPinza.write(10);   // Asegura pinza abierta
  servoBase.write(90);    // Asegura base al frente
  delay(500);
  servoHombro.write(50);  // Baja el hombro para alcanzar el suelo
  delay(1500);            // Tiempo para que el motor termine el movimiento

  Serial.println("2. Cerrando pinza (Sujetando objeto)...");
  // NOTA: Si notas que el motor vibra mucho al cerrar, baja este número (ej. a 120)
  servoPinza.write(140);  
  delay(1000);

  Serial.println("3. Replicando brazo (Levantando carga)...");
  servoHombro.write(140); // Sube el hombro con fuerza
  delay(1500);

  Serial.println("4. Girando la base hacia el contenedor...");
  servoBase.write(170);   // Gira casi por completo a un lado
  delay(1500);

  Serial.println("5. Soltando objeto...");
  servoPinza.write(10);   // Abre la pinza para dejar caer el objeto
  delay(1000);

  Serial.println("6. Regresando a posición de reposo...");
  servoHombro.write(150); // Asegura hombro arriba
  delay(500);
  servoBase.write(90);    // Regresa la base al centro
  delay(2000);            // Pausa de 2 segundos antes de la siguiente simulación
}
