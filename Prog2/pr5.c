/* Rimuove e libera (con free) tutti i nodi con valore NEGATIVO (< 0) dalla lista '*l',
   aggiornando '*l' sul posto se vengono rimossi nodi in testa.
   Esempio: *l = [-3, -1, 4, -5, 7, -2]  -->  *l diventa [4, 7]. */
void removeNegatives(List *l) {
	if(l == NULL || *l == NULL){
		return;
	}
	List *curr = l;
	while((*curr) != NULL){
		if((*curr)->data < 0){
			List rm = *curr;
			*curr = (*curr)->next;
			free(rm);
			rm = NULL;	
		}
		else{
			curr = &(*curr)->next;
		}
	}
}
