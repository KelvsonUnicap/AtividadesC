#include<stdio.h>
#include<string.h>
#include<locale.h>
#include <ctype.h>

int main() {
 setlocale(LC_ALL, "");
 int i, valor = 0;
 char palavra[15], inversa[15];

 printf("\nDigite uma palavra: ");
 gets(palavra);

 //Converter a palavra digitada para minúsculas
 for(i = 0; palavra[i]; i++){
   palavra[i] = tolower(palavra[i]);
 }

 //Copiar a palavra digitada para que seja invertida
 strcpy(inversa, palavra);

 //Inverter a palavra copiada
 strrev(inversa);

 valor = strcmp(palavra, inversa);

 if (valor == 0)
   printf("\nA palavra %s é palíndroma\n", palavra);
 else
   printf("\nA palavra %s não é palíndroma\n", palavra);

 return 0;
}