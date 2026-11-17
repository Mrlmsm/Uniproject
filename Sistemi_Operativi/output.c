#include <stdio.h>
#include <stdlib.h>


int main (int argc){

	for(size_t i = 1; i <= 10; i++){
		for(size_t j = 0; j <= 10; j++){
			int k = i*j;
			printf("%6d", k);
		}
		printf("\n");
	}
	return 0;
}
