/*********************************************************/
//		    	JEU D'OTHELLO - Projet IA         //
//		      	     		MAIN .C                      //
//														 //
//                Par Farid MEZHOUD 
/*********************************************************/


#include "main.h"
#include <stdio.h>
#include <stdlib.h>


void initTableau(char tab[N][N]) // Fonction d'initialisation du tableau de jeu : tout à espace sauf les 4 cases du milieu (règle de l'othello)
{ 
    int i=0,j=0;
    for(i;i<N;i++){
      for(j=0;j<N;j++){
            tab[i][j]=' ';
        }
    }
	tab[3][3]='#';
	tab[4][4]='#';
	tab[4][3]='0';
	tab[3][4]='0';
}

void initPossibl(int possibl[N][N]) // Fonction d'initialisation du tableau de possibilités (tout à 0)
{
    int i=0,j=0;
    for(i;i<N;i++){
      for(j=0;j<N;j++){
            possibl[i][j]=0;
        }
    }
}



void main()												//Fonction principale
{
  int choix,bloque=0,gagnant,saisie=0,saisieIA=0;
  int score_blanc, score_noir;
  char joueur;
  char tab[N][N];
  initTableau(tab);

  printf(" ###   #####   #   #  #####  #      #       ###\n#   #    #     #   #  #      #      #      #   #\n#   #    #     #####  ###    #      #      #   #\n#   #    #     #   #  #      #      #      #   #\n ###     #     #   #  #####  #####  #####   ###\n\n------------------------------------------------\n\n");
  
  
  while(!saisie){										//Saisie du mode de jeu
    printf("Veuillez saisir le nombre de joueurs( 1 ou 2) \n");
    scanf("%d",&choix);
    if(choix==1 || choix==2)
      saisie=1;
  }
  
  
  if(choix==1)											//Boucle de jeu humain VS IA
  {	
	while(!saisieIA)
	{
	printf("Veuillez saisir le niveau de l'IA : \n1 -> Facile\n2 -> Difficile\n");
    scanf("%d",&saisieIA);
    if(choix!=1 && choix!=2)
      saisieIA=0;
	}
	joueur=J1;
	affichage(tab, J1);
	do
	{
		bloque=0;
		if(joueur==J1){
			bloque = bloque + coup(tab, 0, J1);
			affichage(tab,J2);
			joueur=J2;
		}

		if(joueur==J2){
			bloque = bloque + coup(tab, saisieIA, J2);
			affichage(tab, J1);
			joueur=J1;
		}
	} 
	while(bloque<2);
  }
  
  
  
  
  else if (choix==2){									//Boucle de jeu H VS H
    joueur=J1;
    affichage(tab, J1);
    do{
      bloque=0;

      if(joueur==J1){
		bloque = bloque + coup(tab, 0, J1);
		affichage(tab,J2);
		joueur=J2;
      }

      if(joueur==J2){
		bloque = bloque + coup(tab, 0, J2);
		affichage(tab, J1);
		joueur=J1;
      }
    } while(bloque<2);
	
	

    score_blanc=blancs(tab);											//Fin du jeu
	score_noir=noirs(tab);
    if(score_blanc>score_noir){
      printf("Blanc a gagné\nAppuyez sur une touche pour quitter...");
    }else if(score_blanc<score_noir){
      printf("Noir a gagné\nAppuyez sur une touche pour quitter...");
    }else{
      printf("Match nul\nAppuyez sur une touche pour quitter...");
	  
    }
	joueur = getchar();
  }
  return;
}

