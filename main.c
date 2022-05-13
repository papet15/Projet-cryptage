#include <stdio.h>
#include <stdlib.h>
#include <string.h>






//pR='\0';




int main()
{
    unsigned char cle[200]="";
    unsigned char resultat[2000]="";
    unsigned char resultat2[200]="";
    unsigned char txt[100][5]={""};
    unsigned char *ptT=NULL;
    unsigned char *ptP=NULL;
    ptT=&txt[0][0];
    ptP=&cle[0];
    char c;

    do{

    printf("Bienvenue!\n\n");
    int option,i=0;

    printf("---Menu---\n\n");
    printf("1.Encrypter\n");
    printf("2.Decrypter\n");
    printf("3.Details cryptage ascii\n");
    printf("\nVotre choix ? ");
    scanf("%d", &option);
    lecture("fichier.txt",&txt[0][0]);
    lecture("perro.txt",&cle[0]);



        switch(option)
        {
            case 1:
            cryptage(&cle[0],&txt[0],&resultat[0]);
            printf("resultat encrypte : %s",resultat);
            break;

            case 2:
            cryptage(&cle[0],&txt[0],&resultat[0]);
            decryptage(&cle[0],&resultat[0],&resultat2[0]);
            printf("resultat decryptee : %s",resultat2);
            break;

            case 3:
            cryptage(&cle[0],&txt[0],&resultat[0]);
            decryptage(&cle[0],&resultat[0],&resultat2[0]);
            ptT=&txt[0][0];
            for (int i=0;i<strlen(txt);i++,ptT)
            {
                printf("Original : %d puis encrypte : %d puis decrypte : %d\n",*ptT,resultat[i],resultat2[i]);
            }
            ptT=&txt[0][0];
            break;

            default:
            printf("Erreur veuillez recommencer");
            break;
        }
    printf("\n\nContinue ? (o/n) " );
    fflush(stdin);
    scanf("%c",&c);
    i++;
    }while(c == 'o' || c == 'O');


    return 0;
}

void cryptage(unsigned char *ptC, unsigned char *ptD, unsigned char *ptR)
{
    unsigned char *pC=NULL;
    unsigned char *pD=NULL;
    unsigned char *pR=NULL;
    for(pC=ptC,pD=ptD,pR=ptR;*pD!='\0';pD++,pC++,pR++)
    {
        if (*pC=='\0')pC=ptC;
        *pR=*pD - *pC;
    }


}


void decryptage(unsigned char *ptC, unsigned char *ptD, unsigned char *ptR)
{


    unsigned char *pC=NULL;
    unsigned char *pD=NULL;
    unsigned char *pR=NULL;
    for(pC=ptC,pD=ptD,pR=ptR;*pD!='\0';pD++,pC++,pR++)
    {
        if (*pC=='\0')pC=ptC;
        *pR=*pD + *pC;
    }

}

void lecture(const char* fileN, const char *txt)
{
    FILE *fp;
    unsigned char *cpT=NULL;
    unsigned char chaine[2000]="";
    cpT=txt;
    fp=fopen(fileN,"r");
    if (fp == NULL)
    {
        printf("Err Open !");
    }
    while (fgets(chaine,2000,fp) != NULL)
    {
        for(int i=0;i<strlen(chaine);i++,cpT++)
        {
            *cpT=chaine[i];
        }
    }
    fclose(fp);
}



