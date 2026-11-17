/*Scrivere un programma creaproc che effettua le seguenti operazioni:
Crea 3 figli; Dopo aver creato i 3 figli si mette in attesa della loro terminazione con una wait();
Ogni volta che un processo figlio termina, il processo padre stampa il PID del figlio appena terminato
Rendere creaproc parametrico, passando in input il numero di figli da creare;
Fare in modo che ogni figlio, prima di terminare, attenda n secondi (dove n è l’ultima cifra del PID di quel figlio)
*/
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/wait.h>

void creaproc(int figli){
	pid_t n;
	pid_t figlio;
	int attesa;
	for(size_t i = 0; i < figli; i++){ //Con il for creo tanti figli quanti sono il numero in input
		n = fork();
		if(n == -1){
		printf("Errore nella creazione del processo");
		exit(EXIT_FAILURE);
		}
		else if(n == 0){
			figlio = getpid(); //Prendo il pid del figlio
			n = figlio % 10; //Ultima cifra
			sleep(n); //Nanna
			exit(EXIT_SUCCESS);	
		}
	}
		pid_t finito;
		int status;
		for(size_t i = 0; i < figli; i++){
			finito = wait(&status); //Restituisce il PID del figlio appena terminato
		
		if(finito > 0){ //Vuol dire che non è terminato con un errore
		printf("PID figlio: %d\n", finito);
		}
	}
}
int main(){
	int f;
	printf("Numero di figli da creare: ");
	scanf("%d", &f);
	creaproc(f);
	return 0;
}

