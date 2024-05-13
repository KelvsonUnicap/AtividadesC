#include <stdio.h>

typedef struct{
    char nome[30];
    int idade;
    char GSocial;
} amigoes[9];

void display(amigoes amigos){
    for(int i = 0; i < 9; i++){
        printf("Nome: %s\nIdade: %d\nGrupo Social: %c\n", amigos[i].nome, amigos[i].idade, amigos[i].GSocial);
    }
}

void main(){
    amigoes amigos;
    for(int i = 0; i< 9; i++){
        fgets(amigos[i].nome, 29, stdin);
        scanf("%d", &amigos[i].idade);
        amigos[i].GSocial = getchar();  
    }

    display(amigos);
}