/************************************************
 * Francesco Piva
 * Date: 11.12.2014
 * Version: 1.0
 * Titre: Morpion
 * Description: Tic Tac Toe console mode
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char symbolUser = 'X' ;
const char symbolPC = 'O' ;
const char symbolEmpty = ' ' ;

int cpu1(int taille, char morpion[taille][taille])
{
	int i, j ;
	for(i =0 ; i < taille ; i++)
		{
			for(j=0 ; j < taille ; j++)
			{
				if(morpion[i][j] == symbolEmpty)
					{
						morpion[i][j] = symbolPC ;
						printf("\n le PC a joue ! \n");
							if(morpion[i][j] == symbolPC)
							{
								showGrille(taille, morpion) ;
								return 0 ;

							}
					}
			}

		}


}


int showGrille(int taille, char morpion[taille][taille])
{
	int i, j; // i etant la ligne et j la colonne
	for(i = 0 ; i < taille ; i++)
	{
		for(j = 0 ; j < taille; j++)
		{
			printf("| %c | " , morpion[i][j]) ;
		}
	 	printf("\n");
	}
}

void initGrille(int taille, char morpion[taille][taille], char symbolEmpty)
{
	int i, j;
	for(i = 0 ; i < taille; i++)
	{
		for(j = 0 ; j < taille ; j++)
		{
			morpion[i][j] = symbolEmpty ;
		}
	}
}

/*
void lecturetab(int taille, char morpion[taille][taille], int playturns)
{

	int i , j ;
	for(i = 0 ; i <  taille ; i++)
	{
		for(j = 0 ; j < taille ; j++)
		{
			if(morpion[i][j] == symbolEmpty)
			{
//				playturns = playturns + 1;
			}
		}
	}
}
*/

bool tailleMorpion(int taille, int tailleMax, int tailleMin)
{

    if (taille >= tailleMin && taille <= tailleMax)
    {
        return true;
    }
    else
    {
		printf("\n --La taille de votre morpion n'est pas correcte rentrez une taille entre %d et %d : \n", tailleMin, tailleMax);
        return false;
    }

}


bool victory(int taille, char morpion[taille][taille])
{
	int i, j ;

	int sumVer;

	for(j = 0 ; j < taille; j++)
	{
		sumVer = 0;

		for(i = 0 ; i < taille ; i++ )
		{
			if(morpion[i][j] == symbolUser)
			{
				sumVer = sumVer + 1 ;
			}
		}

		// victory condition reached
		if(sumVer == taille)
		{
			printf("\n bravo Ver victory \n") ;
			return true ;
		}
	}

	// Todo check horizontal aligmnent


	for(i = 0; i < taille ; i++ )
	{
		int sumHor = 0;

		for(j = 0 ; j < taille ; j++)
		{
			if(morpion[i][j] == symbolUser)
			{
				sumHor = sumHor + 1 ;
			}
		}
		if(sumHor == taille)
		{
		printf("\n bravo Horiz victory \n") ;
		return true;
		}

	}



	// To do diagonal check right
	// morpion[i][i] == symbolUser

	int sumDia = 0;

	for(i = 0; i < taille ; i++)
	{
		if(morpion[i][i] == symbolUser)
		{
			sumDia = sumDia + 1 ;
		}
	if(sumDia == taille)
	{

	printf("\n bravo ! Dia Left Victory \n");
	return true;

	}

	// To do diagonal check left
	// morpion[tailler-i][taille-i] == symbolUser

	sumDia = 0 ;

	for(i = 0 ; i < taille ; i++)
	{

		if(morpion[taille-i][taille-i] == symbolUser)
		{

			sumDia = sumDia + 1 ;
		}

	if(sumDia == taille)
	{
		printf("\n  bravo ! Dia Right Victory") ;
		return true ;
	}

	}
	}

 /*
printf("\n hello world ! \n");
if()
*/

}



