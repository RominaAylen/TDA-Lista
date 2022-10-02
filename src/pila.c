#include "pila.h"
#include "lista.h"

#define VACIA 0


typedef struct pila {
	nodo_t *nodo_inicio;
	nodo_t *nodo_fin;
	size_t tope_pila;
} pila_t;

pila_t *pila_crear()
{
	return malloc(sizeof(pila_t));
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if (!pila)
		return NULL;

struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));
 
nuevo_nodo->siguiente = NULL;
nuevo_nodo->elemento = elemento;

}

void *pila_desapilar(pila_t *pila)
{
	if (!pila)
		return NULL;
	
}

void *pila_tope(pila_t *pila)
{
		if (!pila)
		return NULL;

	return pila->tope_pila;
}

size_t pila_tamanio(pila_t *pila)
{
		if (!pila)
		return NULL;

	return pila->tope_pila++;
}

bool pila_vacia(pila_t *pila)
{
	if (!pila)
		return NULL;

	return pila->tope_pila == VACIA;
}

void pila_destruir(pila_t *pila)
{
	free(pila);
}
