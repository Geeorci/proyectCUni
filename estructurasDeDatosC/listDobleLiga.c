// DADA UNA LISTA DE NUMEROS, SE ORDENAN USANDO UNA LISTA
// DOBLEMENTE LIGADA

#include <stdio.h>
#include <stdlib.h>




struct nodo
{
	int num;
	struct nodo *sig, *ant;
};

struct nodo *start = NULL;

int datos[]= {73, 5, 5, 8, 80, 92, 56, 1, 7};


void guardar(int num)
{
	struct nodo *new = (struct nodo*)malloc(sizeof(struct nodo));
	struct nodo *aux = start;
	new->sig = new->ant = NULL;
	new->num = num;

	// COLOCARLO
	if ( start )
	{
		while( num > aux->num )
		{
			if ( aux->sig ){
				aux = aux->sig;
				
			}	
			else break;
		}
		if ( aux->sig == NULL ) {	// ES EL ULTIMO
						new->ant = aux;
						aux->sig = new;
					}
		else
			if (aux->ant == NULL )	// ES EL PRIMERO
					{
						new->sig = start;
						start->ant = new;
						start = new;
					}
		else
		{
			new->sig = aux;
			aux->ant->sig = new;
			new->ant = aux->ant;
			aux->ant = new;
		}
	}
	else
		start = new;
}

void inicio()
{
	int k=0;
	int n = sizeof(datos) / sizeof(int);
	for (k=0; k<n; k++)
		guardar(datos[k]);
}

void mostrar()
{
	struct nodo *aux = start;
	while (aux)
	{
		printf("%d\n", aux->num);
		aux = aux->sig;
	}
}

int main() { start = NULL; inicio(); mostrar(); }
 