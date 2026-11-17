#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <syscall.h>

char buffer[30] = "Ciao! Sto scrivendo sul file";
char b[100] = {0};
int main() {
	int f = open("lol.txt", O_TRUNC | O_RDWR, 0644);
	if(f < 0){
		printf("Errore nell'apertura del file");
		exit(EXIT_FAILURE);
	}
	pid_t procpid;

	procpid = fork();
	
	switch(procpid){
		case -1:
			printf("Errore nella creazione della fork");
			exit(EXIT_FAILURE);
		case 0:  
			write(f, buffer, sizeof(buffer));
			exit(EXIT_SUCCESS);
		default:
			int status;
			pid_t fpid = wait(&status);
			lseek(f, 0, SEEK_SET);
			read(f, b, 30);
			printf("%s\n", b);
	}
	close(f);
	return EXIT_SUCCESS;
}
