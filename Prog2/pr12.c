typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode, *List;

void mergeSortedInPlace(List *l1, List *l2) {
    if (l1 == NULL || l2 == NULL) {
        return;
    }

    // 1. Prendiamo i puntatori alle teste reali per scorrere le due liste.
    //    Usiamo List (puntatore singolo) per leggere e avanzare.
    List p1 = *l1;
    List p2 = *l2;

    // 2. 'tail' è il doppio puntatore che punta sempre alla "presa" (il campo next
    //    dell'ultimo nodo inserito, oppure direttamente *l1 all'inizio)
    //    dove agganciare il prossimo nodo più piccolo.
    List *tail = l1;

    // 3. Finché entrambe le liste hanno elementi da confrontare
    while (p1 != NULL && p2 != NULL) {
        // <= garantisce la stabilità: a parità di valore, vince p1 (da l1)
        if (p1->data <= p2->data) {
            *tail = p1;          // Aggancio il nodo di p1 in coda al risultato
            p1 = p1->next;       // Avanzo nella prima lista
        } else {
            *tail = p2;          // Aggancio il nodo di p2 in coda al risultato
            p2 = p2->next;       // Avanzo nella seconda lista
        }
        // Sposto 'tail' sull'indirizzo del campo 'next' del nodo appena agganciato
        tail = &((*tail)->next);
    }

    // 4. Una delle due liste è finita: aggancio in blocco ciò che resta dell'altra
    //    (non serve un ciclo while perché i nodi rimanenti sono già collegati tra loro!)
    if (p1 != NULL) {
        *tail = p1;
    } else {
        *tail = p2;
    }

    // 5. La seconda lista originale ora è stata completamente assorbita in *l1
    *l2 = NULL;
}
