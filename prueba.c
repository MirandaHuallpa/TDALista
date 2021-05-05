#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

#define ERROR -1
#define OK 0

#define TRUE 1
#define FALSE 0

void probar_lista_crear()
{
    pa2m_afirmar(lista_vacia(NULL) == TRUE, "Lista nula es vacia");
    pa2m_afirmar(lista_elementos(NULL) == 0, "Lista nula tiene 0 elementos");
    pa2m_afirmar(lista_primero(NULL) == NULL, "El primer elemento de una lista nula es nulo");
    pa2m_afirmar(lista_ultimo(NULL) == NULL, "El último elemento de una lista nula es nulo");
    pa2m_afirmar(lista_elemento_en_posicion(NULL, 500) == NULL, "Un elemento arbitrario de una lista nula es nulo");

    lista_t* lista = lista_crear();

    pa2m_afirmar(lista != NULL, "Puedo crear una lista");
    pa2m_afirmar(lista_vacia(lista) == TRUE, "La lista esta vacía");
    pa2m_afirmar(lista->cantidad == 0, "La lista tiene 0 elementos");
    pa2m_afirmar(lista->nodo_inicio == NULL, "Primer elemento es NULL");
    pa2m_afirmar(lista->nodo_fin == NULL, "Ultimo elemento es NULL");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1000) == NULL, "Pedir una posicion arbitraria a una lista sin elementos devuelve NULL");

    lista_destruir(lista);
}

void probar_lista_insertar()
{
    int cantidad = 6;
    int numeros[6] = {3, 5, 34, 10, 20, 57};

    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_insertar(NULL, &numeros[0]) == ERROR, "ERROR al insertar elemento con lista nula");
    pa2m_afirmar(lista_insertar(lista, &numeros[0]) == OK, "Puedo insertar al final en una lista vacia");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene un elemento");
    pa2m_afirmar(lista_vacia(lista) == FALSE, "Lista no esta vacia");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &numeros[0] &&
                lista->nodo_inicio->elemento == &numeros[0],"El primer elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El ultimo nodo apunta a NULL");

    for (int i = 0; i < cantidad; i++)
    {
        lista_insertar(lista, numeros + i);
    }

    pa2m_afirmar(lista->cantidad == 7, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista_primero(lista) == &numeros[0] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[0],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[0], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 6) == &numeros[5] &&
                lista_ultimo(lista) == &numeros[5],"El ultimo elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El ultimo nodo apunta a NULL\n");
    lista_destruir(lista);
}

