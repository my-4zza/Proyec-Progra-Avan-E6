# Proyec-Progra-Avan-E6: Clasificador de Colores

Este repositorio comprende todas las actividades que se llevarán a cabo para el proyecto Carro Seguidor de Línea Mejorado para la experiencia educativa Programación Avanzada.

## Descripción General
Este proyecto consiste en un carro seguidor de línea autónomo mejorado con la capacidad de clasificar objetos. Mientras el robot avanza por su trayectoria, utiliza un sensor para identificar el color de los objetos (cubos o pelotas) que encuentra en el camino y toma la decisión automática de "recolectarlos" o "descartarlos" mediante un actuador mecánico.

## Cómo ejecutar o replicar este proyecto
    (Nota: Estas instrucciones se irán actualizando conforme avancemos en las etapas del semestre)
1. Revisa la lista de componentes en la carpeta `hardware/` para ensamblar el chasis, los sensores y la electrónica.
2. Consulta los esquemas de conexión en `docs/`.
3. Carga el código principal ubicado en la carpeta `src/` a tu microcontrolador usando el IDE correspondiente.

## [17-04-2026] - Ensamblaje y Ruteo de Potencia/Control

### Agregado y Configurado

* **Ensamblaje del chasis 4WD y Tracción Diferencial:** * Se agruparon físicamente los motores en paralelo según su lado físico (izquierdo y derecho) para operar bajo un esquema de dirección tipo tanque (differential drive).
  * Los pares de motores izquierdo y derecho se conectaron a las borneras de salida correspondientes del puente H L298N (OUT1/OUT2 y OUT3/OUT4 respectivamente).

* **Sistema de Alimentación y Nodo Central (Fuerza Bruta):** * Se estableció el puente H L298N como el nodo principal de distribución de corriente.
  * El voltaje positivo directo del banco de baterías (7.4V - 8.4V nominal) se enrutó a la entrada de `12V` del L298N.
  * Se unificó el bus negativo de las baterías en la terminal `GND` del L298N, estableciendo la tierra común para todo el vehículo.

* **Etapa de Regulación Lógica (Protección del Cerebro):** * Se integró un regulador de voltaje lineal L7805CV en derivación desde la etapa de potencia.
  * **Conexiones:** Entrada (Pin 1) puenteada a los `12V` del L298N; Tierra (Pin 2) unida al `GND` común; Salida (Pin 3) proveyendo exactamente 5V.
  * Esta salida de 5V se ruteó directamente a la entrada de alimentación de 5V de la FPGA para alimentar su electrónica interna sin exponerla a los picos de los motores.

* **Integración y Calibración de Sensores Infrarrojos (HW-511):** * Se montaron los módulos con el comparador LM393 integrado para la lectura de la pista.
  * **Seguridad de Voltaje:** Se conectó el pin `V+` de los sensores directamente al pin de `3.3V` de la FPGA (en lugar de 5V). Esto garantiza que la salida digital (`S`) opere bajo la norma `LVCMOS33`, protegiendo los puertos de entrada lógicos de la placa.
  * Se realizó la calibración manual de sensibilidad mediante los potenciómetros integrados ("103") para la correcta discriminación del contraste blanco/negro de la línea.

* **Ruteo de Control Lógico (FPGA $\rightarrow$ L298N):** * Se cableó el bus de datos desde los bancos I/O de la FPGA hacia los pines direccionales del controlador de motores.
  * **Asignación:** Pines asignados a `IN1` e `IN2` para el control de sentido del par motor izquierdo; `IN3` e `IN4` para el par motor derecho.
  * **Estado actual de PWM:** Los habilitadores `ENA` y `ENB` se mantuvieron con *jumpers* de hardware a 5V lógicos, configurando el sistema para pruebas iniciales con un control "Todo o Nada" (On/Off combinacional) antes de implementar señales PWM en Verilog.

## [17-04-2026] - Mejoras Futuras y Cambios Necesarios

* **Cambio del chasis:** * Se Observa que se nesecita un cambio de chasis para un mejor desplazamiento debido a que el usado actualmente presenta fallas al momento de tomar vueltas o curvas por su lento movimiento y dificultad para hacerlo de manera eficiente.
  
* **Mejoras Para su Movilidad:** * Tras hacer el cambio del chasis se haran los cambios necesarios para que de una manera mas facil permita esto cambios de direccion al momento de dar giros para su manejo
* Debido a sus cuatro ruedas que no permiten su maxima eficacia de maniobrabilidad,se hara un cambio a un modelo de 3 ruedas para mayor eficacia de manejo y control de direccion para este caso.

 * **Obtencion de Materiales:** Se buscaran los materiales necesarios para hacer las mejoras que se presenten o posibles defectos de piezas que se tengan presentes en un futuro
 * Se buscaran los materiales necesarios para la creacion del brazo y su movilidad del mismo
 * Se buscara la manera de tener mas espacio para poder ubicar el brazo movible 
  
## Estructura del Repositorio

### Archivos Raíz (Top-level)
* **`README.md`** — Descripción general, instrucciones de ejecución y guía del repositorio.
* **`PROJECT.md`** — Título, objetivos, MVP, diagrama a bloques, componentes y cronograma.
* **`AUTHORS.md`** — Lista de integrantes del equipo y correos institucionales.
* **`CHANGELOG.md`** — Historial detallado de versiones y cambios por archivo.
* **`LICENSE`** — Licencia de uso del proyecto.
* **`.gitignore`** — Patrones para excluir binarios, datos pesados y archivos temporales.
* **`CONTRIBUTING.md`** — Guía de commits, ramas y manejo de archivos grandes (Git LFS).

### Carpetas del Proyecto
* **`src/`** — Código fuente principal: `python_no_opt.py` y `c_no_opt.c` (incluye módulos auxiliares).
* **`docs/`** — Documentación visual: diagramas de bloques, fotos de montaje físico y datasheets.
* **`results/`** — Mediciones de rendimiento: tiempos de ejecución (`csv`), salidas crudas y gráficas comparativas.
* **`tests/`** — Casos de prueba: pequeños verificables, escalados y script `run_tests.sh`.
* **`hardware/`** — Detalles físicos: Lista de materiales (BOM) y esquemáticos electrónicos.
* **`scripts/`** — Utilidades de automatización:
    * `bench_python.sh` / `bench_c.sh`: Automatización de pruebas de rendimiento.
    * `setup_env.sh`: Preparación del entorno y dependencias.
    * `deploy.sh`: Instrucciones para flashear el hardware.
* **`data/`** — Datos de entrada grandes y registros de telemetría (gestionado con Git LFS).

## Enlaces Rápidos a Entregables
* Detalles técnicos, Objetivos y Cronograma (PROJECT.md)](./PROJECT.md)
* Equipo de Trabajo (AUTHORS.md)](./AUTHORS.md)
* Historial de Versiones y Etapas (CHANGELOG.md)](./CHANGELOG.md)
