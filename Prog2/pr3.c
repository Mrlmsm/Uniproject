#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Sposta tutti i nodi con valore PARI dalla lista '*src' in coda alla lista '*dst',
   mantenendo l'ordine relativo e senza allocare/liberare memoria.
   Esempio: *src = [2, 3, 4, 5], *dst = [10]  -->  *src = [3, 5], *dst = [10, 2, 4]. */
void moveEvenToTail(List *src, List *dst) {
    // 1. Guardia iniziale: se manca una delle due liste o *src è già vuota, non c'è nulla da spostare.
    //    NOTA: *dst == NULL è ammesso! Significa che la lista di destinazione parte vuota.
    if (src == NULL || *src == NULL || dst == NULL) {
        return;
    }

    // 2. Troviamo l'ultimo nodo di *dst usando un puntatore locale 'tail',
    //    così NON perdiamo l'inizio reale della lista salvato in *dst.
    List tail = *dst;
    if (tail != NULL) {
        while (tail->next != NULL) {
            tail = tail->next;
        }
    }

    // 3. 'curr' è un puntatore al "gancio" (all'inizio punta a src, cioè alla testa di *src;
    //    poi punterà al campo ->next dei nodi dispari che decidiamo di lasciare in *src).
    List *curr = src;

    while (*curr != NULL) {
        if ((*curr)->data % 2 == 0) {
            // --- IL NODO È PARI: LO SGANCIAMO DA *src ---
            List tmps = *curr;          // A. Salviamo il nodo pari da spostare
            *curr = (*curr)->next;      // B. Aggiorniamo il gancio precedente: ora salta 'tmps'
            tmps->next = NULL;          // C. Isoliamo 'tmps' dal resto della lista *src

            // --- LO AGGANCIAMO IN CODA A *dst ---
            if (tail == NULL) {
                // Caso in cui *dst era inizialmente vuota: 'tmps' diventa sia testa che coda
                *dst = tmps;
                tail = tmps;
            } else {
                // Caso normale: attacchiamo dopo l'attuale ultimo nodo e aggiorniamo 'tail'
                tail->next = tmps;
                tail = tmps;
            }
            // NOTA: qui NON facciamo avanzare 'curr', perché al punto B abbiamo già messo
            // in '*curr' l'indirizzo del nodo successivo!
        } else {
            // --- IL NODO È DISPARI: RESTA IN *src ---
            // Spostiamo 'curr' sull'indirizzo del campo 'next' di questo nodo dispari
            curr = &((*curr)->next);
        }
    }
}
