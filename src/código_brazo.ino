// Autor: Alfredo Cid Garcia
// Fecha: 15/05/2026
// PRUEBA DE BRAZO No. 4
#include <Servo.h>

#include <Servo.h>

// Definición de los 4 Servos
Servo servoBase;
Servo servoHombro;  // Pin A1 (Lateral A)
Servo servoAlcance; // Pin A2 (Lateral B)
Servo servoGarra;   // Pin A3 (Punta)

const int pBase=A0, pHombro=A1, pAlcance=A2, pGarra=A3;

// Variables para rastrear posición actual (crucial para suavizado)
int posHombroActual = 90;
int posAlcanceActual = 90;

// Constantes de seguridad de madera (Ajusta si zumban en los extremos)
const int LIMITE_ALTO = 140; // No ir a 180 para no forzar madera
const int LIMITE_BAJO = 40;  // No ir a 0

void setup() {
  Serial.begin(9600);
  Serial.println("--- INICIANDO PROTOCOLO DE PRUEBA TOTAL MEARM ---");

  // Adjuntar servos
  servoBase.attach(pBase);
  servoHombro.attach(pHombro);
  servoAlcance.attach(pAlcance);
  servoGarra.attach(pGarra);

  // POSICIÓN DE REPOSO INICIAL (Segura, a media altura)
  Serial.println("Estableciendo posición de reposo segura...");
  servoBase.write(90);
  servoGarra.write(90); // Garra semi-abierta
  
  // Movimiento directo en setup está bien porque los servos están quietos
  servoHombro.write(90); 
  servoAlcance.write(90); 
  delay(3000); // 3 segundos para prepararte
}

void loop() {
  Serial.println("=== NUEVO CICLO DE DEMOSTRACIÓN ===");

  // --- PRUEBA 1: EJE BASE (Rotación) ---
  Serial.println("1. Probando Base: Girando a la derecha...");
  servoBase.write(40); delay(1500);
  Serial.println("... Girando a la izquierda...");
  servoBase.write(140); delay(1500);
  Serial.println("... Regresando al centro.");
  servoBase.write(90); delay(1000);

  // --- PRUEBA 2: GARRA (Punta) ---
  Serial.println("2. Probando Garra: Abriendo por completo...");
  servoGarra.write(10); delay(1000);
  Serial.println("... Cerrando por completo (Precaución con la madera)...");
  // Si zumba al cerrar, sube este 170 a 160 o 150
  servoGarra.write(170); delay(1000); 
  Serial.println("... Posición neutra.");
  servoGarra.write(90); delay(1000);

  // --- PRUEBA 3: EJE ALCANCE (Lateral B - A2) - Coordinado con Hombro fijo ---
  Serial.println("3. Probando Alcance: Estirando hacia adelante LENTAMENTE...");
  // moverLaterales(HombroDestino, AlcanceDestino, velocidadMs)
  // Dejamos hombro fijo en 90 y estiramos Alcance
  moverLaterales(90, 130, 25); 
  delay(1500);
  Serial.println("... Contrayendo hacia atrás LENTAMENTE...");
  moverLaterales(90, 50, 25); 
  delay(1500);
  // Regresar a reposo
  moverLaterales(90, 90, 20);
  delay(1000);

  // --- PRUEBA 4: EJE HOMBRO (Lateral A - A1) - Coordinado con Alcance fijo ---
  Serial.println("4. Probando Hombro: Bajando toda la estructura LENTAMENTE...");
  // Fijamos Alcance en 90 y bajamos Hombro
  // Precaución aquí de no golpear la mesa (visto en video)
  moverLaterales(60, 90, 30); 
  delay(1500);
  Serial.println("... Levantando toda la estructura LENTAMENTE...");
  moverLaterales(120, 90, 30); 
  delay(1500);
  // Regresar a reposo
  moverLaterales(90, 90, 20);
  delay(1000);

  // --- PRUEBA 5: MOVIMIENTO COMBINADO (Pick & Place simulado) ---
  Serial.println("5. Simulando recolección coordinada suave...");
  moverLaterales(110, 110, 25); // Posición alta y adelante
  delay(1000);
  moverLaterales(70, 70, 25);   // Bajamos y recogemos (como agarrando algo del suelo)
  delay(1000);
  moverLaterales(90, 90, 20);   // Regresar a reposo central

  Serial.println("=== FIN DEL CICLO. Esperando 5 segundos ===");
  delay(5000);
}

// --- FUNCIÓN MAESTRA DE MOVIMIENTO SUAVE Y COORDINADO (Laterales) ---
// hombroDestino: Ángulo final del Servo Hombro (A1)
// alcanceDestino: Ángulo final del Servo Alcance (A2)
// velocidad: Ms de pausa entre grados (más alto = más lento)
void moverLaterales(int hombroDestino, int alcanceDestino, int velocidad) {
  
  // Asegurar límites de seguridad para no romper madera
  hombroDestino = constrain(hombroDestino, LIMITE_BAJO, LIMITE_ALTO);
  alcanceDestino = constrain(alcanceDestino, LIMITE_BAJO, LIMITE_ALTO);

  // Mientras alguno de los dos servos no esté en su destino
  while (posHombroActual != hombroDestino || posAlcanceActual != alcanceDestino) {
    
    // Ajuste paso a paso del Hombro
    if (posHombroActual < hombroDestino) posHombroActual++;
    else if (posHombroActual > hombroDestino) posHombroActual--;
    
    // Ajuste paso a paso del Alcance (simultáneamente)
    if (posAlcanceActual < alcanceDestino) posAlcanceActual++;
    else if (posAlcanceActual > alcanceDestino) posAlcanceActual--;
    
    // Aplicar el movimiento simultáneo a los servos laterales
    servoHombro.write(posHombroActual);
    servoAlcance.write(posAlcanceActual);
    
    delay(velocidad); // Retardo para suavidad mecánica
  }
}
