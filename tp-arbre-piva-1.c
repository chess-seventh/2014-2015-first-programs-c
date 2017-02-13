////////////////////////////////////////////////
/* Auteur    : Francesco Piva                 */
/* Date      : 18/06/2015                     */
/* Titre     : TP 14 Arbres + Code Morses     */
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M_M '-'
#define M_D '.'

typedef struct s_arbreNoeud{
	struct s_arbreNoeud* gauche;
	struct s_arbreNoeud* droite;
	char l;
}arbreNoeud_T;



/*-------------------------------------------------
	DESCRIPTION. : AJOUTE UN ELEMENT A L'ARBRE.
* -------------------------------------------------*/
void ajout_arbre(arbreNoeud_T** arbre, char l, char* sequence)
{
	if(*arbre == NULL)
	{	
		*arbre = (arbreNoeud_T*) malloc(sizeof(arbreNoeud_T));
		(*arbre)->l = '+'; // top of my big tree
		(*arbre)->gauche = NULL;
		(*arbre)->droite = NULL;
	}

	if(strlen(sequence) == 0)
		{
			(*arbre) -> l = l ;		
		}

	else
		{
			switch(sequence[0]) // swithc case parce qu'on a que 2 valeurs a checker ... le . et le - défini tout en haut.
			{
				case M_D:
					sequence = sequence + 1 ;
					ajout_arbre( &( (*arbre) -> droite ) , l, sequence);	// j'ecris a l'adresse de droite. double pointeur en entrée de la fonction
					break;

				case M_M:
					sequence = sequence + 1 ;
					ajout_arbre( &( (*arbre) -> gauche ) , l, sequence);	// j'ecris a l'adresse de gauche. double pointeur en entrée de la fonction
					break;
			}
		}
}

/*-------------------------------------------------
	DESCRIPTION. : Function qui enlève caractère par 
			caractère le truc qu'on veux pas. 
* -------------------------------------------------*/
void remove_all_chars(char* str, char c) {
    char *pr = str, *pw = str;
    while (*pr) 
    {
        *pw = *pr++;
        pw += (*pw != c);
        if(*pw == c)
        	printf(" "); // Remplace le char par un espace. 
    }
    *pw = '\0';
}

/*-------------------------------------------------
	DESCRIPTION. : function qui appelle remove_all_chars 
			et enlève les charactère qu'on veux pas 
			voir dans l'output. 
* -------------------------------------------------*/
void char_cleanup(char* str)
{
	char chars_to_remove[1] = {'/'};

	int i;
	for(i = 0; i < 1; i++)
		remove_all_chars(str, chars_to_remove[i]);
}



/*-------------------------------------------------
	DESCRIPTION. : 	Fonction qui convertis une
				sequence de morse à une	lettre. 
* -------------------------------------------------*/
char arbre_morse_vers_mot(arbreNoeud_T* arbre, char* sequence)
{
	while(strlen(sequence) > 0)
	{
		switch(sequence[0])
		{
			case M_D: 
				arbre = arbre->droite; 
				break;

			case M_M: 
				arbre = arbre->gauche;
				break;
		}
		
		sequence = sequence + 1;
	}
	return arbre -> l;
}

/*-------------------------------------------------
	DESCRIPTION. : 	Fonction récursive qui va 
				à gauche d'abord et ensuite à
				droite en montrant le niveau.
				Affiche l'arbre et printf les
				valeurs qu'il contient. 
					
* -------------------------------------------------*/
void arbre_print(arbreNoeud_T* arbre, int level)
{
	if(arbre != NULL)
	{
		printf("%c -> NIVEAU DE L'ARBRE: %d\n", arbre->l, level);
		level = level + 1;
		arbre_print(arbre->gauche, level);
		arbre_print(arbre->droite, level);
	}
}

/*-------------------------------------------------
	DESCRIPTION. : Fonction qui libère l'arbre 
* -------------------------------------------------*/
void free_arbre(arbreNoeud_T* arbre)
{
	if(arbre != NULL)
	{
		free_arbre(arbre->gauche);
		free_arbre(arbre->droite);
		free(arbre);
	}
}


/*-------------------------------------------------
	DESCRIPTION. : Traduit un texte morse à un 
				language humain - on enlève aussi
				les caractère ici.
* -------------------------------------------------*/
void morse_vers_alphabet(const char filename[], arbreNoeud_T* arbre)
{
	FILE *file;
	char str[100];

	file = fopen(filename, "r");

	while(fscanf(file, "%s", str) != EOF)
	{
		(arbre, str));
	}

	printf("\n");
	fclose(file);
}

/*--------------------------------------------------
	DESCRIPTION. : fonction qui créer l'arbre avec 
* -------------------------------------------------*/
void arbre_creer(const char filename[], arbreNoeud_T** arbre)
{
	FILE *file;
	char str[100];

	file = fopen(filename, "r");

	while(fscanf(file, "%s", str) != EOF)
	{
		char l = str[0];
		fscanf(file, "%s", str);
		char* morse = str;
		// on balance ce qu'on viens de lire dans l'arbre.
		ajout_arbre(arbre, l, morse);
	}

	fclose(file);
}

/*-------------------------------------------------
	DESCRIPTION. : FONCTION MAIN. 
* -------------------------------------------------*/

int main()
{
	const char MORSE_CODE[] = "code-morse.txt";
	const char MORSE_TEXT[] = "texte-morse.txt";

	arbreNoeud_T* arbre = NULL;
	arbre_creer(MORSE_CODE, &arbre);

	printf("\nArbre print:\n");
	printf("\nOu on trouve les lettres de l'Alphabet:\n");
	arbre_print(arbre, 0);


	// traduit le code morse en alphabet. 
	
	printf("\nTranslation:\n \n");
	
	morse_vers_alphabet(MORSE_TEXT, arbre);
	
	free_arbre(arbre);
}