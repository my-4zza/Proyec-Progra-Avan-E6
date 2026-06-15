# Proyec-Progra-Avan-E6: Carrito recolector de objetos

Este repositorio comprende todas las actividades que se llevarán a cabo para el proyecto del carrito recolector de objetos para la experiencia educativa Programación Avanzada.

## Características Principales
* **Tracción Diferencial:** Movimiento controlado mediante puente H L298N y PWM para giros estables sobre su propio eje.
* **Navegación Autónoma:** Detección de obstáculos y evasión de paredes mediante sensor ultrasónico HC-SR04 con algoritmos de filtrado de ruido.
* **Brazo Robótico Articulado:** Cinemática de 3 grados de libertad (DOF) controlada por servomotores de alto torque.
* **Recolección Magnética:** Módulo electroimán integrado con diodo de protección para manipulación segura de objetos metálicos.
* **Potencia Aislada:** Banco de baterías dedicado para tracción y reguladores LM7805 en paralelo para la lógica y servomotores, previniendo caídas de tensión.

# Evidencia en Video | Etapa 4 (Final)
Se adjunta un video demostrando el proceso, conexiones y funcionamiento del proyecto final (dar click a la imagen): 
<div align="center">

[![Proyecto Carrito Recolector de Objetos](https://img.youtube.com/vi/rHxLL-gxWDA/0.jpg)](https://www.youtube.com/watch?v=rHxLL-gxWDA)

</div>

## En el siguiente link se muestran los avances y resultados realizados
### Avances:
[AVANCES ETAPA 3](https://uvmx-my.sharepoint.com/:f:/g/personal/zs24013146_estudiantes_uv_mx/IgDzvoVnMy4NRpvYgp8nVLekASA-eiMD-VeWL5L-A01x4uM?e=aMcDHj)
### Resultados:
[RESULTADOS ETAPA 3](https://drive.google.com/drive/folders/1OujwxJhWj53Z4z1XMeig9Y1i139Go-MI?usp=sharing)

## Descripción General
Este proyecto consiste en un carrito recolector de objetos autónomo. Mientras el robot avanza por su trayectoria y evita obstaculos, utiliza un sensor para identificar objetos frente a el  y con la ayuda de un brazo con un electroiman y garra (intercambiable) recogera objetos metalicos que puedan estorbar en el camino teniendo estas dos alternativas de recoleccion. 

## Cómo ejecutar o replicar este proyecto
    (Nota: Estas instrucciones se irán actualizando conforme avancemos en las etapas del semestre)
1. Revisa la lista de componentes en la carpeta `hardware/` para ensamblar el chasis, los sensores y la electrónica.
2. Consulta los esquemas de conexión en `docs/`.
3. Carga el código principal ubicado en la carpeta `src/carro_recolectorV1.5.ino` a tu microcontrolador usando el IDE correspondiente.

## [04-06-2026] - Ensamblaje, pruebas y conexiones

### Agregado y Configurado

* **Ensamblaje del chasis 4WD y Tracción Diferencial:** * Se agruparon físicamente los motores en paralelo según su lado físico (izquierdo y derecho) para operar bajo un esquema de dirección tipo tanque (differential drive).
  * Los pares de motores izquierdo y derecho se conectaron a las borneras de salida correspondientes del puente H L298N (OUT1/OUT2 y OUT3/OUT4 respectivamente).

* **Sistema de Alimentación y Nodo Central (Fuerza Bruta):** * Se estableció el puente H L298N como el nodo principal de distribución de corriente.
  * El voltaje positivo directo del banco de baterías (11.4V - 10.5V nominal) se en rutó a la entrada de `12V` del L298N y se agrega el uso de otro banco de pilas(7.4V - 8V).
  * Se unificó el bus negativo de las baterías en la terminal `GND` del L298N, estableciendo la tierra común para todo el vehículo.

* **Etapa de alimetacion de la lógica (Protección del Cerebro):** * Mediante el puerto vin de nuestro arduino alimentamos nuestro microcontrolador y evitara perdida de potencia, mientras que el modulo 129N mediante su bornera de +5V alimenta la parte logica, sensores y servomotores.
  * se ocupan 4 reguladores 7805 para distribuir la energia a los servomotores, jumto a un disipador de calor, para evitar la sobrecarga de cada 7805
  * **Asignación:** Pines asignados a `IN1` e `IN2` para el control de sentido del par motor izquierdo; `IN3` e `IN4` para el par motor derecho.

* **Etapa de de brazo (movimiento mecanico):** * Mediante el archivo en `docs/Instrucciones_montaje.md` se hace el armado del brazo junto a los servomotores, siguiendo el orden descrito en el manual del brazo.
  * Se hace la integracion del electroiman, en el lugar donde iria la garra, debido a falta de fuerza de la garra al momento de cargar objetos.
  *  **Asignación** Pin asignado al electroiman D13 para la activacion y desactivación del mismo junto al funcionamiento al del brazo.
    
## Integracion de los sistemas. 
En la integracion de los sistemas es mucho mas efectivo en cuanto ala recoleccion, gracias ala ayuda del eletroimán y las ordenes de activacion para un funcionamiento optimo. 
Creando una buena armonizacion entre los sistemas de control y de potencia, cuiadando en no hacer malas conexiones para evitar algun cortocircuito o quemaduras para los componenetes fisicos. 

## [15-06-2026] - Presentación, Documentación Final y Actualizaciones de Hardware

* **Actualización de Actuadores:** Durante las pruebas físicas finales, se detectó que el brazo extendido exigía un torque que colapsaba la energía de la placa. Por ello, se retiraron los servomotores originales y se cambiaron por servos grandes de alto torque. Este cambio aportó la robustez mecánica para levantar la carga sin generar picos mortales de consumo eléctrico.
* **Producción Audiovisual:** Se integró la evidencia final del proyecto en formato de video, incluyendo subtítulos para mayor accesibilidad. 
* **Aprobación del Equipo:** Todos los integrantes del equipo firmaron y otorgaron su consentimiento explícito y voluntario para que su imagen, voz y participación sean incluidas y publicadas en el repositorio.

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
    * `bench_python.sh` / `bench_c.sh` — Automatización de pruebas de rendimiento.
    * `setup_env.sh` — Preparación del entorno y dependencias.
    * `deploy.sh` — Instrucciones para flashear el hardware.
* **`data/`** — Datos de entrada grandes y registros de telemetría (gestionado con Git LFS).
* **`presentation/`** — Presentacion e integrantes

## Enlaces Rápidos a Entregables
* [Detalles técnicos, Objetivos y Cronograma (PROJECT.md)](./PROJECT.md)
* [Equipo de Trabajo (AUTHORS.md)](./AUTHORS.md)
* [Historial de Versiones y Etapas (CHANGELOG.md)](./CHANGELOG.md)
* [Créditos y Metadatos del Video Final (credits.md)](./presentation/credits.md)
* [Marcas de Tiempo del Video (Timestamps.md)](./presentation/Timestamps.md)
