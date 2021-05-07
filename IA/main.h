/*********************************************************/
//		    	JEU D'OTHELLO - AI         //
//		      	     		MAIN .H                      //
//														 //
//                Par FARID MEZHOUD 			 //
/********************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__
#define N 8
																		// Constante de taille de l'othellier (8x8)
#define J1 '#'															// Char des joueurs
#define J2 '0'
void initPossibl(int possibl[N][N]);									// Fonction d'initialisation du tableau de possibilités (tout à 0)
int coup(char jeu[N][N], int type, char char_joueur);					// Fonction coup : recherche de coups possibles, demande de saisie du coup puis appel de retournement
void affichage(char P[N][N], char char_joueur_suivant);					// Fontion d'affichage de l'othellier + infos de partie (score, joueur, etc...)
void initTableau(char tab[N][N]);										// Fonction d'initialisation du tableau de jeu : tout à espace sauf les 4 cases du milieu (règle de l'othello)
void main();															// Fonction principale, gère la boucle de jeu
void retournement(int x,int y,char tab[N][N],char joueur);				// Retourne les pions capturés à l'ennemi
int blancs(char P[N][N]);												// Retourne le score des blancs
int noirs(char P[N][N]);												// Retourne le score des noirs
void maximisation(int possibl[N][N],char tab[N][N],char joueur); 		// Fonction IA MAximisation
int cptPions(int x,int y,char tab[N][N],char joueur);					// Fonction calcul de la valeur des cases
int calculValCases(int possibl[8][8]);									// Fonction de calcul de la valeur d'une case
void sousPossibl(int possibl[8][8],int possibl1[8][8]);					// Fonction de soustraction de possibilités
void copieTableau(char tab[8][8],char tab1[8][8]);						// Fonction de copie 
void copiePossibl(int possibl[8][8],int possibl1[8][8]);				// Fonction de copie
int coupPossible(char jeu[8][8], char char_joueur,int possibl1[8][8]);	// Fonction de détection de coup possible dans le minimax
int miniMax(char tab[8][8],int possibl[8][8],char joueur,int prof);		// Fonction de MiniMax
void appelMiniMax(char jeu[8][8],int possibl[8][8], char char_joueur);	// Fonction d'appel de MiniMax



#endif
