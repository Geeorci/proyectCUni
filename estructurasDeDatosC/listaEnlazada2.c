#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Función para definir nuestro nodo...
typedef struct{
    struct node *next;
    char* data;
} node;

node *firts = NULL;
node *last = NULL;

//Ahora hacemos uso de esa definición y lo construimos.
node *maker(){
    return (node*)malloc(sizeof(node));
}

//La primera funcion para nuestra lista será la de guardar un nodo.
void save(char* string){
    node *newNode = maker(), *AUX;  // declaramos dos estructuras node *newNode si la inicializamos pero *AUX no.
    newNode -> data = (char*)malloc(sizeof(node));
    strcpy(newNode -> data, string);
    newNode -> next = NULL;

    if ( !firts ) firts = newNode;	// ¿ERES EL PRIMERO?
	else
	{// newNode->Sig = firts; firts = newNode; // AL PRINCIPIO
		AUX = firts;
		while ( AUX->next ) AUX = AUX->next;
		AUX->next = newNode;
	}
}
int main (){
    return 0;
}