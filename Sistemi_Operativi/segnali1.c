#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void dd_signal_handler(int sig){
	printf("TEST!");
}

int main (int argc, char argv[]){
	int j;
	if(signal(SIGINT, dd_signal_handler) == SIG_ERR) 
		exit(EXIT_FAILURE);

	for(j=0;;j++){
		printf("%d\n", j);
		sleep(1);
	}

}
