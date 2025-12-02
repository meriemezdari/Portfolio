/**
 * \file inout.c
 * \brief Des fonctions simples de lecture au clavier en C.
 * \author Pierre Courtieu
 * \version 0.1
 * \date 17 août 2017
 *
 * À utiliser dans le cours d'initiation à la programmation. DUT FIP CNAM.
 *
 */

/*  Wrapper class for students for IO in C.
    Copyright (C) 2017  Pierre Courtieu.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details (see
    <http://www.gnu.org/licenses/>).
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

/** alias BOOL pour int  */
#define BOOL int

/** alias FALSE pour 0  */
#define FALSE 0

/** alias TRUE pour 1. */
#define TRUE 1

///@private
/* \brief Vide le buffer stdin jusqu'a prochain retour à la ligne.

    Attention, si rien n'est dans le buffer le programme attend. On
    purge les caractère pas paquet de 10 caractères.
*/
void purge_line (){
  char trash[10];
  int nbread=0;
    do{
      fgets (trash , 10 , stdin);
      nbread = strlen(trash);
    } while(trash[nbread-1]!='\n');
}


///@private pour cause de: pas pratique à utiliser
/* @brief Lecture d'une chaîne au clavier sans allocation.

   Écrit dans le tableau de caractères `s` la chaine de caractères
   tapée au clavier jusqu'à un saut de ligne (touche entrée). Ignore
   et consomme les caractères tapés au delà de la taille autorisée
   (`size`) jusqu'au saut de ligne. Les caractères suivant le saut de
   ligne ne sont ni lus ni consommés.

   ATTENTION `size` doit être strictement inférieur à la taile du
   tableau (la dernière case est utilisée pour mettre le caractère
   spécial `\0` qui signale la fin de la chaîne).
   
   Exemple d'utilsation:
   \code{c}
   char s [21];
   lireString(s,20);
   \endcode

   \param s a string (`char *` ou `char[]`).
   \param size the size of `s - 1`
                                                
 */
void lireCharArray(char s[],int size);
/* NB. On n'utilise pas `scanf` ou `gets` qui sont obsolètes.

   NB 2. `s` est déclaré comme un tableau dans les arguments mais dans
   ce cas il est implictement considéré comme un pointeur. L'usage
   veut qu'on mette plutôt un pointeur mais je préfère ne pas utiliser
   cette notation pour des débutant. Nous verrons le passage par
   référence en fin de semestre. */
void lireCharArray(char s[],int size){
  /* Lecture au clavier, `fgets` garde le dernier caractère pour le `\0` */
  fgets (s , size+1 , stdin);  /* s==NULL? */
  int nbread = strlen(s);
  /* `fgets` garde le `\n` dans la chaine si il est dans les bornes.
     Si il est là on le remplace par `\0`. */ 
  if (nbread < size || (nbread == size &&  s[nbread-1]=='\n')) {
    s[nbread-1]='\0';
  }
  else { /* Sinon c'est qu'il reste des caractères sur la ligne. On
            les purge en oubliant tout jusqu'au prochain saut de
            ligne. */
    purge_line();
  }
}

void debugChar(char c){
  switch(c) {
  case '\n': printf("\\n"); break;
  case '\r': printf("\\r"); break;
  case '\0': printf("\\0"); break;
  default: printf("%c",c);
  }
}

void debugString(char * s){
  int max = strlen(s);
  int i=0;
  for(i = 0; i <= max; i = i +1){
    debugChar(s[i]);
  }
  
}


char * lireStringFile(FILE * input) {
  char d;
  char c=' ';
  int i=0;
  int size = 32; /* Taille initial du tableau de char, on agrandira si nécessaire. */
  char * res = malloc (sizeof(char)*size);
  res[0]='\0'; // In case nos character is read at all
  int eofbeforeanything = TRUE;
  while((c=fgetc(input))!=EOF) {
    eofbeforeanything = FALSE;
    if (i>size - 2) { // Faut-il agrandir?
      size = size*2;
      void * res_realloc = realloc(res,(sizeof(char)*size));
      if(res_realloc == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
      } else {
        res = res_realloc;
      }
    }
    switch(c) {
    case '\n': // On a fini
      res[i]='\0';
      return res;
      break;
    case '\r': // On a presque fini: on consomme le \n juste après si il existe
      d = getc(input);
      if(d!='\n') {// il ne fallait pas consommer ce caractère
        ungetc(d,input);
        res[i]='\0';
        return res;
      }
      else { // On a consommé le \n suivant le \r on a fini
        res[i]='\0';
        return res;
      }
      break;
    default: // On n'a pas fini
      res[i]=c;
      i=i+1;
    }
  }
  if (eofbeforeanything) {
    free(res);
    return NULL; // If end of file was reached before any char (not even a CR).
  } else {
    return res;
  }
}

/** Lecture d'une ligne au clavier. Le retour à la ligne n'est pas
   inclu dans la chaine retournée mais il est consommé. */
char * lireString() {
  return lireStringFile(stdin);
}


///@private
/* Ajoute les mot de lignecourante dans t à partir de l'indice aPartirDe.*/
int ajouteMots(char * lignecourante,char *t[],int aPartirDe){
  int i = aPartirDe;
  char * motsuivant=strtok(lignecourante," 	");
  do {
    if (motsuivant!=NULL) {
      t[i] = motsuivant;
      i = i + 1;
      motsuivant = strtok(NULL," 	");
    }
  } while (motsuivant!=NULL);
  return i;
}

