
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char caracter;
char res[10];
int i = 0; 
struct pila{
    struct pila *sig;
    char dato;
};
struct pila *top = NULL;

int prioridad(char operador){
    if(operador == ')' )  return -1;
    if(operador == '(')   return 0;
    if(operador == '+' || operador == '-') return 1;
    if(operador == '*' || operador == '/') return 2;
    if(operador == '^') return 3;
}

int operando(char caracter){
    char *operandos ="1234567890.";
    if(strchr(operandos, caracter)) return 1;
    else return 0;
}
void pop(int indice){
  while( top ){
    if(top->dato =='('){ break;}
    else{
      res[indice] = top->dato;
      top = top->sig;
      break;
    }  
  }
}                                                                 

void infijo_posfijo(char *cad){
    while( strlen(cad) > 0){
        caracter = *cad;
        if(operando(caracter)){                                             
          res[i] = caracter;
          i++;
        }
        else{
        struct pila *nuevo = (struct pila*)malloc(sizeof(struct pila));     nuevo ->sig = NULL;     nuevo -> dato = caracter;
            if(top == NULL) top = nuevo; 
            else{
                switch (prioridad(nuevo->dato))
                {
                  case -1:
                    pop(i);
                    top =  top->sig;
                    i++;
                    break;
                  
                  case 0:
                    nuevo->sig = top;
                    top =nuevo;
                    break;
                  case 1:
                    if(prioridad(nuevo->dato) <= prioridad(top->dato) && top->dato != '(' ){pop(i); i++; nuevo->sig = top; top = nuevo;}
                    else {nuevo->sig = top; top = nuevo;}
                    break;
                  case 2:
                    if(prioridad(nuevo->dato) <= prioridad(top->dato) && top->dato != '(' ){pop(i); i++; nuevo->sig = top; top = nuevo;}
                    else {nuevo->sig = top; top = nuevo;}
                    break;
                  case 3:
                    if(prioridad(nuevo->dato) <= prioridad(top->dato) && top->dato != '(' ){pop(i); i++; nuevo->sig = top; top = nuevo;}
                    else {nuevo->sig = top; top = nuevo;}       
                }
            }
        }
        cad++;
        
        if(strlen(cad) == 0 )
        while( top ){
            if(top->dato =='('){top =  top->sig;}
            else{
              res[i] = top->dato;
              top = top->sig;
              i++;
            }
        }    
    
    }    
    
}
int main(){
    char *expresion =/* "2^2*5-1+7/4/(9+0)";*/  /*"4*2+(12/3)-5";*/  /*"((23+32)+5.30-(3.5-7.7))^(86.07+6.0)";*/ "10+(1+2)*2";
    infijo_posfijo(expresion);
    printf("%s\n", res);
}