# Proyec-Progra-Avan-E6: Carrito recolector de objetivos

Este repositorio comprende todas las actividades que se llevarán a cabo para el proyecto del carrito recolector de objetos para la experiencia educativa Programación Avanzada.
## Avance del 70%

### En el siguiente link se muestran los avances hechos hasta el momento

https://drive.google.com/drive/folders/1OujwxJhWj53Z4z1XMeig9Y1i139Go-MI?usp=sharing

## Descripción General
Este proyecto consiste en un carrito recolector de objetos autónomo. Mientras el robot avanza por su trayectoria y evita obstaculos, utiliza un sensor para identificar objetos frente a el  y con la ayuda de un brazo con un electroiman y garra (intercambiable) recogera objetos metalicos que puedan estorbar en el camino teniendo estas dos alternativas de recoleccion. 

## Cómo ejecutar o replicar este proyecto
    (Nota: Estas instrucciones se irán actualizando conforme avancemos en las etapas del semestre)
1. Revisa la lista de componentes en la carpeta `hardware/` para ensamblar el chasis, los sensores y la electrónica.
2. Consulta los esquemas de conexión en `docs/`.
3. Carga el código principal ubicado en la carpeta `src/` a tu microcontrolador usando el IDE correspondiente.

## [15-05-2026] - Ensamblaje, pruebas y conexiones

### Agregado y Configurado

* **Ensamblaje del chasis 4WD y Tracción Diferencial:** * Se agruparon físicamente los motores en paralelo según su lado físico (izquierdo y derecho) para operar bajo un esquema de dirección tipo tanque (differential drive).
  * Los pares de motores izquierdo y derecho se conectaron a las borneras de salida correspondientes del puente H L298N (OUT1/OUT2 y OUT3/OUT4 respectivamente).

* **Sistema de Alimentación y Nodo Central (Fuerza Bruta):** * Se estableció el puente H L298N como el nodo principal de distribución de corriente.
  * El voltaje positivo directo del banco de baterías (11.4V - 10.5V nominal) se enrutó a la entrada de `12V` del L298N.
  * Se unificó el bus negativo de las baterías en la terminal `GND` del L298N, estableciendo la tierra común para todo el vehículo.

* **Etapa de alimetacion de la lógica (Protección del Cerebro):** * Mediante el puerto vin de nuestro arduino alimentamos nuestro microcontrolador y evitara perdida de potencia, mientras que el modulo 129N mediante su bornera de +5V alimenta la parte logica, sensores y servomotores.
  * **Asignación:** Pines asignados a `IN1` e `IN2` para el control de sentido del par motor izquierdo; `IN3` e `IN4` para el par motor derecho.

## [15-05-2026] - Mejoras Futuras y Cambios Necesarios

* **Evaluacion y analisis de funcionalidad de electroiman:** * Tendremos en cuenta la utilizacion ya sea de la garra para la recoleccion o el electroiman, son dos opciones que tenemos para nuestro brazo recolector y estamos en proceso de evaluar caul será más conveniente. 

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
