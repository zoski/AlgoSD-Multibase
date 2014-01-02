#include <stdio.h>
#include <string.h>

				/***** PROTOTYPES *****/
void enBase10(int entree, int base) ;
void prompt() ;
int convNum(int entree, int baseE, int baseS) ;






int main() {
	char reponse[256];
	do {
		prompt();					//affichage >_
		scanf("%s", reponse);
		if(reponse!="quit") {
			printf("%s", reponse);
			//évalutation de la commande
		}
	} while(reponse!="quit");	
}








				/***** FONCTIONS *****/

/* Convertis en base 10 l'entier rentré dans la base "base"*/
void enBase10(int entree, int base) {
	char alphabet[36] = 
	/*chiffres et lettres représentant l'alphabet utilisé pour les différentes bases*/
		 {'0', '1', '2', '3', '4', '5', '6', '7',
		  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		  'W', 'X', 'Y', 'Z'};
	int sol[64] ;			/* tableau de la solution*/
	int index = 0 ;
	
	while (entree != 0) {
		sol[index] = entree%base;
		entree = entree/base;
		index ++;
	}
	index--;/* on recule pour pointer le dernier élément enregistré */
	
	/* Affichage */
	printf("\n");					
	for ( index ; index >=0 ; index--) {	/* on affiche depuis le dernier enregistré */
		printf("%c", alphabet[sol[index]]);
	}
}

/* Retourne la conversion tout numérique d'un entier dans la base baseE en un nouveau entier sortie dans la baseS */
int convNum(int entree, int baseE, int baseS) {

	int i, sortie ;
	
	
	return sortie;
}

void prompt() {
	printf("\n> ");
}

