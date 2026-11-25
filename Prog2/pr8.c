#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode, *List;

/* Cerca l'ULTIMO nodo con valore strettamente positivo (> 0) nella lista '*l',
   lo stacca da dove si trova e lo sposta in TESTA a '*l' (senza malloc/free).
   Esempio: *l = [-2, 5, -1, 8, -4]  -->  *l diventa [8, -2, 5, -1, -4]. */
void moveLastPositiveToFront(List *l) {
    if (l == NULL || *l == NULL) {
        return;
    }

    List *curr = l;         // Cursore per esplorare le frecce senza modificare *l
    List *lastPos = NULL;   // Salverà l'indirizzo della freccia dell'ultimo positivo

    // 1. Scorriamo tutta la lista fino in fondo
    while (*curr != NULL) {
        if ((*curr)->data > 0) {
            // Salviamo l'INDIRIZZO della freccia (senza asterischi!)
            lastPos = curr;
        }
        // Avanziamo sempre il cursore alla freccia successiva
        curr = &((*curr)->next);
    }

    // 2. Se non ci sono positivi (lastPos == NULL)
    //    oppure se l'ultimo positivo è già il primo nodo in testa (lastPos == l), non facciamo nulla
    if (lastPos == NULL || lastPos == l) {
        return;
    }

    // 3. Sganciamo il nodo puntato da *lastPos e lo spostiamo in testa
    List tmp = *lastPos;      // A. Salviamo il nodo positivo (es. [8])
    *lastPos = tmp->next;     // B. Chiudiamo il buco: il nodo prima di [8] ora punta a quello dopo [8]
    tmp->next = *l;           // C. Colleghiamo [8] davanti alla vecchia testa (es. [-2])
    *l = tmp;                 // D. Aggiorniamo la testa reale *l al nuovo primo nodo [8]
}
