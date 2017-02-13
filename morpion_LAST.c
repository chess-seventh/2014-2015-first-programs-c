/*
 ============================================================================
 Name        : new_morpion.c
 Author      : Francesco Piva
 Version     : 1.0
 Description : Tic Tac Toe game, in console mode, with 2 IA levels.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//#include <ctime.h>

const char symbolUser = 'X' ;
const char symbolPC = 'O' ;
const char symbolEmpty = ' ' ;
const int a = 2 ; // sert a definir la taille du tableau retour pour le jeu du CPU.

/*
 ============================================================================
 Function Name : cpu1
 Function Returns : integer, if played 0.
 Function Description : IA du CPU de façon simple. IA bête.
 ============================================================================
 */


int cpu1(int taille, char morpion[taille][taille])
{
	int i, j;

//	srand(getpid()) ;
	i = rand() % taille ;
	j = rand() % taille ;

//printf("\n cpu1 fonctoin \n i =  %d et j = %d \n",i,j);

	if(morpion[i][j] == symbolEmpty)
		{
		morpion[i][j] = symbolPC ;
		showGrille(taille, morpion) ;
		return 0 ;
	}
	else
	{
		return 1 ;
	}

}



/*
 ============================================================================
 Function Name : showGrille
 Function Returns : integer, the grid of the tic-tac-toe.
 Function Description : Shows the grid of the tic-tac-toe.
 ============================================================================
 */

int showGrille(int taille, char morpion[taille][taille])
{
	int i, j; // i etant la ligne et j la colonne

	printf("\n\n------JEU DU MORPION------\n\n");

	for(i = 0 ; i < taille ; i++)
	{
		for(j = 0 ; j < taille; j++)
		{
			printf("| %c | " , morpion[i][j]) ;
		}
	 	printf("\n");
	}
}

/*
 ============================================================================
 Function Name : initGrille
 Function Returns : void, the grid of the tic-tac-toe. 
 Function Description : This initializes the grid, it puts all values to symbolEmpty
 ============================================================================
 */

void initGrille(int taille, char morpion[taille][taille])
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
 ============================================================================
 Function Name : tailleMorpion
 Function Returns : boolean, true or false. 
 Function Description : Checks if the input of the player is in the bounds allowed. 
 ============================================================================
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


/*
 ============================================================================
 Function Name : victoryVerU
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game VERTICALLY
 ============================================================================
 */


bool victoryVerU(int taille, char morpion[taille][taille])
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

	return false ;
}

/*
 ============================================================================
 Function Name : victoryHorU
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game  HORIZONTALLY
 ============================================================================
 */

bool victoryHorU(int taille, char morpion[taille][taille])
{
	int i, j ;

	// Todo check horizontal aligmnent
	int sumHor;
	for(i = 0; i < taille ; i++ )
		{
		sumHor = 0 ;
		for(j = 0 ; j < taille ; j++)
			{
			if(morpion[i][j] == symbolUser)
				{
				sumHor = sumHor + 1 ;
				}
			if(sumHor == taille)
				{
				return true;
				}
			}
		}

	return false ;
}
/*
 ============================================================================
 Function Name : victoryDiaU1
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game  DIAGONALLY from Top Left
			to Bottom Right
 ============================================================================
 */

bool victoryDiaU1(int taille, char morpion[taille][taille])
{

	int i, j ;

	// To do diagonal check right
	int sumDia = 0;

	for(i = 0; i < taille ; i++)
		{
			if(morpion[i][i] == symbolUser)
				{
				sumDia = sumDia + 1 ;
				if(sumDia == taille)
					{
					return true;
					}
				}
		}

	return false ;

}

/*
 ============================================================================
 Function Name : victoryDiaU2
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game  DIAGONALLY from Top Right
			to Bottom Left
 ============================================================================
 */

bool victoryDiaU2(int taille, char morpion[taille][taille])
{

int i, j ;

	int sumDia = 0 ;
		for(i = 0 ; i < taille ; i++)
			{
			if(morpion[i][taille-1-i] == symbolUser)
				{
				sumDia = sumDia + 1 ;
				if(sumDia == taille)
					{
					return true ;
					}
				}
			}
	return false ;
}

/*
 ============================================================================
 Function Name : victoryVerPC
 Function Returns : boolean, true or false.
 Function Description : Checks if PC has won the game VERTICALLY
 ============================================================================
 */

