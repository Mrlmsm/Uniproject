#include <unistd.h>
#include <stdio.h>
#include <syscall.h>
/*
 FORK:
 	pid_t processpid;
 
 	processpid = fork();
 	if (processpid = -1) exit(EXIT_FAILURE);
 
 	if(processpid != 0){
 		Codice padre
 	}
 	else{
 		Codice figlio
 	}



 */

	
int main(){
	pid_t pid = getpid();
	pid_t pid1 = getppid();
	printf("Pid: %d		Ppid: %d\n", pid, pid1);
	return 0;
}	


