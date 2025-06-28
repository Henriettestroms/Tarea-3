# Documentación de la Tarea 3

Este documento resume los elementos principales del simulador gráfico de dispositivos domóticos desarrollado en C++ con Qt. Aporta un diagrama de clases simplificado, una breve explicación de la solución y las dificultades enfrentadas.

## Diagrama UML

```text
+----------------+     +----------------+
|   Publisher    |<>---|    Subscriber  |
+----------------+     +----------------+
        ^                    ^
        |                    |
+---------------+   +------------------+
| VideoPublisher|   |   VideoFollower  |
+---------------+   +------------------+
                    | -volumeSlider |
```

## Explicación de la Solución

El programa implementa el patrón *Publisher–Subscriber*. Un `Broker` central administra la suscripción de objetos `Subscriber` a distintos `Topic`. Los publicadores envían mensajes mediante el `Broker` y los suscriptores reaccionan actualizando su interfaz gráfica.

La clase `VideoPublisher` permite ingresar una URL de video y notifica a todos los seguidores (`VideoFollower`). Estos actualizan un botón con el último enlace recibido y, al presionarlo, muestran el video.

## Dificultades y Soluciones

1. **Integración con Qt:** configurar CMake para enlazar correctamente con `Qt6::MultimediaWidgets` requirió revisar ejemplos oficiales. La solución fue seguir la estructura propuesta en la guía del curso.
2. **Manejo de señales y slots:** sincronizar las actualizaciones del `VideoFollower` con eventos del `VideoPublisher` fue complejo. Se implementó una capa base (`Component`) para facilitar la conexión.
3. **Interfaz gráfica responsiva:** se ajustaron tamaños de widgets y se utilizaron layouts de Qt para asegurar un correcto funcionamiento en distintas resoluciones.

Adicionalmente, en la etapa final se incorporó un `QSlider` para controlar el volumen de reproducción del video. Para ello se emplea un objeto `QAudioOutput` asociado al reproductor.