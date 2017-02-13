#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int i = 0;
	int tab[5] ;
	srand(time(NULL));
	for(i=0;i<5;i++){
		tab[i] = rand()%77 ;
		printf("le num alea est :  %d \n",tab[i]);
		}
	return 0;
}
