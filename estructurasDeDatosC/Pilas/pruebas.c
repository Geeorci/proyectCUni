#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(){
    char *cadena = "hola";
    //char *res = malloc(sizeof(char)*10);
    char res[10];
    char caracter;
    int i = 0;
    while( strlen(cadena) > 0){
    
        caracter = *cadena;
        //printf("%c", caracter);
        res[i] = caracter;
        printf("%c",res[i]);
        i++;
        cadena++;
    }

}