/* Estrae dalla lista '*src' tutti i nodi maggiori di 'threshold' (> threshold)
   e li inserisce IN TESTA alla lista '*dst' (uno dopo l'altro, senza malloc/free).
   Esempio: *src = [2, 10, 4, 20], *dst = [1], threshold = 5
            -->  *src = [2, 4], *dst = [20, 10, 1]. */
void extractGreaterToFront(List *src, List *dst, int threshold) {
	if(src == NULL || dst == NULL){
		return;
	}
	List *curr = src;
	List tmp;
	while((*curr) != NULL){
		if((*curr)->data > threshold){
			tmp = *curr;
			*curr = tmp->next;
			tmp->next = *dst;
			*dst = tmp;
		}
		else{
			curr = &(*curr)->next;
		}
	}
}
