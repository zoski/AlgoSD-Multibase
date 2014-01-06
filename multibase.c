#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
	Gaël Alberola
	Julien Bellec
	
	Fait :
		Conversion Base 10 à Base N retournant un String
		Conversion Base N à Base 10 
		Prompt sommaire avec fonction quitter (quit)
		Aide dans le prompt
		Opération mathématiques (addition/soustraction, multiplication, division)
	
	A faire :
		Implémentation de la grammaire <=> parseur ENCOURS
		Vérification de la grammaire
		Comversion minuscule en majuscule
*/

				/***** PROTOTYPES *****/
void prompt() ;
char *convNum(char* entree, int baseE, int baseS) ;
char *enBase(int entree, int base) ;	/* de la base 10 à autre */
int enBase10(char* entree, int base);	/* d'une base N à la base 10 */
int poids(char lettre, int base);
void afficheAide();
void hello();
char* addition(char* e1, int baseE1, char* e2, int baseE2, int baseS);		/* Addition & soustraction */
char* multiplication(char* e1, int baseE1, char* e2, int baseE2, int baseS);
char* division(char* e1, int baseE1, char* e2, int baseE2, int baseS);
char* evalutation(char * ligne);	/* évalue la ligne */


				/***** MAIN ******/
int main(int argc, char *argv[]) {
	hello();
	prompt();
	printf("Ma solution : %s\n", convNum("a", 36, 10));
	return 0;
}

				/***** FONCTIONS *****/
				
/* Demande la vérification de la grammaire puis évalue si la ligne est valide */
char* evalutation(char * ligne) {
	//TODO vérif grammaire
	
	

}

/* Convertis en base N l'entier rentré dans la base 10 */
char* enBase(int entree, int base) {
	char *resultat ; //a retourner
	int i =0;
	char alphabet[36] = 
	/* chiffres et lettres représentant l'alphabet utilisé pour les base de 2 à 36 */
		 {'0', '1', '2', '3', '4', '5', '6', '7',
		  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
		  'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		  'W', 'X', 'Y', 'Z'};
	int sol[64] ;			/* tableau de stockage de la solution */
	int index = 0 ;
	
	while (entree != 0) {	/* Conversion */
		sol[index] = entree%base;
		entree = entree/base;
		index ++;
	}
	resultat = (char*)malloc(index*sizeof(char));	//reserve la place pour le résultat
	index--;/* on recule pour pointer le dernier élément enregistré */
	
	for (index ; index>=0 ; index--) {	// on affiche depuis le dernier enregistré 
		resultat[i]=alphabet[sol[index]];
		i++ ;
	}
	resultat[i]='\0';
	
	return resultat ;			
	//debug
	/*for ( index ; index>=0 ; index--) {	// on affiche depuis le dernier enregistré 
		printf("%c", alphabet[sol[index]]);
	}*/
	
}

/*	Converti en Base 10		*/
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


/* Retourne le poids d'une lettre de l'alphabet. Nécessaire à la conversion base 10 à base N*/
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
char* convNum(char* entree, int baseE, int baseS) {
	int intermediaire = 0;
	char* sortie;
	/* conversion en base 10 */
	intermediaire = enBase10(entree, baseE);
		
	/* conversion dans la baseS */
	sortie = enBase(intermediaire, baseS);
	
	return sortie;
}

void prompt() {
	char reponse[256];
	char quit[] = "quit";
	char help[] = "help";
	char fliptable[] = "fliptable";
	int compa ;
	
	do {
		printf("\n> ");

		scanf("%s", reponse);
		//printf("%s", reponse);	//debug
		compa = strcmp(reponse, quit);
		if(!strcmp(reponse, fliptable)) printf("(╯° °)╯︵ ┻━┻");
		if(!strcmp(reponse, help)) afficheAide();
		else {
			evalutation(reponse);
			printf("On évalue la commande veuillez patienter...");			
		}
			
		//TODO évalutation de la commande ensuite
		//	idée : récupérer la ligne et l'évaluer
		
		
	} while(compa!=0) ; 
	printf("\nAu-revoir...\n") ;
}

void afficheAide() { /* Affiche l'aide */
	printf("\n Aide : \nFonctions disponibles\n=====================\n'help' : affiche cette aide\n'fliptable' : easter egg\n");
}

void hello() {
	printf("\nBIENVENUE, multibase.c version 0.1\n=========\t\t\t Aide en entrant help\n");
}

		/** OPERATIONS MATHEMATIQUE **/
/* 
	Chaque opération se fait en passant par la base 10.
	Chaque opération nécessite : 2 chaines de caractères e1 et e2, 
								2 bases : baseE1 et baseE2, 
					le résultat est retournée dans la baseS
*/
char* addition(char* e1, int baseE1, char* e2, int baseE2, int baseS) {
	int somme = 0 ;	// résultats de la conversion
	//conversion en base 10 puis somme
	somme = enBase10(e1, baseE1) + enBase10(e1, baseE1);
	// conversion dans la nouvelle base puis retour
	return enBase(somme, baseS);
}

char* multiplication(char* e1, int baseE1, char* e2, int baseE2, int baseS) {
	int produit = 0 ;	// résultats de la conversion
	//conversion en base 10 puis somme
	produit = enBase10(e1, baseE1) * enBase10(e1, baseE1);
	// conversion dans la nouvelle base puis retour
	return enBase(produit, baseS);
}

	/* Division entière */
char* divison(char* e1, int baseE1, char* e2, int baseE2, int baseS) {
	int division = 0 ;	// résultats de la conversion
	
	division = enBase10(e1, baseE1) / enBase10(e1, baseE1);	//conversion en base 10 puis somme
	
	return enBase(division, baseS);// conversion dans la nouvelle base puis retour
}
