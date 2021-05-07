/*********************************************************/
//		    	JEU D'OTHELLO - IA         //
//		      	     		COUP .C                      //
//														 //
//                Par FARID MEZHOUD 		 //
/*********************************************************/



#include "main.h"
#include <stdio.h>
#include <stdlib.h>
int coup(char jeu[8][8], int type, char char_joueur)
{
	int possibl[8][8];
	int coup_possible=0;
	char char_autrejoueur;
	int i, j, k, l;
	initPossibl(possibl);
	if (char_joueur=='#')
		char_autrejoueur='0';
	else
		char_autrejoueur='#';
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{

			if (jeu[i][j]==char_joueur)
			{
			    // Diag haut-droite
				k=i-1;
				l=j+1;
				
				while((k>=0)&&(l<=7)&&(jeu[k][l]==char_autrejoueur))
				{
					k--;
					l++;
					
				}
				if(k>=0&&l<8){
				if(jeu[k][l]==' '&&jeu[k+1][l-1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}
				}
				}
				 // Diag bas-gauche
				k=i+1;
				l=j-1;
				
				while((k<=7)&&(l>=0)&&(jeu[k][l]==char_autrejoueur))
				{
					k++;
					l--;
					
				}
				
				if(k<8&&l>=0){
				if(jeu[k][l]==' '&&jeu[k-1][l+1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}	
				}
				}
				
				 // Diag haut-gauche
				k=i-1;
				l=j-1;
				
				while(k>=0&&l>=0&&jeu[k][l]==char_autrejoueur)
				{
					k--;
					l--;
				}
				if(k>=0&&l>=0){
				if(jeu[k][l]==' '&&jeu[k+1][l+1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}
				}
				}
				// Diag bas-droite
				k=i+1;
				l=j+1;
				
				while(k<=7&&l<=7&&jeu[k][l]==char_autrejoueur)
				{
					k++;
					l++;
				}
				if(k<8&&l<8){
				if(jeu[k][l]==' '&&jeu[k-1][l-1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}
				}
				}
				
				// Haut
				k=i-1;
				while(k>=0&&jeu[k][j]==char_autrejoueur)
				{
					k--;
				}
				if(k>=0){
				if(jeu[k][j]==' '&&jeu[k+1][j]==char_autrejoueur)
				{
					if(possibl[k][j]==0)
					{
					possibl[k][j]=1;
					coup_possible++;
					}
				}
				}
				// Bas
				k=i+1;
				while(k<=7&&jeu[k][j]==char_autrejoueur)
				{
					k++;
				}
				if(k<8){
				if(jeu[k][j]==' '&&jeu[k-1][j]==char_autrejoueur)
				{
					if(possibl[k][j]==0)
					{
					possibl[k][j]=1;
					coup_possible++;
					}
				}
				}
				// Gauche
				l=j-1;
				while(l>=0&&jeu[i][l]==char_autrejoueur)
				{
					l--;
				}
				if(l>=0){
				if(jeu[i][l]==' '&&jeu[i][l+1]==char_autrejoueur)
				{
					if(possibl[i][l]==0)
					{
					possibl[i][l]=1;
					coup_possible++;
					}
				}
				}
				// Droite
				l=j+1;
				while(l>=0&&jeu[i][l]==char_autrejoueur)
				{
					l++;
				}
				if(l<8)
				{
					if(jeu[i][l]==' '&&jeu[i][l-1]==char_autrejoueur)
					{
						if(possibl[i][l]==0)
						{
						      possibl[i][l]=1;
						      coup_possible++;
						}
					}
				}
			}
		}
	}
	int retour;
	printf("Nombre de coups possibles : %d\n\n", coup_possible);
	if(coup_possible!=0 && type==0)												//Joueur HUMAIN
	{
		int x, y;
		do
		{
			printf("Saisir la ligne   :");
			scanf("%d", &x);
			printf("Saisir la colonne :");
			scanf("%d", &y);
			if (x<=0&&x>=7&&y<=0&&y>=7)
				printf("Joue en %d %d - Case valide : %d\n\n", x, y, possibl[x][y]);
			else
				printf("Erreur de saisie !!!\n");
			
		}
		while(!((x>=0)&&(x<=7)&&(y>=0)&&(y<=7)&&(possibl[x][y]==1)));
		
		jeu[x][y]=char_joueur;
		retournement(x, y, jeu, char_joueur);
		return 0;		
	}
	
	
	else if(coup_possible!=0 && type==1)										//Joueur IA Facile
	{
		maximisation(possibl, jeu, char_joueur);
		return 0;
	}
	else if(coup_possible!=0 && type==2)										//Joueur IA Difficile
	{
		appelMiniMax(jeu,possibl,char_joueur);
		return 0;
	}
	else if(coup_possible==0)													// Quelque soit le type de jeu, pas de coup possible
	{
		return 1;
	}
}

