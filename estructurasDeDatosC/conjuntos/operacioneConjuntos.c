#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int N;
	struct nodo *sig;
};

struct nodo *L1, *L2, *LR;


int N1[] = {7, 8, 3, 24, 6, 12, 9, 10, 5};
int N2[] = {24, 3, 5, 11};

struct nodo* Guarda(struct nodo *L, int dato)
{
	struct nodo *new = (struct nodo*)malloc(sizeof(struct nodo));
	new->N = dato; new->sig = NULL;

	if ( !L ) L = new; 
	else
	{
		new->sig = L; L = new;
	}
	return L;
}

void Muestra(struct nodo *L2)
{
	if(!L2)printf("Este conjuto no tienen elementos.\n");
	while(L2)
	{
		printf("%d   ", L2->N);
		L2 = L2->sig;
	}
    printf("\n");
	
}


struct nodo* Interseccion(struct nodo *L1, struct nodo *L2) // INTERSECCION---------------------------------
{
	struct nodo *L = L2;
	while(L1)
	{
		L2 = L;
		while(L2)
		{
			if (L1->N == L2->N) LR = Guarda(LR, L1->N);
			L2 = L2->sig;
		}
		L1 = L1->sig;
	}
	return LR;
}

struct nodo* resta( struct nodo *Minuendo, struct nodo *sustraendo ){ //RESTA-------------------------------
    struct nodo *aux = sustraendo;
    int desicion;
    while(Minuendo){
        aux = sustraendo;
        while (aux){
            if( Minuendo->N != aux->N) desicion = 0;
            else{  desicion = 1; break; }
        aux = aux->sig;
        }
        if(desicion == 0){ LR = Guarda( LR, Minuendo->N );}
    Minuendo = Minuendo->sig;    
    }
return LR;
}


void inicio()
{
	int i=0, Tam = sizeof(N1) / sizeof(int);

	for (i = 0; i<Tam; i++) L1 = Guarda(L1, N1[i]);
	Tam = sizeof(N2) / sizeof(int);
	for (i = 0; i<Tam; i++) L2 = Guarda(L2, N2[i]);

	LR = Interseccion(L1, L2);
	printf("Interseccion:  ");Muestra(LR);
    LR = NULL;
    LR = resta( L1, L2 );
    printf("Resta:  ");Muestra(LR);
}

int main(int k, char **a) { L1 = L2 = LR = NULL; inicio(); }