#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct PILE1
{
int tab;
struct PILE1 *next;
}p1;

struct PILE2
{
int x;
struct PILE2 *next;

}p2;

void afficher(int **p1, int **p2)
{

printf("\n");
printf("\n");
printf("");


}
int insert_tab_values(int tab)
{
// aucun controle d input !! 
// aucun controle de la taille de l'input
// aucun dynamisme dans la taille du tableau

	int val_max;
	printf("\n inserez la taille du tableau 1D:\n");
	scanf("%d",&val_max);
	int  i=0;
		do{
		i = i+1;
		printf("\n inserez la %dere valeure du tableau 1D:\n", i);
		scanf("%d",&tab[i]);
		}while(i =< val_max)

}

void main()
{
int i,j;
int tab[];

tab[i] = (int*)malloc(val_max*sizeof(int));

}


// faire main qui demande ce qu-on veux faire avec la pile (import ou enter numbers)
// >>>>>>>>>>> 2 fonctions 1) import file and then use only imported 2) enter numbers
// faire une fonction qui test que a-1 > a > a+1 pour tout les a (nb) dans la pile
// faire une fonction qui regarde pour quel i de la pile le j de lautre pile va aller
// faire une fonctoin affichage qui affiche ce qu-il y a dans la pile
// faire une fonction qui bouge de liste 1 a liste 2 (ou vice versa ?)
// faire une pile 1 et 2
// 
