#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256 //Grandezza massima della riga del file

char** leggi_lista(FILE* file_in, int* nof_elements){
	if(file_in == NULL || nof_elements == NULL){
		return NULL;
	} //Controllo sul file
	char buffer[MAX]; //Creazione dell'array buffer, in cui andranno tutti i caratteri del file
	size_t c = 0;
	while(fgets(buffer, sizeof(buffer),file_in) != NULL){ /**fgets legge nel file solo il numero di righe che contengono caratteri
								* così possiamo allocare un array corretto di dati
								*/
		c++;
	}
	if(c == 0){
		return NULL; //File vuoto
	}

	rewind(file_in); //Rimetto il cursore all'inizio del file

	char** array = malloc(c * sizeof(char*)); //Alloco l'array che ospiterà poi i dati, i dati sono tutte stringhe quindi char*
	if(array == NULL){ exit(EXIT_FAILURE); }
	
	size_t i = 0;
	while(i < c && fgets(buffer, sizeof(buffer), file_in) != NULL){
		buffer[strcspn(buffer, "\n")] = '\0';
		array[i] = malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(array[i], buffer);
		i++;
	}
	*nof_elements = c;
	return array;
}


void stampa_lista(char** mio_ar, int n_elements){

if (mio_ar == NULL || n_elements <= 0){
        printf("Nessun elemento da stampare.\n");
        return;
    }

    printf("--- Elenco dei nomi (%d elementi) ---\n", n_elements);
    for (int i = 0; i < n_elements; i++) {
        printf("%s\n", mio_ar[i]);
    }

}

int main(int argc, char** argv){
	FILE* file = fopen("lista_nomi.txt", "r");
	if(file == NULL){
		exit(EXIT_FAILURE);
	}
	int n_elementi = 0;

	char** lista = leggi_lista(file, &n_elementi);

	stampa_lista(lista, n_elementi);

	if (lista != NULL) {
        for (int i = 0; i < n_elementi; i++) {
            free(lista[i]); // Libera la stringa singola
        }
        free(lista); // Libera l'array di puntatori
    }
	fclose(file);
	return 0;

}


