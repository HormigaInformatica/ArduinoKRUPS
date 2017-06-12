# ArduinoKRUPS
Keeping alive a KRUPS cofee maker with Arduino

Sé que le falta aún para ser "perfecto" ... pero ¿sabes? HACE CAFE!!

Se le estropeó el circuito de control... y lo quise sustituir por un arduino... busqué ejemplos en internet, y ninguno me convenció, asi que hice el mio... 

AVISO!!
NO tiene PID para el control de temperatura (está un poco a lo bruto)
El funcionamiento del LED es un poco "erratico"

Para la temperatura, la cafetera KRUPS usa una NTC (no preguntéis valores... medidlos si podéis) yo le puse un pin del NTC a +5V, el otro a la entrada A0, y del A0 una resistencia (PullDown) a Gnd de 22000Ohms (22K - naranja, naranja, naranja)

Para el led, le puse una resistencia de 1KOhm (Marron, Negro, Rojo)

Para controlar la resistencia (y la bomba) hice 2 circuitos iguales con un MOC3021 y un TRIAC BTA12-600, para el moc una resistencia de 1Kohm y para el triac una de 220 Ohms (Naranja, Naranja, Marron)

Para los interruptores de Frio/Calor (el selector) puse las entradas PullUp, y las conecté a GND, usando uno de los pines comunes, y los otros a las entradas...

Las salidas y entradas están en el programa... 

Cualquier colaboración (si es para mejorar) será bienvenida
