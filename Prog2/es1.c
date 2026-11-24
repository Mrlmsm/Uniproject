#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
/*Mirror di un albero binario

  Dato: la radice di un albero binario.

  Richiesta:
  Invertire ricorsivamente l'albero scambiando, per ogni nodo, il sottoalbero sinistro con quello destro.
  L'albero va modificato sul posto: non si devono allocare nuovi nodi ne' liberare quelli esistenti.

  ATTENZIONE (punto critico): lo scambio dei due figli va fatto una volta sola per nodo.
  Scegli con cura se fare lo scambio prima o dopo le chiamate ricorsive, e verifica che il risultato sia lo stesso nei due casi.

  ESEMPI:
  (1) albero:        1              risultato:      1
                   /   \                          /   \
                  2     3                        3     2

  (2) albero:        1              risultato:      1
                   /                                  \
                  2                                    2
                 /                                      \
                3                                        3

  (3) albero vuoto (root == NULL)   risultato: albero vuoto
*/
void mirrorBinaryTree(Tree root) {
	if(root == NULL){
		return;
	}
		Tree tmp = NULL;
		tmp = root->right;
		root->right = root->left;
		root->left = tmp;
		mirrorBinaryTree(root->right);
		mirrorBinaryTree(root->left);
}
