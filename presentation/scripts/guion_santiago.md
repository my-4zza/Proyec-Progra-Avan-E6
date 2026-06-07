# Guion de Presentación - José Santiago Alegría Ponce
**Rol:** Lógica de Navegación y Sensores
**Duración estimada:** 2 a 3 minutos

## 1. Introducción y Rol
Hola soy José Santiago y estuve a cargo de la lógica de navegación de los sensores del carrito: la lógica de navegación autónoma mediante el sensor ultrasónico HC-SR04.

## 2. Desarrollo 
En la pantalla pueden ver la función `leerDistancia()`. En lugar de hacer que el sensor hiciera un barrido tipo radar
constante, lo cual generaba lecturas erráticas por la vibración del chasis, decidimos mantenerlo fijo mirando al frente y dividir la
toma de decisiones en dos zonas de alerta mediante condicionales.

## 3. Resultados de Pruebas
Implementamos una 'Zona de Evasión' para distancias entre 10 y 25 cm, donde el
robot asume que es una pared, frena, mira a los lados y gira. Y una 'Zona de Recolección' para objetos a menos de 10 cm.

## 4. Dificultades y Soluciones
La dificultad principal era que el carrito a veces intentaba recoger la pared si se acercaba demasiado. Lo solucionamos 
afinando los umbrales de distancia en el `loop` principal. Ahora, si detecta algo a menos de 10 cm, detiene los motores de 
inmediato, activa la rutina del electroimán, recoge el objeto, y gira el chasis completo para apartarlo del camino.

## 5. Lección Aprendida y Recomendación
Aprendí que los sensores baratos tienen mucho ruido de rebote. Como recomendación, siempre agreguen una línea de código de 
seguridad para filtrar lecturas nulas, como cuando la duración del pulso devuelve cero, para evitar que el robot se quede congelado esperando una respuesta.
