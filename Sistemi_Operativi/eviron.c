#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
	extern char **environ;
	char t1[] = "LOGNAME";
	char t2[] = "HOME";
	char t3[] = "PATH";
	for(size_t i = 0; environ[i] != NULL; i++){
		if(strstr(environ[i], t1) != NULL || strstr(environ[i], t2) != NULL || strstr(environ[i], t3) != NULL){
			printf("%s\n", environ[i]);
		}
	}
	exit(EXIT_SUCCESS);
	return 0;
}
