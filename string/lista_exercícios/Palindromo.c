#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removerEspacos(char *entrada, char *saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != ' ') {
            saida[j++] = tolower(entrada[i]);
        }
    }
    saida[j] = '\0';
}

int checarPalindromo(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char frase[100];
    char fraseSemEspacos[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    removerEspacos(frase, fraseSemEspacos);
    int resultado = checarPalindromo(fraseSemEspacos);

    if(resultado){
        printf("É palindromo");
    } else{
        printf("Não é palindromo");
    }

    return 0;
}