/*
Scrivere un programma che legga in input da tastiera una frase composta da almeno 5 parole e richiami una funzione per la stampa di tale stringa in caratteri maiuscoli e al contrario. Per esempio, data la frase
  	buongiorno a tutti da daniele
il programma deve stampare
  	ELEINAD AD ITTUT A ONROIGNOUB
La funzione per la stampa deve essere ricorsiva. Per lo svolgimento dell'esercizio è possibile utilizzare le funzioni di libreria fgets() e toupper().*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void print_reverse(char* in, int size){
	if(size < 0){
		return;
	}
	if(in[size] != '\n' || in[size] != '\0'){
	char t = toupper((unsigned char)in[size]);
	printf("%c", t);
	}
	return print_reverse(in, size-1);
}

int main(int argc, char** argv){
	char buffer[256];
	printf("Inserisci la stringa da stampare al contrario:\n");
	while(fgets(buffer, sizeof(buffer), stdin) != NULL){
		if(buffer[0] == '\n'){
			exit(EXIT_FAILURE);
		}
		int len = strlen(buffer);
		print_reverse(buffer, len-1);
		printf("\n");
	}

	return 0;


}
