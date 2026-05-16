# Autor: Jose Santiago Alegria ponce 
# Rol: ayudante general
# Descripción: Lee los datos del puerto serial (Sensor Ultrasónico) y los guarda en un archivo CSV para análisis.

import serial
import csv
import time

# Configuración del puerto (Ajustar según tu sistema)
PUERTO = '/dev/ttyACM0'
BAUDIOS = 9600
ARCHIVO_SALIDA = '../results/datos_ultrasonico.csv'

try:
    print(f"Conectando al puerto {PUERTO}...")
    arduino = serial.Serial(PUERTO, BAUDIOS, timeout=1)
    time.sleep(2) # Esperar a que el Arduino reinicie tras la conexión serial

    with open(ARCHIVO_SALIDA, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Timestamp', 'Distancia_cm', 'Evento'])
        
        print("Registrando datos... Presiona Ctrl+C para detener.")
        
        while True:
            if arduino.in_waiting > 0:
                linea = arduino.readline().decode('utf-8').strip()
                
                # Filtrar solo las lecturas numéricas o eventos clave
                if "OBJETO DETECTADO" in linea:
                    writer.writerow([time.strftime("%H:%M:%S"), "", "Recolección Iniciada"])
                    print("--> EVENTO: Recolección")
                elif "Obstáculo" in linea:
                    writer.writerow([time.strftime("%H:%M:%S"), "", "Evasión Iniciada"])
                    print("--> EVENTO: Evasión")
                else:
                    # Asumiendo que el serial imprime solo el número, o extraemos el número
                    try:
                        # Si tu código imprime "Entrada cruda (cm): 25"
                        if "cm" in linea:
                            distancia = int(linea.split()[-1])
                            writer.writerow([time.strftime("%H:%M:%S"), distancia, "Explorando"])
                            print(f"Distancia: {distancia} cm")
                    except ValueError:
                        pass # Ignorar líneas que no se puedan parsear

except serial.SerialException:
    print("Error: No se pudo conectar al Arduino. Verifica el puerto USB.")
except KeyboardInterrupt:
    print("\nRegistro detenido por el usuario. Datos guardados en results/.")
