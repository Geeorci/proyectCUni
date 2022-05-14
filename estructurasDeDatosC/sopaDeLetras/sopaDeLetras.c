#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct letra
{
    struct letra *R, *L, *Up, *Dn;
    char letra;
    int x, y;
};
int i=0, j=0;

char caracter_aleatorio(){
    char letras[] = "abcdefghijklmnsropqtuvwxyz"; int numeroAleatorio, numeroAleatorioAcotado;
    srand(time(NULL));
    numeroAleatorio = rand();
    numeroAleatorioAcotado = numeroAleatorio % 26;
    char caracter = letras[numeroAleatorioAcotado];
    return caracter;
   
}

struct letra* creaNodo(){
    struct letra *new = (struct letra*)malloc(sizeof(struct letra)); new->L=NULL; new->R=NULL; new->Up=NULL; new->Dn=NULL;
    return new;    
}


struct letra* renglon ( int nivel, int limR ){
    struct letra *primRenglon = NULL, *aux = NULL;
    int i = 0;
    while ( i < limR){
    struct letra *new = creaNodo(); new->letra = caracter_aleatorio(); new->x = i; new->y = nivel;
        if( !primRenglon ) { primRenglon = new; aux = primRenglon; }
        else{
            aux->R = new; new->L = aux; aux = new;
        }
        i++;
    }
    return primRenglon;    
}

struct letra* ultimo(struct letra *last){
    if(!last->Dn) return last;
    else{
        ultimo(last->Dn);
    } 
}

struct letra* creaSopa ( struct letra* primDeRenglon, struct letra* sigRenglon ){
    struct letra *aux = primDeRenglon; int i = 0;
 if ( !primDeRenglon->Dn )    
   while ( aux ){
       aux->Dn = sigRenglon;
       sigRenglon->Up = aux;
   aux = aux->R;
   }
 else{
     aux = ultimo(aux);
     while ( aux ){
       aux->Dn = sigRenglon;
       sigRenglon->Up = aux;
     aux = aux->R;
     }
 }  
return primDeRenglon;
}     

/*void imprimir (struct letra* prim ){
        struct letra *aux = prim;
        while ( aux ){
            printf("%c\t",aux->letra);
        aux = aux->R;
        }
        printf("\n\n");
}*/

void printSopa(struct letra *inicio){
    struct letra *copia = inicio;
    struct letra *aux;
    for( copia; copia; copia = copia->Dn){
        for( aux = copia; aux; aux = aux->R )
            printf("%c\t",aux->letra);
        printf("\n\n");        
    }  
}

char direc(struct letra *l, char letra){
    if(l->L && c->L->letra == letra) return 'l';
    if(l->R && c->R->letra == letra) return 'r';
    if(l->Up && c->Up->letra == letra) return 'u';
    if(l->Dn && c->Dn->letra == letra) return 'd';
}

struct letra* camino(struct letra *c, char direc, int sizePalabra){
    if( direc == l)
        if(c->letra == )
} 

void explorador(struct letra *inicio, char *palabra){
    struct letra *copia = inicio;
    struct letra *aux, *aux2;
    char auxcar;
    char *cpyp = palabra;
    char caracter = *palabra;
    for( copia; copia; copia = copia->Dn){
        for( aux = copia; aux; aux = aux->R ){
            // printf("%d,%d\t",aux->x,aux->y);
            auxcar = *cpyp;
            if(auxcar == aux->letra){ 
                // printf("Encontre la letra: %c, en x: %d, y: %d\n",caracter, aux->x, aux->y);
                 cpyp++; auxcar = *cpyp;
                 char direccion = direc( aux, auxcar);
                 switch (direeccion)
                 {
                 case 'l':
                 camino();
                 }
            }
        }    
        printf("\n\n");        
    }
}

int main(){
    int tam = 5;
    char *palabra = "hola";
    struct letra *vec[tam];
    int i = 0;
    struct letra *priSop = NULL;
    while ( i < tam)
    {
        vec[i] = renglon(i,tam);
        if( i > 0) priSop = creaSopa(vec[0], vec[i]);
    i++;    
    }
    struct letra *aux = priSop;
    printSopa(aux);
    aux = priSop;
    explorador(aux, palabra);
    return 0;
}