void probar_lista_insertar_en_posicion()
{
    int cantidad = 15;
    int numeros[15] = {3, 5, 34, 10, 20, 57, 93, 94, 75, 87, 0, 7, 1, 5, 27};

    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_insertar_en_posicion(NULL, &numeros[0], 0) == ERROR, "ERROR al insertar elemento con lista nula");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &numeros[0], 100) == OK, "Puedo insertar en una posicion arbitraria de lista vacia");
    pa2m_afirmar(lista_elementos(lista) == 1, "La cantidad de elementos es el esperado");
    pa2m_afirmar(lista_vacia(lista) == FALSE, "Lista no esta vacia");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[0] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[0],"El primer elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->elemento == &numeros[0], "El ultimo elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &numeros[1], 0) == OK, "Puedo insertar en la posicion 0");
    pa2m_afirmar(lista_elementos(lista) == 2, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->elemento == &numeros[0] &&
                lista_elemento_en_posicion(lista, 1) == &numeros[0],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &numeros[2], 3000) == OK, "Puedo insertar en una posicion arbitraria");
    pa2m_afirmar(lista_elementos(lista) == 3, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &numeros[2] &&
                lista_ultimo(lista) == &numeros[2],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &numeros[3], 1) == OK, "Puedo insertar en la posicion 1");
    pa2m_afirmar(lista_elementos(lista) == 4, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista_ultimo(lista) == &numeros[2] &&
                lista_elemento_en_posicion(lista, 3) == &numeros[2],"El ultimo elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &numeros[4], 2) == OK, "Puedo insertar en la posicion 2");
    pa2m_afirmar(lista_elementos(lista) == 5, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[3], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &numeros[4], "El tercer elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    for (size_t i = 5; i < cantidad; i++)
    {
        lista_insertar_en_posicion(lista, numeros + i, i);
    }
    pa2m_afirmar(lista_elementos(lista) == 15, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista_ultimo(lista) == &numeros[14] &&
                lista_elemento_en_posicion(lista, 14) == &numeros[14],"El ultimo elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &numeros[0], 14) == OK, "Puedo insertar en la última posición");
    pa2m_afirmar(lista_elementos(lista) == 16, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 14) == &numeros[0], "El penúltimo elemento es el esperado");
    pa2m_afirmar(lista_ultimo(lista) == &numeros[14] &&
                lista_elemento_en_posicion(lista, 15) == &numeros[14],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");
    lista_destruir(lista);
}

void probar_lista_borrar()
{
    int numeros[15] = {3, 5, 34, 10, 20, 57, 93, 94, 75, 87, 0, 7, 1, 5, 27};
    int cantidad = 15;

    lista_t *lista = lista_crear();

    pa2m_afirmar(lista_borrar(NULL) == ERROR, "ERROR al insertar en una lita nula.");
    pa2m_afirmar(lista_borrar(NULL) == ERROR, "Borrar al final de una lista nula da ERROR"); 
    pa2m_afirmar(lista_borrar(lista) == ERROR, "Borrar un elemento de una lista vacia da ERROR");
    pa2m_afirmar(lista_vacia(lista) == TRUE, "La lista está vacía\n");

    pa2m_afirmar(lista_insertar(lista, &numeros[0]) == OK, "Puedo insertar elemento en una lista vacia");
    pa2m_afirmar(lista_borrar(lista) == OK, "Borrar en una lista con un elemento");
    pa2m_afirmar(lista_vacia(lista) == TRUE, "La lista esta vacia");
    pa2m_afirmar(lista_elementos(lista) == 0, "La cantidad de elementos es la esperada");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "El último elemento de una lista vacia es NULL\n");

    pa2m_afirmar(lista_insertar(lista, &numeros[1]) == OK, "Puedo volver a insertar elemento en una lista vacia");
    pa2m_afirmar(lista_elementos(lista) == 1, "La cantidad de elementos es la esperada");
    pa2m_afirmar(lista_borrar(lista) == OK, "Borrar en una lista con un elemento");
    pa2m_afirmar(lista_elementos(lista) == 0, "La cantidad de elementos es la esperada");
    pa2m_afirmar(lista->nodo_fin == NULL,"La lista esta vacia");

    for (int i = 0; i < cantidad; i++)
    {
        lista_insertar(lista, numeros + i);
    }
    pa2m_afirmar(lista_elementos(lista) == 15, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista_borrar(lista) == OK, "Puedo eliminar el último elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == &numeros[13], "El último elemento es el esperado\n");

    pa2m_afirmar(lista_borrar(lista) == OK, "Puedo eliminar el último elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == &numeros[12], "El último elemento es el esperado");
    pa2m_afirmar(lista_elementos(lista) == 13, "La cantidad de elementos de la lista es la esperada");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El final de la lista es NULL\n");
    lista_destruir(lista);
}

void probar_lista_borrar_de_posicion()
{
    int numeros[15] = {3, 5, 34, 10, 20, 57, 93, 94, 75, 87, 0, 7, 1, 5, 27};
    int cantidad = 15;

    lista_t *lista = lista_crear();

    pa2m_afirmar(lista_borrar_de_posicion(NULL, 30) == ERROR, "Error al insertar elemento aleatorio en una lista vacia");
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == ERROR, "Borrar al inicio de una lista nula da ERROR");                
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 389) == ERROR, "Borrar una posicion arbitraria de una lista nula da ERROR"); 
    pa2m_afirmar(lista_borrar_de_posicion(lista, 30) == ERROR, "Borrar en posicion arbitraria en lista vacia da ERROR");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == ERROR, "Borrar el primer elemento de la lista vacia da ERROR");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 9) == NULL, "Pedir posicion arbitraria de lista sin elementos da ERROR");
    pa2m_afirmar(lista->nodo_inicio == NULL, "El inicio de la lista es NULL");
    pa2m_afirmar(lista->nodo_fin == NULL, "El final de la lista es NULL");
    pa2m_afirmar(lista->cantidad == 0, "El cantidad de elementos de la lista es la esperada");

    for (size_t i = 0; i < cantidad; i++)
    {
        lista_insertar_en_posicion(lista, &numeros[i], i);
    }
    pa2m_afirmar(lista->cantidad == 15, "La cantidad de la lista es la esperada");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 100) == OK, "Borro en posicion inexistente de la lista");
    pa2m_afirmar(lista->cantidad == 14, "La cantidad de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[0] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[0],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[1], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 13) == &numeros[13] &&
                lista->nodo_fin->elemento == &numeros[13],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == OK, "Se pudo borrar el primer elemento de la lista");
    pa2m_afirmar(lista->cantidad == 13, "La cantidad de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[2], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 12) == &numeros[13] &&
                lista->nodo_fin->elemento == &numeros[13],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_borrar_de_posicion(lista, 1) == OK, "Se pudo borrar el segundo elemento de la lista");
    pa2m_afirmar(lista->cantidad == 12, "La cantidad de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[3], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &numeros[4], "El tercer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == &numeros[5], "El cuarto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 11) == &numeros[13] &&
                lista->nodo_fin->elemento == &numeros[13],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_borrar_de_posicion(lista, 6) == OK, "Se pudo borrar el elemento del medio de la lista");
    pa2m_afirmar(lista->cantidad == 11, "La cantidad de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[3], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &numeros[4], "El tercer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == &numeros[5], "El cuarto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &numeros[6], "El quinto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 5) == &numeros[7], "El sexto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 6) == &numeros[9], "El septimo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 7) == &numeros[10], "El octavo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 10) == &numeros[13] &&
                lista->nodo_fin->elemento == &numeros[13],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");

    pa2m_afirmar(lista_borrar_de_posicion(lista, 10) == OK, "Se pudo borrar el último elemento de la lista");
    pa2m_afirmar(lista->cantidad == 10, "La cantidad de la lista es la esperada");
    pa2m_afirmar(lista->nodo_inicio->elemento == &numeros[1] &&
                lista_elemento_en_posicion(lista, 0) == &numeros[1],"El primer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &numeros[3], "El segundo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &numeros[4], "El tercer elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == &numeros[5], "El cuarto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &numeros[6], "El quinto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 5) == &numeros[7], "El sexto elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 6) == &numeros[9], "El septimo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 7) == &numeros[10], "El octavo elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 8) == &numeros[11], "El noveno elemento es el esperado");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 9) == &numeros[12] &&
                lista->nodo_fin->elemento == &numeros[12],"El último elemento es el esperado");
    pa2m_afirmar(lista->nodo_fin->siguiente == NULL, "El siguiente del último nodo es NULL\n");
    lista_destruir(lista);
}

