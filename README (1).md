# Proyecto: El Caso del Detective
### Estructuras de Datos — Mayo 2026

---

## Descripción general
Juego de investigación criminal en consola desarrollado en C++. El usuario es un detective que debe moverse por una ciudad (cuadrícula 9x9), recolectar 10 pistas ocultas, interrogar testigos y acusar al sospechoso correcto.

---

## Estructura de archivos

```
proyecto/
├── main.cpp
├── Pista.h / Pista.cpp ✓
├── Sospechoso.h / Sospechoso.cpp ✓
├── Detective.h / Detective.cpp ✓
├── Ubicacion.h / Ubicacion.cpp ✓
├── Pila.h / Pila.cpp
├── Cola.h / Cola.cpp
├── TablaHash.h / TablaHash.cpp
├── ABB.h / ABB.cpp
├── Mapa.h / Mapa.cpp
├── Juego.h / Juego.cpp
└── README.md
```

---

## Estructuras de datos utilizadas

| Estructura | Archivo | Para qué se usa |
|---|---|---|
| Lista múltiplemente enlazada | `Mapa` | El tablero de la ciudad (cada celda conectada arriba, abajo, izquierda, derecha) |
| Pila | `Pila` | Las pistas recogidas por el detective (LIFO) |
| Cola | `Cola` | Declaraciones de testigos por procesar (FIFO) |
| Tabla Hash | `TablaHash` | Los 8 sospechosos del caso, búsqueda eficiente por nombre |
| ABB | `ABB` | Historial de puntajes de detectives, ordenado de menor a mayor |

---

## Orden de implementación
Las clases se construyeron de adentro hacia afuera, primero las más simples y luego las que dependen de ellas.

1. `Pista` → la más simple, no depende de nadie
2. `Sospechoso` → datos del sospechoso y sus atributos
3. `Detective` → datos del jugador
4. `Ubicacion` → una celda del mapa
5. `Pila` → para apilar las pistas recogidas
6. `Cola` → para las declaraciones de testigos
7. `TablaHash` → para gestionar los sospechosos
8. `ABB` → para el historial de puntajes
9. `Mapa` → el más complejo, une todo el tablero
10. `Juego` → lógica principal que une todas las clases
11. `main` → punto de entrada, solo arranca el juego

---

## Compilación

```bash
g++ -o detective main.cpp Pista.cpp Sospechoso.cpp Detective.cpp Ubicacion.cpp Pila.cpp Cola.cpp TablaHash.cpp ABB.cpp Mapa.cpp Juego.cpp
./detective
```

O en CLion, el `CMakeLists.txt` debe incluir todos los `.cpp`:

```cmake
cmake_minimum_required(VERSION 3.x)
project(detective)
set(CMAKE_CXX_STANDARD 17)

add_executable(detective
        main.cpp
        Pista.cpp
        Sospechoso.cpp
        Detective.cpp
        Ubicacion.cpp
        Pila.cpp
        Cola.cpp
        TablaHash.cpp
        ABB.cpp
        Mapa.cpp
        Juego.cpp
)
```

---

## Clases explicadas

---

### 🔍 `Pista`
**Archivos:** `Pista.h`, `Pista.cpp`

Representa una pista oculta en el mapa. Puede ser de 4 tipos definidos con un `enum`:

| Tipo | Símbolo | Efecto al usarla con "X" |
|---|---|---|
| Huella | H | Reduce a la mitad los puntos acumulados |
| Coartada | C | Elimina 2 callejones cerrados del tablero aleatoriamente |
| Testimonio | T | Aleatoriamente: puntaje a cero O se multiplica por 2 |
| Prueba Forense | P | Teletransporta al detective a una posición aleatoria válida |

**¿Por qué `enum`?**
Porque los tipos de pista son un conjunto fijo y conocido de opciones. Es más legible que usar números (0, 1, 2, 3) y el compilador avisa si usas un valor inválido.

**Atributos:**
- `tipo` → el tipo de pista (TipoPista)
- `recogida` → si ya fue tomada por el detective o no

**Métodos:**
- `getTipo()` → devuelve el enum del tipo
- `getTipoString()` → devuelve el nombre legible ("Huella", "Coartada", etc.)
- `getSimbolo()` → devuelve la letra para mostrar en el tablero (H, C, T, P)
- `recoger()` → marca la pista como recogida
- `isRecogida()` → consulta si ya fue recogida

---

> *Iremos modificando el README a medida que se implementen las demás clases.*
