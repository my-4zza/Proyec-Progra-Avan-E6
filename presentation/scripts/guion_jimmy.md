# Guion de Presentación - Jimmy Loucioss Alarcon Galván
**Rol en el proyecto:** Integración de Sistemas y pruebas
**Duración estimada:** 2 a 3 minutos

## 1. Introducción y Rol
Hola, mi nombre es Jimmy y mi rol fue la integración final de todos las fases anteriores y la resolución de fallas en las pruebas hechas.

## 2. Desarrollo 
Una vez que tuvimos todos los sistemas listos, mi trabajo fue ensamblar las partes y hacer pruebas.
Como pueden ver en la pantalla, realizamos pruebas de cada sistema creando códigos que solo movían un componente a la vez para descartar fallas de hardware.

## 3. Resultados de Pruebas
Logramos integrar el movimiento con el puente h, el sensor ultrasonico, el movimiento del brazo y el electroiman en un solo 
codigo continuo que permitiera al carrito operar de manera 100% autónoma y estable.

## 4. Dificultades y Soluciones
En la etapa final, nos enfrentamos a un fallo crítico de funcionamiento: el motor de la base no respondía a las instrucciones del Arduino, 
a pesar de que la batería entregaba 7.4V.
Y aislando el código descubrimos que el problema era físico.
Ejecutamos un salto de pines de emergencia, reasignando el control del servo del pin analógico A2 al A3 en el código base, 
lo cual devolvió la vida al ensamble inmediatamente.

## 5. Lección Aprendida y Recomendación
La mayor lección aprendida es el valor del diagnóstico modular. Mi recomendación para la instrumentación es: si el sistema falla, divide y vencerás.
Nunca asumas que todo el código está mal; aísla los componentes hasta encontrar el hardware o el pin defectuoso.
