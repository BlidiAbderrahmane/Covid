#ifndef LSTPRIM_H_INCLUDED
#define LSTPRIM_H_INCLUDED
#include"ELTPRIM.h"
#include"LSTSDD.h"

NOEUD noeudCreer(ELEMENT);
void noeudDetruire(NOEUD);
LISTE listeCreer(void);
void listeDetruire(LISTE);
void listeAfficher(LISTE);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
int inserer(LISTE,ELEMENT,int);
int supprimer(LISTE,int);
ELEMENT recuperer(LISTE,int);
LISTE listeCopier(LISTE);
int listeComparer(LISTE,LISTE);
void saisir(LISTE[24],char[24][20]);
void afficheEvol(LISTE[24],char[24][20]);
void supp(LISTE[24]);
void modifier(LISTE[24],char[24][20]);
void affiche(LISTE[24],char[24][20]);
void saisirTxt(LISTE[24]);
void quitter(LISTE[24]);
#endif // LSTPRIM_H_INCLUDED
