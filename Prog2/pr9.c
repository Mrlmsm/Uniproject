typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode, *List;

/* Rimuove e libera (con free) tutti i nodi con valore PARI (data % 2 == 0)
   dalla lista '*l', aggiornando '*l' sul posto se vengono rimossi nodi in testa.
   Se la lista è vuota o non contiene numeri pari, non fa nulla.
   Esempio: *l = [2, 5, 8, 3, 4]  -->  *l diventa [5, 3]. */
void removeEvens(List *l) {
	if(l == NULL || *l == NULL){
		return;
	}
	List *curr = l;
	while((*curr) != NULL){
		if((*curr)->data % 2 == 0){
			List tmp = *curr;
			*curr = tmp->next;
			free(tmp);
			
		}
		else{
		curr = &((*curr)->next);
		}
	}
}
