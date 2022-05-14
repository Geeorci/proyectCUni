#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *sig, *ant;
    char *cadena;
};

struct node *primera = NULL;

char *cadenas[] = { "raton","teclado","monitor","CPU"};

int size = sizeof(cadenas)/sizeof(int);

void guardar(char *cad)
{
    struct node *nueva = (struct node*)malloc(sizeof(struct node));
    nueva -> cadena = (char*)malloc(sizeof(char)*80);
    struct node *aux = primera;
    strcpy(nueva -> cadena, cad);
    nueva -> sig = nueva -> ant = NULL;

    if ( primera ) 
    {   
        printf("llego: %s y estaba: %s\n", cad, aux ->cadena);
        int decision = strcmp(cad, aux -> cadena );
        printf("decision = %d\n", decision);
        while( decision > 0){
            if( aux -> sig) aux = aux -> sig;
            else break;
        }
        
        if ( aux->sig == NULL ) {	// ES EL ULTIMO
        printf("entre como el ultimo.\n");
						nueva->ant = aux;
						aux->sig = nueva;
					}        
        else
			if (aux->ant == NULL )	// ES EL PRIMERO
					{
						nueva->sig = primera;
						primera->ant = nueva;
						primera = nueva;
					}
            else
            {
                nueva->sig = aux;
                aux->ant->sig = nueva;
                nueva->ant = aux->ant;
                aux->ant = nueva;
            }        
    }
        else{
            //printf("Y la primera cadena fue: %s .\n", nueva -> cadena);
            primera = nueva;
		}               
}

void mostrar()
{
    struct node *aux = primera;
      while( aux ) 
      {
          printf("%s\n", aux -> cadena);
          aux = aux -> sig;
      }

}
int main()
{
    int i;
    for(i = 0; i < size; i++ )
    guardar(cadenas[i]);
    mostrar();
}