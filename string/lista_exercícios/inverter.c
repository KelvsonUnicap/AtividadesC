/*
1ª Questão: Faça um programa que peça para o usuário digitar 
duas strings e você deve imprimir em ordem alfabética crescente. 
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

void inverte(char *string, char *invertida){
    int j = 0;
    for(int i = 0; string[i] != '\0'; i++){
        invertida[j++] = string[strlen(string) - 1 - i];
    }
    invertida[j] = '\0';
}

void main(){
    char string[MAX];
    fgets(string, sizeof(string) - 1, stdin);
    string[strlen(string)-1] = '\0';
    char invertida[strlen(string)];

    inverte(string, invertida);
    printf("%s", invertida);
}