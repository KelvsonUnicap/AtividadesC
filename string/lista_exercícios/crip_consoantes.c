/*
Faça um programa para ler uma frase de, no máximo, 80 caracteres,
criptografá-la e exibir o resultado obtido. 
Nesse caso, a criptografia irá consistir em inverter a frase e trocar as consoantes por #. 
Exemplo: Entrada: Eu estou na escola Saída: a#o##e a# uo#e# uE
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

void criptografia(char *string, char *criptografada){
    int j = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == ' '){
            criptografada[j++] = string[i];
        } else criptografada[j++] = '#';
    }
    criptografada[j] = '\0';
}

char inverter(char *criptografada, char *invertida){
    int j = 0;
    for(int i = 0; criptografada[i] != '\0'; i++){
        invertida[j++] = criptografada[strlen(criptografada) - 1 -i];
    }
    invertida[j] = '\0';
}

void main(){
    char string[MAX];
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    char criptografada[strlen(string)];
    char invertida_criptografada[strlen(string)];

    criptografia(string, criptografada);
    inverter(criptografada, invertida_criptografada);

    printf("%s", invertida_criptografada);
}