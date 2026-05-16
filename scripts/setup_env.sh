#!/bin/bash

echo "--- Iniciando configuración del entorno para el Explorador Autónomo ---"


if ! command -v arduino-cli &> /dev/null; then
    echo "arduino-cli no encontrado. Instalando..."
    curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
    export PATH=$PATH:$PWD/bin
else
    echo "arduino-cli ya está instalado."
fi


echo "Actualizando índice del núcleo de Arduino..."
arduino-cli core update-index


echo "Instalando arquitectura arduino:avr..."
arduino-cli core install arduino:avr


echo "Verificando librería Servo..."
arduino-cli lib install Servo

echo "--- Entorno configurado correctamente. Listo para compilar. ---"
