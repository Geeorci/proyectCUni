#include <stdio.h>
#include <stdlib.h>

struct nodoArb{
    struct nodoArb *rai, *izq, *Der;
    int num;
};
struct nodoArb *raiz = NULL;



void save(struct nodoArb *new, struct nodoArb *Raiz){
    if(Raiz->num > new->num)
        if( Raiz->izq ) {
            Raiz = Raiz->izq;
            save(new, Raiz);
        }
        else{
            Raiz->izq = new;
            new->rai = Raiz;
        }
    else{ 
        if(Raiz->Der){
            Raiz = Raiz->Der;
            save(new, Raiz);
        }
        else{
            Raiz->Der = new;
            new->rai = Raiz;
        } 
    }   
}

struct nodoArb creaNdo(int k){ //definimos y reservamos memoria para un nuevo nodo del arbol.
    struct nodoArb *new = (struct nodoArb*)malloc(sizeof(struct nodoArb));
    new->izq = new->Der = new->rai = NULL;
    new->num = k;
    if(!raiz) raiz = new;//si este no tiene un nodo previo entonces lo creamos y lo asignamos como la raiz.
    else{
        save(new, raiz);//si ya hay una raiz o nodos previos entonces solo guardamos uno nuevo en donde corresponda.(segun la funcion guardar)
    } 
}

void preorden(struct nodoArb *arbol){
    if(arbol) printf("%d, ",arbol->num);
    if(arbol->izq) preorden(arbol->izq);
    if(arbol->Der) preorden(arbol->Der);        
}
void inorden(struct nodoArb *arbol){
    if(arbol->izq) inorden(arbol->izq);
    if(arbol) printf("%d, ",arbol->num);
    if(arbol->Der) inorden(arbol->Der);        
}

void posorden(struct nodoArb *arbol){
    if(arbol->izq) posorden(arbol->izq);
    if(arbol->Der) posorden(arbol->Der);  
    if(arbol) printf("%d, ",arbol->num);
}

void podar(struct nodoArb *arbol){
    if(arbol->izq) podar(arbol->izq);
     if(arbol){
            if(arbol->Der == NULL && arbol->izq == NULL )
                if(arbol->num > arbol->rai->num)
                    arbol->Der == NULL;
                else
                    arbol->izq == NULL;
     }                
    if(arbol->Der) podar(arbol->Der);                

}
int main(){
    int v[5]={7,0,1,500,18};
    for(int i = 0; i < 5; i++){
        creaNdo(v[i]);
    }
    preorden(raiz);
    printf("\n");
    inorden(raiz);
    printf("\n");
    posorden(raiz);
    printf("\n");
    podar(raiz);
    inorden(raiz);
    return 0;
}