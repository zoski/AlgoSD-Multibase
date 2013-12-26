Elaboration d'un interpreteur de calculs arithmétique travaillant dans différentes bases
========================================================================================

Consignes
---------


Sujet à remettre avant le 6 janvier 2014 sous forme d'un fichier nomé : **multibase.c** . Un commentaire au début du fichier comportera les noms des membres du binome.
A remettre en main propre ou par mail (non zippé).

Arithmétique multibase d'entiers
--------------------------------
Comportera les opérations suivantes :
 - addition
 - soustraction
 - multiplication
 - division
	
Le programme affichera un invité de commande ">_"
On écrira l'opération puis l'appuie sur "entrée" evaluera la ligne.

Définition de la grammaire
--------------------------
<lexem>

Une ligne est composé d'une base (optionnelle car []) et d'une expression.
Puis résultat de l'expression dans la base mise en paramètre (si pas de précésion de la base : base 10). Base 2 à 36 (base 36 : 10 chiffres et 26 lettres)
Signe optionnel, terme puis de 0 à n couple signe terme.

La ligne que l'on doit évaluer doit respecter la grammaire suivante :
	<ligne>::=[base] '=' <expression> ' ;'
	<expression>::=[signe]<terme>(<signe><terme>)*
	<signe>::= '+' | '-'
	<terme>::=<facteur>(<op><facteur>)*
	<op>::= '*' | '/'
	<facteur>::=<entier> | '(' <expression> ')'
	<entier>::=[base'#']<nombre>
	<base>::=<chiffre>(<chiffre>)*
	<chiffre>::= '0' ... '9'
	<nombre>::=<caractere>(<caractere>)*
	<caractere::=<chiffre> | <lettre>
	<lettre>::= 'A' ...'Z', 'a'...'z'
	
Exemples
--------
> 2=55 ;
110111
> 36=35 ;
z
> 2=8/(4-2#101) ;
-1000
> 2=8/(4-2#100) ;
	       ^ division par zéro //facultatif de positionner la boulette
> 37=8 ;
Base interdite
> 2=(56+2)/5-(3) ;
Parenthèse manquante.
