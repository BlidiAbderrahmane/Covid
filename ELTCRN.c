#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include "ELTPRIM.h"

ELEMENT elementCreer() {
    ELEMENT e;
    e=(ELEMENT)malloc(sizeof(corona));
    e->cp=0;
    e->date.a=0;
    e->date.m=0;
    e->date.j=0;
    e->dec=0;
    e->grs=0;
    e->nva=0;
}
int isValid (d dt)
{
    int succee=0;
    if(dt.a>=1900 && dt.a<=9999)
    {
        if(dt.m>=1 && dt.m<=12)
        {
            if((dt.j>=1 && dt.j<=31) && (dt.m==1 || dt.m==3 || dt.m==5 || dt.m==7 || dt.m==8 || dt.m==10 || dt.m==12))
                succee=1;
            else if((dt.j>=1 && dt.j<=30) && (dt.m==4 || dt.m==6 || dt.m==9 || dt.m==11))
                succee=1;
            else if((dt.j>=1 && dt.j<=28) && (dt.m==2))
                succee=1;
            else if(dt.j==29 && dt.m==2 && (dt.a%400==0 ||(dt.a%4==0 && dt.a%100!=0)))
                succee=1;
        }
    }
    return succee;
}

void elementLire(ELEMENT *e) {
    do
    {
        printf("Donner le nombre des cas positifs : ");
        scanf("%i",&((*e)->cp));
    } while ((*e)->cp<0);
    do
    {
        printf("Donner le nombre des guerisons : ");
        scanf("%i",&((*e)->grs));
    } while ((*e)->grs<0);
    do
    {
        printf("Donner le nombre des deces : ");
        scanf("%i",&((*e)->dec));
    } while ((*e)->dec<0);
    do
    {
        printf("Donner le nombre des vacinees : ");
        scanf("%i",&((*e)->nva));
    } while ((*e)->nva<0);
}
void elementDetruire(ELEMENT e) {
    free(e);
}
void elementAfficher(ELEMENT e) {
    printf("DATE : %i/%i/%i\n",e->date.j,e->date.m,e->date.a);
    printf("CAS POSITIFS : %i\n",e->cp);
    printf("GUERISONS : %i\n",e->grs);
    printf("DECES : %i\n",e->dec);
    printf("NOMBRE DE VACINEES : %i\n",e->nva);
}
void elementAffecter(ELEMENT *e1,ELEMENT e2) {
    *e1=e2;
}
void elementCopier(ELEMENT *e1,ELEMENT e2) {
    memcpy(*e1,e2,sizeof(corona));
}
int elementComparer(ELEMENT e1,ELEMENT e2)
{
    if ((e1->cp==e2->cp)&&(e1->dec==e2->dec)==(e1->grs==e2->grs)&&(e1->nva==e2->nva)&&(e1->date.j==e2->date.j)&&(e1->date.m==e2->date.m)&&(e1->date.a==e2->date.a))
        return 1;
    else
        return 0;
}
