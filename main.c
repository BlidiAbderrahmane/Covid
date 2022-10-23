#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTPRIM.h"
#include "LSTPRIM.h"

int main()
{
    int i,stop=0;
    char c,ligne[200];
    int vide;
    LISTE tab[24];
    char noms[24][20]={"ARIANA","BEJA","BEN AROUS","BIZERTE","GABES","GAFSA","JENDOUBA","KAIROUAN"
                      ,"KASSERINE","KEBILI","LA MANOUBA","LE KEF","MAHDIA","MEDENINE","MONASTIR","NABEUL"
                      ,"SFAX","SIDI BOUZID","SILIANA","SOUSSE","TATAOUINE","TOZEUR","TUNIS","ZAGHOUAN"};
    for (i=0;i<24;i++)
    {
        tab[i]=listeCreer();
    }
    printf(R"EOF(
                                              .       .:.
                                             ivKRL     .XujU
                                           .BBBQB.     :PPEE.      :v.
                                            ..iBQv      :E5        PQRqi
                                               QgBP.::iiK2X.       idbQBr
                                      .        gZgMgbEdPUIIdddji iqEZi .
                                    rBBU    .XBDEULYuu21uY11I2KPbPSq7
                                   rBBBBj. PBBdKv77L7vJ17ivUjLvLvj1P.
                                    r: IBBBQdXqSERBQM2vJ111js2ggdjjUE7    .Y7
                                        KMPPKPQBBBQBBBXYuUuJuBBBBBvU2gu   gQQb
                                       iBPPXKQBQQRQQBQMv1uuJsqQQMUYJ1UPKZQdZBB.
                                       BDPKqPBQQQQQBBB1YJujUsL7vvYJuu11q2.  :
                                      JBdqPKXqBBBBBBMJvs1uU11juJuJ1JUu15u
                              rqBY .:rggqPKqI7LKqP5u7YJ1J1u7iuu1uUuUj1u5b
                              BbBBBQBBgPPqPgQsLvv7vvL7vvJj1ssjUU2U211jUUZ
                              QRBQ:v2PMdqPKRM1LuJusYsPPSLsjUuU1vrrv2u1j2XY.  .Kr
                               :1     SQdKqKPsYJ1JY2BBBBQYJj1uUi::ru1u11PgBBdPg2
                                      .BdPKPKS7Ys1LPBBBBBss1jUu1vYuUjUUPsv77JQMv
                                       1BPPKQBBKYJuvSDRbuLuu1jsLU1Uu1uP5     75
                                        DDqbBBBMvjJuvv7vsUu1uJbQPJuUu55
                                       XBQBdddESYYJLuJ1uUYuUUsPgKs22bEZ:
                                  .BQIBBMurQBgPdPUiiYUu1:i:v1uYYs5dZii2Q5PD7
                                  .BBBB     vQBREdqJjjU17rrY2uU1PPv    :BQBJ
                                    Xg:       .2gdZQgPSqPdEZK51qi       :7.
                                               .BEBEIPPIIjsi7ESP:
                                               7BBq          :KPu
                                             rYbB2            7bbgBJ
                                            rBBBRBi          .BQZqY.
                                              :ruD:
)EOF");
    sleep(4);
    system("cls");
    printf("||--------------------------------------------------------------------------------------------------||\n");
    printf("||                                             BIENVENUE                                            ||\n");
    printf("||--------------------------------------------------------------------------------------------------||\n");
    printf("\n\n");
    do
    {
        vide=estVide(tab[0]);
        printf("||--------------------------------------------------------------------------------------------------||\n");
        printf("||                                             CHOISISSEZ                                           ||\n");
        printf("||--------------------------------------------------------------------------------------------------||\n");
        printf("||                      1- SAISIR                                                                   ||\n");
        printf("||                      2- AFFICHER L'EVOLUTION DE STATISTIQUES D'UN GOUVERNORAT                    ||\n");
        printf("||                      3- AFFICHER LES INFORMATIONS DES GOUVERNORATS VIA UNE DATE                  ||\n");
        printf("||                      4- SAISIR A PARTIR D'UN FICHIER TEXTE                                       ||\n");
        if (vide==0)
        {
            printf("||                      5- MODIFIER                                                                 ||\n");
            printf("||                      6- SUPPRIMER                                                                ||\n");
        }
        printf("||--------------------------------------------------------------------------------------------------||\n");
        printf("||                                             7- QUITTER                                           ||\n");
        printf("||--------------------------------------------------------------------------------------------------||\n");
        c=getchar();
        switch (c)
        {
            case '1' : saisir(tab,noms); break;
            case '2' : afficheEvol(tab,noms); break;
            case '3' : affiche(tab,noms); break;
            case '4' : saisirTxt(tab); break;
            case '5' : if (vide==0) {modifier(tab,noms);} break;
            case '6' : if (vide==0) {supp(tab);} break;
            case '7' : quitter(tab);stop=1; break;
        }
        getchar();
    } while ((c<'1')||(c>'7')||(stop==0));
    return 0;
}

