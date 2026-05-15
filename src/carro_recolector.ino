//Autor:Jose Santiago Alegría Ponce
//Fecha:15/05/2026
// Descripción: Este es el primer código que vinvula las llantas con el puente H con la Arduino UNO

//Motor A (Izquierdo)
int enA = 9;
int in1 = 2;
int in2 = 3;

//Motor B (Derecho)
int enB = 10;
int in3 = 4;
int in4 = 5;

// Ajuste de velocidad
int velocidadBase = 200; 

//Valor de compensación
int compensacionB = 10; 

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Definir dirección hacia adelante una sola vez
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void loop() {
  // Calculamos la velocidad final para el Motor B
  int velocidadB = velocidadBase + compensacionB;
  
//limite de velocidad
  velocidadB = constrain(velocidadB, 0, 255);

  // Aplicar potencia constante
  analogWrite(enA, velocidadBase);
  analogWrite(enB, velocidadB);
  
    // Se mantiene encendido en un loop
}
