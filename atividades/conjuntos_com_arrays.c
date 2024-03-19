#include <stdio.h>

# define QNTD_VETS 2

void vet_elements(int vet[], int tam){
    for(int i = 0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

//

int check_element(int vet[], int tam, int element){
    for(int k = 0; k < tam; k++){
        if(element == vet[k]){
            return -1; // para aqui se for igual
        }
    }
    return 0; // se não for igual, então ele vai passar pelo for e retorna 0;
}

//

int main(){

    // pegar o tamanho do vetor
    int tam;
    scanf("%d", &tam);

    // Criando o vetor com o tamanho que foi adquirido
    int vets[QNTD_VETS][tam];

    // adquirindo os valores dos vetores
    for(int vetId = 0; vetId < QNTD_VETS; vetId++){
        for(int i = 0; i<tam; i++){
            int vetValue;
            do{
                printf("Digite o %d° valor do %d° vetor: ", i+1, vetId);
                scanf("%d", &vetValue);
            } while(check_element(vets[vetId], i, vetValue) == -1); // checar o vetor [vetId] e vai ver se na quantidade i de elementos tem o valor vetValue =-:> vetor[1], i = 3, 5 => vai pôr no loop for(k<3) e checar se tem 5
            vets[vetId][i] = vetValue;
        }
    }

    // unindo vetores
    vet_union(vets[0], vets[1], tam);
    printf("\n\n");

    // printando vetores
    vet_elements(vets[0], tam);
    vet_elements(vets[1], tam);
    return 0;
}