#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int nbLignes, nbMots;
    int i, j;


    printf("Veuillez saisir la nombre de ligne : ");
    scanf("%d", &nbLignes);
    printf("Veuillez saisir la nombre de mots : ");
    scanf("%d", &nbMots);

    int LongeurMots[101] = {0}; // initialise un tableau pour compter les mots de chaque longueur, de 1 à 100 caractères.


    printf("Veuillez saisir %d lignes de phrase avec chaque phrase contenant %d mots :\n", nbLignes, nbMots);
    for (i = 0 ; i < nbLignes ; i++){
        for(j = 0 ; j < nbMots ; j++){
            char Mot[101];
            scanf("%s", Mot); // lit un mot du texte

            int Longeur = strlen(Mot);
            if (Longeur <= 100){
                LongeurMots[Longeur]++; // incrémente le compteur pour cette longueur.
            }
        }
    }

    for (i = 1 ; i < 100 ; i++){
        if (LongeurMots[i] > 0) { //  vérifie si la longueur i a des mots.
            printf("%d : %d\n", i, LongeurMots[i]); // affiche la longueur et le nombre de mots de cette longueur.
        }
    }

    return 0;
}

/*

Initialisation d'un Tableau :

int longueurMots[101] = {0}; initialise un tableau pour compter les mots de chaque longueur de 1 à 100.
Traitement des Lignes de Texte :

Deux boucles for imbriquées pour parcourir chaque mot dans chaque ligne.
scanf("%s", mot); lit chaque mot.
int longueur = strlen(mot); calcule la longueur du mot.
longueurMots[longueur]++; incrémente le compteur correspondant à cette longueur de mot.
Affichage des Résultats :

Une boucle for parcourt le tableau des longueurs.
Si le compteur pour une longueur est supérieur à 0, le programme affiche cette longueur et le nombre de mots de cette longueur au format longueur : nombre.

*/
