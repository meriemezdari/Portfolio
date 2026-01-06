#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int generationPrix(int min, int max){
    return rand() % (max - min + 1) + min;
}

float generationPrixFloat(float min, float max){
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

void dessinerTelephone(){
    printf("  -----\n");
    printf(" |     |\n");
    printf(" |     |\n");
    printf(" |  o  |\n");
    printf("  -----\n");
}

void dessinerTablette(){
    printf("  --------\n");
    printf(" |        |\n");
    printf(" |        |\n");
    printf(" |   o    |\n");
    printf("  --------\n");
}

void dessinerTelevision(){
    printf("  --------\n");
    printf(" |        |\n");
    printf(" |        |\n");
    printf(" |--------|\n");
    printf("     |     \n");
    printf("    ___     \n");
}

void dessinerStylo(){
    printf("  --- \n");
    printf("  | | \n");
    printf("  | | \n");
    printf("  | | \n");
    printf("   - \n");
}

void dessinerLunette(){
    printf("  ---     ---  \n");
    printf("--| |  -- | |--\n");
    printf("  ---     ---  \n");
}

void dessinerTrousse(){
    printf(" --------'- \n");
    printf("(          )\n");
    printf(" ---------- \n");
}

void dessinerGrosLot(){
    printf("     ∞                                 \n");
    printf(" ---------                --------     \n");
    printf("|         |             /  |       \\  \n");
    printf(" +-------+      --->     ----------    \n");
    printf(" |   +   |      --->   |            |  \n");
    printf(" |   +   |              --(*)--(*)--   \n");
    printf(" +-------+                             \n");
}

int choixUtilisateur(){
    int choix;
    scanf("%d", &choix);
    return choix;
}

float choixUtilisateurFloat(){
    float valeur;
    scanf("%f", &valeur);
    return valeur;
}

// Niveau 1 (facile)
int devinerPrix(char* objet, int min, int max){
    int prixSecret = generationPrix(min, max);
    int essais = 0;
    int proposition;

    printf("\n--- Devinez le prix du %s ---\n", objet);

    if (objet == "telephone")
    {
        dessinerTelephone();
    }
    else if (objet == "tablette")
    {
        dessinerTablette();
    }
    else
    {
        dessinerTelevision();
    }

    printf("Prix entre %d et %d euros\n", min, max);

    while (essais < 5)
    {
        essais++;
        printf("Essai %d/5 : ", essais);
        proposition = choixUtilisateur();

        if (proposition < prixSecret)
        {
            printf("Trop bas !\n");
        }
        else if (proposition > prixSecret)
        {
            printf("Trop haut !\n");
        }
        else
        {
            printf("Bravo ! Prix correct : %d euros\n\n", prixSecret);
            return 1;
        }
    }
    printf("Echec ! Le prix etait : %d euros\n\n", prixSecret);
    return 0;
}

// Niveau 2 (moyen)
int devinerPrixNiveau2(char* objet, float min, float max){
    float prixSecret = generationPrixFloat(min, max);
    int essais = 0;
    float proposition;

    printf("\n--- Devinez le prix du %s ---\n", objet);

    if (objet == "stylo")
    {
        dessinerStylo();
    }
    else if (objet == "lunettes")
    {
        dessinerLunette();
    }
    else
    {
        dessinerTrousse();
    }

    printf("Prix entre %.2f et %.2f euros\n", min, max);

    while (essais < 5)
    {
        essais++;
        printf("Essai %d/5 : ", essais);
        proposition = choixUtilisateurFloat();

        if (proposition < prixSecret - 0.1)
        {
            printf("Trop bas !\n");
        }
        else if (proposition > prixSecret + 0.1)
        {
            printf("Trop haut !\n");
        }
        else
        {
            printf("Bravo ! Prix correct : %.2f euros\n\n", prixSecret);
            return 1;
        }
    }
    printf("Echec ! Le prix etait : %.2f euros\n\n", prixSecret);
    return 0;
}

// Niveau final (difficile)
int devinerPrixNiveau3(){
    int prixSecret = generationPrix(150000, 200000);
    int essais = 0;
    int proposition;
    
    printf("--- Trouvez le prix du GROS LOT (voiture) ! ---\n\n");
    dessinerGrosLot();
    printf("Le prix est entre 150 000 et 200 000 euros !\n");

    while (essais < 5)
    {
        essais++;
        printf("Essai %d/5 : ", essais);
        proposition = choixUtilisateur();

        if (proposition < prixSecret)
            printf("Trop bas !\n");
        else if (proposition > prixSecret)
            printf("Trop haut !\n");
        else
        {
            printf("INCROYABLE !!! Vous avez trouvé le prix ! (%d euros)\n\n", prixSecret);
            return 1;
        }
    }

    printf("Perdu ! Le prix était : %d euros\n\n", prixSecret);
    return 0;
}

void niveau3(){
    printf("\n=== NIVEAU 3 (difficile) ===\n");

    if (devinerPrixNiveau3())
        printf("=== FÉLICITATIONS !!! Vous remportez le GROS LOT ! ===\n");
    else
        printf("=== DOMMAGE ! Vous avez perdu :( ===\n");
}

void niveau2(){
    printf("\n=== NIVEAU 2 (moyen) ===\n");

    if (devinerPrixNiveau2("stylo", 1.50, 5.50))
    {
        if (devinerPrixNiveau2("lunettes", 40.80, 60.75))
        {
            if (devinerPrixNiveau2("trousse", 8.99, 15.75))
            {
                printf("=== FELICITATIONS ! Vous avez gagné le niveau 2 ! ===\n\n");
                printf("Voulez vous passer au niveau suivant ? : \n");
                printf("1. oui\n2. non\n");
                if(choixUtilisateur() == 1) {
                    niveau3();
                } else {
                    printf("Aurevoir");
                }
            }
            else
            {
                printf("=== ECHEC sur la trousse ===\n\n");
                printf("Voulez vous recommencer ? : \n");
                printf("1. oui\n2. non\n");
                if(choixUtilisateur() == 1) {
                    niveau2();
                } else {
                    printf("Aurevoir");
                }
            }
        }
        else
        {
            printf("=== ECHEC sur les lunettes ===\n\n");
            printf("Voulez vous recommencer ? : \n");
            printf("1. oui\n2. non\n");
            if(choixUtilisateur() == 1) {
                niveau2();
            } else {
                printf("Aurevoir");
            }
        }
    }
    else
    {
        printf("=== ECHEC sur le stylo ===\n\n");
        printf("Voulez vous recommencer ? : \n");
        printf("1. oui\n2. non\n");
        if(choixUtilisateur() == 1) {
            niveau2();
        } else {
            printf("Aurevoir");
        }
    }
}

void niveau1(){
    printf("\n=== NIVEAU 1 (facile) ===\n");

    if (devinerPrix("telephone", 200, 600))
    {
        if (devinerPrix("tablette", 300, 800))
        {
            if (devinerPrix("television", 400, 1200))
            {
                printf("=== FELICITATIONS ! Vous avez gagné le niveau 1 ! ===\n\n");
                printf("Voulez vous passer au niveau suivant ? : \n");
                printf("1. oui\n2. non\n");
                if(choixUtilisateur() == 1) {
                    niveau2();
                } else {
                    printf("Aurevoir");
                }
            }
            else
            {
                printf("=== ECHEC sur la television ===\n\n");
                printf("Voulez vous recommencer ? : \n");
                printf("1. oui\n2. non\n");
                if(choixUtilisateur() == 1) {
                    niveau1();
                } else {
                    printf("Aurevoir");
                }
            }
        }
        else
        {
            printf("=== ECHEC sur la tablette ===\n\n");
            printf("Voulez vous recommencer ? : \n");
            printf("1. oui\n2. non\n");
            if(choixUtilisateur() == 1) {
                niveau1();
            } else {
                printf("Aurevoir");
            }
        }
    }
    else
    {
        printf("=== ECHEC sur le telephone ===\n\n");
        printf("Voulez vous recommencer ? : \n");
        printf("1. oui\n2. non\n");
        if(choixUtilisateur() == 1) {
            niveau1();
        } else {
            printf("Aurevoir");
        }
    }
}

//menu
void menu() {
    printf("Programmé par : Saratou DJALO, Christian JIN et Meriem MEZDARI étudiants en DSP-Intégrateur Web\n");
    printf("\n=== JEU DU JUSTE PRIX ===\n");
    printf("1. NIVEAU 1 (facile)\n");
    printf("2. NIVEAU 2 (moyen)\n");
    printf("3. NIVEAU FINAL (difficile)\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");

    int choix;
    scanf("%d", &choix);

    if (choix == 1) {
        niveau1();
    } 
    else if (choix == 2) {
        niveau2();
    } 
    else if (choix == 3) {
        niveau3();
    } 
    else if (choix == 4) {
        printf("Au revoir !\n");
    } 
    else {
        printf("Choix invalide !\n");
    }
}

int main(){
    srand(time(NULL));
    menu();
    return 0;
}