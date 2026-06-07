# Guion de Presentación - Azael Pérez González
**Rol en el proyecto:** Diseño Mecánico y Cinemática del Brazo
**Duración estimada:** 3 a 4 minutos

## 1. Introducción y Rol
"Hola, mi nombre es Azael Pérez y mi rol en este proyecto fue el diseño mecánico y la cinemática de las articulaciones del carrito. Mi objetivo fue crear una estructura de madera estable que pudiera soportar los movimientos bruscos sin perder el centro de gravedad."

## 2. Desarrollo (Hardware y Mecánica)
"Para el brazo robótico, utilizamos un enfoque de potencia dividida. En la pantalla pueden observar la base y el hombro. Anclamos el servomotor MG995 directamente al hombro porque es la articulación que exige mayor torque para levantar todo el ensamble. Para el alcance y el giro de la base, implementamos motores MOT-110 que nos brindan la precisión necesaria para la recolección."

## 3. Resultados de Pruebas
"Durante las pruebas de movimiento, notamos que si el brazo quedaba extendido, bloqueaba el campo de visión del sensor ultrasónico frontal."

## 4. Dificultades y Soluciones
"El mayor reto fue la colisión física de la madera y la obstrucción del radar. Lo resolvimos programando un 'Modo Tortuga'. Ajustamos los límites de los servos a ángulos extremos pero seguros: el hombro a 160 grados y el alcance a 40 grados. Esto repliega el brazo por completo hacia arriba y atrás, dejando el horizonte 100% libre para la navegación."

## 5. Lección Aprendida y Recomendación
"La lección más grande es que el diseño de las piezas físicas debe ir de la mano con el código. Una recomendación para futuros proyectos es siempre verificar la fricción en las uniones mecánicas; apretar demasiado un tornillo puede disparar el consumo de corriente y quemar un motor."
