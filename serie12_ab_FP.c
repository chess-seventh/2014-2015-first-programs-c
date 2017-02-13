////////////////////////////////////////////////
/* Auteur    : Francesco Piva                 */
/* Date      : 28/05/2015                     */
/* Titre     : TP 12 A + B Avec Tab Rand      */
////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Creation of Structure PILE. With type name : PILE_T.

typedef struct Pile
{
	int n;
	struct Pile *next;
}PILE_T;


// creation dun noeud et d'une liste.

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


// function to push a value in a stack.
PILE_T* push(PILE_T *maPile, int nbr)
{

	PILE_T *nouveau_element = malloc(sizeof(*nouveau_element));

	nouveau_element->n = nbr;
	nouveau_element->next = maPile;

	return nouveau_element;
}


// function to remove a value from a stack
PILE_T* pop(PILE_T *maPile)
{
	if(maPile == NULL)
	{
		printf("la pile est vide \n");
		exit(EXIT_FAILURE);
	}

	PILE_T *elem_suivant;
	elem_suivant = maPile->next;
	free(maPile);
	return elem_suivant;
}

// function to see the first element of a stack.

int top(PILE_T *maPile)
{
	if(maPile == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return maPile->n;
}


// function random creator of the data set to sort.
int tab_rand(int tab[], int l)
{
	int i = 0;
	srand(time(NULL));

	for(i=0 ; i < l ; i++)
	{
		tab[i] = rand()%77 ;
		printf("Num Alea #%d = %d \n", i, tab[i]);
	}

	return *tab;
}

// fonction pour initialiser la liste.
LIST_T* init_list()
{
	LIST_T *nouvelle_list = malloc(sizeof(* nouvelle_list));
    	nouvelle_list-> origine = NULL;
	nouvelle_list-> longueur = 0;
    	return nouvelle_list;
}

// fonction pour initialiser les noeuds
NOEUD_T* init_node(int val)
{
	NOEUD_T *nouveau_noeud = malloc(sizeof(* nouveau_noeud));
        nouveau_noeud->val = val;
	return nouveau_noeud;
}


// fonction pour ajouter des noeuds
void ajouter_noeud(LIST_T* l, int val){

	NOEUD_T* nouveau = init_node(val);

	// la liste est vide, elle devient circulaire avec 1 element

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


// fonction pour afficher la liste
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


// fonction pour enlever un element d'un noeud.
void enlever_element(LIST_T* l,int k)
{

	int i = 1;

	if((l-> longueur) > 1)
	{
		NOEUD_T* enlever = l-> origine;
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
	int i = 0;

	//initialisation of the 2 stacks

	PILE_T *pile_croissante = NULL;
	PILE_T *pile_decroissante = NULL;

	// creating a random set of numbers stored in a tab.

	int taille = 10; 
	int iTab[taille];
	iTab[taille] = tab_rand(iTab, taille);

	//For testing purpose
	//int iTab[5] = { 5, 4, 3, 4, 1};

	// on commence avec pile croissante
	pile_croissante = push(pile_croissante, iTab[0]);
	printf("on commence avec pile croissante premier push %d \n", pile_croissante->n);

	// flag is used to indicate whether the element has already been added to the stack
	int flag = 0;

	for(i=1 ; i< taille ; i++)
	{

	printf("\n\n\n %d-eme VALEUR DU TABLEAU ALEA %d\n", i, iTab[i]);

		if(pile_croissante != NULL)
		{
			while (pile_croissante != NULL)
			{
				if(iTab[i] >= (pile_croissante->n) && flag == 0)
				{
					pile_decroissante  = push(pile_decroissante,iTab[i]);
					printf("Pile décroissante insertion nouvelle valeur %d \n", iTab[i]);
					flag = 1;
				}
				pile_decroissante  = push(pile_decroissante, pile_croissante->n);
				printf("Pile décroissante nouvelle valeur %d \n", pile_decroissante->n);

				pile_croissante = pop(pile_croissante);
			}


			// verification si la valeur a bien été ajoutee
			if(flag == 0)
			{
				printf("Pile décroissante, flag 0 insertion nouvelle valeur %d \n", iTab[i]);
				pile_decroissante  = push(pile_decroissante,iTab[i]);
			}
			else
			{
				// reinit flag
				flag = 0;
			}
		}
		else if(pile_decroissante != NULL)
		{
			while (pile_decroissante != NULL)
			{
				if(iTab[i] <= (pile_decroissante->n) && flag == 0)
				{
					pile_croissante  = push(pile_croissante,iTab[i]);
					flag = 1;
					printf("Pile croissante insertion nouvelle valeur %d \n", iTab[i]);
				}
				pile_croissante  = push(pile_croissante, pile_decroissante->n);
				printf("Pile croissante nouvelle valeur %d \n", pile_croissante->n);

				pile_decroissante = pop(pile_decroissante);
			}

			// verification si la valeur a bien été ajoutee
			if(flag == 0)
			{
				printf("Pile croissante, flag 0 insertion nouvelle valeur %d \n", iTab[i]);
				pile_croissante  = push(pile_croissante,iTab[i]);
			}
			else
			{
				// reinit flag
				flag = 0;
			}
		}

	}

	// Check result

//	free(iTab);


	if(pile_croissante != NULL)
	{
		printf("résultat dans pile Croissante ! \n");
		for(i=0 ; i< taille ; i++)
		{
			printf("valeur %d \n", pile_croissante->n);
			iTab[i] = pile_croissante->n ;
			pile_croissante = pop(pile_croissante);
		}
	}
	else
	{
		printf("résultat dans pile Decroissante! \n");
		for(i=0 ; i< taille ; i++)
		{
			printf("valeur %d \n", pile_decroissante->n);
			iTab[i] = pile_decroissante->n ;
			pile_decroissante = pop(pile_decroissante);
		}
	}

	/// faire ici l'anneau le node avec les valeurs qu'on à dans le premier rand du tableau.

	LIST_T* l = init_list();

	int j = 0;
	for(j = 0; j < taille; j++)
	{
		ajouter_noeud(l,iTab[j]);
	}
	//print_list(l);
	while(l-> longueur > 0)
	{
		print_list(l);
		enlever_element(l,3);
	}

}
