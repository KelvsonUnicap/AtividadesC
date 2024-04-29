#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 60

void display(char frase[]){
    for(int i = 0 ; i < strlen(frase); i ++){
        printf("%c", frase[i]);
    }
}

int len(char text[]){
    int tamanho_sem_espaco = 0;
    for(int i = 0; i<strlen(text); i++){
        if(text[i] == ' '){
            continue;
        }
        tamanho_sem_espaco++;
    }
    
    return tamanho_sem_espaco;
}

int check_palindromo(char frase[]){
    int tamanho_sem_espacos = len(frase);
    char primitiva_sem_espaco[tamanho_sem_espacos], copia[tamanho_sem_espacos];

    for(int i = 0 , j= 0; i < strlen(frase); i++){
        if(frase[i] == ' '){ continue; }
        primitiva_sem_espaco[j] = frase[i];
        j++;
    }

    for(int i = 0, j=0; i<=tamanho_sem_espacos; i++){
        copia[j] = primitiva_sem_espaco[tamanho_sem_espacos - i];
        j++;
    }

    display(primitiva_sem_espaco);
}

void main(){

    char frase[MAX];

    fgets(frase, 59, stdin);

    check_palindromo(frase);
}