#include <stdio.h>
#include <string.h>

#define MAX 80

void codificar(char *parr, int t){
    static const char vogais[] = "aeiouAEIOU";
    for(int i = 0; i < t; i++){
        for(int k = 0; k < strlen(vogais) ; k++){
            if(parr[i] == vogais[k]){
                parr[i] = '*';
            }
        }
    }
}

void display(char parr[], int t){
    for(int i = 0; i<t; i++){
        printf("%c", parr[i]);
    }
}

void main(){
    char frase[MAX];
    fgets(frase, MAX-1, stdin);
    int t = strlen(frase);

    codificar(frase, t);
    display(frase, t);
}