/*
 Faça um programa para ler uma frase de, no máximo, 100 caracteres e um caracter. 
 O programa deve calcular e exibir a quantidade de vezes que o caracter aparece na frase. 
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int conta_vogal(char *string, char vogal){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == vogal) count++;
    }
    return count;
}

int main(){

    char string[MAX];
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';

    char vogal = getchar();

    printf("%d", conta_vogal(string, vogal));

    return 0;
}


