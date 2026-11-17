#include <stdio.h>
#include <string.h>
#include "list.h"




/**
 * Data una stringa s, restituisce una lista di caratteri che contiene tutti
 * e soli i caratteri alfabetici maiuscoli (A - Z) trasformati in minuscoli
 * (a - z) della stringa s nell'ordine in cui occorrono in s.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se s == NULL, restituisce NULL.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) data s == NULL  restituisce NULL
 * (2) data s == "" restituisce NULL
 * (3) data s == "A" restituisce [a]
 * (4) data s == "AZbCuu12R" restituisce [a,z,c,r]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_stringToList"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
List makenode(char data){
	List newnode = malloc(sizeof(ListNode));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

List stringToList(char *s){
	if(s == NULL) return NULL; 
	if(*s == '\0') return NULL;
	char f = NULL;
	for(int i = 0; s[i] != '\0'; i++){
		if (s[i] >= 'A' && s[i] <= 'Z') f = tolower(s[i]);
		List node = makenode(f);
	}

}
