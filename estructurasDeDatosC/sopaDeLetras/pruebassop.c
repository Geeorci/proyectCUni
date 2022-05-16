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