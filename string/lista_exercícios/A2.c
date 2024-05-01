#include <stdio.h>
#include <string.h>

#define MAX 80

void display(char parr[], int t){
    for(int i = t; i>=0; i--){
        printf("%c", parr[i]);
    }
}

void main(){
    char frase[MAX];
    fgets(frase, MAX-1, stdin);
    int t = strlen(frase);

    display(frase, t);
}
