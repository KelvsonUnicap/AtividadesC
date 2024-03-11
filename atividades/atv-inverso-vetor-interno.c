#include <stdio.h>

void invertevet(int vet[], int tam){
    int aux;
    for(int j = 0; j<tam/2; j++){
        aux = vet[j];
        vet[j] = vet[tam-1-j];
        vet[tam-1-j] = aux;
    }

    for (int k = 0; k<tam; k++){
        printf("%d ", vet[k]);
    }
    printf("\n");    
}

int main(){

    int tam;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam];

    for(int i = 0; i<tam; i++){
        scanf("%d", &vet[i]);
    }

    invertevet(vet, tam);

    return 0;
}