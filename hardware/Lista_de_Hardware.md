## Lista de Componentes y Hardware 

Este proyecto utiliza una arquitectura de control basada en IDE Arduino para controlar un chasis móvil de 4 ruedas. A continuación, se detalla la función de cada elemento físico del sistema:

Versión 2.0.1
Fecha: 07/06/2026

* **Arduino uno:** Es el "cerebro" del carrito. Se encarga de ejecutar la lógica de control, procesar las lecturas del sensor ultrasonico a si como mover el brazo y generar las señales de control (como PWM y dirección) necesarias para mover los motores a través del módulo L298N.

* **Módulo Controlador de Motores L298N (Puente H):** Actúa como el intermediario de potencia. Recibe las señales lógicas de bajo voltaje del Arduino UNO y suministra la corriente de 12V necesaria para hacer girar los motores en ambas direcciones.

* **Sensor ultrasonico:** Este componente es el encargado de hacer las mediciones entre distancias, evitando que el carrito pueda chocar contra alguna superficie y accionar tomas de decisiones en la logica principal.
* **Servo motor(de torque potente):** Para este caso la utilización del servo motor es la de actuar como un cuello para nuestro sensor ultrasonico y así analizar el entorno. 
* **Portapilas (12V):** La fuente de alimentación principal. Aloja 3 baterías que en serie suman 12V, proporcionando la energía "cruda" para los motores y la entrada del regulador de voltaje.
* **4 Motores DC (Motorreductores):** Convierten la energía eléctrica del L298N en movimiento mecánico. Al tener una caja reductora integrada, sacrifican un poco de velocidad máxima para entregar un mayor torque (fuerza) al chasis.
* **4 Ruedas de Tracción:** Acopladas a los motores, proporcionan la fricción y el agarre necesarios con el suelo para desplazar el carrito.
* **Chasis y Esqueleto del Carro:** La estructura física (generalmente de acrílico) que soporta y mantiene unidos de forma segura todos los componentes electrónicos, motores y la fuente de alimentación.
* **Mini Protoboard:** Placa de pruebas que facilita la distribución de los voltajes (especialmente las líneas de 5V y Tierra comun) hacia los diferentes sensores y módulos sin necesidad de soldadura.
* **Cables Jumpers (Dupont):** Cables de conexión rápida utilizados para enlazar las señales de control y alimentación entre la Arduino UNO, los sensores, el puente H y la protoboard.
* **Brazo junto con servomotores:** Este brazo articulado es el encargado de hacer la recoleccion, esta articulacion funciona con la activacion de servomotores que se encuentran acoplados dentro del mismo brazo para su correcto funcionamiento.
* **Modulo Electroiman 5v 10n 1kg Con Driver Arduino:** Es el actuador final del brazo robótico, encargado de ejecutar la recolección física de los objetivos. Funciona mediante una bobina interna que genera un campo magnético concentrado capaz de levantar hasta 1 kg de fuerza (10 Newtons) al energizarse. La gran ventaja de este componente es su circuito de control integrado en la PCB (driver con transistor), el cual permite activar y desactivar el imán de forma segura mediante una señal digital de baja corriente (SIG) directamente desde el microcontrolador, aislando la etapa de potencia y protegiendo el sistema mediante un diodo flyback que absorbe las corrientes de retorno inductivo.
* **4 reguladores lm7805** Estos componentes son el corazón del sistema de alimentación. Se encargan de tomar el voltaje crudo de las baterías y reducirlo a unos 5V limpios y estables. Utilizar cuatro reguladores es una excelente decisión de diseño para dividir la carga de corriente; en lugar de exigirle todo a uno solo, se distribuye la alta demanda de los servomotores, aislando el ruido eléctrico y evitando caídas de tensión que puedan reiniciar la placa de control.
* **disipador de calor**Elemento mecánico indispensable para la etapa de potencia. Dado que los reguladores LM7805 son de tecnología lineal, el "exceso" de voltaje que recortan de la batería se transforma directamente en calor. El disipador de aluminio absorbe y dispersa esta temperatura hacia el aire, evitando que los integrados alcancen su límite térmico y se apaguen por autoprotección al forzar los motores.
* **2 pilas de 18 A650**Fuente de energía principal del prototipo. Son celdas recargables de iones de litio de alta capacidad que, al conectarse en serie, entregan un voltaje nominal de 7.4V (hasta 8.4V completamente cargadas). Este es el voltaje de entrada perfecto: proporciona los picos de corriente (amperaje) masivos que exigen los motores para generar torque, y mantiene un margen excelente para que los reguladores LM7805 trabajen sin sobrecalentarse en exceso.
