#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

				/***** PROTOTYPES *****/
void prompt() ;
int convNum(int entree, int baseE, int baseS) ;
char* enBase(int entree, int base) ;	/* de la base 10 à autre */
int enBase10(char* entree, int base);	/* d'une base à la base 10 */
int poids(char lettre, int base);

				/***** MAIN ******/
int main(int argc, char *argv[]) {
	
	char *sol = malloc(sizeof(enBase(3, 36)));
	printf("Sol = %s\n", sol);
	int test = enBase10("1C4", 16);
	printf("Résulat de la converison %d\n", test);
	return 0;
}

				/***** FONCTIONS *****/

/* Convertis en base 'base' l'entier rentré dans la base 10 */
char* enBase(int entree, int base) {
	char *resultat ; //a retourner
	char alphabet[36] = 
	/*chiffres et lettres représentant l'alphabet utilisé pour les différentes bases*/
		 {'0', '1', '2', '3', '4', '5', '6', '7',
		  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		  'W', 'X', 'Y', 'Z'};
	int sol[64] ;			/* tableau de la solution */
	int index = 0 ;
	
	while (entree != 0) {
		sol[index] = entree%base;
		entree = entree/base;
		index ++;
	}
	index--;/* on recule pour pointer le dernier élément enregistré */
	
	/* Affichage */
	
	for ( index ; index>=0 ; index--) {	/* on affiche depuis le dernier enregistré */
		int i =0 ;
		resultat[i]=alphabet[sol[index]];
	}
	return resultat ;			
	/*for ( index ; index>=0 ; index--) {	/* on affiche depuis le dernier enregistré 
		printf("%c", alphabet[sol[index]]);
	}*/
	
}

/*			*/
int enBase10(char* entree, int base) {
	int resultat = -3;
	int taille = strlen(entree);
	int puissance, sol = 0;
	while(taille != 0) {
		resultat = poids(entree[taille-1], base)*pow((double)base,(double)puissance);	/*multipli du poids de la lettre fois la base^index*/
		sol = sol + resultat ;
		taille = taille - 1;
		puissance ++ ;
	}
	return sol;
}


/* VERIFIé*/
int poids(char lettre, int base) {
	int i ;
	char alphabet[36] = 
	/*chiffres et lettres représentant l'alphabet utilisé pour les différentes bases*/
		 {'0', '1', '2', '3', '4', '5', '6', '7',
		  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		  'W', 'X', 'Y', 'Z'};
	for(i=0 ; i<base ; i++) {
		if(alphabet[i] == lettre) return i ;
	}
	return -1 ;
}

/* Retourne la conversion tout numérique d'un entier dans la base baseE en un nouveau entier sortie dans la baseS */
int convNum(int entree, int baseE, int baseS) {

	int i, sortie ;
	
	
	return sortie;
}

void prompt() {
	char reponse[256];
	char quit[] = "quit";
	int compa ;
	
	do {
		printf("\n> ");

		scanf("%s", reponse);
		printf("%s", reponse);	//debug
		compa = strcmp(reponse, quit);
		//évalutation de la commande
		
		
	} while(compa!=0) ; 
	printf("\nAu-revoir...\n") ;
}

