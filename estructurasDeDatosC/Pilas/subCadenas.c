//con este programa podemos extraer un caracter o una sub cadena de una cadena ya establecida.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int operando(char *cadena){
    char *operandos = "1234567890";
    if (strcmp(operandos, cadena)) return 1;
    else return 0;
}
int main(){
    int i = 0;
    char posfija[100];
    char *cadena ="1+2";
    while( strlen(cadena) > i ){
    if ( operando(cadena) )//ponlo en la cadena posfija
        sprintf(posfija,"%c\n",cadena[0]);
        cadena++;
        //i++;
    //metelo en la pila
    }
    printf("%s\n",posfija);
    return 0;
}    
    
