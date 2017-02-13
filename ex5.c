#include <stdio.h>

void main()
{
float pi = 3.1415;
float r = 0;

printf("entrez le rayon du cercle\n");
scanf("%f", &r);

float surfa = pi * r * r;

printf("la surface du cercle est de %f \n", surfa);

float perim = 2 * pi * r;

printf("le permietre du cercle est de %f \n", perim);

}
