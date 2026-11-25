/* Rimuove e libera (con free) TUTTE le occorrenze di 'target' dalla lista '*l'.
   Modifica '*l' sul posto: se anche i primi nodi valgono 'target', la testa '*l' deve aggiornarsi.
   Esempio: *l = [5, 5, 2, 5, 8], target = 5  -->  *l diventa [2, 8]. */
void removeAll(List *l, int target) {
	if(l == NULL || *l == NULL){
		return;
	}
	if((*l)->data == target){
		List tmp = *l;
		*l = (*l)->next;
		free(tmp);
		removeAll(&(*l), target);
	}
	else{
	removeAll(&(*l)->next, target);
	}
}
