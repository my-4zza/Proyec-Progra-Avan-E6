Para mantener nuestro código y documentación en orden, todos los integrantes del equipo debemos seguir estas reglas al realizar cambios.

## 1. Uso de Ramas (Branches)

Nunca trabajaremos directamente sobre la rama `main`. La rama `main` es sagrada y solo debe contener código y documentos que funcionen al 100%.

Para trabajar en una nueva tarea, crea una rama descriptiva a partir de `main` usando este formato:
* `feature/nombre-de-la-tarea` (para código nuevo o hardware)
* `fix/nombre-del-error` (para corregir fallos)
* `docs/nombre-del-documento` (para actualizar archivos .md)

**Ejemplos de nombres de ramas válidos:**
* `feature/control-pid`
* `feature/activacion-bomba-agua`
* `fix/calibracion-sensores-ir`
* `docs/actualizar-esquematico`

## 2. Formato de los Mensajes de Commit

Para que nuestro historial sea fácil de leer, usaremos el formato estándar de "Conventional Commits". Cada mensaje debe estar en minúsculas (excepto siglas) y seguir esta estructura:

`tipo: descripción breve de lo que cambiaste`

**Tipos permitidos:**
* `feat:` (Feature) Añadir una nueva funcionalidad o componente.
* `fix:` (Fix) Solucionar un error en el código C/Python o en las conexiones.
* `docs:` (Documentation) Cambios en el README, PROJECT, o comentarios del código.
* `style:` (Style) Ajustes de formato, espacios o limpieza de código (sin afectar la lógica).
* `refactor:` (Refactor) Mejorar el código existente sin añadir cosas nuevas.

**Ejemplos de buenos commits:**
* `feat: integrar lectura de sensores infrarrojos TCRT5000`
* `fix: corregir cálculo del error en la fórmula del PID`
* `docs: agregar los correos institucionales a AUTHORS.md`
* `feat: configurar pin del microcontrolador para el módulo relé`

## 3. Proceso para subir cambios (Pull Requests)

1. Trabaja en tu rama local y haz tus commits siguiendo el formato de arriba.
2. Asegúrate de que tu código en C o Python compile y no tenga errores de sintaxis antes de subirlo.
3. Sube tu rama a GitHub (`git push origin nombre-de-tu-rama`).
4. Abre un **Pull Request (PR)** hacia la rama `main`.
5. Pide a otro integrante del equipo (ej. Azael u otro compañero) que revise tus cambios.
6. Una vez aprobado, el código se puede fusionar (merge) con `main`.

## 4. Estilo de Código
* Mantener el código en C/Python bien comentado, especialmente en la lógica de control de los motores y los umbrales de los sensores.
* Usar nombres de variables descriptivos (ej. `velocidadMotorIzquierdo` en lugar de `v1`).
