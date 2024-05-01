/*
4ª Questão: Faça um programa que peça para o usuário digitar uma palavra e 
imprima a palavra toda em maiúscula. Utilize a função toupper.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

void imprimir_maiuscula(char *string){
    for(int i = 0 ; string[i] != '\0'; i++){
        printf("%c", toupper(string[i]));
    }
}

int main(){

    char string[MAX];

    fgets(string, sizeof(string) - 1, stdin);
    string[strlen(string) - 1] = '\0';

    imprimir_maiuscula(string);

    return 0;
}