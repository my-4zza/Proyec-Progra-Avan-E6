## Lista de Componentes y Hardware 

Este proyecto utiliza una arquitectura de control basada en IDE Arduino para controlar un chasis móvil de 4 ruedas. A continuación, se detalla la función de cada elemento físico del sistema:

Versión 2.0.0
Fecha: 15/05/2026

* **Arduino uno:** Es el "cerebro" del carrito. Se encarga de ejecutar la lógica de control, procesar las lecturas del sensor ultrasonico a si como mover el brazo y generar las señales de control (como PWM y dirección) necesarias para mover los motores a través del módulo L298N.

* **Módulo Controlador de Motores L298N (Puente H):** Actúa como el intermediario de potencia. Recibe las señales lógicas de bajo voltaje del Arduino UNO y suministra la corriente de 12V necesaria para hacer girar los motores en ambas direcciones.

* **Sensor ultrasonico:** Este componente es el encargado de hacer las mediciones entre distancias, evitando que el carrito pueda chocar contra alguna superficie y accionar tomas de decisiones en la logica principal.
* **Servo motor:** Para este caso la utilización del servo motor es la de actuar como un cuello para nuestro sensor ultrasonico y así analizar el entorno. 
* **Portapilas (12V):** La fuente de alimentación principal. Aloja 3 baterías que en serie suman 12V, proporcionando la energía "cruda" para los motores y la entrada del regulador de voltaje.
* **4 Motores DC (Motorreductores):** Convierten la energía eléctrica del L298N en movimiento mecánico. Al tener una caja reductora integrada, sacrifican un poco de velocidad máxima para entregar un mayor torque (fuerza) al chasis.
* **4 Ruedas de Tracción:** Acopladas a los motores, proporcionan la fricción y el agarre necesarios con el suelo para desplazar el carrito.
* **Chasis y Esqueleto del Carro:** La estructura física (generalmente de acrílico) que soporta y mantiene unidos de forma segura todos los componentes electrónicos, motores y la fuente de alimentación.
* **Mini Protoboard:** Placa de pruebas que facilita la distribución de los voltajes (especialmente las líneas de 5V y Tierra comun) hacia los diferentes sensores y módulos sin necesidad de soldadura.
* **Cables Jumpers (Dupont):** Cables de conexión rápida utilizados para enlazar las señales de control y alimentación entre la Arduino UNO, los sensores, el puente H y la protoboard.
* **Brazo junto con servomotores:** Este brazo articulado es el encargado de hacer la recoleccion, esta articulacion funciona con la activacion de servomotores que se encuentran acoplados dentro del mismo brazo para su correcto funcionamiento.
