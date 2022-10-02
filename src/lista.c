#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

#define VACIA 0
#define ERROR NULL
#define POSICION_INICIO 0
const char NO_INSERTADO = -1;

lista_t *lista_crear()
{
	struct lista *lista_nueva = malloc(sizeof(lista_t));

	if (!lista_nueva)
	{
		return ERROR;
	}

	lista_nueva->cantidad = 0;
	lista_nueva->nodo_inicio = NULL;
	lista_nueva->nodo_fin = NULL;
	return lista_nueva;
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{
	if (!lista)
	{
		return ERROR;
	}

	struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));

	if (!nuevo_nodo)
		return ERROR;

	nuevo_nodo->siguiente = NULL;
	nuevo_nodo->elemento = elemento;

	if (lista->nodo_fin)
	{
		lista->nodo_fin->siguiente = nuevo_nodo;
	}
	else
	{
		lista->nodo_inicio = nuevo_nodo;
	}
	lista->nodo_fin = nuevo_nodo;
	lista->cantidad += 1;
	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento, size_t posicion)
{
	struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));
	if (!nuevo_nodo)
		return ERROR;
	nuevo_nodo->siguiente = NULL;
	nuevo_nodo->elemento = elemento;

	struct nodo *nodo_actual = lista->nodo_inicio;

	if (!nodo_actual)
	{
		lista->nodo_inicio = nuevo_nodo;
		lista->nodo_fin = nuevo_nodo;
		lista->cantidad = 1;
		return lista;
	}

	if (posicion == POSICION_INICIO)
	{
		nuevo_nodo->siguiente = nodo_actual;
		lista->nodo_inicio = nuevo_nodo;
		lista->cantidad += 1;
		return lista;
	}

	if (posicion >= lista->cantidad)
	{
		return lista_insertar(lista, elemento);
	}
	else
	{

		int contador_nodos = 0;
		struct nodo *aux_nodo_anterior = lista->nodo_inicio;

		while (nodo_actual->siguiente && contador_nodos < posicion)
		{
			aux_nodo_anterior = nodo_actual;
			nodo_actual = nodo_actual->siguiente;
			contador_nodos++;
		}

		nuevo_nodo->siguiente = nodo_actual;
		aux_nodo_anterior->siguiente = nuevo_nodo;

		lista->cantidad += 1;
		return lista;
	}
}

void *lista_quitar(lista_t *lista)
{
	return NULL;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	if (!posicion)
		return ERROR;
	return NULL;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	if (!lista || (lista->cantidad) > posicion)
		return ERROR;
	int contador = 0;
	struct nodo *nodo_actual = lista->nodo_inicio;

	while (nodo_actual || contador != posicion)
	{
		nodo_actual = nodo_actual->siguiente;
		contador++;
	}
	return nodo_actual;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *), void *contexto)
{
	if (!comparador)
		return ERROR;

	return NULL;
}

void *lista_primero(lista_t *lista)
{
	if (!lista || !(lista->nodo_inicio) || !(lista->nodo_inicio->elemento))
		return ERROR;

	return lista->nodo_inicio->elemento;
}

void *lista_ultimo(lista_t *lista)
{
	if (!lista || !(lista->nodo_fin) || !(lista->nodo_fin->elemento))
		return ERROR;

	return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t *lista)
{

	return !lista || !(lista->nodo_inicio);
}

size_t lista_tamanio(lista_t *lista)
{
	if (!lista)
		return VACIA;

	return lista->cantidad;
}

void lista_destruir(lista_t *lista)
{
	free(lista);
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	if (!lista)
		return ERROR;

	lista_iterador_t *lista_interador_elemento_actual = malloc(sizeof(lista_iterador_t));

	lista_interador_elemento_actual->corriente = lista->nodo_inicio;
	lista_interador_elemento_actual->lista = lista;

	return lista_interador_elemento_actual;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	if (!iterador)
		return false;
	return iterador->corriente->siguiente != NULL;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	if (!iterador)
		return false;

	return (iterador->corriente == iterador->corriente->siguiente);
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if (iterador->corriente)
		return iterador->corriente = iterador->corriente->elemento;
	else
		return NULL;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	free(iterador);
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *), void *contexto)
{
	return 0;
}
