#include <stdio.h>
#include <stdlib.h>

struct nodoPila
{
	struct nodoPila *sig;
	int num;
};

struct nodoPila *start = NULL;

int datos[] = {7, 6, 17, 21, 3};
int k = 0;
int n = sizeof(datos) / sizeof(int);

void push(int n)
{
	struct nodoPila *nuevo = (struct nodoPila*)malloc(sizeof(struct nodoPila));
	nuevo ->sig = NULL;
	nuevo ->num = n;
	
	
	if(start == NULL) start = nuevo;
	else{
	   nuevo->sig = start;
	   start = nuevo;
	}
	
}
 
void pop(){ 
while( start ){
    printf("%i\n", start->num);
    start = start -> sig;
}
}

int main ()
{
	int r;
for (k = 0; k < n; k++)
      push(datos[k]);
      pop();

} 