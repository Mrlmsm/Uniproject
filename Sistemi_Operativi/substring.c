#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
	FILE* f = fopen("complexity.txt", "r");
	int c = 0;
	char buffer[256];
	char target[] = "computational";
       	while(fgets(buffer, sizeof(buffer), f) != NULL){
		printf("%s", buffer);
	}
	rewind(f);
	while(fgets(buffer, sizeof(buffer), f) != NULL){
		if(strstr(buffer, target) != NULL){
			printf("%s", buffer);
			c++;
		}
	}
	printf("Occorrenze trovate: %d", c);
	fclose(f);
	return 0;

}
