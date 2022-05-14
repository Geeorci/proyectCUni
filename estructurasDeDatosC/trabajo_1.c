#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *sig, *ant;
    char *cadena;
};

struct node *primera = NULL;

char *cadenas[] = {"monitor","raton","teclado","cpu","dinero","hola"};

int size = sizeof(cadenas)/sizeof(int);

void guardar(char *cad)
{
    struct node *nueva = (struct node*)malloc(sizeof(struct node));
    nueva -> cadena = (char*)malloc(sizeof(char)*10);
    struct node *aux = primera;
    strcpy(nueva -> cadena, cad);
    nueva -> sig = nueva -> ant = NULL;

    if(primera){ 
            int decision = strcmp(cad, aux -> cadena ); //Con esta linea comparamos las dos cadenas Primera y cad(parametro de guardar)
            while( decision > 0){                       //alfabeticamente. 
                if( aux -> sig){
                    aux = aux -> sig;
                    decision = strcmp(cad, aux -> cadena);
                }
                else break;
            }
            if ( aux->sig == NULL ){    // poner el nuevo nodo despues del ultimo, pasando a ser este el ultimo.
                            nueva->ant = aux;
                            aux->sig = nueva;
            }        
            else
                if (aux->ant == NULL ){   //cuando la cadena de este nodo es menor que la del primer nodo, entonces..
                            nueva->sig = primera; //se vuelve el primer nodo.
                            primera->ant = nueva;
                            primera = nueva;
                }
                else{                       // cuando ingresamos un nodo en medio de otros dos.
                    nueva->sig = aux;
                    aux->ant->sig = nueva;
                    nueva->ant = aux->ant;
                    aux->ant = nueva;
                }    
    }else
        primera = nueva;
}

void mostrar()
{
    int posicion = 1;
    struct node *aux = primera;
      while( aux ) 
      {
          printf("%d.- %s\n",posicion , aux -> cadena);
          aux = aux -> sig;
          posicion ++;
      }

}
int main()
{
    //printf("%d\n", size);
    int i;
    for(i = 0; i < size; i++ )
    guardar(cadenas[i]);
    mostrar();
}