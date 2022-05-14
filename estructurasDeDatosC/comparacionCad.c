#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct comp
{
    struct comp *sig, *ant;
    char *dato;
};

char *cadenas[] = { "raton","teclado","monitor","CPU"};

void guardar(){
struct comp *inicio = NULL;
struct comp *primera = (struct comp*)malloc(sizeof(struct comp));
struct comp *segunda = (struct comp*)malloc(sizeof(struct comp));


primera -> dato = "monitor";
segunda -> dato = cadenas[1];


int des = strcmp(primera ->dato, cadenas[1]);

        if( des == 1)
        printf("%s es mayor que %s.\n",primera -> dato, segunda -> dato);
        if( des == 0)
        printf("%s es igual que %s.\n",primera -> dato, segunda -> dato);
        if( des == -1)
        printf("%s es menor que %s.\n",primera -> dato, segunda -> dato);


} 

int main ()
{  
    guardar();
    return 0;

}