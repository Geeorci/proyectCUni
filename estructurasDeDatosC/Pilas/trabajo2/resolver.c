#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct pila{
    struct pila *sig;
    char dato;
    float numero;
};
struct pila *top = NULL;

char *cadena ="4.5 2.1*12.6 3.17/+9-";
char caracter, num[10];
int i = 0; float digito = 0;

float operacion(float a, float b, char signo){
    if(signo == '+') return a+b;
    if(signo == '-') return a-b;
    if(signo == '*') return a*b;
    if(signo == '/') return a/b;
    if(signo == '&') return pow(a,b);
}

int eres(char caracter){
  char *operadores ="+-*/&";
  char *numeros ="0123456789.";
  char espacio =' ';
  if(strchr(numeros, caracter)) return 1;
  if(strchr(operadores, caracter)) return 2;
  if(espacio == caracter) return 3;
}

void ctof(char *cad){
    while(strlen(cad) > 0)
    {
        caracter = *cad;  
        switch (eres(caracter))
        {
        case 1:
            num[i] = caracter; i++;
            break;
        
        case 2:
            if(num[0] != '\0'){
                digito = atof(num); memset(num, 0, 10); i=0;
                struct pila *nuevo = (struct pila*)malloc(sizeof(struct pila)); nuevo->sig = NULL; nuevo->numero = digito;
                if( top == NULL ) top = nuevo; else{ nuevo->sig = top; top = nuevo;}
                float resparcial, resultado = 0;  resparcial = top->numero;  top = top->sig; 
                 resultado = operacion(top->numero,resparcial,caracter); 
                top->numero = resultado;
            }else{
                float resparcial, resultado = 0;  resparcial = top->numero;  top = top->sig; 
                resultado = operacion(top->numero,resparcial,caracter); 
                top->numero = resultado;
            }
            break;
        case 3:
            if(num[0] != '\0'){
                digito = atof(num); memset(num, 0, 10); i=0;
                struct pila *nuevo = (struct pila*)malloc(sizeof(struct pila)); nuevo->sig = NULL; nuevo->numero = digito;
                    if( top == NULL ) {top = nuevo;} else{ nuevo->sig = top; top = nuevo;}
            }
            break;
        }
    cad++;
    }
    printf("La solucion a tu expresion es:%.2f\n",top->numero);
}
int main (){
ctof(cadena); 
}