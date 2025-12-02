#include"inout.h"

//question1
void ecritBonjour(){
    ecrireString("Bonjour\n");
}

//question2
void ecrit3Bonjour(){
    ecrireString("Bonjour\n");
    ecrireString("Bonjour\n");
    ecrireString("Bonjour\n");
}

//question3
void ecritSommeDeuxlireInt(void){
    int x = lireInt();
    int y = lireInt();
    ecrireString("Somme : ");
    ecrireInt(x + y);
    ecrireString("\n");
}

//question4
void ecritDeuxFoislireInt(void){
    int x = lireInt();
    ecrireString("Nombre saisi : ");
    ecrireInt(x);
    ecrireString("\n");
    ecrireString("Nombre saisi n°2 : ");
    ecrireInt(x);
    ecrireString("\n");
}

//question5
void ecritDeuxInt(int x, int y){
    ecrireString("Premier entier : ");
    ecrireInt(x);
    ecrireString("\n");
    ecrireString("Deuxième entier : ");
    ecrireInt(y);
    ecrireString("\n");}

//question6
void ecritSommeDeuxInt(int x, int y){
    ecrireString("Somme : ");
    ecrireInt(x + y);
    ecrireString("\n");
}

//question7
void ecritSommeDeuxIntBavard(int x, int y){
    ecrireString("Premier nombre : ");
    ecrireInt(x);
    ecrireString("\n");

    ecrireString("Deuxième nombre : ");
    ecrireInt(y);
    ecrireString("\n");

    ecrireString("Somme : ");
    ecrireInt(x + y);
    ecrireString("\n");
}

//question8
void ecritSommeTroisInt(int x, int y, int z){
    ecrireString("x = ");
    ecrireInt(x);
    ecrireString("\n");

    ecrireString("y = ");
    ecrireInt(y);
    ecrireString("\n");

    ecrireString("z = ");
    ecrireInt(z);
    ecrireString("\n");

    ecrireString("Somme = ");
    ecrireInt(x + y + z);
    ecrireString("\n");
}

//question9
void ecritSommeDifflireInt(){
    int x = lireInt();
    int y = lireInt();

    ecrireString("Somme : ");
    ecrireInt(x + y);
    ecrireString("\n");

    ecrireString("Différence : ");
    ecrireInt(x - y);
    ecrireString("\n");
}

void main(void){
    ecritBonjour();
    ecrit3Bonjour();
    ecritSommeDeuxlireInt();
    ecritDeuxFoislireInt();
    ecritDeuxInt(2, 5);
    ecritSommeDeuxInt(2, 5);
    ecritSommeDeuxIntBavard(2, 5);
    ecritSommeTroisInt(2, 5, 9);
    ecritSommeDifflireInt();
}