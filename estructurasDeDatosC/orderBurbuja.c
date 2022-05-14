#include <stdio.h>

int main (){
    int lista[10] ={60, 11, 2, 331, 42, 576, 86, 71, 8, 1029};
    int i, j, AUX;
    for( i= 0; i<10; i++){
        for( j = 0; j < 10; j++){
            if( lista[j] > lista[j+1] ){
                AUX = lista[j+1];
                lista[j+1] = lista[j];
                lista[j] = AUX;
            }
        }       
    }
    i = 0;
    while(i < 10){
        printf("%d\t", lista[i]);
        i++;
    }
    return 0;
}