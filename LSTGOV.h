#ifndef LSTGOV_H_INCLUDED
#define LSTGOV_H_INCLUDED
#include "ELTPRIM.h"

typedef struct structNoeud {
    ELEMENT info;
    struct structNoeud *suivant;
    struct structNoeud *precedent;
} structNoeud, *NOEUD;

typedef struct
{
    int lg;
    NOEUD tete;
    NOEUD Queue;
}laStruct,*LISTE;


#endif // LSTGOV_H_INCLUDED
