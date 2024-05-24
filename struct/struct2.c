// 1ªQuestão: Foi feita uma pesquisa nos 26 estados brasileiros para coletar dados sobre
// acidentes de trânsito e gerar algumas estatísticas. Em cada estado observaram-se os
// seguintes aspectos: nome do estado, número de veículos que circulam no estado (em
// 2007) e número de acidentes de trânsito (em 2007). Faça um programa para:

// (a) Coletar os dados dos 26 estados e armazenar em um vetor de estruturas. Para tal,
// construa um procedimento que irá solicitar ao usuário que informe os dados
// coletados de cada estado;

// (b) Informar a maior e a menor número de acidentes de trânsito e o nome dos estados
// em que eles ocorreram. Para tal, construa um procedimento que receba como
// parâmetro o cadastro e tenha como parâmetros de saída (por referência) os
// índices (posição no cadastro) dos estados que possuem as características
// solicitadas. A exibição dos dados deve ocorrer no programa principal.

// (c) Informar o percentual de veículos envolvidos em acidentes de trânsito em cada
// estado. Para tal, construa uma função que receba como parâmetro o cadastro e o
// estado e retorne o percentual solicitado;

// (d) Informar a média de acidentes no país. Para tal, construa uma função que receba
// como parâmetro o cadastro e retorne a média solicitada. A exibição da média deve
// ocorrer no programa principal;

// (e) Informar o nome dos estados que estão acima da média de acidentes do país.
// Para tal, construa um procedimento que receba como parâmetro o cadastro e a
// media do pais e exiba os dados solicitados.

#include <stdio.h>
#include <string.h>

#define LOCAIS 26

struct Estatisticas{
    char estado[2];
    int veiculos;
    int sinistros;
};

void Coletar_dados(struct Estatisticas dados[], int amostras){
    for(int i = 0; i < amostras; i++){

        printf("Estado: ");
        fgets(dados[i].estado, 3, stdin);
        dados[i].estado[strlen(dados[i].estado) - 1] = '\0';
        
        printf("Numero de veiculos: ");
        scanf("%d", &dados[i].veiculos);

        printf("Numero de sinistros: ");
        scanf("%d", &dados[i].sinistros);
        while(getchar() != '\n');
    }
}

void Maior_e_menor(struct Estatisticas dados[], int amostras, int *indexMaior, int *indexMenor){
    *indexMaior = 0;
    *indexMenor = 0;
    for(int i = 1; i<amostras; i++){
        if(dados[i].sinistros > dados[*indexMaior].sinistros){
            *indexMaior = i;
        }
        else if (dados[i].sinistros < dados[*indexMenor].sinistros){
            *indexMenor = i;
        }
    }
}

void percentual(struct Estatisticas dados[], int amostras){
    for(int i = 0; i<amostras;i++){
        printf("A porcentagem de acidentes do estado %s é: %.2f\n", dados[i].estado, ((dados[i].sinistros)*1.0/(dados[i].veiculos)));
    }
}

void acimaMedia(struct Estatisticas dados[], int amostras){
    double mediaGeral = 0;
    for(int i = 0; i<amostras; i++){
        mediaGeral += (dados[i].sinistros*0.1/dados[i].veiculos);
    }

    for(int j = 0; j<amostras; j++){
        if((dados[j].sinistros*0.1/dados[j].veiculos) > mediaGeral){
            printf("%s está acima da média geral de acidentes.\n", dados[j].estado);
        }
    }
}

int main(){
    struct Estatisticas dados[LOCAIS];
    
    int estados;
    int estadoMaior, estadoMenor;

    printf("Estados analisados: ");
    scanf("%d", &estados);
    while(getchar() != '\n');

    Coletar_dados(dados, estados);
    
    Maior_e_menor(dados, estados, &estadoMaior, &estadoMenor);
    
    printf("O estado com maior quantidade de sinistros é o: %s - com %d veiculos e %d sinistros\n", dados[estadoMaior].estado, dados[estadoMaior].veiculos, dados[estadoMaior].sinistros);
    printf("O estado com menor quantidade de sinistros é o: %s - com %d veiculos e %d sinistros\n", dados[estadoMenor].estado, dados[estadoMenor].veiculos, dados[estadoMenor].sinistros);

    percentual(dados, estados);

    acimaMedia(dados, estados);

    return 0;
}