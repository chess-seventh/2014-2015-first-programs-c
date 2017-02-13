#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

int franci(int i)
{

int i;

if(isalpha(i)) ;
printf("\n inserez i \n");
scanf("%d", &i);



}
*/

int caco(int j)
{

	int a;
//	printf("\n inserez j \n");
//	scanf("%d", &a);

	if ( isdigit(a) )
		{
		printf("\n YEAAAHHH a = %d \n",a );
		return a ;
		}
	else
		{
		printf("\n tu as rentrer un valeur ALPHA  ... recommence a = %d \n",a );
//		return;
		}

}


int main()
{

	int taille = 3 ;
	int i ;
	int j = 0 ;
	do{

	j = caco(j);
	printf("\n \n prout prout \n") ;

	}while(isdigit(j));

	printf("\n \n j = %d \n", j) ;

	return 0;

}
