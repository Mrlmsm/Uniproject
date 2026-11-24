#include <stdio.h>
#include "List.h"
#include <stdlib.h>
/* Date due liste di caratteri 'l' ed 'r' di **uguale lunghezza, senza modificarle**,
  restituisce una nuova lista ottenuta a partire dalla lista 'l', esclusi i
  nodi di 'l' tali per cui il nodo corrispondente di 'r' nella stessa posizione
  contiene lo stesso dato ('l->data' è uguale a 'r->data').

  ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
  (1) date l=[a,a,b],     r=[a,a,b],     restituisce t=[]
  (2) date l=[a,b, c,d],  r=[b,a,d,c],   restituisce t=[a,b,c,d]
  (3) date l=[a,d,b,d,c], r=[a,b,b,c,c], restituisce t=[d,d]                        */
List nuovonodo (char data){
	List new = malloc(sizeof(ListNode));
	if(new == NULL){
		return NULL;
	}
	new->data = data;
	new->next = NULL;
	return new;
}


List difference(List l, List r) {
	if(l == NULL){
		return NULL; 
	}
	List lnext = l;
	List rnext = r;
	List head = NULL;
	List tail = NULL;
	while(lnext != NULL){
		if(rnext == NULL || lnext->data != rnext->data){
			List nuovo = nuovonodo(lnext->data);
			if(head == NULL){
				head = nuovo;
				tail = nuovo;
			}
			else{
				tail->next = nuovo;
				tail = nuovo;
			}
		}
		lnext = lnext->next;
		if(rnext != NULL){
			rnext = rnext->next;
		}
	}
	return head;
}