int cptPions(int x,int y,char tab[N][N],char joueur){
	int i,j;
	int nbPions=0;
  int case_non_vide=1;
  //Compte des pions a retourner en haut de la case choisie
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
	nbPions++;
      i++;
    }
  }
  }


  //Compte des pions a retourner a gauche de la case choisie
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
	nbPions++;
      i++;
    }
  }
  }

  //Compte des pions a retourner en bas de la case choisie
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
	nbPions++;
      i--;
    }
  }
  }
  

  //Compte des pions a retourner a droite de la case choisie
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
	  nbPions++;
	i--;
      }
    }
    }
  
  //Compte des pions a retourner sur la diagonale en bas à gauche
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
	    nbPions++;
	  i--;
	  j++;
        }
    }
  }
  
  //Compte des pions a retourner sur la diagonale en haut a droite
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
	    nbPions++;
	  i++;
	  j--;
        }
    }
  }
  
  //Compte des pions a retourner sur la diagonale en bas a droite
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
	    nbPions++;
	  i--;
	  j--;
        }
    }
  }
  
  //Compte des pions a retourner sur la diagonale en haut a gauche
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
	      nbPions++;
	  i++;
	  j++;
        }
    }
  }
  return nbPions;
}
void maximisation(int possibl[N][N],char tab[N][N],char joueur){			//Fonction IA de Maximisation
	int i=0,j=0;
	int valX,valY,nbPions=0;
    for(i;i<N;i++){
      for(j=0;j<N;j++){
		  if(possibl[i][j]){
		  if(cptPions(i,j,tab,joueur)>=nbPions){
			  valX=i;
			  valY=j;
		  }
		  }
        }
    }
	tab[valX][valY]=joueur;
	retournement(valX,valY,tab,joueur);
}


int calculValCases(int possibl[8][8]){
	int i,j,valMax=-1000;
	int val[8][8]={{100,-100,50,10,10,50,-100,100},
					{-100,-100,50,1,1,50,-100,-100},
					{50,50,50,1,1,50,50,50},
					{10,1,1,0,0,1,1,10},
					{10,1,1,0,0,1,1,10},
					{50,50,50,1,1,50,50,50},
					{-100,-100,50,1,1,50,-100,-100},
					{100,-100,50,10,10,50,-100,100}};
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(valMax<val[i][j] && possibl[i][j]==1)
				valMax=val[i][j];
		}
	}
	return valMax;
	
}
void sousPossibl(int possibl1[8][8],int possibl[8][8]){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
		if (possibl[i][j]!=possibl1[i][j])
			possibl1[i][j]=1;
		else
			possibl1[i][j]=0;
		}
	}
	
}
void copieTableau(char tab[8][8],char tab1[8][8]){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			tab1[i][j]=tab[i][j];
		}
	}
}

