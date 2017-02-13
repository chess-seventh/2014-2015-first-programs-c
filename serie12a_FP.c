////////////////////////////////////////////////
/* Auteur    : Francesco Piva                 */
/* Date      : 28/05/2015                     */
/* Titre     : TP 12A                         */
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
		printf("fail dans top\n");
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


//main function
int main()
{
	int uInput;
	int uPlay;
	int i , j = 0;

	//initialisation of the 2 stacks
	
	PILE_T *pile_croissante = NULL;
	PILE_T *pile_decroissante = NULL;

	// creating a random set of numbers stored in a tab.
	
	int l = 10; 
	int iTab[l];
	iTab[l] = tab_rand(iTab, l);

	//For testing purpose
	//int iTab[5] = { 5, 4, 3, 4, 1};

	// on commence avec pile croissante
	pile_croissante = push(pile_croissante, iTab[0]);
	printf("on commence avec pile croissante premier push %d \n", pile_croissante->n);

	// flag is used to indicate whether the element has already been added to the stack
	int flag = 0;

	for(i=1 ; i< l ; i++)
	{
	
	// printf("\n\n\n %d-eme VALEUR DU TABLEAU ALEA %d\n", i, iTab[i]);

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
			
			// verification si la valeur a bien été ajoute
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

			// verification si la valeur a bien été ajoute
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
	if(pile_croissante != NULL)
	{
		printf("résultat dans pile croissante \n");
		for(i=0 ; i< l ; i++)
		{
			printf("valeur %d \n", pile_croissante->n);
			pile_croissante = pop(pile_croissante);
		}
	}
	else
	{
		printf("résultat dans pile décroissante \n");
		for(i=0 ; i< l ; i++)
		{
			printf("valeur %d \n", pile_decroissante->n);
			pile_decroissante = pop(pile_decroissante);
		}
	}
	
}


