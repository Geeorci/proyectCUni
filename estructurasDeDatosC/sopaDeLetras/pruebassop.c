#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int n[1000];
char c[1000];
void numeroAleatorio(   int x   ){
    int numAle;
    int numAleAco;
    // int n[10];
    char letras[] = "abcdefghijklmnsropqtuvwxyz";
    // char *caracter = malloc(sizeof(char)*x+1);
    srand(time(NULL));
    int i;
    for(i = 0; i<x; i++){
        numAle = rand();
        numAleAco = numAle%26;
        // printf("%c\t",caracter[i]);
        // return caracter;
        c[i] = letras[numAleAco];
        printf("%c\t",letras[numAleAco]);
        // n[i] = numAleAco;
       
    }
 printf("\n");
}



int main(){
    // char *c;
    int i;
    numeroAleatorio(10);
    for ( i = 0; i < 10; i++)
        printf("%c\t",c[i]);
    
    return 0;
}

                                    /*if(strlen(p) == 0){ printf("x:%d  y:%d dir:%c\n",x,y,dir); break;}
                                    if(dir == 'l'){ if(aux->L && aux->L->letra == *p) aux=aux->L;}
                                    if(dir == 'r'){ if(aux->R && aux->R->letra == *p) aux=aux->R;}
                                    if(dir == 'u'){ if(aux->Up && aux->Up->letra == *p) aux=aux->Up;}
                                    if(dir == 'd'){ if(aux->Dn && aux->Dn->letra == *p) aux=aux->Dn;} */