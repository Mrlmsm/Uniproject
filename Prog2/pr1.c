#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* Estrae (stacca) il primo nodo dalla lista '*l' e lo restituisce.
   Dopo la chiamata, '*l' deve puntare al secondo nodo (oppure a NULL se era l'ultimo).
   Se la lista è vuota (o 'l == NULL'), restituisce NULL.
   Non allocare né liberare memoria.
   Esempio: se *l = [10, 20, 30], restituisce il nodo [10] (con next == NULL) e *l diventa [20, 30]. */
List popFront(List *l) {
	if(l == NULL || *l == NULL){
		return NULL;
	}
	List head = *l;
	*l = (*l)->next;
	head->next = NULL;
	return head;
}