bool canPlay(int taille, char morpion[taille][taille], int userCol, int userLin)
{
	// verification that input is in the bounds of the grid
	if(userLin > taille || userCol > taille || userLin < 0 || userCol < 0 || morpion[userLin][userCol] !=  symbolEmpty)
	{
		printf("\n les donnees que vous avez rentre ne sont pas correcte. veuillez recommencer. \n") ;
		userPlay(taille, morpion, userLin, userCol) ;
		return false ;

	}
	// verification that the grid cell is not already taken
	else if(morpion[userLin][userCol] == symbolPC || morpion[userLin][userCol] == symbolUser )
	{

		printf("\n la case que vous voulez utiliser est deja prise. veuillez recommencer. \n") ;
		userPlay(taille, morpion, userLin, userCol) ;
		return false ;

	}
	else
	{
		return true;
	}


}

int userPlay(int taille, char morpion[taille][taille])
{
	int userLin,userCol;

	// Collect Input (verify that input is an int)
	printf("\n Entrez votre ligne : ");
	scanf("%d", &userLin);
	userLin = userLin - 1;
	printf("\n Entrez votre colonne : ");
	scanf("%d", &userCol);
	userCol = userCol - 1;

	if(canPlay(taille, morpion, userCol, userLin) == true)
	{
		printf("joueur a jouer L%d et C%d \n", userLin, userCol);
		morpion[userLin][userCol] = symbolUser ;
		showGrille(taille, morpion) ;
	}

}



bool easyWinV(int taille, char morpion[taille][taille], int sumVer, int idanger, int jdanger)
{

}



bool easyWinH(int taille, char morpion[taille][taille], int sumHor, int idanger, int jdanger)
{

}

bool easyWinD(int taille, char morpion[taille][taille], int idanger,  int jdanger, int sumDia)
{

}

bool cpuPlay(int taille, char morpion[taille][taille], int idanger, int jdanger, int sumVer, int sumHor, int sumDia)
{
idanger = 0 ;
jdanger = 0 ;

	if(easyWinV(taille, morpion, sumVer, idanger, jdanger) == true)
		{
		morpion[idanger][jdanger] = symbolPC ;
//		printf("\n idanger %d jdanger %d \n", idanger, jdanger);
		}
	if(easyWinH(taille, morpion, sumHor, idanger, jdanger) == true)
		{
		morpion[idanger][jdanger] = symbolPC ;
		}
	if(easyWinD(taille, morpion, idanger, jdanger, sumDia) == true)
		{
		morpion[idanger][jdanger] = symbolPC ;
		}

//return true; 

}

int IA_level(int taille, char morpion[taille][taille], int IA)
{

while(IA < 1 || IA > 3)
	{
	printf("\n choisissez le niveau de difficultee : ");
	printf("\n Level 1 = EASY : ");
	printf("\n Level 2 = NORMAL : ");
	scanf("%d", &IA);
	}

	return IA;

}


int main()
{
	int tailleMax = 25 ;
	int tailleMin = 3 ;
	int sumVer = 0 ;
	int sumHor = 0 ;
	int sumDia = 0 ;
	int jdanger, idanger ;
	int taille ;

	// Ask user for size of grid
	do
	{
		printf("\n --Entrez la taille du jeu du morpion, min %d, max %d \n", tailleMin, tailleMax);
		scanf("%d", &taille);
	} while(tailleMorpion(taille, tailleMax, tailleMin) != true) ;


	int iPC, jPC, IA ;

	// Grid Initialisation
	char morpion [taille][taille];

	initGrille(taille, morpion, symbolEmpty) ;
	showGrille(taille, morpion) ;

/*
	    switch (IA_level(taille, morpion, IA))
	    {
		case 1:
		    printf("Vous avez choisi le niveau EASY \n");
		    break;
		case 2:
		    printf("Vous avez choisi le niveau NORMAL \n");
		    break;

	    }

*/


	// start playing
	do
	{
		userPlay(taille, morpion) ;
		cpu1(taille, morpion) ;

	} while(victory(taille, morpion) != true) ;

/*		if(canPlay(taille, morpion, userCol, userLin) == true)
		{
			printf("joueur a jouer L%d et C%d \n", userLin, userCol);
			morpion[userLin][userCol] = symbolUser ;
			showGrille(taille, morpion) ;
			int idanger, jdanger ;
			cpuPlay(taille, morpion, idanger, jdanger, sumVer, sumHor, sumDia) ;
		}
*/


}
