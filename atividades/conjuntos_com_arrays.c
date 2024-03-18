#include <stdio.h>

# define QNTD_VETS 2

void vet_elements(int vet[], int tam){
    for(int i = 0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int check_element(int vet[], int tam, int element){
    for(int k = 0; k < tam; k++){
        if(element == vet[k]){
            return -1;
        }
        return 0;
    }
}

int main(){

    // pegar o tamanho do vetor
    int tam;
    scanf("%d", &tam);

    // Criando o vetor com o tamanho que foi adquirido
    int vet[tam], vet2[tam];

    // adquirindo os valores dos vetores
    for(int vetId = 0; vetId < QNTD_VETS; vetId++){
        for(int j = 0; j<tam; j++){
            int VetValue;
            if(vetId == 0){
                do{
                    printf("Digite o %d° valor do %d: ", j+1, vetId + 1);
                    scanf("%d", &VetValue);
                } while(check_element(vet, tam, VetValue) == -1);
                vet[j] = VetValue;

            } 
            else {
                do{
                    printf("Digite o %d valor do %d: ", j+1, vetId + 1);
                    scanf("%d", &VetValue);
                } while(check_element(vet2, tam, VetValue) == -1);
                vet2[j] = VetValue;
            }
        }
    }
    vet_elements(vet, tam);
    vet_elements(vet2, tam);
    return 0;
}