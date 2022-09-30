#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

const char VACIA = 0;
const char NO_INSERTADO = -1;

lista_t *lista_crear()
{

	return malloc(sizeof(lista_t));
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{
	if (!lista)
		return NULL;
	struct nodo* nuevo_nodo = malloc(sizeof(struct nodo));
	
	if(!nuevo_nodo)
		return NULL;
	
	nuevo_nodo->siguiente = NULL;
	nuevo_nodo->elemento = elemento;
	
	struct nodo* actual_nodo = lista->nodo_inicio;
	
	if(!actual_nodo){
		lista->nodo_inicio = nuevo_nodo;
		return lista;
	}

	while (actual_nodo->siguiente)
	{
		actual_nodo->siguiente = nuevo_nodo; 
	return lista;
	}
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento,
									size_t posicion)
{
	return NULL;
}

void *lista_quitar(lista_t *lista)
{
	return NULL;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *),
							void *contexto)
{
	return NULL;
}

void *lista_primero(lista_t *lista)
{
	return NULL;
}

void *lista_ultimo(lista_t *lista)
{
	return NULL;
}

bool lista_vacia(lista_t *lista)
{
	return false;
}

size_t lista_tamanio(lista_t *lista)
{
	int contador = 0;
	
	if(!lista || lista->nodo_inicio == NULL)
		return VACIA;

	struct nodo* actual_nodo = lista->nodo_inicio;
	while (actual_nodo)
	{
		actual_nodo = actual_nodo->siguiente;
		contador++;
	}
	
	return contador;
}

void lista_destruir(lista_t *lista)
{
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	if (!lista)
		return NULL;

	lista_iterador_t *lista_interador_elemento_actual = malloc(sizeof(lista_iterador_t));

	lista_interador_elemento_actual->corriente = lista->nodo_inicio;
	lista_interador_elemento_actual->lista = lista;

	return lista_interador_elemento_actual;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	return iterador->corriente->siguiente != NULL;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	return(iterador->corriente == iterador->corriente->siguiente);
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if(iterador->corriente)
	return iterador->corriente = iterador->corriente->elemento;
	else 
	return NULL;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	free(iterador);
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
							   void *contexto)
{
	return 0;
}
