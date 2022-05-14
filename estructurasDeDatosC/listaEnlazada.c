#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo
{
	char *Dato;
	struct Nodo *Sig;
};

struct Nodo *Inicio = NULL;

struct Nodo *CreaNodo() { return (struct Nodo*)malloc(sizeof(struct Nodo)); }


void Guardar(char *cad)
{
	cad++;cad++;
	struct Nodo *newNodo = CreaNodo(), *AUX;
	newNodo->Dato = (char*)malloc(sizeof(char)*80);
	strcpy(newNodo->Dato, cad);
	newNodo->Sig = NULL;

	if ( !Inicio ) Inicio = newNodo;
	else
	{
		AUX = Inicio;
		while ( AUX->Sig ) AUX = AUX->Sig;
		AUX->Sig = newNodo;
	}
}



void Mostrar()
{
	struct Nodo *AUX = Inicio;

	while ( AUX )
	{
		printf("%s\n", AUX->Dato);
		AUX = AUX->Sig;
	}
}

/*
int Mostrar(struct Nodo *aux)
{
	if ( !aux->Sig ) return 1;
	Mostrar( aux = aux->Sig );
	printf("%s\n", aux->Dato);
}
*/

int Buscar(char *cad)
{
	struct Nodo *aux = Inicio;
	cad++; cad++; cad++;
	while( aux )
	{
		if ( !strcmp(cad, aux->Dato) ) return 1;
		aux = aux->Sig;
	}
	return 0;
}

void Borrar(char *cad) {
	//printf("0paso");
	struct Nodo *aux, *aux2;

	aux = aux2 = Inicio;
	cad++; cad++; cad++;
	while(aux){
		if(!strcmp(cad,aux->Dato))
		{
			// ¿Eres el primero?
			if ( aux == Inicio ) Inicio = Inicio->Sig;
			// eres el último??
			else if ( !aux->Sig ) aux2->Sig = NULL;
				else	// entonces está en medio
					aux2->Sig = aux->Sig;
		}
		aux2 = aux;
		aux = aux->Sig;
	}
	

}

int ciclo()
{
	char *Operacion = (char*)malloc(sizeof(char)*80);
	while ( 1 )
	{
		printf("G cad\tBO cad\tBU cad\tM\tS\n");
		printf("==> "); gets(Operacion);
		if ( Operacion[0] == 'S' ) return 1;

		switch(Operacion[0])
		{
			case 'G':	Guardar(Operacion); break;
			case 'B':	if (Operacion[1] == 'O') Borrar(Operacion);
					else if (Buscar(Operacion) ) printf("Si lo encontré ...\n");
					break;

			case 'M':	Mostrar(); //Mostrar(Inicio); printf("%s\n", Inicio->Dato);

		}
	}
}


main() { ciclo(); }