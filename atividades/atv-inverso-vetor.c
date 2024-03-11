#include <stdio.h>

void imprimirvet(int vet[], int vettam){
    for(int i = 0; i < vettam; i++){
        printf("%d", vet[i]);
    }
    printf("\n");
}

int main(){

    int vettam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &vettam);
    
    int vet[vettam];
    int vetcopia[vettam];
    
    for(int j = 0; j<vettam; j++){
        scanf("%d", &vet[j]);
    }

    for(int i = 0; i<vettam; i++){
        vetcopia[i] = vet[vettam -i - 1];
    }

    imprimirvet(vet, vettam);
    imprimirvet(vetcopia, vettam);
    return 0;
}