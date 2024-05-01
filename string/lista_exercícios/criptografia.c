/*
1ª Questão: Faça um programa para ler uma frase de, no máximo, 80 caracteres, 
criptografá-la e exibir o resultado obtido. 
Nesse caso, a criptografia irá consistir em trocar as vogais da frase por *. 
Exemplo: Entrada: Eu estou na escola Saída: ** *st** n* *sc*l* 
*/

#include <stdio.h>
#include <string.h>

#define MAX 80

void criptografia(char *string, char *criptografada){
    char buffer[strlen(string)];
    strcpy(buffer, string);
    int i = strcspn(buffer, "aeiouAEIOU");
    if(i < strlen(buffer)){
        while(i < strlen(buffer)){
            buffer[i] = '*';
            i = strcspn(buffer, "aeiouAEIOU");
        }
        strcpy(criptografada, buffer);
    } else strcpy(criptografada, string);
}

int main(){

    char string[MAX];
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    char criptografada[strlen(string) - 1];

    criptografia(string, criptografada);

    printf("%s", criptografada);
    
    return 0;
}