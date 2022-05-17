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

void agrPalabra(struct letra *ini, int x, int y, char *palabra, char dir){
    struct letra *aux;
    for( ini; ini; ini = ini->Dn){
        for( aux = ini; aux; aux = aux->R )
            if(aux->y == y && aux->x == x){
                switch (dir)
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

char direc(struct letra *l, char *letra){
    struct letra *aux = l; char *p = letra;
    p++;
        if(aux->L && aux->L->letra == *p) return 'l';   
        if(aux->R && aux->R->letra == *p) return 'r';
        if(aux->Up && aux->Up->letra == *p) return 'u';
        if(aux->Dn && aux->Dn->letra == *p) return 'd';
}

void donde(struct letra *e, char *letra){
    char dir; char *p = letra;
    dir = direc(e, p); int x,y; x=e->x; y=e->y;
    p = letra; int z=0;
    while(e->letra == *p){
        p++; z = strlen(p);
        if(dir == 'l'){ if(e->L && e->L->letra == *p) e=e->L;}
        if(dir == 'r'){ if(e->R && e->R->letra == *p) e=e->R;}
        if(dir == 'u'){ if(e->Up && e->Up->letra == *p) e=e->Up;}
        if(dir == 'd'){ if(e->Dn && e->Dn->letra == *p) e=e->Dn;}
    }
    if(z == 0) printf("esta en x:%d y:%d direccion:%c\n", x, y, dir);
}


void camino(struct letra *c, char *letra){
    struct letra *v[1000]; int k=0; int i = 0; int j = 0;
    struct letra *aux; char *p =letra;
    for(c;c;c=c->Dn){
        for(aux = c;aux; aux = aux->R) if(aux->letra == *letra) {
            v[i] = aux;
            i++; k++;
        }
    }

    while(j < k){
        p=letra;
        donde(v[j],p);
        j++;
    }
}



int main(){
    int tam = 13;
    caracterAleatorio((tam*tam));
    char *palabra = "hola", *cpy1 = palabra, *palabra2 = "mundo", *cpy2 = palabra2, *palabra3 = "estructura", *cpy3 = palabra3, *palabra4="datos", *cpy4 = palabra4;
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
    agrPalabra(aux, 0, 0, palabra, 'd'); aux = priSop;
    agrPalabra(aux, 9, 2, palabra2, 'l'); aux = priSop;
    agrPalabra(aux, 0, 10, palabra3, 'r'); aux = priSop;
    agrPalabra(aux, 6, 8, palabra4, 'd'); aux = priSop;
    printSopa(aux);
    aux = priSop;
    printf("'%s' ",palabra); camino(aux, cpy1);
    aux = priSop;
    printf("'%s' ",palabra2); camino(aux, cpy2);
    aux = priSop;
    printf("'%s' ",palabra3); camino(aux, cpy3);
    aux = priSop;
    printf("'%s' ",palabra4); camino(aux, cpy4);

    return 0;
}