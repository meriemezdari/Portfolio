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

/**
 * \file inout.h
 * \brief Des fonctions simples de lecture au clavier en C.
 * \author Pierre Courtieu
 * \version 0.1
 * \date 17 août 2017
 *
 * À utiliser dans le cours d'initiation à la programmation. DUT FIP CNAM.
 *
 */

#include<stdio.h>

/**
    @brief Lecture d'une chaîne dans un fichier avec allocation.

    Lit les caractères dans le fichier (à la position corante jusqu'au
    prochain saut de ligne (compris) et retourne une chaine de
    caractères (`char *`) contenant les caractères (excepté le saut de
    ligne).

    EN PRINCIPE il faut faire `free` dessus pour la libérer quand on
    en n'a plus besoin. Pour les débutants on ne le fera pas (mais
    c'est mal). */
char * lireStringFile(FILE * input);

/**
    @brief Lecture d'une chaîne au clavier avec allocation.

    Lit les caractères tapés par l'utilisateurs jusqu'au prochain saut
    de ligne (compris) et retourne une chaine de caractères (`char *`)
    contenant ces caractères (excepté le saut de ligne).

    EN PRINCIPE il faut faire `free` dessus pour la libérer quand on
    en n'a plus besoin. Pour les débutants on ne le fera pas (mais
    c'est mal). */
char * lireString();

/** \brief Lecture des mots d'un fichiers + modifie le deuxième
    arguments (nb de mots lus).

    Retourne un tableau de chaines de charactères contenant tous les
    mots du fichier nomFicher.

    La fonction modifie également la valeur du deuxième argument afin
    qu'il contienne le nombre de mots dans le tableau retourné.
 **/
char ** lireFichierParMots(char * nomFicher, int* nombreMots);

/** \brief Lecture d'un entier suivi d'un saut de ligne.

    Si d'autres caractères sont tapés entre le caractère et le saut de
    ligne, ils sont ignorés.

    \return l'entier lu
*/
int lireInt();

/** \brief comme liseInt() mais avec une valeur à retourner en cas
    d'échec de lecture.

    Contrairement à `lireInt` cette fonction ne fait donc pas planter
    votre programme si l'utilisateur tape autre chose qu'un entier ou
    tape seulement "entrée".

    En revanche la fonction plante toujours si la fin de fichier est
    lue (si on tape ctrl-d ou si on atteint la fin d'un fichier
    redirigé vers l'entrée standard).

    \return l'entier lu ou defaut si pas d'entier lu.
*/
int lireIntDefaut(int defaut);

/** \brief Lecture d'un caractère suivi d'un saut de ligne.

    Si d'autres caractères sont tapés entre le caractère et le saut de
    ligne, ils sont ignorés.

    \return le caractère lu
*/
char lireChar();

/** \brief comme lireChar() mais avec une valeur à retourner en cas
    d'échec de lecture.

    Contrairement à `lireChar` cette fonction ne fait donc pas planter
    votre programme si l'utilisateur tape seulement "entrée".

    En revanche la fonction plante toujours si la fin de fichier est
    lue (si on tape ctrl-d ou si on atteint la fin d'un fichier
    redirigé vers l'entrée standard).

    \return l'entier lu ou defaut si pas d'entier lu.
*/
char lireCharDefaut(char defaut);

/** \brief Lecture d'un double suivi d'un saut de ligne.

    Si des caractères sont tapés entre le double et le saut de ligne,
    ils sont ignorés.

    \return le caractère lu
*/
double lireDouble();

/** \brief Écrit dans le terminal la date actuelle. */
void ecrireDate();

/** \brief Retourne le numéro de l'heure actuelle (entre 0 et 23). */
int heureActuelle();

/** \brief Retourne le numéro de la minute actuelle (entre 0 et 59). */
int minuteActuelle();

/** \brief Retourne le numéro de la seconde actuelle (entre 0 et 59). */
int secondeActuelle();

/** \brief Retourne le numéro de l'année actuelle (entre 0 et 23). */
int anneeActuelle();

/** \brief Retourne le numéro du mois actuel (entre 1 et 12). */
int moisActuel();

/** \brief Retourne le numéro du jour actuel (entre 1 et 31). */
int jourActuel();


/** \brief Écrit dans le terminal la chaîne de caractères `s`. */
void ecrireString(char s[]);

/** \brief Écrit dans le terminal l'entier `n`. */
void ecrireInt(int n);

/** \brief Écrit dans le terminal le double `n`. */
void ecrireDouble(double n);

/** \brief Écrit dans le terminal le caractère ``c`. */
void ecrireChar(char c);

/** \brief Écrit dans le terminal le long `n`. */
void ecrireLong(long n);

/** \brief Écrit un saut deligne dans le terminal. */
void ecrireSautDeLigne();

/** \brief Pause jusqu'à ce que l'utilisateur appuie sur entrée.

    Tous les caractères tapés avant le entrée sont ignorés et
    oubliés. */
void pause();

/** \brief Fonction de debugage: affiche un caractère. Les caractères
    `\n` `\r` et `\0` sont affichés tel quels. */
void debugChar(char c);

/** \brief Fonction de debugage: affiche une chaine de cractère en
    montrant les `\n` `\r` et `\0`. */
void debugString(char * s);
