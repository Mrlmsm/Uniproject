#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Dato un array di caratteri 'str', con 'n' elementi,
 * restituisce un nuovo array (di lunghezza 'n') ottenuto da 'str' eliminando tutte le occorrenze delle cifre ('0'...'9'),
 * trasformando tutte le occorrenze delle lettere minuscole 'k' e 'h' nelle corrispondenti lettere maiuscole,
 * e riempiendo le eventuali posizioni rimaste libere alla fine del nuovo array con delle occorrenze del carattere '#'.
 * Esempio: '56akhra45' diventa 'aKHra####'. */
char* str(char* a, int n){
	if(a == NULL || n == 0){
		return NULL;
	}
	int canc = 0;
	int l = 0;
	char* r = malloc(sizeof(*r) * (n + 1));
	for(size_t i = 0; a[i] != '\0'; i++){
		if(a[i] >= '0' && a[i] <= '9'){
			canc++;
		}
		else if(a[i] == 'k' || a[i] == 'h'){
			char f = toupper(a[i]);
			r[l] = f;
			l++;
		}
		else{
			r[l] = a[i];
			l++;
		}
	}
	for(size_t j = l; j < n; j++){
		r[j] = '#';
	}
	r[n] = '\0';
	return r;
}
