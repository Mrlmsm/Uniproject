/* Stacca l'ULTIMO nodo dalla lista '*l' e lo sposta in TESTA (primo nodo),
   senza allocare né liberare memoria.
   Se la lista è vuota, ha un solo nodo, o 'l == NULL', non fa nulla.
   Esempio: *l = [10, 20, 30, 40]  -->  *l diventa [40, 10, 20, 30]. */
void moveLastToFront(List *l) {
	if(l == NULL || *l == NULL || (*l)->next == NULL){
		return;
	}
	List curr = *l;
	while(curr->next->next != NULL){
		curr = curr->next;
	}
	List tmp = curr->next;
	curr->next = NULL;
	tmp->next = *l;
	*l = tmp;
}
