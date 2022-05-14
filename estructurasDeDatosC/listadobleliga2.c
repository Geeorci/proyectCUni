#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *pre, *next;    
};

struct node *firts;

int data[] = {300, 2, 17, 183, 25, 1};

int save(int num){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    struct node *aux = firts;
    new->next = new->pre = NULL;
    new->num = num;

     //AÑADIR UN NUEVO NODO
    if( firts )
    { //caundo ya hay almenos un nodo.
        while ( num > aux->num )
        {
            if( aux->next ) aux = aux->next;
            else break;
        }
        if( aux->pre == NULL  ) {   //El dato es menor  que aux y ademas lo comparamos con el PRIMERO.
                new -> next = firts;
                firts -> pre = new;
                firts = new;
                
        }
        else     
            if(aux -> next == NULL) 
            {//cuando el dato es el mas grande lo colocamos detras del ULTIMO. 
                new->pre = aux;
                aux->next = new;
            }
        else
                {
                    new->next = aux;
                    aux -> pre -> next = new;
                    new -> pre = aux -> pre;
                    aux -> pre = new; 
                }        
    }
    else
        firts = new;

}

void start(){
    int i, size = sizeof(data) / sizeof(int); 
    for( i=0; i < size; i++ ) save(data[i]);

   
}

void show()
{
    struct node *aux = firts;
    while(aux){
    printf("%d\n", aux->num);
    aux = aux->next;
    }
}



int main(){
    firts = NULL; start(); show();
}