////////////////////////////////////////////////
/* Programme : tableau structure              */
/* Chemin    : USB                            */
/*                                            */
/*                                            */
/* Auteur    : Franci                         */
/* Date      : 23/04/2015                     */
/* Version   : Version v 1.0                  */
/* Titre     : TP 12C liste                   */
/* Descr     : liste                          */
/*             del search ins                 */
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
	char *data;
	int recur;
	struct node *prev;
	struct node *next;
} t_node;

typedef struct dlist
{
	int count;
	t_node *debut;
	t_node *fin;
} t_dlist;

/////////////////// init liste ///////////////////////
void init_list(t_dlist *list)
{
	list->count = 0;
	list->debut = NULL;
	list->fin = NULL;
}

/////////////////////// delete liste ////////////////////////
void delete_list(t_dlist *list)
{
	t_node *n1, *n2;
	n1 = list->debut;

	while (n1 != NULL)
	{
		n2 = n1->next;
		free(n1);
		n1 = n2;
	}

	printf(" \n delete liste OK \n");
}

///////////////// inserer un nuouveau noeud dans la liste ///////////////////////
void insert(t_dlist *list, char *new_data, int pos_r)
{
    int i;

	t_node *new_node;
	new_node = malloc(sizeof(t_node));
    new_node->data =(char*)malloc(sizeof(char)*strlen(new_data)+1);
    new_node->prev =malloc(sizeof(t_node));
    new_node->next=malloc(sizeof(t_node));

///////////////// insertion du premier de liste ///////////////////
 if(list->count == 0)
    {
        strcpy (new_node->data, new_data);
        new_node->prev =   list->debut;
        new_node->next = list->fin;
        new_node->recur = 0;
        list->debut = new_node;
        list->fin = new_node;
	}


//////////////  insertion debout de la liste ///////////////////////
if (list->count > 0 && pos_r == 0)
	{
        strcpy (new_node->data, new_data);
        new_node->prev = NULL;
        new_node->next = list->debut;
        new_node->recur = 0;
        list->debut->prev = new_node;
        list->debut = new_node;
    }

//////////////////// insertion en fin de liste /////////////////
	if (list->count != 0 && list->count==pos_r)
	{
        strcpy (new_node->data, new_data);
        new_node->next = NULL;
        new_node->prev = list->fin;
        new_node->recur = 0;
        list->fin->next = new_node;
        list->fin = new_node;
    }
	if (list->count != 0 && list->count!=pos_r && pos_r != 0)

///////////////////////// insertion à la position demandée ////////////////
if (list->count != 0 && list->count!=pos_r && pos_r != 0)
    {
    t_node *tmp;
    tmp = list->debut;

    for (i = 0; i < pos_r-1; i++)
        {
            tmp = tmp->next;
        }
          strcpy (new_node->data, new_data);
            new_node->recur = 0;
              new_node->next = tmp->next;
                new_node->prev = tmp;
                    tmp->next->prev = new_node;
                        tmp->next =new_node;

    }
list->count++;
}

//////// delete d'un noeud de la liste ////////////////
void delete_node(t_dlist *list, t_node *n)
{

 if (n->next == NULL)
                {
                    list->fin = n->prev;
                    list->fin->next = NULL;
                }
                else if (n->prev == NULL)
                {
                    list->debut = n ->next;
                    list->debut->prev = NULL;
                }
                else
                {
                    n->next->prev = n->prev;
                    n->prev->next = n->next;
                }
                	free(n);
	list->count--;

}


///////////// print d' une liste /////////////////////////
void print_list(t_dlist *list)
{
	t_node *tmp;
	tmp = list->debut;
	int i;

      while(tmp != NULL)
        {
        printf("%s %i \n",tmp->data, tmp->recur+1);
        tmp = tmp->next;
        }
}

