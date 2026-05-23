// Prueba de electroiman
// Antonio De Jesus Portilla Durán
// 23/05/2026
const int pinIman = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pinIman, OUTPUT);
  
  
  digitalWrite(pinIman, LOW);
  
  Serial.println("--- PRUEBA DE ELECTROIMÁN INICIADA ---");
  Serial.println("El ciclo comenzará en 3 segundos...");
  delay(3000); 
}

void loop() {
  
  Serial.println("ESTADO: ENCENDIDO (Acerca el metal)");
  digitalWrite(pinIman, HIGH);
  
  
  delay(5000); 
  
  
  Serial.println("ESTADO: APAGADO (Soltando metal)");
  digitalWrite(pinIman, LOW);
  
  
  delay(5000); 
}
