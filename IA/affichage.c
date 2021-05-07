/*********************************************************/
//		    	JEU D'OTHELLO - IA         //
//		      	     	AFFICHAGE.C                      //
//														 //
//                Par AFARID MEZHOUD		 //
/*********************************************************/


#include <stdio.h>
#include <stdlib.h>

void affichagepossibl(int possibl[8][8])				// Fonction de débuggage : Affiche le tableau de possibilités
{
	int i, j;
	for(i=0; i<8; i++)									//Pour chaque ligne
	{										
			for(j=0; j<8; j++)							//Je parcours chaque cellule
			{
				printf("%d ", possibl[i][j]);			//J'affiche la case de possibilité

			}
		if(i!=7)
			printf("\n-------------------------\n");
	}
}

void affichage(char P[8][8], char char_joueur_suivant)
{
	int i, j;
	char char_autre_joueur;
	if (char_joueur_suivant=='#')
	{
		char_autre_joueur='0';
		printf("\n\n\nA noirs (%c) de jouer...\n\n\n", char_joueur_suivant); 
	}
	else
	{
		char_autre_joueur='#';
		printf("\n\n\nA blancs (%c) de jouer...\n\n\n", char_joueur_suivant); 
	}
	
	printf("  0  1  2  3  4  5  6  7\n+-----------------------+\n");			//Haut de l'othellier
	for(i=0; i<8; i++)															//Pour chaque ligne
	{
		printf("|");															//J'affiche un pipe (séparateur de cellules) 
		
			for(j=0; j<8; j++)													//Je parcours chaque cellule
			{;
				
				printf("%c ", P[i][j]);											//J'affiche le contenu
				printf("|");	
																				//J'affiche le séparateur
			}
		if(i!=7)
			printf(" %d \n-------------------------\n", i);						//Affichage des séparateurs de ligne sauf la dernière
	}
	printf(" 7  \n+-----------------------+\n\n");								//Affiche le dernier séparateur
	
	printf("Score : Blancs (0) %d - Noirs (#) %d\n\n ", blancs(P), noirs(P));			//Affiche les infos de jeu
		
	return;
}

int blancs(char P[8][8])														//Calcul de score blancs
{
	int i, j, valeur=0;
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			if(P[i][j]=='0')
				valeur++;
		}
		
	}
	return valeur;
}

int noirs(char P[8][8])															//Calcul de score noirs
{
	int i, j, valeur=0;
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			if(P[i][j]=='#')
				valeur++;
		}
		
	}
	return valeur;
}
