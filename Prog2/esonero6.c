/* Crea una funzione che dato un array ne duplichi i numeri.
 * Esempio: abc1c diventa abc11c */
char* duplicaNumeri(const char *str, int len) {
	if(str == NULL || len < 0){
		return NULL;
	}
	int count = 0;
	for(int i = 0; i < len; i++){
		if(str[i] >= '0' && str[i] <= '9'){
			count++;
		}
	}
	int new = len + count;
	char *a = malloc(sizeof(*a) * (new + 1));
	if(a == NULL){
		return NULL;
	}
	int f = 0;
	for(int j = 0; j < len; j++){
		if(str[j] >= '0' && str[j] <= '9'){
			a[f] = str[j];
			a[f + 1] = str[j];
			f += 2;
		}
		else{
			a[f] = str[j];
			f++;
		}
	}
	a[new] = '\0';
	return a;
}
