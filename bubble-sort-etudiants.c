/*
******************************************
==========================================
	PROGRAM NAME    >> TRIER FICHIERS
	Description     >>
Lire deux fichiers, les concatener, et
trier le fichier final.

	Developped by   >> Francesco Piva
	Date		>> 15/03/2015
==========================================
******************************************
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  <stdbool.h>



/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: tabloop
-------------------------------------------------
Description: sert a allouer bonne taille/memoire
aux lignesd du tableau dynamique.
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void tabloop(const int MAX_CHAR, const int TAILLE, char ** TAB)
{
	int k;
	for(k=0;k<TAILLE;k++)
	{
		TAB[k] = (char*)malloc(MAX_CHAR*sizeof(char));
	}
}


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: insert
-------------------------------------------------
Description: sert a ajouter une ligne lue dans le
tableau dont on se sert.
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void insert(int k, const int MAX_CHAR, char oneString[MAX_CHAR], char ** TAB)
{
	strcpy(TAB[k], oneString) ;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: create_tab
-------------------------------------------------
Description: fonction qui sert a creer le tableau
en lisant le fichier input.
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void create_tab(const int MAX_CHAR, const int TAILLE, const char NOM[] ,char ** TAB)
{
	FILE *fid;
	char oneString[MAX_CHAR];
	int k ;

	fid = fopen(NOM, "r");

	for(k=0;k<TAILLE;k++)
	{
		fscanf(fid, "%s", oneString) ;
		insert(k, TAILLE, oneString, TAB) ;
	}

	fclose(fid) ;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: bubble_sort
-------------------------------------------------
Description: sert a trier les valeurs dans un
tableau, la methode utilisee et celle a bulle.
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void bubble_sort(const int MAX_CHAR, const int TAILLE_FINALE,  char ** TAB_OUT)
{
	int i;
	char temp_tab[MAX_CHAR] ;

	int test = true;

	while (test)
	{
	test = false;

	for(i=0;i<TAILLE_FINALE - 1;i++)
		{
			if(strcmp(TAB_OUT[i],TAB_OUT[i+1])>0)
			{
				strcpy(temp_tab,TAB_OUT[i+1]);
				strcpy(TAB_OUT[i+1],TAB_OUT[i]);
				strcpy(TAB_OUT[i],temp_tab);

				test = true ;

			}
		}
	}
}


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: concatenate_all
-------------------------------------------------
Description: fonction qui met les 2 tableau l'un
apres l'autre.
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void concatenate_all(const int TAILLE1, const int TAILLE2, char ** TAB1, char **  TAB2, char  ** TAB_OUT)
{
	int i , j ;
	for(i=0;i<TAILLE1;i++)
	{
		strcpy(TAB_OUT[i], TAB1[i]);
	}
	for(j=0;j<TAILLE2;j++)
	{
		strcpy(TAB_OUT[i+j], TAB2[j]);
	}
}


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: write_file
-------------------------------------------------
Description: fonction qui sert a ecrire dans un
fichier les donnes du tableau qu'on lui rentre
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void write_file(const int TAILLE, const int MAX_CHAR, char ** TAB, const char NOM[])
{

	FILE *fid ;
	char oneString[MAX_CHAR] ;
	int k ;

	fid = fopen(NOM, "w") ;

	for(k=0;k<TAILLE;k++)
	{
		fprintf(fid, "%s\n", TAB[k]);
	}
	fprintf(fid, "Total Noms dans la liste = %i \n", k);
	fclose(fid);
}


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: empty
-------------------------------------------------
Description: qui sert a vider la memoire et le 
tableau qu'on a utiliser
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void empty(const int TAILLE, char ** TAB)
{
	int i;
	for(i=0;i<TAILLE;i++)
	{
		free(TAB[i]);
	}
	free(TAB);

}


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: show_tab
-------------------------------------------------
Description: fonction d'affichage des tableau
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
void show_tab(const int TAILLE, char ** TAB)
{
	int i;
	for(i=0;i<TAILLE;i++)
	{
		printf("%s\n",TAB[i]);
	}
}


/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
-------------------------------------------------
Fonction: main
-------------------------------------------------
Etapes :
	1) Allocation memoire pour 3 tableaux dynamiques.
	2) Creation de 2 tableaux avec les donnes des 2 fichiers.
	3) On les concatenate dans 1 seul tableau.
	3a) On montre ce qu'on a dans les tableaux.
	4) On trie les valeur du tableau output.
	4a) On montre les valeur rangees du tableau output.
	5) on ecrit dans le fichier output.
	6) on vide la memoire.
-------------------------------------------------
-= -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
int main()
{

	const int  TAILLE_FICH1 = 300 ;
	const int TAILLE_FICH2 = 148 ;
	const int TAILLE_FINALE = TAILLE_FICH1 + TAILLE_FICH2;

	const int MAX_CHAR = 80 ;

	const char NOMFICHIER1[] = "etudiants2.txt" ;
	const char NOMFICHIER2[]  = "etudiants3.txt" ;
	const char NOMFICHIER_OUT[] = "FPetudiants_out.txt" ;

	char **TABDYN_1 ;
	char **TABDYN_2 ;
	char **TABDYN_OUT ;

	FILE *fid;

// Etape 1)

	TABDYN_1 = (char**)malloc(TAILLE_FICH1*sizeof(int*)) ;
	TABDYN_2 = (char**)malloc(TAILLE_FICH2*sizeof(int*)) ;
	TABDYN_OUT = (char**)malloc(TAILLE_FINALE*sizeof(int*)) ;
	tabloop(MAX_CHAR, TAILLE_FICH1, TABDYN_1);
	tabloop(MAX_CHAR, TAILLE_FICH2, TABDYN_2);
	tabloop(MAX_CHAR, TAILLE_FINALE, TABDYN_OUT);

// Etape 2)
	create_tab(MAX_CHAR, TAILLE_FICH1, NOMFICHIER1, TABDYN_1);
	create_tab(MAX_CHAR, TAILLE_FICH2, NOMFICHIER2, TABDYN_2);

//Etape 3)
	concatenate_all(TAILLE_FICH1, TAILLE_FICH2, TABDYN_1, TABDYN_2, TABDYN_OUT);

// Etape 3a)
	show_tab(TAILLE_FICH1,TABDYN_1);
	printf("\n \n === FIN DE L'AFFICHAGE DU TABDYN_1 === \n\n");

	show_tab(TAILLE_FICH2,TABDYN_2);
	printf("\n \n === FIN DE L'AFFICHAGE DU TABDYN_2 === \n\n");

	show_tab(TAILLE_FINALE,TABDYN_OUT);
	printf("\n \n === FIN DE L'AFFICHAGE DU TABDYN_OUT === \n\n");

// Etape 4)
	bubble_sort(MAX_CHAR, TAILLE_FINALE, TABDYN_OUT);

// Etape 4a)
	show_tab(TAILLE_FINALE, TABDYN_OUT);
	printf("\n \n === FIN DU TRIAGE TABDYN_OUT === \n\n");

// Etape 5)
	write_file(TAILLE_FINALE, MAX_CHAR, TABDYN_OUT, NOMFICHIER_OUT);

// Etape 6)
	empty(TAILLE_FICH1, TABDYN_1);
	empty(TAILLE_FICH2, TABDYN_2);
	empty(TAILLE_FINALE, TABDYN_OUT);
	return 0;
}
