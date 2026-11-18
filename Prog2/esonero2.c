#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * Date due liste di caratteri l ed r, restituire una nuova lista p (senza
 * modificare le liste l ed r) che contenga il più lungo prefisso di l per
 * cui nessun suo carattere ha un carattere uguale nella posizione
 * corrispondente di r.
 * 
 * Si definisce "prefisso" di una lista una qualunque sotto-lista di nodi dall'inizio.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) date l=[] e s=[], restituisce p=[]
 * (2) date l=[] e s=[p,i,p,p,o], restituisce p=[]
 * (3) date l=[p,i,p,p,o] e s=[], restituisce p=[p,i,p,p,o]
 * (4) date l=[p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[]
 * (5) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,l,u,t,o], restituisce p=[s,u,p,e,r,p,i,p,p,o]
 * (6) date l=[p,l,u,t,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,l,u,t,o]
 * (7) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[s,u], perché la p seguente è in comune
 * (8) date l=[p,i,p,p,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,i], perché la p seguente è in comune
 * 
 * NOTA: questa funzione compare negli errori di compilazione come "student_antiPrefix"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
List creanodo(char c){
	List nuovonodo = malloc(sizeof(ListNode));
	nuovonodo->data = c;
	nuovonodo->next = NULL;
	return nuovonodo;
}
List antiPrefix(List l, List r){
	if(l == NULL){
		return NULL;
	}
	List nextl = l;
	List nextr = r;
	List head = NULL;
	List tail = NULL;
	while(nextl != NULL){
		if(nextr != NULL && nextl->data == nextr->data){
			return head;
		}
		else{
			List nuovo = creanodo(nextl->data);
			if(head == NULL){
				head = nuovo;
				tail = nuovo;
			}
			else{
				tail->next = nuovo;
				tail = nuovo;
			}
		}
		nextl = nextl->next;
		if(nextr != NULL){
		nextr = nextr->next;
		}
	}
	return head;
}
