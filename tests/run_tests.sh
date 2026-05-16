#!/bin/bash

echo "======================================"
echo "   INICIANDO PRUEBAS DE SOFTWARE      "
echo "======================================"

# Verificar que la carpeta results existe para guardar el reporte
if [ ! -d "../results" ]; then
  mkdir ../results
fi

echo "Ejecutando Test 01 con datos simulados del sensor..."

# Ejecutar Python inyectando el archivo input_01.txt
py ../scripts/log_sensor_data.py < input_01.txt > temp_output.txt

# Comparar lo que respondió el script vs lo que anotamos en output_01.txt
if diff -w temp_output.txt output_01.txt > /dev/null; then
    echo "[PASSED] La lógica de evasión y recolección es CORRECTA."
    echo "Test_01: PASSED" > ../results/tests_summary.txt
else
    echo "[FAILED] ERROR en la lógica. El comportamiento es diferente al esperado."
    echo "Test_01: FAILED" > ../results/tests_summary.txt
    echo "--- Diferencias (Esperado vs Obtenido) ---"
    diff -u output_01.txt temp_output.txt
fi

# Borrar el archivo basura que usamos para comparar
rm temp_output.txt

echo "Resumen de la prueba guardado en: ../results/tests_summary.txt"
echo "======================================"