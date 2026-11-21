/* Crea una funzione che, data una stringa, crea un array in cui toglie i numeri
 * dall'array che le viene passato e li sostituisce con le lettere maiuscole 'A''B', ovvero:
 * ciao1c2a4o2 diventa ciaoAcBaAoB (sostituisce consecutivamente i numeri con A e B) */
char *sostituisciNumeri(const char *str, int len) {
	if(str == NULL || len < 0){
		return NULL;
	}
	char *a = malloc(sizeof(*a) * len + 1);
	if (a == NULL){
		return NULL;
	}
	bool s = true;
	for(int i = 0; i < len; i++){
		if(str[i] >= '0' && str[i] <= '9'){
			if(s){
				a[i] = 'A';
				s = false;
			}
			else{
				a[i] = 'B';
				s = true;
			}
		}
		else{
			a[i] = str[i];
		}
	}
	a[len] = '\0';
	return a;
}