bool victoryVerPC(int taille, char morpion[taille][taille])
{
	int i , j;
	int sumVer;

	for(j = 0 ; j < taille; j++)
		{
		sumVer = 0;
		for(i = 0 ; i < taille ; i++ )
			{
			if(morpion[i][j] == symbolPC)
				{
				sumVer = sumVer + 1 ;
		// victory condition reached
				if(sumVer == taille)
					{
					return true ;
					}
				}
			}
		}
	return false;

}

/*
 ============================================================================
 Function Name : victoryHorPC
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game HORIZONTALLY
 ============================================================================
 */


bool victoryHorPC(int taille, char morpion[taille][taille])
{

	int i, j ;
	int sumHor;

	for(i = 0; i < taille ; i++ )
	{
		int sumHor = 0;
		for(j = 0 ; j < taille ; j++)
			{
			if(morpion[i][j] == symbolPC)
				{
				sumHor = sumHor + 1 ;
				if(sumHor == taille)
					{
					return true;
					}
				}
			}

	}

	return false;

}

/*
 ============================================================================
 Function Name : victoryDiaPC1
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game DIAGONALLY from top left
			to bottom right
 ============================================================================
 */


bool victoryDiaPC1(int taille, char morpion[taille][taille])
{

	int i, j ;
	int sumDia = 0;

	for(i = 0; i < taille ; i++)
		{
			if(morpion[i][i] == symbolPC)
				{
				sumDia = sumDia + 1 ;
				if(sumDia == taille)
					{
				return true;
					}
				}
		}
	return false ;
}
/*
 ============================================================================
 Function Name : victoryDiaPC2
 Function Returns : boolean, true or false.
 Function Description : Checks if user has won the game DIAGONALLY from top left
			to bottom right
 ============================================================================
 */


bool victoryDiaPC2(int taille, char morpion[taille][taille])
{

	int i, j ;
	int sumDia ;


	sumDia = 0 ;
		for(i = 0 ; i < taille ; i++)
		{
			if(morpion[i][taille-1-i] == symbolPC)
				{
				sumDia = sumDia + 1 ;
				}
			if(sumDia == taille)
				{
				return true ;
				}
		}
	return false ;

}


/*
 ============================================================================
 Function Name : victory
 Function Returns : boolean, true or false.
 Function Description : Checks who has won the game
 ============================================================================
 */


bool victory(int taille, char morpion[taille][taille])
{

//bool u, p ;
	if(victoryHorU(taille, morpion) == true || victoryVerU(taille, morpion) == true || victoryDiaU1(taille, morpion) == true || victoryDiaU2(taille, morpion) == true)
		{
		printf("\n User a gagne ! \n");
		return true ;
		}
	if(victoryHorPC(taille, morpion) == true || victoryVerPC(taille, morpion) == true || victoryDiaPC1(taille, morpion) == true || victoryDiaPC2(taille, morpion) == true)
		{
		printf("\n PC a gagne ! \n");
		return true ;
		}
	else
		{
		return false;
		}


}



/*
 ============================================================================
 Function Name : canPlay
 Function Returns : boolean, true or false. 
 Function Description : Checks if the input of the player is in the bounds allowed. 
 ============================================================================
 */


bool canPlay(int taille, char morpion[taille][taille], int userCol, int userLin)
{
//	printf("ON EST DANS LA FONCTION CANPLAY valeur de userCol = %d userLin = %d \n", userCol, userLin);

	// verification that input is in the bounds of the grid
	if(userLin > taille || userCol > taille || userLin < 0 || userCol < 0 || morpion[userLin][userCol] !=  symbolEmpty)
	{
		printf("\n les donnees que vous avez rentre ne sont pas correcte. veuillez recommencer. \n") ;
		return false ;
	}
	// verification that the grid cell is not already taken
	else if(morpion[userLin][userCol] == symbolPC || morpion[userLin][userCol] == symbolUser )
	{
		printf("\n la case que vous voulez utiliser est deja prise. veuillez recommencer. \n") ;
		return false ;
	}
	else
	{
	return true;
	}
}

/*
 ============================================================================
 Function Name : userPlay
 Function Returns : integer, stores the information of the play for the computer.
 Function Description : The user plays in this function. 
 ============================================================================
 */

