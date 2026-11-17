#include <stdio.h>
#include <stdlib.h>






int main(){

	
	
	for(size_t i = 55; i < 100; i++){
	
		printf((i&1) ? "%zu pari\n" : "%zu dispari\n", i);
	}

	
	exit(EXIT_SUCCESS);


}
