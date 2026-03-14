# Proyec-Progra-Avan-E6: Clasificador de Colores

Este repositorio comprende todas las actividades que se llevarán a cabo para el proyecto Carro Seguidor de Línea Mejorado para la experiencia educativa Programación Avanzada.

## Descripción General
Este proyecto consiste en un carro seguidor de línea autónomo mejorado con la capacidad de clasificar objetos. Mientras el robot avanza por su trayectoria, utiliza un sensor para identificar el color de los objetos (cubos o pelotas) que encuentra en el camino y toma la decisión automática de "recolectarlos" o "descartarlos" mediante un actuador mecánico.

## Cómo ejecutar o replicar este proyecto
    (Nota: Estas instrucciones se irán actualizando conforme avancemos en las etapas del semestre)
1. Revisa la lista de componentes en la carpeta `hardware/` para ensamblar el chasis, los sensores y la electrónica.
2. Consulta los esquemas de conexión en `docs/`.
3. Carga el código principal ubicado en la carpeta `src/` a tu microcontrolador usando el IDE correspondiente.

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