int userPlay(int taille, char morpion[taille][taille], int userCol, int userLin, int warPC[2])
{
		do
		{
			userLin = userPlayLin(taille,morpion,userCol,userLin) ;
			userCol = userPlayCol(taille, morpion, userCol, userLin);
		} while(morpion[userLin][userCol] != symbolEmpty && canPlay(taille, morpion, userCol, userLin) == true) ;

	morpion[userLin][userCol] = symbolUser ;
	warPC[0] = userLin ;
	warPC[1] = userCol ;
	printf("\n...Le Joueur a jouer!\n");
//	showGrille(taille, morpion);
	return  warPC[a] ;

}

/*
 ============================================================================
 Function Name : userPlayLin
 Function Returns : integer, stores the information of the play for the computer.
 Function Description : The user input of the Line of the player. 
 ============================================================================
 */

int userPlayLin(int taille, char morpion[taille][taille], int userCol, int userLin)
{
	// Collect Input (verify that input is an int)
	do
	{
	printf("\n Entrez votre ligne : ");
	scanf("%d", &userLin) ;
	//	{
	//	while(getchar() != '\n') ;
	//	printf("\n...Valeure numerique seulement ! \n");
	///	}
	// je n'ai pas reussi a faire fonctionner le parametre : isdigit(userLin) ...
	userLin = userLin - 1;
	}while(userLin > taille ||  userLin < 0 &&  canPlay(taille, morpion, userCol, userLin == true)) ;
	return userLin ;
}

/*
 ============================================================================
 Function Name : userPlayCol
 Function Returns : integer, stores the information of the play for the computer.
 Function Description : The user input of the Column of the player.
 ============================================================================
 */

int userPlayCol(int taille, char morpion[taille][taille], int userCol, int userLin)
{
	do
	{
		printf("\n Entrez votre colonne : ");
		scanf("%d", &userCol) ;
		//	{
		//	while(getchar() != '\n');
		//	printf("\n...Valeure numerique seulement ! \n");
		//	}
	// je n'ai pas reussi a faire fonctionner le parametre : isdigit(userCol) ...

	userCol = userCol - 1;
	}while(userCol > taille || userCol < 0 &&  canPlay(taille, morpion, userCol, userLin == true));

	return userCol ;
}

/*
 ============================================================================
 Function Name : easyWinV
 Function Returns : boolean, true or false.
 Function Description : IA checks if there is an easy win Vertically for the player and blocks.
 ============================================================================
 */

int easyWinV(int taille, char morpion[taille][taille], int userLin, int userCol, int warPC[2])
{
	int sumVer = 0 ;
	int i, j ;
		for(i = 0 ; i < taille ; i++)
		{
			if(morpion[i][userCol] == symbolUser)
				{
				sumVer = sumVer + 1 ;
					if(sumVer == taille - 1)
						{
						for(j = 0 ;  j < taille ; j++)
							{
							if(morpion[j][userCol] == symbolEmpty)
								{
								printf("\n on est dans easywinV userCol = %d et j = %d \n", userCol, i) ;
								morpion[j][userCol] = symbolPC ;
//								warPC[0] = j ;
//								warPC[1] = userCol ;
								showGrille(taille, morpion);
								return 0 ;
								}
							}
						}
				}
		}
		return -1 ;
}

/*
 ============================================================================
 Function Name : easyWinH
 Function Returns : boolean, true or false.
 Function Description : IA checks if there is an easy win Horizontally for the player and blocks.
 ============================================================================
 */

int easyWinH(int taille, char morpion[taille][taille], int userLin, int userCol, int warPC[2])
{
	int sumHor = 0 ;
	int i , j ;
		for(i = 0 ; i < taille ; i++)
		{
			if(morpion[userLin][i] == symbolUser)
				{
				sumHor = sumHor + 1 ;
				if(sumHor == taille - 1)
					{
					for(j = 0 ; j < taille ; j++)
						{
						if(morpion[userLin][j] == symbolEmpty)
							{
							printf("\n on est dans easywinH userLin = %d et j = %d \n", userLin, j) ;
							morpion[userLin][j] = symbolPC;
							showGrille(taille, morpion);
							return 0 ;
							}
						}
					}

				}
		}

	return -1 ;


}

/*
 ============================================================================
 Function Name : easyWinD1
 Function Returns : boolean, true or false.
 Function Description : IA checks if there is an easy win Diagonal for the player and blocks.
 ============================================================================
 */

