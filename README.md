# Tarea-3
# Simulador Gráfico de Dispositivos Domóticos  
**Curso:** Diseño y Programación Orientados a Objetos  
**Semestre:** 1° Semestre 2025  
**Tarea 3:** Simulador gráfico en C++ del patrón de diseño *Publicador–Suscriptor*  

---

## 🔍 Descripción General

Esta tarea busca implementar en **C++ y Qt** un simulador gráfico que reproduce el patrón de diseño *Publisher–Subscriber*, similar al desarrollado en la Tarea 2 con Java y JavaFX.

El simulador permite crear:
- Un publicador de **URLs de videos**
- Un publicador de **posiciones GPS de un automóvil**

Ambos publicadores requieren nombre y tópico. Se sugiere usar `QInputDialog::getText(...)` para solicitar esta información.

---

## 🎯 Objetivos

- Modelar objetos reales como software.
- Extender clases para cumplir nuevos requerimientos.
- Analizar código C++ para identificar clases y relaciones.
- Compilar y ejecutar C++ desde consola.
- Configurar un entorno con Qt y C++.
- Usar Git como sistema de control de versiones.
- Preparar entregas de software (README, documentación).
- Familiarizarse con desarrollo **iterativo e incremental**.
- Crear aplicaciones gráficas usando la biblioteca Qt.

---

## 🖼️ Interfaz Gráfica

La aplicación gráfica contiene:
- **Izquierda:** dos publicadores (uno para *Video*, otro para *GPS*).
- **Derecha:** dos suscriptores:
  - Uno muestra un botón con la última URL publicada.
  - Otro muestra el movimiento del móvil en su propio panel, incluyendo tiempo y coordenadas.

> Al presionar el botón del suscriptor de video, se reproduce el video correspondiente.

El programa debe ejecutarse desde **QtCreator**.

---

## ⚙️ Funcionalidad por tipo de Publicador

### 🎬 Publicador y suscriptor de videos

- Muestra un campo de texto para ingresar la URL del video.
- Usa componentes como `QLabel` y `QLineEdit`.
- El suscriptor muestra un botón (`QPushButton`) con el último URL.
- Al presionar el botón, el video se reproduce.

📷 **Figura 1:** Reproductor de video al presionar el botón  
(Ejemplo de código: http://profesores.elo.utfsm.cl/~agv/elo329/1s25/Assignments/T3/VideoPlayer/)

---

### 📍 Publicador y suscriptor de posiciones GPS

- Al crear el publicador, se solicita seleccionar un archivo `.txt` con posiciones.
- Formato del archivo (una línea por posición):

<tiempo> <posición x> <posición y>

- `GPSCarPublisher` lee e interpola posiciones, enviando una por segundo.
- El suscriptor actualiza visualmente un círculo en movimiento.
- También se muestra el tiempo y coordenadas (x, y) en la ventana.

📷 **Figura 2:** Vista de posición móvil (con círculo y datos numéricos)  
(Ejemplo útil: http://profesores.elo.utfsm.cl/~agv/elo329/1s25/Assignments/T3/MovingCircle/)

---

## 🧪 Etapas de Desarrollo

El desarrollo debe ser **iterativo e incremental**, entregando una solución funcional en cada fase parcial.

### Etapa 1: Publicador y suscriptor de videos

- Implementar clases: `Topic`, `Broker`, `Component`, `Publisher`, `Subscriber`.
- Agregar: `VideoPublisher`, `VideoFollower`.
- Al presionar ENTER en el campo de texto:
- Se publica el URL.
- Se borra el campo.
- El botón del suscriptor se actualiza.
- El botón aún no reproduce el video.
- Interfaz creada con `Stage1.cpp`.

🔁 Entregar todas las clases de esta etapa.

---

### Etapa 2: Reproducción de video

- `VideoFollower` ahora responde al botón.
- Al presionar, se reproduce el video en un reproductor gráfico.

🎥 Videos para prueba:
- http://profesores.elo.utfsm.cl/~agv/elo329/1s22/Assignments/20220430_100849.mp4  
- http://profesores.elo.utfsm.cl/~agv/elo329/1s22/Assignments/20220430_101027.mp4

---

### Etapa 3: Publicador de GPS

- Crear `GPSCarPublisher` (hereda de `Publisher`).
- Se usa `QFileDialog` para seleccionar archivo de coordenadas.
- El publicador emite una posición cada segundo con interpolación lineal.
- El suscriptor:
- Muestra tiempo y coordenadas (x, y) en una ventana separada.
- No incluye aún la animación del círculo.

📤 Entregar:
- Clases implementadas.
- Archivo de entrada usado.

---

### Etapa 4: Funcionalidad completa

Se implementan **todas las funcionalidades** descritas en las secciones 2 y 3:
- Video funcional
- Movimiento del círculo
- Dos publicadores / dos suscriptores

---

### Etapa 5 (Extra-crédito): Control de volumen

🎁 **+8 puntos** (nota máxima = 100)

- Incorporar `QSlider` horizontal para ajustar el volumen del video.
- Si se implementa esta parte, debe mencionarse **explícitamente en este README**.

---

## 📦 Entrega

- Solo se entrega **la última etapa alcanzada**.
- Subir un **link al repositorio GitHub/GitLab** en AULA.
- Dar acceso a los ayudantes.
- No se entrega `makefile`.
- Debe incluirse:
- Código fuente completo.
- Diagrama de clases (de la última etapa).
- Documentación adicional (formato PDF o HTML).

📚 Ver [normas de entrega](http://profesores.elo.utfsm.cl/~agv/elo329/1s24/Assignments/guideline_2024/)

---

## 🗂️ Recursos y Ejemplos

- 📺 [VideoPlayer](http://profesores.elo.utfsm.cl/~agv/elo329/1s25/Assignments/T3/VideoPlayer/)
- ⏱️ [SimpleTimer](http://profesores.elo.utfsm.cl/~agv/elo329/1s25/Assignments/T3/SimpleTimer/)
- 🔵 [MovingCircle](http://profesores.elo.utfsm.cl/~agv/elo329/1s25/Assignments/T3/MovingCircle/)
- 📘 [Desarrollo Iterativo – Wikipedia](https://es.wikipedia.org/wiki/Desarrollo_iterativo_y_creciente)

---

## 👥 Autores

- [Tu Nombre o Grupo]
- Universidad Técnica Federico Santa María (UTFSM)  
- Curso: ELO329