void copiePossibl(int possibl[8][8],int possibl1[8][8]){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			possibl1[i][j]=possibl[i][j];
		}
	}
	
}
int coupPossible(char jeu[8][8], char char_joueur,int possibl[8][8])
{
	int coup_possible=0;
	char char_autrejoueur;
	int i, j, k, l;
	initPossibl(possibl);
	if (char_joueur=='#')
		char_autrejoueur='0';
	else
		char_autrejoueur='#';
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{

			if (jeu[i][j]==char_joueur)
			{
			    // Diag haut-droite
				k=i-1;
				l=j+1;
				
				while((k>=0)&&(l<=7)&&(jeu[k][l]==char_autrejoueur))
				{
					k--;
					l++;
					
				}
				if(k>=0&&l<8){
				if(jeu[k][l]==' '&&jeu[k+1][l-1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}
				}
				}
				 // Diag bas-gauche
				k=i+1;
				l=j-1;
				
				while((k<=7)&&(l>=0)&&(jeu[k][l]==char_autrejoueur))
				{
					k++;
					l--;
					
				}
				
				if(k<8&&l>=0){
				if(jeu[k][l]==' '&&jeu[k-1][l+1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}	
				}
				}
				
				 // Diag haut-gauche
				k=i-1;
				l=j-1;
				
				while(k>=0&&l>=0&&jeu[k][l]==char_autrejoueur)
				{
					k--;
					l--;
				}
				if(k>=0&&l>=0){
				if(jeu[k][l]==' '&&jeu[k+1][l+1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}
				}
				}
				// Diag bas-droite
				k=i+1;
				l=j+1;
				
				while(k<=7&&l<=7&&jeu[k][l]==char_autrejoueur)
				{
					k++;
					l++;
				}
				if(k<8&&l<8){
				if(jeu[k][l]==' '&&jeu[k-1][l-1]==char_autrejoueur)
				{
					if(possibl[k][l]==0)
					{
					possibl[k][l]=1;
					coup_possible++;
					}
				}
				}
				
				// Haut
				k=i-1;
				while(k>=0&&jeu[k][j]==char_autrejoueur)
				{
					k--;
				}
				if(k>=0){
				if(jeu[k][j]==' '&&jeu[k+1][j]==char_autrejoueur)
				{
					if(possibl[k][j]==0)
					{
					possibl[k][j]=1;
					coup_possible++;
					}
				}
				}
				// Bas
				k=i+1;
				while(k<=7&&jeu[k][j]==char_autrejoueur)
				{
					k++;
				}
				if(k<8){
				if(jeu[k][j]==' '&&jeu[k-1][j]==char_autrejoueur)
				{
					if(possibl[k][j]==0)
					{
					possibl[k][j]=1;
					coup_possible++;
					}
				}
				}
				// Gauche
				l=j-1;
				while(l>=0&&jeu[i][l]==char_autrejoueur)
				{
					l--;
				}
				if(l>=0){
				if(jeu[i][l]==' '&&jeu[i][l+1]==char_autrejoueur)
				{
					if(possibl[i][l]==0)
					{
					possibl[i][l]=1;
					coup_possible++;
					}
				}
				}
				// Droite
				l=j+1;
				while(l>=0&&jeu[i][l]==char_autrejoueur)
				{
					l++;
				}
				if(l<8)
				{
					if(jeu[i][l]==' '&&jeu[i][l-1]==char_autrejoueur)
					{
						if(possibl[i][l]==0)
						{
						      possibl[i][l]=1;
						      coup_possible++;
						}
					}
				}
			}
		}
	}
	
	
	// affichagepossibl(possibl);
	
	if(coup_possible!=0)
	{
	  
	  return 1;
	}
	else if(coup_possible==0)
	{
		return 0;
	}
	
}
int miniMax(char tab[8][8],int possibl[8][8],char joueur,int prof){
	int i,j,x=-1,y=-1,val=0,val1=-1000;
	int possibl1[8][8];
	char tab1[8][8];
	char joueur1=joueur;
	copieTableau(tab,tab1);
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(possibl[i][j]==1){
				retournement(x,y,tab1,joueur);				
				if (coupPossible(tab1,joueur1,possibl1)!=0 && prof<3){
				if(joueur1==J1){
					joueur1=J2;
				}else if(joueur1==J2){
					joueur1=J1;
					}
					val=miniMax(tab1,possibl1,joueur,prof+1);
					if (val>val1){
						val1=val;
						x=i;
						y=j;
					
				}
				}
			}
		}
	}
	sousPossibl(possibl1,possibl);
	val1=calculValCases(possibl1);
	if(x!=-1 && y!=-1){
	tab[x][y]=joueur;
	retournement(x,y,tab,joueur);
	}
	return val1;
}

void appelMiniMax(char jeu[8][8],int possibl[8][8], char char_joueur){
	miniMax(jeu,possibl,char_joueur,0);	
}
