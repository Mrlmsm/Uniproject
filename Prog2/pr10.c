typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode, *List;

/* Sposta dalla lista '*src' alla lista '*dst' tutti i nodi che hanno valore
   STRICTLY GREATER (> ) di 'k', inserendoli IN TESTA a '*dst' (uno dopo l'altro,
   senza allocare né liberare memoria).
   I nodi <= k restano in '*src' nel loro ordine originale.
   Esempio: *src = [3, 10, 2, 20], *dst = [99], k = 5
            -->  *src diventa [3, 2], *dst diventa [20, 10, 99]. */
void moveGreaterToFront(List *src, List *dst, int k) {
	if(src == NULL || dst == NULL){
		return;
	}
	List *currs = src;
	List *head = dst;
	while((*currs) != NULL){
		if((*currs)->data > k){
			List s = *currs;
			*currs = (*currs)->next;
			s->next = *head;
			*head = s;
		}
		else{
			currs = &((*currs)->next);
		}
	}
}
