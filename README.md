# Analyse de fréquence

En étudiant différents types de textes (romans, lois, article de journaux…), on se rend compte que non seulement les mots utilisés ne sont pas les mêmes mais aussi que leurs longueurs sont statistiquement différentes : par exemple, il est beaucoup plus fréquent de trouver de longs mots complexes dans un article de loi que dans un livre pour enfants.
Afin d’essayer de déterminer automatiquement à quelle catégorie appartient un livre, on souhaite déterminer le nombre de mots de 1 lettre, 2 lettres, 3 lettres… qu’il contient.

## CONSTRAINTS
Le texte contient un ensemble de mots, séparés par des espaces, sans aucun signe de ponctuation.
Chaque mot contient au plus 100 caractères.

## INPUT
La première ligne contient deux entiers : nbLignes et nbMots.
Chacune des nbLignes lignes suivantes contient nbMots mots.

## OUTPUT
Pour chaque longueur de mot possible, et uniquement s’il y avait des mots de cette longueur dans le texte, vous devez afficher sur une ligne la longueur et le nombre de mots de cette longueur, séparés par un deux-points (il faut mettre un espace de chaque côté du deux-points).

## EXAMPLE
### input:
2 7
Qui vole un oeuf vole un boeuf
Une abeille vaut mieux que mille mouches

### output:
2 : 2
3 : 3
4 : 4
5 : 3
7 : 2

## Principe du Programme
L'objectif de ce programme est de compter le nombre de mots de différentes longueurs dans un texte donné. Chaque mot est lu à partir des lignes de texte fournies et la longueur de chaque mot est comptabilisée. À la fin, le programme affiche combien de mots de chaque longueur sont présents dans le texte.

## Explication 
#### Déclaration des Variables :
int nbLignes, nbMots;
int i, j;
nbLignes : nombre de lignes de texte à lire.
nbMots : nombre de mots par ligne.
i et j : variables de boucle pour parcourir les lignes et les mots.

#### Initialisation d'un Tableau pour les Longueurs de Mots :
int LongueurMots[101] = {0};
LongueurMots est un tableau qui compte les mots de chaque longueur possible, de 1 à 100 caractères. Chaque index du tableau représente une longueur de mot et la valeur à cet index représente le nombre de mots de cette longueur.
#### Lecture des Mots et Comptage des Longueurs :
for (i = 0; i < nbLignes; i++) {
    for (j = 0; j < nbMots; j++) {
        char Mot[101];
        scanf("%s", Mot);

        int Longueur = strlen(Mot);
        if (Longueur <= 100) {
            LongueurMots[Longueur]++;
        }
    }
}
Deux boucles imbriquées parcourent chaque ligne (nbLignes) et chaque mot dans la ligne (nbMots).
char Mot[101]; déclare une variable pour stocker chaque mot lu (jusqu'à 100 caractères).
scanf("%s", Mot); lit un mot.
int Longueur = strlen(Mot); calcule la longueur du mot.
if (Longueur <= 100) { LongueurMots[Longueur]++; } vérifie si la longueur du mot est valide (≤ 100) et incrémente le compteur correspondant dans LongueurMots.

#### Affichage des Résultats :
for (i = 1; i <= 100; i++) {
    if (LongueurMots[i] > 0) {
        printf("%d : %d\n", i, LongueurMots[i]);
    }
}
Une boucle parcourt les longueurs de 1 à 100.
if (LongueurMots[i] > 0) vérifie s'il y a des mots de longueur i.
printf("%d : %d\n", i, LongueurMots[i]); affiche la longueur du mot et le nombre de mots de cette longueur.

## Fonctionnement du Programme
Le programme va lire chaque mot de ces deux lignes, calculer la longueur de chaque mot, et compter combien de mots de chaque longueur apparaissent.

#### Première Ligne : Qui vole un oeuf vole un boeuf
Qui : 3 lettres → compteur de mots de longueur 3 (LongueurMots[3]) est incrémenté à 1.
vole : 4 lettres → compteur de mots de longueur 4 (LongueurMots[4]) est incrémenté à 1.
un : 2 lettres → compteur de mots de longueur 2 (LongueurMots[2]) est incrémenté à 1.
oeuf : 4 lettres → compteur de mots de longueur 4 (LongueurMots[4]) est incrémenté à 2.
vole : 4 lettres → compteur de mots de longueur 4 (LongueurMots[4]) est incrémenté à 3.
un : 2 lettres → compteur de mots de longueur 2 (LongueurMots[2]) est incrémenté à 2.
boeuf : 5 lettres → compteur de mots de longueur 5 (LongueurMots[5]) est incrémenté à 1.

#### Deuxième Ligne : Une abeille vaut mieux que mille mouches
Une : 3 lettres → compteur de mots de longueur 3 (LongueurMots[3]) est incrémenté à 2.
abeille : 7 lettres → compteur de mots de longueur 7 (LongueurMots[7]) est incrémenté à 1.
vaut : 4 lettres → compteur de mots de longueur 4 (LongueurMots[4]) est incrémenté à 4.
mieux : 5 lettres → compteur de mots de longueur 5 (LongueurMots[5]) est incrémenté à 2.
que : 3 lettres → compteur de mots de longueur 3 (LongueurMots[3]) est incrémenté à 3.
mille : 5 lettres → compteur de mots de longueur 5 (LongueurMots[5]) est incrémenté à 3.
mouches : 7 lettres → compteur de mots de longueur 7 (LongueurMots[7]) est incrémenté à 2.

### Sortie Générée
2 : 2 → Il y a 2 mots de 2 lettres (un, un).
3 : 3 → Il y a 3 mots de 3 lettres (Qui, Une, que).
4 : 4 → Il y a 4 mots de 4 lettres (vole, oeuf, vole, vaut).
5 : 3 → Il y a 3 mots de 5 lettres (boeuf, mieux, mille).
7 : 2 → Il y a 2 mots de 7 lettres (abeille, mouches).