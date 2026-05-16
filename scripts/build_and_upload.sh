#!/bin/bash

PUERTO="/dev/ttyACM0"
PLACA="arduino:avr:uno"
CARPETA_SKETCH="../src/Explorador_MeArm" 

echo "--- Iniciando Compilación ---"
arduino-cli compile --fqbn $PLACA $CARPETA_SKETCH

if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Subiendo al Arduino en $PUERTO..."
    arduino-cli upload -p $PUERTO --fqbn $PLACA $CARPETA_SKETCH
    
    if [ $? -eq 0 ]; then
        echo "Carga completada. El robot está listo."
    else
        echo "Error al subir el código. Verifica la conexión USB y los permisos del puerto."
    fi
else
    echo "Error de compilación. Revisa la sintaxis del código C++."
fi
