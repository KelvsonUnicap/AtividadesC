/*
Faça um programa para ler uma frase de, no máximo, 100 caracteres.
O programa deve calcular e exibir quantas letras, quantos dígitos e quantos símbolos aparecem na frase.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


int conta_letra(char *string, char letra){
    int count_l = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == letra) count_l++;
    }
    return count_l;
}

int conta_numero(char *string, char numero){
    int count_n = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == numero) count_n++;
    }
    return count_n;
}

int conta_simbolo(char *string, char simbolo){
    int count_s = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == simbolo) count_s++;
    }
    return count_s;
}

int main(){

    char string[MAX];
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';

    char letra, numero, simbolo;

    /*continua...*/

    printf("letra: %d\n", conta_letra(string, letra));
    printf("numero: %d\n", conta_letra(string, numero));
    printf("simbolo: %d\n", conta_letra(string, simbolo));

    return 0;
}