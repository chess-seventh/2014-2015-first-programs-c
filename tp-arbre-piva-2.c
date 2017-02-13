////////////////////////////////////////////////
/* Auteur    : Francesco Piva                 */
/* Date      : 18/06/2015                     */
/* Titre     : TP 14 Arbres + Code Morses     */
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct s_arbreNoeud{
	struct s_arbreNoeud* left;
	struct s_arbreNoeud* right;
	int val;
}arbreNoeud_T;


void arbre_add(arbreNoeud_T** arbre, int val)
{
	if(*arbre != NULL)
		{
			if( (*arbre)->val <= val )
				arbre_add(&((*arbre)->right), val);
			
			else if ((*arbre)->val > val)
				arbre_add(&((*arbre)->left), val);
		}
	else
		{
			*arbre = (arbreNoeud_T*) malloc(sizeof(arbreNoeud_T));
			(*arbre)->val = val;
			(*arbre)->left = NULL;
			(*arbre)->right = NULL;
		}
}

void arbre_print(arbreNoeud_T* arbre, int niveau)
{
	if(arbre != NULL)
		{
			
			arbre_print(arbre->left, niveau++);
			printf("%d -> niveau de l'arbre : %d\n", arbre->val, niveau);
			arbre_print(arbre->right, niveau++);
		}
}

int main()
{
	const int NB_NUMBERS = 10;
	arbreNoeud_T* arbre = NULL;

	int i, n;
	
	srand(time(NULL));
	
	for(i = 0; i < NB_NUMBERS; i++)
		{
			n = rand() % 77 ;
			printf("%d ", n);
			
			arbre_add(&arbre, n);
		}
printf("\n\n");
	printf("\n");
	arbre_print(arbre, 0);

	return 0;
}
