/* ESERCIZIO 2 - Conta foglie tra due profondita'

  Dati:
  - la radice di un albero binario;
  - due interi minDepth e maxDepth.

  Richiesta:
  Contare il numero di foglie la cui profondita' e' compresa fra minDepth e maxDepth (estremi inclusi).
  La radice ha profondita' 0. Una foglia e' un nodo senza figli.

  ATTENZIONE (punto critico): la profondita' non e' un campo del nodo, quindi va passata come parametro.
  Serve una funzione ausiliaria ricorsiva: decidi dove incrementarla e dove fare il controllo sulla foglia.

  ESEMPI:
  (1) albero:        1              minDepth=1, maxDepth=2
                   /   \            foglie: 4,5 (prof. 2), 3 (prof. 1)
                  2     3           Risultato: 3
                 / \
                4   5

  (2) stesso albero, minDepth=2, maxDepth=2
      Risultato: 2

  (3) albero vuoto -> Risultato: 0
*/

int aux(Tree root, int min, int max, int depth) {
	if(root == NULL || depth > max){
		return 0;
	}
	if(root->right == NULL && root->left == NULL){
		if(depth >= min && depth <= max){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return aux(root->right, min, max, depth + 1) + aux(root->left, min, max, depth + 1);
	}
}
int countLeavesBetweenDepths(Tree root, int minDepth, int maxDepth) {
	if(root == NULL){
		return 0;
	}
	int count = aux(root, minDepth, maxDepth, 0);
	return count;
}
