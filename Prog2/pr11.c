typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode, *List;

/* Sposta dalla lista '*src' alla lista '*dst' tutti i nodi che hanno valore
   STRICTLY GREATER (>) di 'k', inserendoli IN CODA a '*dst' (preservando
   il loro ordine relativo originale, senza allocare né liberare memoria).
   I nodi <= k restano in '*src' nel loro ordine originale.
   Esempio: *src = [3, 10, 2, 20], *dst = [99], k = 5
            -->  *src diventa [3, 2], *dst diventa [99, 10, 20]. */
void moveGreaterToTail(List *src, List *dst, int k) {
	if(src == NULL || dst == NULL){
		return;
	}
	List *scurr = src;
	List *dcurr = dst;
	while((*dcurr) != NULL){
		dcurr = &((*dcurr)->next);
	}
	
	while((*scurr) != NULL){
		if((*scurr)->data > k){
			List tmp = *scurr;
			*scurr = (*scurr)->next;
			tmp->next = NULL;
			*dcurr = tmp;
			dcurr = &((*dcurr)->next);
		}
		else{
			scurr = &((*scurr)->next);
		}
	}
}
