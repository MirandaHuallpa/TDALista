
INTRODUCCION

Se busca lograr la implementación de los TDAs LISTA, COLA, PILA e ITERADOR EXTERNO.    
Para ello contamos con un conjunto de primitivas a realizar en las cuales se toma importancia su complejidad computacional.

Para la función lista_insertar() que a su vez llame dentro de la primitiva lista_apilar, tiene complejidad O(1).
Ya que directamente accedo a la última posición a través del puntero nodo_fin y no tengo que recorrer la lista.

La función lista_borrar() que termina teniendo complejidad O(n), por ser necesario tener que recorrer la lista para que 
nodo_fin apunte al nuevo nodo último. También los use llamandolo en la función lista_desapilar().

La función lista_elemento_en_posicion, recorre los nodos hasta la posicion ingresada y devuelve el elemento. Para esto decidi
usar dos punteros auxiliares "anterior" y "actual" en un principio, porque estaba creando punteros auxiliares del tipo void*.
Después me di cuenta de que debia crear auxiliares del tipo nodo_t* y que solo necesitaba un auxiliar para esta función.

En lista_insertar_en_posicion() mis casos bordes son si la lista esta vacia o si la posición no existe, acá reutilice la función
lista_insertar().
Al usar puntero auxiliar del tipo void* necesite crear dos punteros "anterior" y "actual", con un while voy avanzando solo si la 
posicion es mayor a 1.
Usando aritmetica de punteros para acceder al elemento del nodo al que termina apuntado "actual" : actual = *(anterior+1),
en donde "actual" será igual al puntero "anterior" donde se accede al segundo campo del nodo, para obtener el siguiente a ese nodo.
Después se iguala anterior = actual, para seguir avanzando.
Al corregir mis punteros auxiliares a tipo nodo_t*, se me redujo bastante el codigo y sólo necesite de un puntero para esta función.

En la función lista_borrar_de_posicion(), tuve que crear tres punteros (anterior,actual,siguiente) ya que necesitaba 
el siguiente del eliminado para poder unir el anterior y el siguiente de los nodos de ambos lados.

LINEA DE COMPILACION 
gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

-Wall cuando compilas habilita a todos los warnings.


LINEA DE EJECUCION
./lista_se
Se eligio por implementarse una lista simplemente enlazada.

LISTAS
Lista es un conjunto de elementos ordenados, donde cada elemento tiene su posicion, un elemento y tiene una referencia al siguiente
nodo. La diferencia entre una lista simple y una doblemente enlazada es que la simplemente enlazada tiene referencia al siguiente
nodo en una sóla dirección mientras que la doblemente enlazada tiene referencia a su anterior y siguiente, pudiendo ser recorrida 
en ambas direcciones. Por ejemplo, si se quiere eliminar un nodo de una lista doblemente enlazada, no hace falta crear auxiliares,
puedo eliminar directamente teniendo una referencia a ese nodo. Una desventaja seria que se vuelve más complejo y aumenta espacio 
en memoria.

PILAS Y COLAS
Lo que caracteriza al TDA PILA son sus primitivas que determinan su comportamiento. Se puede ir apilando al final de la pila,
quedando en el tope el último elemento apilado el cual es el único elemento al que se puede tener acceso. Para poder ir teniendo
acceso a los elementos de los anteriormente apilados debo desapilar uno a uno, siempre desde la última posición. El primero que 
entra es el último que sale,por ejemplo, como cuando tenes una pila de platos para lavar sacas siempre el último.

A su vez, el TDA COLA se caracteriza por poder ir encolando en la última posición pero para desencolar lo hago en la primer
posición, sólo se tiene acceso al primer elemento de la cola. Su comportamiento se rige en que, el primero que entra es el 
primero que sale. Por ejemplo, como en la cola del supermercado el primero es atendido primero.

ITERADOR
El iterador es un tipo de TDA que permite recorrer los elementos de una lista.
La diferencia principal entre el TDA externo y el interno es que el primero es un TDA con sus primitivas y el segundo sólo una 
función, ambos con sus ventajas y desventajas.
En el iterador interno el usuario llama a la función