///////////////// determiner la position dans la liste ///////////////////////////////////////////
int pos (t_dlist *list, char *new_data)
{
    int i;
    i=0;
	t_node *tmp;

    tmp = list->debut;

    while(tmp != NULL)
    {
     if (strcmp(new_data, tmp->data) < 0)
        {
            break;
        }

    i++;
    tmp = tmp->next;
    }
    return i;
}

///////////////////////// chercher dans la liste ///////////////////////////////////
t_node * search2(t_dlist *list, char *value)
{
	t_node *tmp;
	tmp = list->debut;

	// scorro la lista cercando value
	// ritorno l'indirizzo del primo nodo che contiene value
	// altrimenti continuo a scorrere la lista
	while (tmp != NULL)
	{
		if (strcmp(tmp->data, value) == 0)
           { return tmp;
        printf("ritorno tmp");
	}
		tmp = tmp->next;
	}

	// se non trovo nessun nodo contenente value, ritorno NULL
	return NULL;
}

///////////////////////// inserer dans la liste ///////////////////////////////////
void insertliste(t_dlist *list, const char *nomfich)
{
    int pos_d;
    char ligne[30]; //tableau tampon ligne
    FILE *fid;
    fid = fopen(nomfich, "r");

    while(fscanf(fid, "%s" , ligne) != EOF)
        {
        sscanf(ligne,"%[^,()”“.;]", ligne);
            if(search2(list, ligne) == NULL)
              { pos_d = pos(list, ligne);
                insert(list, ligne, pos_d); }

                    else
                {
                    (search2(list, ligne))->recur++;
                }
        }
    fclose(fid);
}

///////////////////////// intersect de liste///////////////////////////////////
void intersect(t_dlist *list3, char *ligne)
{
    int pos_d;
        if(search2(list3, ligne) == NULL)
            {   pos_d = pos(list3, ligne);
                insert(list3, ligne, pos_d);
            }
}