///@private
int max (int i, int j) {
  return i>j?i:j;
}


/** \brief Lecture des mots d'un fichiers + modifie le deuxième
    arguments (nb de mots lus).
    
    Retourne un tableau de chaines de charactères contenant tous les
    mots du fichier nomFicher.

    La fonction modifie également la valeur du deuxième argument afin
    qu'il contienne le nombre de mots dans le tableau retourné.
 **/
char ** lireFichierParMots(char * nomFicher, int* nombreMots) {
  int size = 32; /* Taille initial du tableau de char, on agrandira si nécessaire. */
  char ** t = (char**)malloc(sizeof(char *)*size);
  int i=0;
  FILE *FICHIER1 =fopen(nomFicher,"r");   
  char * lignecourante;
  BOOL fini = FALSE;
  while(! fini){
    lignecourante = lireStringFile(FICHIER1);
    if (lignecourante == NULL) {
      fini = TRUE;
    } else {
      int nb_spaces = strlen (lignecourante);
      if (i>=size - nb_spaces) { // Faut-il agrandir?
        void * t_realloc = realloc(t,max(sizeof(char *)*size*2,size+nb_spaces));
        if(t_realloc == NULL){
          printf("Memory allocation failed!\n");
          exit(1);
        } else {
          t = t_realloc;
        }
        size = size*2;
      }
      if (i>size - nb_spaces) { // Faut-il agrandir encore plus?
        void * t_realloc = realloc(t,sizeof(char *)*size+2*nb_spaces*sizeof(char *));
        if(t_realloc == NULL){
          printf("Memory allocation failed!\n");
          exit(1);
        }
        size = size+2*nb_spaces;
      }
      i = ajouteMots(lignecourante,t,i); // Ajoute les mot de lignecourante dans t.
    }
  }
  *nombreMots = i; // On modifie le paramètre
  return t;
}

///@private
/** \brief Fonction auxiliaire de gestion d'erreur de sscanf. */
void dispatchError(int nbmatch, char * msg) {
  if (nbmatch == EOF) {
    printf("Erreur de lecture\n");
    exit(1);
  }
  else if (nbmatch == 0) {
    printf("Erreur, ceci n'est pas un(e) %s\n",msg);
    exit(1);
  }
}

/* Lecture d'un entier suivi d'un saut de ligne. */
int lireInt(){
  char * s=lireString();
  int res;
  int nbmatch = sscanf(s,"%d",&res);
  if (nbmatch == 1)  {
    free(s);
    return res;
  }
  else {
    dispatchError(nbmatch,"entier");
    assert(FALSE);
  }
}

/* Lecture d'un entier suivi d'un saut de ligne avec valeur par défaut
   en cas d'échec. Le seul cas où la fonction plante est quand il n'y
   a pas du tout de texte tapé (même pas une ligne vide), c'est-à-dire
   lorsque quelquechose met fin à la lecture (end of file
   principalement: la fin d'un fichier ou ctrl-d). */
int lireIntDefaut(int defaut){
  char * s=lireString();
  if (s==NULL) { printf("\nPlus d'entrée, fin du programme.\n"); exit (1); }
  int res;
  int nbmatch = sscanf(s,"%d",&res);
  if (nbmatch == 1)  {
    free(s);
    return res;
  }
  else {
    return defaut;
  }
}

/* Lecture d'un caractère suivi d'un saut de ligne. */
char lireChar(){
  char * s = lireString();
  char res;
  int nbmatch = sscanf(s,"%c",&res);
  if (nbmatch == 1) {
    free(s);
    return res;
  }
  else {
    dispatchError(nbmatch,"caractère");
    assert(FALSE);
  }
}

/* Lecture d'un caractère suivi d'un saut de ligne. */
char lireCharDefaut(char defaut){
  char * s = lireString();
  if (s==NULL) { printf("\nPlus d'entrée, fin du programme.\n"); exit (1); }
  char res;
  int nbmatch = sscanf(s,"%c",&res);
  if (nbmatch == 1) {
    free(s);
    return res;
  }
  else {
    return defaut;
  }
}

/* Lecture d'un double suivi d'un saut de ligne. */
double lireDouble(){
  char * s = lireString();
  double res;
  int nbmatch = sscanf(s,"%lf",&res);
  free(s);
  if (nbmatch == 1) {
    return res;
  }
  else {
    dispatchError(nbmatch,"double");
    assert(FALSE);
  }
}


void ecrireDate (){

  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  /* t contient maintenant la date et l'heure courante */
  printf("%d/%d/%d %d:%d:%d",t->tm_mday,t->tm_mon+1,t->tm_year+1900,
         t->tm_hour,t->tm_min,t->tm_sec);
}

int heureActuelle(){
  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  return t -> tm_hour;
}

int minuteActuelle(){
  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  return t -> tm_min;
}

int secondeActuelle(){
  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  return t -> tm_sec;
}

int jourActuel(){
  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  return t -> tm_mday;
}

int moisActuel(){
  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  return t -> tm_mon + 1;
}

int anneeActuelle(){
  time_t timestamp;
  struct tm * t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  return 1900 + t -> tm_year;
}



void ecrireInt(int n){
  printf("%d",n);
}

void ecrireDouble(double n){
  printf("%lf",n);
}

void ecrireChar(char c){
  printf("%c",c);
}

void ecrireLong(long n){
  printf("%ld",n);
}

void ecrireString(char s[]){
  printf("%s",s);
}

void ecrireSautDeLigne(){
  printf("\n");
}

void pause(){
  purge_line();
}
