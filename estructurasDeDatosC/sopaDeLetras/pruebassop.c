#include <stdio.h>

struct nodo{
    struct nodo *sig;
    int dato;
};

struct nodo* prueba(struct nodo* c, int i){
    if( i == 1) return  c->sig;
}



int main(){
    char *palabra = "hola";
    char *cpyp = palabra;
    cpyp++;
    char caracter = *cpyp;
    printf("%c\n",caracter);
    printf("%c\n",*palabra);
    
    return 0;
}