void retournement(int x,int y,char tab[N][N],char joueur){					//Fonction de retournement de coups
  int i,j;
  int case_non_vide=1;
  //Retournement en haut de la case choisie
  i=x-1;
  while(i>=0 && tab[i][y]!=joueur && case_non_vide){
    if(tab[i][y]==' ')
      case_non_vide=0;
    i--;
  }
  if(i>=0){
  i++;
  if(case_non_vide==1){
    while(i!=x){
      if (tab[i][y]!=joueur)
	tab[i][y]=joueur;
      i++;
    }
  }
  }

  //Retournement a gauche de la case choisie
  case_non_vide=1;
  i=y-1;

  while(i>=0 && tab[x][i]!=joueur && case_non_vide){
    if(tab[x][i]==' ')
      case_non_vide=0;
    i--;
  }
  if(i>=0){
  i++;
  if(case_non_vide==1) {
    while(i!=y){
      if (tab[x][i]!=joueur)
	tab[x][i]=joueur;
      i++;
    }
  }
  }

  //Retournement en bas de la case choisie
  case_non_vide=1;
  i=x+1;
  while(i<=N-1 && tab[i][y]!=joueur && case_non_vide){
    if(tab[i][y]==' ')
      case_non_vide=0;
    i++;
  }
  if(i<N){
  i--;
  if(case_non_vide==1){
    while(i!=x){
      if(tab[i][y]!=joueur)
	tab[i][y]=joueur;
      i--;
    }
  }
  }
  

  //Retournement a droite de la case choisie
  case_non_vide=1;
  i=y+1;
  while(i<=N-1 && tab[x][i]!=joueur && case_non_vide)
    {
      if(tab[x][i]==' ')
	case_non_vide=0;
      i++;
    }
    if(i<N){
  i--;
  if(case_non_vide==1&&i<8)
    {
      while(i!=y){
	if(tab[x][i]!=joueur)
	  tab[x][i]=joueur;
	i--;
      }
    }
    }
  
  //Reoturnemnent des cases sur la diagonale en bas à gauche
  case_non_vide=1;
  i=x+1;
  j=y-1;
  while((i<=N-1) && (j >=0) && (tab[i][j]!=joueur) && (case_non_vide)){
    if(tab[i][j]==' ')
      case_non_vide=0;
    i++;
    j--;
  }
  if(i<N && j>=0){
  i--;
  j++;
  if(case_non_vide==1)
    {
      while((i!=x)&&(j!=y))
        {
	  if (tab[i][j]!=joueur)
	    tab[i][j]=joueur;
	  i--;
	  j++;
        }
    }
  }
  
  //Retournement des cases sur la diagonale en haut a droite
  case_non_vide=1;
  i=x-1;
  j=y+1;
  while(i>=0 && j <=N-1 && tab[i][j]!=joueur && case_non_vide){
    if(tab[i][j]==' ')
      case_non_vide=0;
    i--;
    j++;
  }
  if(i>=0 && j<N){
   i++;
  j--; 
  if(case_non_vide==1)
    {
      while(i!=x && j!=y)
        {
	  if (tab[i][j]!=joueur)
	    tab[i][j]=joueur;
	  i++;
	  j--;
        }
    }
  }
  
  //Retournement diagonale en bas a droite
  case_non_vide=1;
  i=x+1;
  j=y+1;
  while(i<=N-1 && j<=N-1 && tab[i][j]!=joueur && case_non_vide){
    if(tab[i][j]==' ')
      case_non_vide=0;
    i++;
    j++;
  }
  if(i<N && j<N){
  i--;
  j--;
  if(case_non_vide==1)
    {
      while(i!=x && j!=y)
        {
	  if (tab[i][j]!=joueur)
	    tab[i][j]=joueur;
	  i--;
	  j--;
        }
    }
  }
  
  //Retournement diagonale en haut a gauche
  case_non_vide=1;
  i=x-1;
  j=y-1;
  while((i>=0) && (j>=0) && (tab[i][j]!=joueur) && (case_non_vide)){
    if(tab[i][j]==' ')
      case_non_vide=0;
    i--;
    j--;
  }
  if (i>=0 && j>=0){
  i++;
  j++;
  if(case_non_vide==1)
    {
      while(i!=x && j!=y)
        {
	  if (tab[i][j]!=joueur)
	      tab[i][j]=joueur;
	  i++;
	  j++;
        }
    }
  }
  
}

