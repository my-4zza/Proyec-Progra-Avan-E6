
# Guion de Presentación - Antonio Portilla
**Rol en el proyecto:** Arquitectura de Hardware y Gestión de Potencia

## 1. Introducción y Rol
Hola, mi nombre es Antonio Portilla y en este proyecto me encargué del diseño y la arquitectura de hardware del carrito recolector. Mi objetivo principal fue garantizar que el cerebro del robot, el puente H de tracción y los motores del brazo mecánico tuvieran un suministro de energía estable y seguro sin interferir entre sí.

## 2. Desarrollo (Hardware y Conexiones)
Sabíamos que alimentar todo desde una sola línea iba a colapsar el sistema. Por eso, dividimos la potencia: las baterías de 7.4V alimentan directamente al módulo puente H L298N para darle fuerza bruta a los motores amarillos de tracción. Por otro lado, para proteger el Arduino y alimentar los servos del brazo, implementé una etapa de regulación utilizando integrados LM7805. Esto nos garantizó un voltaje limpio de 5V para la lógica y el control fino de las articulaciones.

## 3. Resultados de Pruebas
Al poner la electrónica a prueba en la pista, la separación de voltajes fue un éxito. El Arduino nunca sufrió reinicios por caídas de tensión cuando el carrito arrancaba, y el módulo electroimán recibía la señal nítida para atrapar los objetos sin generar ruido eléctrico en los demás sensores.

## 4. Dificultades y Soluciones
El reto técnico más grave que enfrentamos ocurrió al calibrar el brazo robótico. Al intentar mover el Hombro y el Alcance al mismo tiempo, el pico de corriente era tan masivo que los reguladores LM7805 entraban en protección térmica y apagaban el sistema en milisegundos. Lo resolvimos combinando hardware y software: ajustamos la mecánica para evitar fricción y aplicamos un modificacion en el código, aislando los movimientos para que el brazo primero se estirara, luego bajara, y finalmente se recogiera antes de subir. Esto dividió el consumo de amperaje a la mitad.

## 5. Lección Aprendida y Recomendación
La mayor lección de instrumentación que me deja este proyecto es que el código perfecto no sirve de nada si tu hardware está ahogado. Como recomendación para cualquier sistema robótico autónomo: siempre deben aislar las etapas de potencia y respetar celosamente las tolerancias de corriente de sus reguladores.
