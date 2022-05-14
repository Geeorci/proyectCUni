#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct nodo{
    char *cadena;
    struct nodo *sig;
};
struct nodo *primera = NULL;
char *palabras[] = {"manzana","zapote","platano","naranja","pepino","almendra","toronja","pina","arandano","fresa"};
int size = sizeof(palabras)/sizeof(int);
int des, k;
void crearlista(char *cad){
    struct nodo *aux, *new = (struct nodo*)malloc(sizeof(struct nodo));
    new -> cadena = (char*)malloc(sizeof(char)*20);
    strcpy(new -> cadena, cad);
    new ->sig = NULL;

    if( primera ){
        aux = primera;
        while( aux -> sig ) aux = aux ->sig;
        aux -> sig = new;
    }
    else primera = new;
}
void ordBurbuja(){
    struct nodo *aux = primera, *aux1, *aux2, *aux3;
    for(aux1 = primera; aux1; aux1 = aux1->sig )
        for(aux2 = primera; aux2; aux2 = aux2->sig){
            aux3 = aux2->sig;
            if ( !aux3 ) break;
            des = strcmp(aux2->cadena, aux3->cadena);
            if(des > 0){     
                strcpy( aux->cadena , aux2->cadena );
                strcpy( aux2->cadena , aux3->cadena );
                strcpy( aux3->cadena , aux->cadena );
            }    
        }        
}
void mostrar(){
    struct nodo *aux = primera ->sig;
    for(aux; aux; aux = aux->sig) printf("%s\n",aux->cadena);        
}
int main(){  
    for(k = 0; k < size; k++) crearlista(palabras[k]);
    ordBurbuja(); mostrar(); return 0;        
}
