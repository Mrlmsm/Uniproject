#include <stdio.h>
#include "list.h"
#include "tree.h"
#include <ctype.h>
#include <stdlib.h>
/**
 * Dato un albero binario t, restituire una nuova lista p (senza modificare t)
 * che contenga il percorso entro t che parte dalla radice, e procede a sinistra
 * se il valore in un nodo è dispari, e a destra altrimenti.
 *
 * Gli alberi sono rappresentati tramite parentesi, con "-" per indicare un figlio mancante.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) dato t={}, restituisce l=[]
 * (2) dato t={-1-}, restituisce l=[1]
 * (3) dato t={[-3-]1-[-4-]}, restituisce l=[1,3]
 * (4) dato t={[-3-]2-[-4-]}, restituisce l=[1,4]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_parityPath"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
List creanodo(int data){
	List nodo = malloc(sizeof(ListNode));
	nodo->data = data;
	nodo->next = NULL;
	return nodo;
}


List parityPath(Tree t){
	if(t == NULL){
		return NULL;
	}
	List new = creanodo(t->data)
	if(t->data % 2 == 0){
		new->next = parityPath(t->right);
	}
	else{
		new->next = parityPath(t->left);
	}
	return new;
}
