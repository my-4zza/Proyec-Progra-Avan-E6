## Lista de Componentes y Hardware 

Este proyecto utiliza una arquitectura de control basada en FPGA para gobernar un chasis móvil de 4 ruedas. A continuación, se detalla la función de cada elemento físico del sistema:

Versión 1.0.0
Fecha: 17/04/2026

* **FPGA Tang Nano 9K:** Es el "cerebro" digital del carrito. Se encarga de ejecutar la lógica de control, procesar las lecturas del sensor LM393 y generar las señales de control (como PWM y dirección) necesarias para mover los motores a través del módulo L298N.

* **Módulo Controlador de Motores L298N (Puente H):** Actúa como el intermediario de potencia. Recibe las señales lógicas de bajo voltaje de la Tang Nano 9K y suministra la corriente de 12V necesaria para hacer girar los motores en ambas direcciones.

* **Regulador de Voltaje LM7805:** Es el encargado de proteger la electrónica sensible. Toma los 12V provenientes de las baterías y los reduce a un voltaje lineal y estable de 5V, con el cual se alimenta la Tang Nano 9K y el sensor.
* **Sensor Óptico/Infrarrojo (con comparador LM393):** Sirve como los "ojos" del carrito. Detecta la presencia de líneas u obstáculos (según la configuración) y envía una señal digital (1 o 0) a la FPGA para que tome decisiones de navegación.
* **Portapilas (12V):** La fuente de alimentación principal. Aloja 3 baterías que en serie suman 12V, proporcionando la energía "cruda" para los motores y la entrada del regulador de voltaje.
* **4 Motores DC (Motorreductores):** Convierten la energía eléctrica del L298N en movimiento mecánico. Al tener una caja reductora integrada, sacrifican un poco de velocidad máxima para entregar un mayor torque (fuerza) al chasis.
* **4 Ruedas de Tracción:** Acopladas a los motores, proporcionan la fricción y el agarre necesarios con el suelo para desplazar el carrito.
* **Chasis y Esqueleto del Carro:** La estructura física (generalmente de acrílico) que soporta y mantiene unidos de forma segura todos los componentes electrónicos, motores y la fuente de alimentación.
* **Mini Protoboard:** Placa de pruebas que facilita la distribución de los voltajes (especialmente las líneas de 5V y Tierra comun) hacia los diferentes sensores y módulos sin necesidad de soldadura.
* **Cables Jumpers (Dupont):** Cables de conexión rápida utilizados para enlazar las señales de control y alimentación entre la FPGA, los sensores, el puente H y la protoboard.
