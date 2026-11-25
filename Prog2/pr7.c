/* Rimuove e libera (con free) SOLO LA PRIMA occorrenza di un numero multiplo di 3
   (data % 3 == 0) dalla lista '*l', aggiornando '*l' sul posto se è in testa.
   Se non ce ne sono, o se la lista è vuota, non fa nulla.
   Esempio: *l = [4, 9, 5, 6]  -->  *l diventa [4, 5, 6]. */
void removeFirstMultipleOf3(List *l) {
	if(l == NULL || *l == NULL){
		return;
	}
	List *curr = l;
	while((*curr) != NULL){
		if((*curr)->data % 3 == 0){
			List tmp = *curr;
			*curr = tmp->next;
			free(tmp);
			return;
		}
		else{
			curr = &((*curr)->next);
		}
	}
}