int easyWinD1(int taille, char morpion[taille][taille], int userLin, int userCol, int warPC[a])
{

	int sumDia = 0 ;
	int i, j ;
		for(i = 0 ; i < taille ; i++)
		{
			if(morpion[i][i] == symbolUser)
				{
				sumDia = sumDia + 1 ;
				if(sumDia == taille - 1)
					{
					for(j = 0 ; j < taille ; j++)
						{
						if(morpion[j][j] == symbolEmpty)
							{
							morpion[j][j] = symbolPC ;
							showGrille(taille, morpion) ;
							return 0 ;
							}
						}
					}
				}
		}
	return -1 ;

}


/*
 ============================================================================
 Function Name : easyWinD2
 Function Returns : boolean, true or false.
 Function Description : IA checks if there is an easy win Diagonal for the player and blocks.
 ============================================================================
 */

int easyWinD2(int taille, char morpion[taille][taille], int userLin, int userCol, int warPC[a])
{

int sumDia, i, j ;
	sumDia = 0 ;
		for(i = 0 ; i < taille ; i++)
		{
			if(morpion[i][taille-1-i] == symbolUser)
				{
				sumDia = sumDia + 1 ;
					if(sumDia == taille-1)
						{
						for(j = 0 ;  j < taille ; j++)
							{
							if(morpion[j][taille-1-j] == symbolEmpty)
								{
								morpion[j][taille-1-j] = symbolPC ;
								showGrille(taille, morpion);
								return 0 ;
								}
							}
						}

				}
		}

	return -1 ;


}

/*
 ============================================================================
 Function Name : cpuPlay
 Function Returns : boolean, true or false.
 Function Description : IA du CPU de façon "intelligente". IA checks if user is going to win.
 ============================================================================
 */

bool cpuPlay(int taille, char morpion[taille][taille], int userCol, int userLin, int warPC[])
{
	userLin = warPC[0] ;
	userCol = warPC[1] ;
	int i ;

	if(easyWinV(taille, morpion, userCol, userLin, warPC) == 0)
		{
		return true ;
		}
	else if(easyWinH(taille, morpion, userCol, userLin, warPC) == 0)
		{
		return true ;
		}
	else if(easyWinD1(taille, morpion, userCol, userLin, warPC) == 0)
		{
		return true ;
		}
	else if(easyWinD2(taille, morpion, userCol, userLin, warPC) == 0)
		{
		return true ;
		}
	else
		{
		do
			{
			i = cpu1(taille, morpion);

			}while(i != 0);

		printf("\n... Ordinateur à jou! \n") ;
		return true ;

		}

}

/*
 ============================================================================
 Function Name : IA_level
 Function Returns : integer, returns the IA level of the computer.
 Function Description : Asks the player to choose the IA level
 ============================================================================
 */

int IA_level(int taille, char morpion[taille][taille], int IA)
{

while(IA < 1 || IA > 3)
	{
	printf("\n choisissez le niveau de difficultee : ");
	printf("\n Level 1 = Very Easy ");
	printf("\n Level 2 = PC Tries a bit harder \n ");
	scanf("%d", &IA);
	}

	return IA;

}

/*
 ============================================================================
 Function Name : main function
 ============================================================================
 */

int main()
{
	int tailleMax = 25 ;
	int tailleMin = 3 ;
	int taille ;
	int userLin, userCol ;
	int IA ;
	int warPC[a] ;

	warPC[0] = 0 ;
	warPC[1] = 0 ;
	// Ask user for size of grid
	do
	{
		printf("\n ...Entrez la taille du jeu du morpion, min %d, max %d \n", tailleMin, tailleMax);
		scanf("%d", &taille);
	} while(tailleMorpion(taille, tailleMax, tailleMin) != true) ;

	// Grid Initialisation

	char morpion [taille][taille];
	initGrille(taille, morpion) ;
	showGrille(taille, morpion) ;
	int f;
	    switch (IA_level(taille, morpion, IA))
	    {
		case 1:
			printf("...Vous avez choisi le niveau EASY \n");
			do
			{
				userPlay(taille, morpion, userLin, userCol, warPC) ;
				showGrille(taille, morpion) ;


				do
				{
				f = cpu1(taille, morpion) ;
				}while(f != 0) ;
			}while(victory(taille, morpion) != true);
			break;

		case 2:
				printf("...Vous avez choisi le niveau NORMAL \n");
				do
				{
					warPC[a] = userPlay(taille, morpion, userLin, userCol, warPC);
					showGrille(taille, morpion) ;
					cpuPlay(taille, morpion, userLin, userCol, warPC) ;
				}while(victory(taille, morpion) != true);
		    break;
	    }
	printf("\n... Merci d'avoir joue ! \n\n") ;
}
