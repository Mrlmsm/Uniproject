#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void recur_to_up(char* in_str){
	if(*in_str == '\n'){
		return;
	}
	*in_str = toupper((unsigned char)*in_str);

	return recur_to_up(in_str + 1);
}

int main (int argc, char** argv){
	char buffer[256];
	char* result;
	printf("Inserisci una stringa da convertire in maiuscolo:\n");
	while(fgets(buffer, sizeof(buffer), stdin) != NULL){
		if(buffer[0] == '\n') { exit(EXIT_FAILURE); }
		recur_to_up(buffer);
		printf("%s\n", buffer);
	}
	return 0;
}

