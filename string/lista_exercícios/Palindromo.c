#include <stdio.h>
#include <string.h>
#define MAX 60

int check_palindromo(char frase[]){
    char palindromo[MAX];
    char copia[MAX];

    strcpy(frase,copia);

    for(int i = strlen(frase), j = 0; i>=0; i--){
        if(frase[i] == ' '){ continue; }
        else{
            palindromo[j++] = frase[i]; 
        }
    }

    for(int i = 0 ; i<=strlen(frase); i ++){
        printf("%c", copia[i]);
    }
}

void main(){

    char frase[MAX];

    fgets(frase, 59, stdin);

    check_palindromo(frase);
}