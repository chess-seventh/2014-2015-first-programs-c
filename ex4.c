#include <stdio.h>

void main()
{
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int n5 = 0;


printf("Note le premier nombre stp\n");
scanf("%d", &n1);

printf("Note le deuxieme nombre stp\n");
scanf("%d", &n2);

printf("Note le troiseme nombre stp\n");
scanf("%d", &n3);

printf("Note le quatrieme nombre stp\n");
scanf("%d", &n4);

printf("Note le cinquieme nombre stp\n");
scanf("%d", &n5);

int moy = (n1+n2+n3+n4+n5)/5 ;

printf("La moyenne est de : %d, merci d'avoir participe\n", moy);

}