///////////////////////// MAIN ///////////////////////////////////
int main()
{
    const char NOM_FICH[]  = "onTheOriginOfMusic.txt";
    const char NOM_FICH1[]  = "languageSymbolismMusic.txt";
    char ligne[30]; //tableau tampon ligne
    char ser_data[30];
    int pos_d;
	int choix, choix_search, choix_e, choix_v;
    pos_d = 0;
    choix = 1;

        printf("\nCreo e inizializzo la lista\n");
        t_dlist *list;
        list = (t_dlist *) malloc (sizeof(t_dlist));
        init_list(list);

        t_dlist *list2;
        list2 = (t_dlist *) malloc (sizeof(t_dlist));
        init_list(list2);

        t_dlist *list3;
        list3 = (t_dlist *) malloc (sizeof(t_dlist));
        init_list(list3);



while (choix != 0)
    {
        printf("\nQue voulez-vous faire?\n1)inserer un mot dans un liste (liste1) \n2)search un mot (liste1-2-3) \n3)supprimer un mot(liste3)\n4)liste mots communs a deux listes(liste3)\n5)liste difference(liste3)\n6)concatenation(liste3)\n7)Visualisation de la liste n:\n8)Eliminer la liste n:\n\n0)Exit\nChoix : ");
        scanf("%d",&choix);

        if (choix == 1)
        {
    ////////////////////////////////    insertion d un mot  //////////////////////////////////////////
        printf("vos puvez ecrire un mot");
        scanf("%s", ligne);

        sscanf(ligne,"%[a-z0-9]", ligne);

        if(search2(list, ligne) == NULL)
              {
                pos_d = pos(list, ligne);
                printf("test %i", (search2(list, ligne) == NULL));
                printf("\n inserisco questo: %s  pos: %i \n", ligne, pos_d);
                insert(list, ligne, pos_d); }


                    else
                {
                    (search2(list, ligne))->recur++;
                }
            printf("\n Stampo la lista:\n");
            print_list(list);

        }
            else if (choix == 2)
        {
    ////////////////////////////////    chercher un mot    //////////////////////////////////////////
            printf("digitez le mot que vous voulez chercher ");
            scanf("%s", &ser_data);

            printf("de quelle liste:");
            scanf("%i", &choix_search);

               if (choix_search == 1)
                    {
                     if (search2(list, ser_data) == NULL)
                        printf("n'existe pas");
                     else
                        printf("existe  %i", (search2(list, ligne))->recur +1);
                    }

                if (choix_search == 2)
                    {
                    if (search2(list2, ser_data) == NULL)
                        printf("n'existe pas");
                    else
                        printf("existe  %i", (search2(list2, ligne))->recur +1);
                    }

                if (choix_search == 3)
                    {
                    if (search2(list3, ser_data) == NULL)
                        printf("n'existe pas");
                    else
                        printf("existe  %i", (search2(list3, ligne))->recur +1);
                    }
               if (choix_search != 3 && choix_search != 2 && choix_search != 1)
                printf("Mauvais choix - Exit - Exit ! ! !");

        }

            else if (choix == 3)

        {
    ////////////////////////////////    eliminer un mot    //////////////////////////////////////////
            printf("digitez le mot que vous voulez eliminer");
            scanf("%s", &ser_data);
            if (search2(list3, ser_data) == NULL)
                    printf("n'existe pas");
            else
                {
                    delete_node(list, search2(list3, ser_data));
                    printf("delete OK \n");
                }
        }


         else if (choix == 4)
        {
    ////////////////////////////////   inserer deux listes:    //////////////////////////////////////////
            insertliste(list, NOM_FICH);
            insertliste(list2, NOM_FICH1);
                        print_list(list);
                                    print_list(list2);
            t_node *tmp;
            tmp = list->debut;
              while(tmp != NULL)
                {

                if (search2(list2, tmp->data) != NULL)
                    {printf("test");
                        intersect(list3, tmp->data);

                        }

                tmp = tmp->next;
              }
            printf("\n Stampo la lista:\n");
            print_list(list3);
        }


         else if (choix == 5)
        {
    ////////////////////////////////   difference des deux listes:    //////////////////////////////////////////
            insertliste(list, NOM_FICH);
            insertliste(list2, NOM_FICH1);
                        print_list(list);
                                    print_list(list2);
            t_node *tmp;
            tmp = list->debut;
              while(tmp != NULL)
                {

                if (search2(list2, tmp->data) == NULL)
                    {printf("test");
                        intersect(list3, tmp->data);

                        }

                tmp = tmp->next;
              }
            printf("\n Stampo la lista:\n");
            print_list(list3);
        }

            else if (choix == 6)
        {
    ////////////////////////////////   intersect des deux listes:    //////////////////////////////////////////
            insertliste(list, NOM_FICH);
            insertliste(list, NOM_FICH1);
            printf("\n Stampo la lista:\n");
            print_list(list);
        }

            else if (choix == 7)
        {
    ////////////////////////////////   visualisation de lal liste:   //////////////////////////////////////////
            printf("digitez la liste a visuliser");
            scanf("%i", &choix_v);
            if (choix_v ==1)
                print_list(list);
            else if (choix_v ==2)
                print_list(list2);
            else if (choix_v ==3)
                print_list(list3);
            else
            {
               printf("Mauvais choix - Exit - Exit ! ! !");
            }

         }

             else if (choix == 8)
        {
    ////////////////////////////////   eliminer une liste:   //////////////////////////////////////////

            while (choix_e != 0)
                {
                printf("eliminer quelle liste: (0 pour sortir)");
                scanf("%i", &choix_e);
                    if (choix_e == 1)
                        delete_list(list);
                    else if (choix_e ==2)
                        delete_list(list2);
                    else if (choix_e  ==3)
                        delete_list(list3);
                    else
                    {
                        printf("Mauvais choix - Exit - Exit ! ! !");
                    }

                }
        }

        else
        {
            printf("Mauvais choix - Exit - Exit ! ! !");
        }
        }


delete_list(list);
delete_list(list2);
delete_list(list3);
}

