#include <signal.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char argv[]){

	for(int i = 0; i < NSIG; i++){
	
		printf("Signal %d is %s\n", i, strsignal(i));
	
	}
	return 0;
}