void probar_operaciones_pila()
{
    int numeros[6] = {3, 5, 34, 10, 20, 57};
    int cantidad = 6;

    lista_t *lista = lista_crear();

    pa2m_afirmar(lista_apilar(NULL, &numeros[0]) == ERROR, "ERROR al insertar elemento en una lista nula");
    pa2m_afirmar(lista_tope(NULL) == NULL, "El tope de una lista nula es nulo");
    pa2m_afirmar(lista_apilar(NULL, &numeros[0]) == ERROR, "Apilar una lista nula da ERROR");
    pa2m_afirmar(lista_desapilar(NULL) == ERROR, "Desapilar una lista nula da ERROR");

    for (size_t i = 0; i < cantidad; i++)
    {
        lista_apilar(lista, &numeros[i]);
    }

    pa2m_afirmar(lista_apilar(lista, &numeros[0]) == OK, "Pude apilar elementos");
    pa2m_afirmar(lista_tope(lista) == &numeros[0], "El tope de la pila es el esperado");
    pa2m_afirmar(lista_desapilar(lista) == OK, "Puedo desapilar el elemento\n");

    int i = 5;
    while (!lista_vacia(lista))
    {
        pa2m_afirmar(lista_tope(lista) == &numeros[i], "El tope de la pila es el esperado");
        pa2m_afirmar(lista_desapilar(lista) == OK, "Puedo desapilar el elemento");
        i--;
    }
    pa2m_afirmar(lista_vacia(lista) == TRUE, "La pila está vacia");
    lista_destruir(lista);
}

void probar_operaciones_cola()
{
    int numeros[6] = {3, 5, 34, 10, 20, 57};
    int cantidad = 6;

    lista_t *lista = lista_crear();

    pa2m_afirmar(lista_primero(NULL) == NULL, "El primer elemento de una lista nula es nulo");
    pa2m_afirmar(lista_encolar(NULL, &numeros[0]) == ERROR, "Encolar una lista nula da ERROR");
    pa2m_afirmar(lista_desencolar(NULL) == ERROR, "Desencolar una lista nula da ERROR");

    for (size_t i = 0; i < cantidad; i++)
    {
        lista_encolar(lista, &numeros[i]);
    }

    int i = 0;
    while (!lista_vacia(lista))
    {
        pa2m_afirmar(lista_primero(lista) == &numeros[i], "El primer elemento de la cola es el esperado");
        pa2m_afirmar(lista_desencolar(lista) == OK, "Puedo desencolar el elemento");
        i++;
    }
    pa2m_afirmar(lista_vacia(lista) == TRUE, "La cola está vacia");
    lista_destruir(lista);
}

