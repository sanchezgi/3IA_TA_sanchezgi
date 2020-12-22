Miembros del equipo : Alejandro Sanchez Gimeno

El proyecto se basa en un pequeño ejemplo de inteligencia artificial basica y su implementacion. Realizado en un mapa de tiles por el que los agentes se mueven y detectan colisiones con los muros/limites del mapa y/u otros agentes.

El proyecto contiene una clase board que se encarga de cargar el mapa de tiles y guardar los datos de esos tiles y la posicion de los agantes en el mapa. La clase agente gestiona la inteligencia artificial de los agantes y controla el movimiento.

El ejemplo consta de 4 agentes, cada uno con un tipo de IA y movimiento. Cada uno de ellos updatea su IA de manera independiente:

- Random Movement -> 0.75 casilla / seg
- Determinist Movement -> 1 casilla / seg
- Pattern Movement -> 1.25 casilla / seg
- Pac-Man Movement -> 1.5 casilla / seg

Tipos de IA y sus moviminetos:

- Random Movement -> lo realiza el agente con el sprite de la S azul. Cada frame escoge una direccion aleatoria, y si el movimiento es valido, se mueve, si no escoge otra direccion.

- Determinist Movement -> lo realiza el agente con el sprite de la I azul. Antes de spawnear en un punto aleatorio comprueba si su cadena de movimientos sera valida, una vez encuantra una posicion     valida spawnea, por lo tanto no toma en cuenta muros y/o agentes en runtime. En este ejemplo el movimiento determinista va de izquierda a derecha.

- Pattern Movement -> lo realiza el agente con el sprite de la M azul. Antes de spawnear en un punto aleatorio comprueba si su patron de movimientos sera valido, una vez encuantra una posicion valida     spawnea, por lo tanto no toma en cuenta muros y/o agentes en runtime. En este ejemplo el movimiento determinista realiza un cuadrado.
  
- Pac-Man Movement -> lo realiza el agente con el sprite del punto rojo y azul. Siguiendo la logica de la IA del Pac-Man, el agente toma como referencia un destino ( en este caso sera un agente estatico que spawnea aleatoriamnete en el mapa(sprite de la S roja)) y escoge el camino mas cercano basandose em la distancia de manhattan. AL igual que en el Pac-Man, el agente se quedara atascado en las superficies concavas.