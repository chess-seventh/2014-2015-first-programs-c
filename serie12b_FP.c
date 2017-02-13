////////////////////////////////////////////////
/* Auteur    : Francesco Piva                 */
/* Date      : 28/05/2015                     */
/* Titre     : TP 12B                         */
////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Noeud
{
	struct Noeud* suivant;
	int val;
}NOEUD_T;


typedef struct List
{
	struct Noeud* origine;
	int longueur;
}LIST_T;


LIST_T* init_list()
{
	LIST_T *nouvelle_list = malloc(sizeof(* nouvelle_list));
    	nouvelle_list-> origine = NULL;
	nouvelle_list-> longueur = 0;
    	return nouvelle_list;
}


NOEUD_T* init_node(int val)
{
	NOEUD_T *nouveau_noeud = malloc(sizeof(* nouveau_noeud));
        nouveau_noeud->val = val;   
	return nouveau_noeud;
}

void ajouter_noeud(LIST_T* l, int val){

	NOEUD_T* nouveau = init_node(val);
	// la liste est vide, elle devient circulaire avec un element
    	if (l->origine == NULL)
	{
		l-> origine = nouveau;
     	   	l-> origine->suivant = nouveau;
    	}
    	else
	{
        	NOEUD_T* courant = l-> origine;
		// la liste a un seul element
       		if (courant == l-> origine-> suivant)
		{
           	 	l-> origine-> suivant = nouveau;
            		nouveau-> suivant = l-> origine;
       		}
        	else
		{
			// on recherche le dernier noeud
            		while(courant->suivant != l->origine)
			{
                		courant = courant-> suivant;
			}
            		courant-> suivant = nouveau;
            		nouveau-> suivant = l-> origine;
        	}
    	}
	l-> longueur = (l-> longueur + 1);
}

void print_list(LIST_T* l)
{
	if(l != NULL)
	{
		NOEUD_T* courant = l-> origine;
		printf("\n");
		printf("Valeur origine %d \n", courant->val);
		while(courant->suivant!=l->origine)
		{
                	courant = courant-> suivant;
			printf("Valeur %d \n", courant->val);
		}
		printf("\n");
	}	
}

void enlever_element(LIST_T* l,int k)
{
	
	if((l-> longueur) > 1)
	{
		NOEUD_T* enlever = l-> origine;
		int i ;
		for(i = 1; i < k; i++)
		{
			enlever = enlever -> suivant;
		}
		printf("Valeur à enlever: %d \n", enlever->val);
		
		// chercher predecesseur du noeud à enlever
		NOEUD_T* pre = l-> origine;
		while(pre->suivant != enlever )
		{
			pre = pre->suivant;
		}
		
		//changer d’ordre
		pre->suivant = enlever->suivant;

		// changer origine de la liste
		l->origine = enlever->suivant;

		//clean up
		free(enlever);
		l-> longueur = (l-> longueur) - 1;
	}
	else
	{
		printf("Valeur à enlever: %d \n", l-> origine->val);
		l-> longueur = 0;
		NOEUD_T* enlever = l-> origine;
		l-> origine = NULL;
		free(enlever);
	}
}

//main function
int main()
{
	LIST_T* l = init_list();
	int i ;
	for(i = 1; i < 9; i++)
	{
		ajouter_noeud(l,i);
	}

	//print_list(l);
	while(l-> longueur > 0)
	{
		print_list(l);
		enlever_element(l,3);
	}
}

// 1,2,3,4,5,6,7,8     3
// 4,5,6,7,8,1,2       6
// 7,8,1,2,4,5         1
// 2,4,5,7,8,          5
// 7,8,2,4             2
// 4,7,8               8
// 4,7                 4