void probar_iterador_externo()
{

    lista_t *lista = lista_crear();
    lista_iterador_t *iterador = lista_iterador_crear(lista);

    pa2m_afirmar(lista_iterador_crear(NULL) == NULL, "Un iterador de una lista nula es nulo");
    pa2m_afirmar(iterador != NULL, "Puedo crear un iterador con una lista vacia");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == FALSE, "El iterador de una lista vacia no tiene siguiente");
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL, "El elemento actual de un iterador de lista vacía siempre es NULL");
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL, "El elemento actual de un iterador de lista vacía siempre es NULL");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == FALSE, "El iterador de una lista vacía no puede avanzar");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == FALSE, "El iterador de una lista vacia no tiene siguiente luego de avanzar");
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL, "El elemento actual de un iterador de lista vacía siempre es NULL aún después de avanzar\n");
    lista_iterador_destruir(iterador);

    int cantidad = 6;
    int numeros[6] = {3, 5, 34, 10, 20, 57};

    for (int i = 0; i < cantidad; i++)
    {
        lista_insertar(lista, numeros + i);
    }

    lista_iterador_t *it = lista_iterador_crear(lista);

    pa2m_afirmar(it != NULL, "Creo un iterador con una lista no vacia");
    pa2m_afirmar(lista_iterador_tiene_siguiente(it) == TRUE, "El iterador tiene siguiente");

    int iteraciones = 0;

    while (lista_iterador_tiene_siguiente(it))
    {
        pa2m_afirmar(lista_iterador_elemento_actual(it) == &numeros[iteraciones], "El elemento actual es el esperado");

        if (iteraciones != cantidad - 1)
        {
            pa2m_afirmar(lista_iterador_avanzar(it) == TRUE, "El iterador puede avanzar");
        }
        if (iteraciones == cantidad - 1)
        {
            pa2m_afirmar(lista_iterador_avanzar(it) == FALSE, "El iterador no puede avanzar, estoy en el último nodo");
        }
        iteraciones++;
    }

    pa2m_afirmar(lista_elementos(lista) == cantidad, "Se iteran la misma cantidad que de elementos tiene la lista");

    lista_destruir(lista);
    lista_iterador_destruir(it);
}

bool mostrar_elementos(void* elemento,void* cantidad_elementos)
    {
        if (elemento && cantidad_elementos) 
        {
            (*(int*)cantidad_elementos)++;
            return TRUE;
        }
        return FALSE;
    }

void probar_iterador_interno()
{
    lista_t *lista = lista_crear();

    int cantidad = 6;
    int numeros[6] = {3, 5, 34, 10, 20, 57};

    for (int i = 0; i < cantidad; i++)
    {
        lista_insertar(lista, numeros + i);
    }

    int cantidad_elementos = 0;
    size_t elementos_recorridos = 0;

    elementos_recorridos = lista_con_cada_elemento(lista, mostrar_elementos, (void*)&cantidad_elementos);

    pa2m_afirmar(lista_con_cada_elemento(NULL,mostrar_elementos,(void*)&cantidad_elementos) == 0,"Recorrer una lista nula con el iterador interno recorre 0 elementos");
    pa2m_afirmar(lista_con_cada_elemento(lista, NULL, NULL) == 0, "No puedo iterar una lista sin función de iteración");
    pa2m_afirmar(elementos_recorridos == lista->cantidad, "Se iteran todos los elementos esperados");

    for (int i = 0; i < cantidad; i++)
    {
        lista_borrar_de_posicion(lista,0);
    }
    
    cantidad_elementos = 0;
    elementos_recorridos = 0;

    elementos_recorridos = lista_con_cada_elemento(lista, mostrar_elementos, (void*)&cantidad_elementos);
    
    pa2m_afirmar(elementos_recorridos == lista->cantidad, "Se iteran todos los elementos esperados en una lista vacia");
    lista_insertar(lista,&cantidad);
    
    cantidad_elementos = 0;
    elementos_recorridos = 0;

    elementos_recorridos = lista_con_cada_elemento(lista, mostrar_elementos, (void*)&cantidad_elementos);
    pa2m_afirmar(elementos_recorridos == lista->cantidad, "Se iteran todos los elementos esperados");
    
    lista_destruir(lista);
    

}

int main()
{

    pa2m_nuevo_grupo("PRUEBAS DE CREACION");
    probar_lista_crear();

    pa2m_nuevo_grupo("PRUEBAS DE INSERCION");
    probar_lista_insertar();
    probar_lista_insertar_en_posicion();

    pa2m_nuevo_grupo("PRUEBAS DE BORRAR");
    probar_lista_borrar();
    probar_lista_borrar_de_posicion();

    pa2m_nuevo_grupo("PRUEBAS PILA");
    probar_operaciones_pila();

    pa2m_nuevo_grupo("PRUEBAS COLA");
    probar_operaciones_cola();

    pa2m_nuevo_grupo("PRUEBAS ITERADOR EXTERNO");
    probar_iterador_externo();

    pa2m_nuevo_grupo("PRUEBAS ITERADOR INTERNO");
    probar_iterador_interno();

    pa2m_mostrar_reporte();
}
