# Carrito recolector de objetos

# Objetivos
**Objetivo General:**
Diseñar y coordinar los motores del carrito con el imán recolector y el sensor de proximidad para autonomía del carrito 

**Objetivos Específicos:**
-	Diseñar la estructura del carrito recolector y optimizar espacio dentro del chasis.
-	Programar el software para la coordinación de las cuatro ruedas con el sensor que viene a ser el "ojo" del carrito
-	Integrar el Software y hardware para controlar los moteres de carro 
-	Realizar pruebas del funcionamiento del carro, mediante pruebas de circuitos con obstáculos y callejones.

## Producto Mínimo Viable (MVP)
Un carrito autónomo que al toparse con un obstáculo manda una señal al sensor para que busque a la izquiera o derecha una alternativa de camino y si encuentra una ruta libre gira hacia esa dirección, si no encuentra camino libre se activa el brazo con el imán para quitar el obstáculo

1. Navegación Básica (Hardware)
- El robot sigue una linea recta hasta toparse con el objetivo y analisa posibles rutas
- Movimiento a velocidad constante baja-media
2. Módulo de navegación
-	El sensor ultrasónico solo está calibrado para distinguir objetos grandes o paradedes (Es posible una integración de un segundo sensor)
-	Los servomotores SG90 se encargarán de mover la base de la garra y extenderla y retraerla, teniendo en cuenta que se pueden mover 180 grados.
3. Software "Crudo" (C Arduino)
-	El sensor ultrasónico manda señales a la arduino que indican las posibles salidas.

## Diagrama a Bloques del Hardware

<img width="785" height="564" alt="Diagrama_bloques_carrito" src="https://github.com/user-attachments/assets/e86c3280-cd0b-4955-81c5-d8231887d215" />

Leyenda de conexiones:
---(Señal)--->  : Conexión digital simple (1 bit)
===(PWM)=====>  : Conexión de múltiples bits (Bus de datos)

| Categoría | Componente | Descripción |
| :--- | :--- | :--- |
| **Cerebro** | **Tarjeta Arduino UNO** | Procesamiento lógico central y control de periféricos. |
| **Visión** | **Sensor Ultrasónico** | Interfaz para control inalámbrico y recepción de comandos. |
| **Brazo** | **Servomotor SG90** |Control de brazo mecánico y retirar objetos del camino |
| **Estructura** | **Kit de chasis 2WD** | Base mecánica con cuatro ruedas de tracción |

---

## Sistema de Alimentación y Potencia

Para garantizar la autonomía y estabilidad del robot, se utiliza una configuración de celdas de litio con regulación de voltaje:

* **Baterías:** 4x Li-Ion 18650 (Alta densidad energética).
* **Soporte:** 1x Portapilas para celdas 18650.

---

## Sensores Integrados

El robot utiliza un único sensor para interactuar con su entorno de manera inteligente (Se planea integrar más sensores)

1.  **Sensor Ultrasónico(HC-SR04):** Permite identificar superficies a dos distancias variables y con ditinta acción

---

## Próximos Pasos
- [ ] Mejorar el reconocimiento de objetivos con el sensor HC-SR04
- [ ] Implementación de más sensores de identificación 


## Lista de componentes
### Lista de Materiales (BOM)

| Categoría | Material / Cantidad | Función | Precio |
| :--- | :--- | :--- | :--- |
| **Cerebro y comunicación** | Tarjeta Arduino UNO | placa electrónica basada en un microcontrolador | $400 |
| **Sensores (Entradas)** | Sensor de color TCS3200 | Funciona para clasificación de colores. | $200 |
| | 1 Sensor Ultrasónico HC-SR04 | Visión del carrito para detectar objetivos | $60 |
| **Actuadores (Salidas)** | Módulo Puente H TB6612FNG | Para funcionamiento del carrito. | $120 |
| | 3 Servomotores SG90 | Para el brazo recolector. | $150 |
| **Chasis y mecánica** | Kit de chasis 2WD | Estructura o base del carro. | $175 |
| | Materiales para el brazo recolector | Los materiales de los que haremos el brazo. | Aún pendiente |
| **Energía (Alimentación)** | 4 Baterías Li-Ion 18650 | Para tener buena corriente. | $500 |
| | 1 Portapilas para 18650 | Para poner las pilas ahí. | $100 |
| | Paquetes de jumpers | Para conexión. | $140 |


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
