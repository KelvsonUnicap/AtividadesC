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
    int j = 0, id = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            criptografada[j++] = '*';
        } else criptografada[j++] = string[i];
    }
    criptografada[j] = '\0';
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