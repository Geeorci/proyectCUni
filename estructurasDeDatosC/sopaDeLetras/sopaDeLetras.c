#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct letra
{
    struct letra *R, *L, *Up, *Dn;
    char letra;
    int x, y;
};
int i=0, j=0;
char c[1000];
void caracterAleatorio(   int x   ){
    int numAle, numAleAco;
    char letras[] = "abcdefghijklmnsropqtuvwxyz";
    srand(time(NULL));
    for(i = 0; i<x; i++){
        numAle = rand();
        numAleAco = numAle%26;
        c[i] = letras[numAleAco];  
    }
}

struct letra* creaNodo(){
    struct letra *new = (struct letra*)malloc(sizeof(struct letra)); new->L=NULL; new->R=NULL; new->Up=NULL; new->Dn=NULL;
    return new;    
}

int  k=0;
struct letra* renglon ( int nivel, int limR ){
    struct letra *primRenglon = NULL, *aux = NULL;
    int i = 0;
    while ( i < limR){
    struct letra *new = creaNodo(); new->letra = c[k]; new->x = i; new->y = nivel;
        if( !primRenglon ) { primRenglon = new; aux = primRenglon; }
        else{
            aux->R = new; new->L = aux; aux = new;
        }
        i++;
        k++;
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
    struct letra *aux = primDeRenglon; //int i = 0;
 if ( !primDeRenglon->Dn )    
   while ( aux ){
       aux->Dn = sigRenglon;
       sigRenglon->Up = aux;
       sigRenglon = sigRenglon->R;
   aux = aux->R;
   }
 else{
     aux = ultimo(aux);
     while ( aux ){
       aux->Dn = sigRenglon;
       sigRenglon->Up = aux;
       sigRenglon = sigRenglon->R;
     aux = aux->R;
     }
 }  
return primDeRenglon;
}     

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
    if(l->L && l->L->letra == letra) return 'l';
    if(l->R && l->R->letra == letra) return 'r';
    if(l->Up && l->Up->letra == letra) return 'u';
    if(l->Dn && l->Dn->letra == letra) return 'd';
}

void agrPalabra(struct letra *ini, int x, int y, char *palabra, char direccion){
    struct letra *aux;
    for( ini; ini; ini = ini->Dn){
        for( aux = ini; aux; aux = aux->R )
            if(aux->y == y && aux->x == x){
                switch (direccion)
                {
                case 'l':
                    while(strlen(palabra) > 0){
                        if(strlen(palabra) == 1) aux->letra = *palabra;
                        else{
                            aux->letra = *palabra;
                            aux = aux->L; 
                        }
                     palabra++;       
                    }
                break;
                
                case 'r':
                 while(strlen(palabra) > 0){
                        if(strlen(palabra) == 1) aux->letra = *palabra;
                        else{
                            aux->letra = *palabra;
                            aux = aux->R;
                               
                        }
                     palabra++;       
                    }
                break;

                case 'u':
                    while(strlen(palabra) > 0){
                        if(strlen(palabra) == 1) aux->letra = *palabra;
                        else{
                            aux->letra = *palabra;
                            aux = aux->Up; 
                        }    
                     palabra++;       
                    }
                break;

                case 'd':
                 while(strlen(palabra) > 0){
                        if(strlen(palabra) == 1) aux->letra = *palabra;
                        else{
                            aux->letra = *palabra;
                            aux = aux->Dn; 
                        }
                     palabra++;       
                    }
                break;        
                }  
            }
    }
}


struct letra* camino(struct letra *c, char direc, int sizePalabra, char comparar){
    if( direc == 'l')
        if( c->letra == comparar ) c = c->L;
} 

void explorador(struct letra *inicio, char *palabra){
    struct letra *copia = inicio;
    struct letra *aux, *aux2;
    char auxcar;
    char *cpyp = palabra;
    char caracter = *palabra;
    for( copia; copia; copia = copia->Dn){
        for( aux = copia; aux; aux = aux->R ){
            auxcar = *cpyp;
            if(auxcar == aux->letra){ 
                 cpyp++; auxcar = *cpyp;
                 char direccion = direc( aux, auxcar);
                 switch (direccion)
                 {
                 case 'l':
                    aux2 = camino(aux, direccion, 3, auxcar);
                 }
            }
        }    
        printf("\n\n");        
    }
}

int main(){
    int tam = 15;
    caracterAleatorio((tam*tam));
    char *palabra = "hola";
    struct letra *vec[tam];
    i = 0;
    struct letra *priSop = NULL;
    while ( i < tam)
    {
        vec[i] = renglon(i,tam);
        if( i > 0) priSop = creaSopa(vec[0], vec[i]);
    i++;    
    }
    struct letra *aux = priSop;
    agrPalabra(aux, 1, 0, palabra, 'd');
    aux = priSop;
    printSopa(aux);
    return 0;
}