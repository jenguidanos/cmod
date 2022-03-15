# Ansi C Modular

Un intento de hacer OOP con C Ansi, creando interfaces con structs.

## Interfaces

En C declaramos una interfaz así:

```C
// file inet.h
struct iNet {
    int id;
    void (*connect)();
}
```

* Nuestra clase sirve para representar un módem de comunicaciones (GPRS, WiFi, LoRa...)
* Añadimos la `i` al inicio para indicar que es una interfaz
* La función puntero `connect` está vacía por defecto, luego le añadiremos una función/callback.

### Crear un objeto

A los objetos de una interfaz los llamamos módulos. Por ejemplo, vamos a crear el módulo del módem de comunicación N27 de Neoway:

```C
// Creamos un .h y .c para el módulo

// ---------------------
// file net-n27.h
#pragma once
#include "inet.h"       // Incluímos nuestra interfaz
void n27_connect();     // prototipo de nuestra función connect
extern struct iNet N27; // hacemos que el módulo sea público

// ---------------------
// file net-n27.c
#include "net-n27.h"

struct iNet N27 = { // Creamos el módulo, ojo al igual (=)
    .id = 0x27,     // ojo también a los puntos delante de las propiedades
    .connect = n27_connect()
}

// Declaramos/desarrollamos la función connect
void n27_connect() {
    // conectamos al server utilizando los comando AT de N27
}
```

* Todas las funciones y variables de este archivo empiezan con el prefijo "n27_", por ejemplo `n27_connect()`. Haremos lo posible por mantener esta nomenclatura y evitar conflictos con otros archivos `.c` que hayan en el proyecto (en C++ solucionamos esto utilizando `namespace {}`).
* Hemos creado el objeto/módulo *N27* a partir de la interfaz `iNet` con la declaración `struct iNet N27`
* Ahora `N27` tiene la obligación de implementar todos los métodos y propiedades que tenga `iNet`
* Haremos lo mismo con cualquier otro módulo de comunicación que se quiera añadir

### Utilizar el objeto

Aunque luego veremos mejores formas, podemos empezar diciendo que el header `net-n27.h` se puede incluir en cualquier sitio:

```C
// file main.c

#include "net-n27.h"

void main() {
	N27.connect();
}
```

Este código, aunque válido, carece de sentido para nosotros, ya y que necesitamos un sistema de control para determinar qué módulos se activarán y cuando.

Para solucionar esto entre en escena el core.

## El Core

Es un struct que funciona como módulo principal. Se encargará de contener el resto de módulos de la aplicación, la columna principal para otorgar orden y organización a nuestro proyecto.

Cuando queramos acceder al método `N27.connect()` no lo haremos así directamente, error!, si no que nuestro core funcionará de intermediario y ejecutará la función `connect`del módulo que se haya activado: `core.net->connect()`

```C
// file core.h

#include "inet.h"

struct Core {
    struct iNet *net;  // esto apuntará al módulo que se elija
    bool (*setNet)(struct iNet *net); // con esto asignaremos módulos
};

// core público para las masas
extern Core core;

// file core.c
#inclue "core.h"

// prototipos
bool setNet(struct iNet *net);

struct Core core;

bool setNet(struct iNet *net) {
    core.net = net;
}
```

* Hemos creado nuestro módulo `core` y añadido un método para asignar un módulo de `iNet`.
* Aunque `core` esté definido, todavía no le hemos asignado un módulo de net.
* Nuestro core es muy pequeñito, solo incluye el módulo de net. En el futuro se agrandará para contener nuevos módulos y otros métodos y propiedades.

### Inicializar el Core

Pues ya tenemos nuestro módulo de net y nuestro core. Hay muchas formas de inicializar esto, por ejemplo estaría bien tener un archivo de configuración para indicar el módulo de net por defecto, así el init del core puede asignar este módulo directamente.

Vemos algo sencillo en el `main.c`

```C
// file main.c

#include "core.h"
#include "net-n27.h"
#include "net-s7080.h"

// Un método sencillo de elegir el módulo que deseemos.
#define NET_DEFAULT N27
// #define NET_DEFAULT S7080

void main() {
    // Configuramos nuestro módulo net
    core.setNet(&NET_DEFAULT);
}
```

En cualquier otra parte del código:

```C
// file battery.c

#include "core.h"

void publishBattery() {
    // Este método "connect" pertenece a N27 (N27.connect())
    if (!core.net->connect()) {
        return error;
    }

    [...]
}
```

