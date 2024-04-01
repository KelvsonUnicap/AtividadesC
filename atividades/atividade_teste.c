#include <stdio.h>

#define pesos 4
#define alunos 1

void pegar_pesos(double vet_pesos[]){
    // pegando pesos:
    for (int i = 0; i < pesos; i++){
        printf("Digite o %d° peso: ", i+1);
        scanf("%lf", &vet_pesos[i]);
    }
}

void calcular_matriz(double matriz[][pesos+1], double vet_pesos[]){
    // Pegando as notas e encontrando a média
    double sum_pesos = 0;

    for(int i = 0; i<pesos; i++){
        sum_pesos += vet_pesos[i];
    }

    for (int i = 0; i < alunos; i++){
        for (int j = 0; j < pesos; j++){
            printf("Insira a nota %d° do %d° aluno: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
            matriz[i][pesos] += (matriz[i][j] * vet_pesos[j])/sum_pesos;
        }
    }
}

void display_matriz(double matriz[][pesos + 1]){
    for (int i = 0; i < alunos; i++){
        printf("Aluno %d:\n", i+1);
        for (int k = 0; k < pesos + 1; k++){
            printf("Nota %d: %lf \n", k + 1, matriz[i][k]);
        }
    }
}

void main(){

    // Criando variável, vetor e matriz
    double sum_pesos = 0;
    double vet_pesos[pesos];
    double notas[alunos][pesos + 1];

    pegar_pesos(vet_pesos);

    calcular_matriz(notas, vet_pesos);

    display_matriz(notas);
}