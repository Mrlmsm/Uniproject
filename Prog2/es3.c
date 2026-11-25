#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/* Restituisce la lista alternata dei nodi di '*l' e '*r', togliendoli da '*l' e '*r',
   che alla fine conterranno entrambi 'NULL' (non alloca nuova memoria).
   Esempio: l = [1, 5, 9], r = [0, 2, 4, 6, 8], restituisce t = [1, 0, 5, 2, 9, 4, 6, 8]. */
List mixAlternate(List *l, List *r) {
    // Guardia difensiva: se uno dei due puntatori a lista non è valido, esci.
    if (l == NULL || r == NULL) {
        return NULL;
    }

    List head = NULL; // Testa della nuova lista intrecciata
    List tail = NULL; // Coda della nuova lista (serve per inserire in O(1))
    bool scelta = true; // true = pesca da *l, false = pesca da *r

    // Continua finché almeno una delle due liste originali ha ancora nodi.
    // NOTA: usiamo direttamente *l e *r (le teste reali nel main), non delle copie!
    while (*l != NULL || *r != NULL) {
        if (scelta) {
            // TURNO DI *l
            if (*l != NULL) {
                // 1. Aggancia il primo nodo di *l a un puntatore temporaneo 'nodo'
                List nodo = *l;

                // 2. Sposta la testa reale '*l' al nodo successivo.
                //    Così facendo, 'nodo' non fa più parte della lista *l!
                *l = (*l)->next;

                // 3. Stacca la coda di 'nodo' dal resto della vecchia lista.
                //    (Va fatto DOPO il passo 2, altrimenti perderesti il resto di *l!)
                nodo->next = NULL;

                // 4. Inserisci 'nodo' in coda alla nuova lista (head / tail)
                if (head == NULL) {
                    head = nodo;
                    tail = nodo;
                } else {
                    tail->next = nodo;
                    tail = nodo;
                }
            }
            // Passa il turno a *r (anche se *l era già vuota)
            scelta = false;
        } else {
            // TURNO DI *r (identico e simmetrico)
            if (*r != NULL) {
                List nodo = *r;     // 1. Prendi il primo nodo di *r
                *r = (*r)->next;    // 2. Avanza la testa reale *r
                nodo->next = NULL;  // 3. Isola il nodo preso

                // 4. Inserisci in coda alla nuova lista
                if (head == NULL) {
                    head = nodo;
                    tail = nodo;
                } else {
                    tail->next = nodo;
                    tail = nodo;
                }
            }
            // Passa il turno a *l
            scelta = true;
        }
    }

    // Arrivati qui, sia *l che *r hanno raggiunto la fine e valgono già NULL!
    return head;
}
