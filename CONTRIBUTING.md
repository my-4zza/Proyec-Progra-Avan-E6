# Guías de Contribución y Estándares de Desarrollo

Con el propósito de mantener la integridad, trazabilidad y organización del código fuente y la documentación del proyecto "Carrito Recolector de Objetos", todos los miembros del equipo de la experiencia educativa de Programación Avanzada deberán apegarse estrictamente a las siguientes directrices al proponer e integrar cambios en el repositorio.

## 1. Gestión de Ramas (Branching Model)

Queda estrictamente prohibido realizar confirmaciones (*commits*) directas sobre la rama `main`. La rama `main` es considerada el entorno de producción y únicamente debe alojar código y documentación que haya sido probada y validada en su totalidad.

Para el desarrollo de nuevas asignaciones, se deberá crear una rama descriptiva derivada de `main` respetando la siguiente nomenclatura:

* `feature/nombre-de-la-tarea` (Destinada a la implementación de nuevo código, módulos o integraciones de hardware).
* `fix/nombre-del-error` (Destinada a la depuración y corrección de fallos en el sistema).
* `docs/nombre-del-documento` (Destinada a la creación o modificación de archivos de documentación `.md`).

**Ejemplos de nomenclatura válida para este proyecto:**
* `feature/control-brazo-mearm`
* `feature/activacion-electroiman`
* `fix/calibracion-sensor-ultrasonico`
* `docs/actualizar-esquematico-potencia`

## 2. Estandarización de Mensajes de Commit

Para garantizar la legibilidad y el seguimiento eficiente en el historial de versiones (`CHANGELOG.md`), se adoptará el estándar "Conventional Commits". Cada mensaje deberá redactarse en minúsculas (con excepción de siglas técnicas) y estructurarse de la siguiente manera:

`tipo: descripción concisa de la modificación realizada`

**Tipologías permitidas:**

* `feat:` (*Feature*) Integración de una nueva funcionalidad, sensor o actuador.
* `fix:` (*Fix*) Resolución de un error lógico en el código (C++/Arduino o Python) o fallos de conexión.
* `docs:` (*Documentation*) Actualizaciones en el `README.md`, `PROJECT.md`, esquemáticos o comentarios en el código fuente.
* `style:` (*Style*) Modificaciones de formato, indentación o limpieza de código que no alteren la lógica de ejecución.
* `refactor:` (*Refactor*) Reestructuración del código existente para mejorar su eficiencia o legibilidad sin añadir nuevas características.

**Ejemplos de confirmaciones adecuadas:**
* `feat: integrar rutina de recolección y lectura del sensor HC-SR04`
* `fix: mitigar caída de tensión en reguladores LM7805 durante picos de corriente`
* `docs: anexar declaraciones de consentimiento al directorio de presentación`
* `feat: asignar y configurar pin digital para el módulo electroimán`

## 3. Protocolo de Integración de Cambios (Pull Requests)

El flujo de trabajo colaborativo deberá seguir el siguiente procedimiento de validación:

1.  Desarrollar los cambios requeridos en la rama local asignada, registrando confirmaciones bajo el estándar previamente descrito.
2.  Verificar exhaustivamente que el código fuente compile sin errores de sintaxis o advertencias críticas antes de proceder a la subida.
3.  Subir la rama al repositorio remoto en GitHub mediante el comando: `git push origin nombre-de-la-rama`.
4.  Aperturar una solicitud de integración (*Pull Request* - PR) apuntando hacia la rama `main`.
5.  Solicitar la revisión de código (*Code Review*) a un mínimo de un integrante del equipo.
6.  Proceder con la fusión (*merge*) hacia la rama `main` de manera exclusiva tras haber obtenido la aprobación correspondiente.

## 4. Convenciones de Estilo de Código

* Documentar adecuadamente el código fuente mediante comentarios descriptivos, haciendo especial énfasis en la lógica de control de tracción diferencial, la cinemática de los servomotores y los umbrales de detección del sensor ultrasónico.
* Emplear una nomenclatura descriptiva y semántica para la declaración de variables y funciones (e.g., utilizar `velTraccion` o `posHombroActual` en lugar de identificadores ambiguos como `v1` o `p1`).

## 5. Gestión de Archivos Binarios y de Gran Tamaño (Git LFS)

Para preservar la eficiencia y velocidad de clonado del repositorio, queda estrictamente prohibida la subida directa de archivos binarios de gran tamaño (tales como material audiovisual extenso, ejecutables o conjuntos de datos masivos) mediante confirmaciones estándar.

Si la naturaleza técnica de la aportación exige la inclusión de archivos superiores a 50 MB, el desarrollador responsable está obligado a utilizar la herramienta **Git LFS** (*Large File Storage*).

**Procedimiento operativo para Git LFS:**
1.  Inicializar la herramienta en la terminal local: `git lfs install`
2.  Declarar la extensión o archivo específico a rastrear (ejemplo para video): `git lfs track "*.mp4"`
3.  Confirmar obligatoriamente el archivo `.gitattributes` generado por el sistema.
4.  Proceder con el ciclo estándar de control de versiones (`git add`, `git commit` y `git push`) para el archivo de gran tamaño.
