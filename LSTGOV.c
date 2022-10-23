#include "LSTPRIM.h"
#include<malloc.h>
#include<stdio.h>
#include <string.h>
#include<unistd.h>
#include<stdlib.h>
NOEUD noeudCreer(ELEMENT e)
{
    NOEUD n;
    n=(NOEUD)malloc(sizeof(structNoeud));
    if (!n)
    {
        printf("\nPlus d'espace");
    }
    else
    {
        elementAffecter(&n->info,e);
        n->suivant=NULL;
        n->precedent=NULL;
    }
    return n;
}
void noeudDetruire(NOEUD n)
{
    elementDetruire(n->info);
    free(n);
}
LISTE listeCreer()
{
    LISTE L;
    L=(LISTE)malloc(sizeof(laStruct));
    if (!L)
    {
        printf("\nProbleme de memoire");
    }
    else
    {
        L->lg=0;
        L->Queue=NULL;
        L->tete=NULL;
    }
    return (L);
}
void listeDetruire(LISTE L)
{
    int i;
    NOEUD p,q;
    q=L->tete;
    for (i=1;i<=L->lg;i++)
    {
        p=q;
        q=q->suivant;
        noeudDetruire(p);
    }
    free(L);
}
void listeAfficher(LISTE L)
{
    int i=1;
    NOEUD p;
    p=L->tete;
    for (i=1;i<=L->lg;i++)
    {
        elementAfficher(p->info);
        printf("--------------------------------\n");
        p=p->suivant;
    }
}
int listeTaille(LISTE L)
{
    return (L->lg);
}
int estVide(LISTE L)
{
    return (L->lg==0);
}
int estSaturee(LISTE L)
{
    NOEUD temp;
    int saturee=1;
    temp=(NOEUD)malloc(sizeof(structNoeud));
    if (temp!=NULL)
    {
        saturee=0;
        free(temp);
    }
    return saturee;
}
int inserer(LISTE L,ELEMENT e,int pos)
{
    int succee=1,i;
    NOEUD n,p,q;
    if (estSaturee(L))
    {
        printf("\nLa Liste est saturee");
        succee=0;
    }
    else{
        if ((pos<1)||(pos>L->lg+1))
        {
            printf("\nLa position est invalide");
            succee=0;
        }
        else
        {
            n=noeudCreer(e);
            if (L->lg==0)
            {
                L->tete=n;
                L->Queue=n;
            }
            else{
                if (pos==1)
                {
                    L->tete->precedent=n;
                    n->suivant=L->tete;
                    L->tete=n;
                }
                else
                {
                    if (pos==(L->lg+1))
                    {
                        L->Queue->suivant=n;
                        n->precedent=L->Queue;
                        L->Queue=n;
                    }
                    else
                    {
                        q=L->tete;
                        for (i=1;i<pos;i++)
                        {
                            p=q;
                            q=q->suivant;
                        }
                        p->suivant=n;
                        n->precedent=p;
                        n->suivant=q;
                        q->precedent=n;
                    }
                }
            }
            (L->lg)++;
        }
    }
    return succee;
}
int supprimer(LISTE L,int pos)
{
    int i,succee=1;
    NOEUD p,q;
    if (estVide(L))
    {
        printf("\nListe Vide");
        succee=0;
    }
    else
    {
        if ((pos<1)||(pos>L->lg))
        {
            printf("\nPosition Invalide");
            succee=0;
        }
        else
        {
            if (L->lg==1)
            {
                q=L->tete;
                L->tete=NULL;
                L->Queue=NULL;
            }
            else
            {
                if (pos==1)
                {
                    q=L->tete;
                    L->tete=L->tete->suivant;
                    L->tete->precedent=NULL;
                }
                else
                {
                    if (pos==L->lg)
                    {
                        q=L->Queue;
                        L->Queue=L->Queue->precedent;
                        L->Queue->suivant=NULL;
                    }
                    else
                    {
                        q=L->tete;
                        for (i=1;i<pos;i++)
                        {
                            p=q;
                            q=q->suivant;
                        }
                        q->suivant->precedent=p;
                        p->suivant=q->suivant;
                    }
                }
            }
            noeudDetruire(q);
            (L->lg)--;
        }
    }
    return succee;
}
ELEMENT recuperer(LISTE L,int pos)
{
    ELEMENT e=elementCreer();
    int i;
    NOEUD p;
    if (estVide(L))
    {
        printf("\nListe Vide\n");
    }
    else
    {
        if ((pos<1)||(pos>L->lg))
        {
            printf("\nPosition Invalide");
        }
        else
        {
            p=L->tete;
            for (i=1;i<pos;i++)
            {
                p=p->suivant;
            }
            elementAffecter(&e,p->info);
        }
    }
    return e;
}
LISTE listeCopier(LISTE L)
{
    LISTE LR=listeCreer();
    int i;
    ELEMENT e;
    for (i=1;i<=L->lg;i++)
    {
        e=elementCreer();
        elementCopier(&e,recuperer(L,i));
        inserer(LR,e,i);
    }
    return LR;
}
int listeComparer(LISTE L1,LISTE L2)
{
    int test=1,i;
    if (listeTaille(L1)!=listeTaille(L2))
    {
        test=0;
    }
    while ((i<listeTaille(L1))&&(test))
    {
        if (elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
        {
            test=0;
        }
        i++;
    }
    return test;
}

int exValid(d dt,LISTE tab[24])
{
    int succee=1;
    if (!isValid(dt))
        succee=0;
    else
    {
        if (!estVide(tab[0]))
        {
            d dt2=(recuperer(tab[0],tab[0]->lg))->date;
            if (dt.a<dt2.a)
                succee=0;
            else if ((dt.a==dt2.a)&&(dt.m<dt2.m))
                succee=0;
            else if ((dt.a==dt2.a)&&(dt.m==dt2.m)&&(dt.j<=dt2.j))
                succee=0;
        }
    }
    return succee;
}

int posDate (d dt,LISTE L)
{
    int i=1,stop=0, pos=0;
    ELEMENT e=elementCreer();
    while ((i<=L->lg)&&(stop==0))
    {
        e=recuperer(L,i);
        if ((e->date.j==dt.j)&&(e->date.m==dt.m)&&(e->date.a==dt.a))
        {
            pos=i;
            stop=1;
        }
        i++;
    }
    return pos;
}

void saisir(LISTE tab[24],char noms[24][20])
{
    system("cls");
    char c;
    d dt;
    int i;
    ELEMENT e;
    do
    {
        printf("DONNER UNE DATE POUR LA SAISIE : \n");
        printf("JOUR  :  ");scanf("%i",&(dt.j));
        printf("MOIS  :  ");scanf("%i",&(dt.m));
        printf("ANNEE :  ");scanf("%i",&(dt.a));
    } while (exValid(dt,tab)==0);
    for (i=0;i<24;i++)
    {
        e=elementCreer();
        printf("\nDONNEZ LES INFORMATIONS DU %s :  \n",noms[i]);
        elementLire(&e);
        e->date=dt;
        inserer(tab[i],e,(tab[i]->lg)+1);
    }
    do
    {
        printf("\nVOULEZ VOUS ECRIRE LES INFORMATIONS D'UNE AUTRE DATE : ");
        printf("1- OUI     2- NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1')
        saisir(tab,noms);
    system("cls");
}

void afficheEvol(LISTE tab[24],char noms[24][20])
{
    system("cls");
    int ch;
    char c;
    do{
        system("cls");
        printf("1-ARIANA | 2-BEJA | 3-BEN AROUS | 4-BIZERTE | 5-GABES | 6-GAFSA | 7-JENDOUBA | 8-KAIROUAN\n");
        printf("9-KASSERINE | 10-KEBILI | 11-LA MANOUBA | 12-LE KEF | 13-MAHDIA | 14-MEDENINE | 15-MONASTIR | 16-NABEUL\n");
        printf("17-SFAX | 18-SIDI BOUZID | 19-SILIANA | 20-SOUSSE | 21-TATAOUINE | 22-TOZEUR | 23-TUNIS | 24-ZAGHOUAN\n\n");
        printf("CHOISIR UN NUMERO DE GOUVERNORAT :  ");
        scanf("%i",&ch);
    } while ((ch<1)||(ch>24));
    system("cls");
    printf("----------------  %s  ---------------\n\n",noms[ch-1]);
    listeAfficher(tab[ch-1]);
    do
    {
        printf("\n\nVOULEZ VOUS AFFICHER L'EVOLUTION DE STATISTIQUES D'UN AUTRE GOUVERNORAT : ");
        printf("1- OUI     2- NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1')
        afficheEvol(tab,noms);
    system("cls");
}

void supp(LISTE tab[24])
{
    d dt;
    int i;
    char c;
    system("cls");
    do
    {
        printf("DONNER UNE DATE POUR LA SUPPRESSION : \n");
        printf("JOUR  :  ");scanf("%i",&(dt.j));
        printf("MOIS  :  ");scanf("%i",&(dt.m));
        printf("ANNEE :  ");scanf("%i",&(dt.a));
    } while (posDate(dt,tab[0])==0);
    int pos=posDate(dt,tab[0]);
    for (i=0;i<24;i++)
    {
        supprimer(tab[i],pos);
    }
    printf("LES DONNEES CORRESPONDANTS AU %i/%i/%i SONT SUPPRIMES AVEC SUCCES",dt.j,dt.m,dt.a);
    do
    {
        printf("\n\nVOULEZ VOUS SUPPRIMER LES INFORMATIONS D'UNE AUTRE DATE : ");
        printf("1- OUI     2- NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1')
        supp(tab);
    system("cls");
}

void modifier(LISTE tab[24],char noms[24][20])
{
    system("cls");
    int ch,inf,val,i;
    d dt;
    char c;
    ELEMENT e=elementCreer();
    do
    {
        printf("DONNER UNE DATE POUR LA MODIFICATION : \n");
        printf("JOUR  :  ");scanf("%i",&(dt.j));
        printf("MOIS  :  ");scanf("%i",&(dt.m));
        printf("ANNEE :  ");scanf("%i",&(dt.a));
    } while (!posDate(dt,tab[0]));
    int pos=posDate(dt,tab[0]);
    do{
        system("cls");
        printf("1-ARIANA | 2-BEJA | 3-BEN AROUS | 4-BIZERTE | 5-GABES | 6-GAFSA | 7-JENDOUBA | 8-KAIROUAN\n");
        printf("9-KASSERINE | 10-KEBILI | 11-LA MANOUBA | 12-LE KEF | 13-MAHDIA | 14-MEDENINE | 15-MONASTIR | 16-NABEUL\n");
        printf("17-SFAX | 18-SIDI BOUZID | 19-SILIANA | 20-SOUSSE | 21-TATAOUINE | 22-TOZEUR | 23-TUNIS | 24-ZAGHOUAN\n\n");
        printf("CHOISIR UN NUMERO DE GOUVERNORAT :  ");
        scanf("%i",&ch);
    } while ((ch<1)||(ch>24));
    e=recuperer(tab[ch-1],pos);
    do
    {
        printf("----------------  %s  ---------------\n\n",noms[ch-1]);
        printf("1-CAS POSITIFS : %i\n",e->cp);
        printf("2-GUERISONS : %i\n",e->grs);
        printf("3-DECES : %i\n",e->dec);
        printf("4-NOMBRE DE VACCINES : %i\n",e->nva);
        printf("\nSAISIR LE NUMERO D'INFORMATION QUE VOUS ALLEZ LE MODIFIER :  ");
        scanf("%i",&inf);
    } while ((inf<1)||(inf>4));
    do {
        printf("\nSAISIR LA NOUVELLE VALEUR :  ");
        scanf("%i",&val);
    } while (val<0);
    switch (inf)
    {
        case 1 : e->cp=val;break;
        case 2 : e->grs=val;break;
        case 3 : e->dec=val;break;
        case 4 : e->nva=val;break;
    }
    NOEUD p=tab[ch-1]->tete;
    for (i=1;i<pos;i++)
    {
        p=p->suivant;
    }
    p->info=e;
    printf("MODIFICATION EST FAITE AVEC SUCCES\n");
    do
    {
        printf("\n\nVOULEZ VOUS MODIFIER DES AUTRES INFORMATIONS : ");
        printf("1- OUI     2- NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1')
        modifier(tab,noms);
    system("cls");
}

void permute (int t1[5],int t2[5])
{
    int aux[5],i;
    for (i=0;i<5;i++)
    {
        aux[i]=t1[i];
        t1[i]=t2[i];
        t2[i]=aux[i];
    }
}

void affiche(LISTE tab[24],char noms[24][20])
{
    system("cls");
    d dt;
    char c;
    int t[4],cp,guer,pos,dec,nva,ord,i,j,m[24][5],b=0;
    ELEMENT e;
    do
    {
        printf("DONNER UNE DATE POUR L'AFFICHAGE : \n");
        printf("JOUR  :  ");scanf("%i",&(dt.j));
        printf("MOIS  :  ");scanf("%i",&(dt.m));
        printf("ANNEE :  ");scanf("%i",&(dt.a));
    } while (!posDate(dt,tab[0]));
    printf("ON VA TRIEER LES INFORMATIONS SELON 4 CRITERES : \n");
    printf("1. CAS POSITIFS |2. GUERISONS |3. DECES |4. NOMBRE DE VACCINES\n");
    printf("LE TRI VA S'EXPRIMER EN UTILISANT 4 NIVEAUX DE PRIORITE DE 1 A 4 (1 EST LE PLUS IMPORTANT)\n");
    do
    {
        printf("DONNER LE NIVEAU DE PRIORITE DE 'CAS POSITIFS' : ");
        scanf("%i",&cp);
    } while ((cp<1)||(cp>4));
    do
    {
        printf("DONNER LE NIVEAU DE PRIORITE DE 'GUERISONS' : ");
        scanf("%i",&guer);
    } while ((guer<1)||(guer>4)||(guer==cp));
    do
    {
        printf("DONNER LE NIVEAU DE PRIORITE DE 'DECES' : ");
        scanf("%i",&dec);
    } while ((dec<1)||(dec>4)||(dec==guer)||(dec==cp));
    do
    {
        printf("DONNER LE NIVEAU DE PRIORITE DE 'NOMBRE DE VACINEES' : ");
        scanf("%i",&nva);
    } while ((nva<1)||(nva>4)||(nva==guer)||(nva==cp)||(nva==dec));
    t[cp-1]=1;t[guer-1]=2;t[dec-1]=3;t[nva-1]=4;
    do
    {
        printf("0: DECROISSANT\n1: CROISSANT\n");
        printf("DONNER L'ORDRE DE TRI : ");
        scanf("%i",&ord);
    } while ((ord<0)||(ord>1));
    pos=posDate(dt,tab[0]);
    for (i=0;i<24;i++)
    {
        e=elementCreer();
        e=recuperer(tab[i],pos);
        m[i][0]=i;
        m[i][1]=(e->cp);
        m[i][2]=(e->grs);
        m[i][3]=(e->dec);
        m[i][4]=(e->nva);
    }
    i=0;
    while (b==0)
    {
        b=1;
        for (j=0;j<23;j++)
        {
            if (ord==1)
            {
                if (m[j][t[i]]>m[j+1][t[i]])
                {
                    permute(m[j],m[j+1]);
                    b=0;
                }
                else if (m[j][t[i]]==m[j+1][t[i]])
                {
                    if (m[j][t[i+1]]>m[j+1][t[i+1]])
                    {
                        permute(m[j],m[j+1]);
                        b=0;
                    }
                    else if (m[j][t[i+1]]==m[j+1][t[i+1]])
                    {
                        if (m[j][t[i+2]]>m[j+1][t[i+2]])
                        {
                            permute(m[j],m[j+1]);
                            b=0;
                        }
                        else if (m[j][t[i+2]]==m[j+1][t[i+2]])
                        {
                            if (m[j][t[i+3]]>m[j+1][t[i+3]])
                            {
                                permute(m[j],m[j+1]);
                                b=0;
                            }

                        }
                    }
                }
            }
            else
            {
                if (m[j][t[i]]<m[j+1][t[i]])
                {
                    permute(m[j],m[j+1]);
                    b=0;
                }
                else if (m[j][t[i]]==m[j+1][t[i]])
                {
                    if (m[j][t[i+1]]<m[j+1][t[i+1]])
                    {
                        permute(m[j],m[j+1]);
                        b=0;
                    }
                    else if (m[j][t[i+1]]==m[j+1][t[i+1]])
                    {
                        if (m[j][t[i+2]]<m[j+1][t[i+2]])
                        {
                            permute(m[j],m[j+1]);
                            b=0;
                        }
                        else if (m[j][t[i+2]]==m[j+1][t[i+2]])
                        {
                            if (m[j][t[i+3]]<m[j+1][t[i+3]])
                            {
                                permute(m[j],m[j+1]);
                                b=0;
                            }

                        }
                    }
                }
            }

        }
    }
    printf("GOUVERNORAT / CAS POSITIFS / GUERISONS / DECES / NOMBRE DE VACCINES\n\n");
    for (i=0;i<24;i++)
    {
        printf("%s / %i / %i / %i / %i\n",noms[m[i][0]],m[i][1],m[i][2],m[i][3],m[i][4]);
    }
    do
    {
        printf("\n\nVOULEZ VOUS AFFICHER LES INFORMATIONS D'UNE AUTRE DATE : ");
        printf("1- OUI     2- NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1')
        affiche(tab,noms);
    system("cls");
}

void saisirTxt(LISTE tab[24])
{
    system("cls");
    FILE *fichier;
    ELEMENT e;
    char c;
    char nomFichier[100],ligne[100],chj[10],chm[10],cha[10],chngov[10],chcp[20],chger[20],chdec[20],chnva[20];
    int i,stop,k,j,m,a,ngov,cp,ger,dec,nva;
    printf("ON VA REMPLACER LES LISTES PAR DES AUTRES A PARTIR D'UN FICHIER TEXTE\n");
    do
    {
        printf("DONNER LE NOM DU FICHIER TEXTE SOURCE : \n");
        scanf("%s",nomFichier);
    } while ((strlen(nomFichier)==0)||(fopen(nomFichier,"r")==NULL));
    fichier=fopen(nomFichier,"r");
    do
    {
        printf("LES LISTES ACTUELLES VONT ETRE SUPPRIMER\nVOULEZ VOUS CONTINUER ? : \n");
        printf("1-OUI         2-NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1'){
    for (i=0;i<24;i++)
    {
        while (!estVide(tab[i]))
            supprimer(tab[i],1);
    }
    while (fgets(ligne,100,fichier)!=NULL)
    {
        i=0;k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chj[k]=ligne[i];
            i++; k++;
        }
        chj[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chm[k]=ligne[i];
            i++; k++;
        }
        chm[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            cha[k]=ligne[i];
            i++; k++;
        }
        cha[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chngov[k]=ligne[i];
            i++; k++;
        }
        chngov[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chcp[k]=ligne[i];
            i++; k++;
        }
        chcp[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chger[k]=ligne[i];
            i++; k++;
        }
        chger[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chdec[k]=ligne[i];
            i++; k++;
        }
        chdec[k]='\0';
        i++; k=0;
        while ((ligne[i]>='0')&&(ligne[i]<='9'))
        {
            chnva[k]=ligne[i];
            i++; k++;
        }
        chnva[k]='\0';
        j=atoi(chj); m=atoi(chm); a=atoi(cha); ngov=atoi(chngov); cp=atoi(chcp); ger=atoi(chger); dec=atoi(chdec); nva=atoi(chnva);
        e=elementCreer();
        e->date.a=a;e->date.j=j;e->date.m=m;
        e->cp=cp;e->dec=dec;e->grs=ger;e->nva=nva;
        inserer(tab[ngov],e,(tab[ngov]->lg)+1);
    }
    printf("REMPLISSAGE EST FAITE AVEC SUCCES\n");
    }
    fclose(fichier);
    do
    {
        printf("\n\nVOULEZ VOUS REMPLIR LES LISTES A PARTIR D'UN AUTRE FICHIER TEXTE : ");
        printf("1- OUI     2- NON\n");
        getchar();
        c=getchar();
    } while ((c<'1')||(c>'2'));
    if (c=='1')
        saisirTxt(tab);
    system("cls");
}
void quitter(LISTE tab[24])
{
    FILE *fichier;
    fichier=fopen("latestVersion.txt","w");
    ELEMENT e;
    int i,j;
    for (i=1;i<=tab[0]->lg;i++)
    {
        for (j=0;j<24;j++)
        {
            e=elementCreer();
            e=recuperer(tab[j],i);
            fprintf(fichier,"%i/%i/%i-%i-%i-%i-%i-%i\n",e->date.j,e->date.m,e->date.a,j,e->cp,e->grs,e->dec,e->nva);
        }
    }
    fclose(fichier);
    system("cls");
    printf("||--------------------------------------------------------------------------------------------------||\n");
    printf("||            LES INFORMATIONS ACTUELLES SONT ENREGISTREES DANS LE FICHIER 'latestVersion.txt'      ||\n");
    printf("||--------------------------------------------------------------------------------------------------||\n");
    printf("||                                          AU REVOIR                                               ||\n");
    printf("||--------------------------------------------------------------------------------------------------||\n");
        printf(R"EOF(
                                                  .v i
                                                7BQBbB   i
                                              7BBBBQBBKvBB
                                             DBBBBBBBBBgs
                                             RBBBBBBBBB
                                             BBBBBBBBBBB.
                                             BBBBBBBBBBBBB
                                             QBBBBQBBBBBBB
                                             BBBBBBQBBBBB
                                            qBQBBBBBBBB7
                                          JQBBBBBBBBB
                                         BBBBBBBQBBBZ   :.
                                        :BBBBBBBBBBBBQ7. 7
                                         :BBBBBBBBBBBBQBRB
                                           rBBBBBBBBBBBBBQBI
                                            iBBBBBBBQBBBBBQQ
                                             XBBBBBQBQBQBQDv
                                               .BBQBBBBB:
                                                :BBBBBZ
                                                 BBBB
                                                 MBBB.
                                                 iBBQg
                                                  BB:       b
)EOF");
    sleep(4);
}
