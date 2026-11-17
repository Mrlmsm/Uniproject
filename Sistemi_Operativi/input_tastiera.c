/*
 *Scrivere un programma per la lettura da standard input di coppie <nome,cognome>. Nome e cognome possono essere separati da uno o più spazi bianchi e/o tabulazioni. La stringa letta in input si assume sempre composta di una coppia <nome,cognome>. 
Si implementi la funzione parse_nome per l'estrazione del nome. La funzione ha il seguente prototipo
La funzione parse_nome prende in input la stringa contenente nome e cognome, e restituisce la stringa contenente solo il nome immesso dall'utente.
Il main deve contenere la chiamata alla funzione implementata e un meccanismo elementare di gestione dell'interazione che richieda all'utente di inserire una coppia composta di nome e cognome, e che termini nel momento in cui l'utente preme invio senza avere digitato altri caratteri.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* parse_nome(char* stringa_completa){
	size_t i = 0;
	while(stringa_completa[i] != '\0' &&
		       	stringa_completa[i] != ' ' &&
		       	stringa_completa[i] != '\t' &&
		       	stringa_completa[i] != '\n'){
		i++;
	}
	char* result = malloc((i + 1) * sizeof(*result));
	if(result == NULL){ exit(EXIT_FAILURE); }
	for(size_t j = 0; j < i; j++){
		result[j] = stringa_completa[j];
	}
	result[i] = '\0';
	return result;
}
int main(int argc, char** argv){
	char buffer[256];
	char* result;
	printf("Inserisci una coppia nome cognome oppure invio per terminare:\n");
	while(fgets(buffer, sizeof(buffer), stdin) != NULL){
		if(buffer[0] == '\n'){ exit(EXIT_FAILURE); }
		result = parse_nome(buffer);
		printf("Nome estratto: %s\n", result);
		free(result);
		printf("Inserisci un altro nome cognome oppure invio per terminare:\n");
	}
	return 0;
}
