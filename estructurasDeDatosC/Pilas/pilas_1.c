#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct nodoPila{
    struct nodoPila *sig;
    char caracter;
};
struct nodoPila *tope = NULL;
char *exprecion = "2A+3B1";
char resultado[10];
char *operadores = "*/+-^";
char symb;
int k = 0, i = 0;

bool esOperando(char car){
    char *nums = "1234567890";
    if(strchr(nums,car)) return true;
    else return false;
}

void inf_Pos(char *cad){
    while(strlen(cad) > k){
        symb = cad[k];
        printf("llego:%c\t",symb);
        if( esOperando(symb) ) resultado[i] = symb;
         i++;
         cad++;   
    }
    //printf("%s\n",resultado);
}


int main(){
    inf_Pos(exprecion);
    printf("\t%c\t",resultado[1]);
}   