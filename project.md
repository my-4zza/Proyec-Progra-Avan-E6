# Carro Seguidor de Línea con Detección de Colores

# Objetivos
**Objetivo General:**
Diseñar y adaptar módulo de selección por color a un carrito seguidor de línea, implementando un FPGA, con lenguaje Python.

**Objetivos Específicos:**
-	Diseñar la estructura del seguidor de línea para la capacidad de clasificar objetos por color
-	Programar el software para el seguimiento de líneas y clasificación de colores mediante un sensor
-	Integrar el Software y hardware para controlar los moteres de carro 
-	Realizar pruebas del funcionamiento del carro, mediante pruebas de circuitos con líneas con obstáculos 


## Producto Mínimo Viable (MVP)
Un carrito que avanza por una línea negra se detiene automáticamente cuando le pones una pieza enfrente, enciende el servo para separarla hacia la izquierda o la derecha (dependiendo de si es un color u otro), y manda un mensaje de texto por Bluetooth a la computadora.

1. Navegación Básica (Hardware)
•	El robot sigue una pista sencilla (un óvalo o una línea recta con una curva ligera).
•	Movimiento a velocidad constante baja-media, un control básico (si sale por la derecha, girar a la izquierda) es suficiente.
2. Clasificación Binaria (El corazón del FPGA)
•	El sensor de color (TCS3200) solo está calibrado para distinguir dos colores muy contrastantes (Rojo vs. Azul, o Blanco vs. Negro).
•	El servomotor SG90 solo tiene dos posiciones programadas (0 grados para un color, 180 grados para el otro).
3. Software "Crudo" (Python)
•	El módulo Bluetooth envía caracteres simples (Ejemplo: R para Rojo, A para Azul).
•	El script de Python corriendo en tu Acer simplemente lee el puerto COM y lo imprime en la consola de comandos/terminal: "Pieza ROJA detectada. Total: 1".


## Diagrama a Bloques del Hardware

## Lista de componentes
### Lista de Materiales (BOM)

| Categoría | Material / Cantidad | Función | Precio |
| :--- | :--- | :--- | :--- |
| **Cerebro y comunicación** | Tarjeta FPGA | Matriz de puertas lógicas programables. | $650 |
| | Módulo Bluetooth HC-05 | Para enviar el inventario en tiempo real a tu código en Python. | $148 |
| | Módulo conversor de nivel lógico (Level Shifter) 3.3V a 5V | Este chip protege el FPGA si se usan sensores que manden señales de 5V. | $66 |
| **Sensores (Entradas)** | Sensor de color TCS3200 | Funciona para clasificación de colores. | $200 |
| | Pololu QTR-8RC | Es el sensor que ayuda a hacer el seguidor de línea. | $80 |
| | Sensor infrarrojo de obstáculos FC-51 | Para detectar si el cubo o pelota entra al mecanismo y el FPGA empiece a leer el color. | $140 |
| **Actuadores (Salidas)** | Módulo Puente H TB6612FNG | Para funcionamiento del carrito. | $120 |
| | 2 Motorreductores DC | Son para el funcionamiento de las llantas. | $170 |
| | 2 Servomotores SG90 | Para el brazo recolector. | $100 |
| **Chasis y mecánica** | Kit de chasis 2WD | Estructura o base del carro. | $175 |
| | Materiales para el brazo recolector | Los materiales de los que haremos el brazo. | Aún pendiente |
| **Energía (Alimentación)** | 4 Baterías Li-Ion 18650 | Para tener buena corriente. | $500 |
| | 1 Portapilas para 18650 | Para poner las pilas ahí. | $100 |
| | Regulador MP1584 | Para reducir el voltaje a 3.3 o 5v y no quemar algunos componentes. | $70 |
| | Paquetes de jumpers | Para conexión. | $140 |

## Roles

### Cronograma del Proyecto

| Actividad | Marzo | Abril | Mayo | Junio | Julio |
| :--- | :---: | :---: | :---: | :---: | :---: |
| Establecimiento de proyecto y definición de componentes | █ | | | | |
| Primera versión de hardware y funcionamiento básico | █ | █ | | | |
| Segunda revisión de hardware y pruebas de campo | | █ | █ | | |
| Prueba de chasis y refinamiento del código | | | █ | █ | |
| Pruebas finales y búsqueda de errores | | | | █ | █ |
| Entrega de proyecto | | | | | █ |
# Módulo de Selección por Color a Carrito Seguidor de Línea

Este documento contiene los créditos del equipo para la experiencia educativa de **Programación Avanzada**.

**Docente:** José Alfonso Dominguez Chavez

## Integrantes del Proyecto

| Nombre del Integrante | Rol de Trabajo |
| :--- | :--- |
| **Azael Pérez González** | Representante. |
| **José Santiago Alegría Ponce** | Sub representante y ayudante general. |
| **Juan Carlos Hernández García** | Programador. |
| **Alfredo Cid García** | Programador |
| **Antonio De Jesus Portilla Durán** | Encargado de hardware. |
| **Jimmy Loucioss Alarcon Galván** | Encargado de hardware. |
