// Faça um programa que define um vetor de pessoas de tamanho 100 e um vetor de grupos de tamanho 20 e exibe um
// menu com as seguintes funcionalidades que serão implementadas em funções a parte: (0,5 ponto):
// 1. inserirPessoa - que recebe como parâmetros o vetor de pessoas e o tamanho atual deste vetor como
// referência e se houver espaço disponível no vetor, pede para o usuário digitar as informações da pessoa e
// armazena no vetor, e incrementa o tamanho atual do vetor em 1. (1,5 pontos)
// 2. listarGrupo - que recebe como parâmetros o vetor de pessoas, o tamanho atual deste vetor, o vetor de
// grupos e o tamanho atual deste vetor e peça para o usuário digitar o nome do grupo, e caso encontre um
// grupo com esse nome, liste os nomes de todos os integrantes deste grupo. (2,0 pontos)
// 3. listarPessoasOrdenada - que recebe como parâmetro o vetor de pessoas e o tamanho atual deste vetor e
// imprime o nome e as outras informações das pessoas em ordem alfabética. (2,0 pontos)
// 4. estatisticasPessoas - que recebe como parâmetro o vetor de pessoas e o tamanho atual deste vetor e
// imprime as seguintes informações: a) nome e idade da pessoa mais velha; b) nome, idade e peso do jovem
// mais pesado (considere que jovem é uma pessoa entre 15 e 29 anos); c) média de idade das pessoas que
// pesam até 60kg. (2,0 pontos)
// 5. estatisticasGrupo - que recebe como parâmetros o vetor de pessoas, o tamanho atual deste vetor, o vetor de
// grupos e o tamanho atual deste vetor e imprime as seguintes informações: a) o nome de cada grupo com a
// sua respectiva quantidade de participantes; b) o nome do grupo e seus respectivos participantes do grupo
// que possui a maior média de idade entre todos os grupos; c) o nome do grupo, seus respectivos participantes
// e a média de idade do grupo que possui a menor média de peso entre todos os grupos (2,0 pontos)

#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100
#define MAX_GRUPOS 20
#define MAX_INTEGRANTES 6

struct Pessoa{
    int id;
    char nome[50];
    int idade;
    double peso;
};

struct Grupo{
    char nome[50];
    int tam;
    int integrantes[6]; // vetor com os ‘id’ dos integrantes do grupo
};

void inserirPessoas(struct Pessoa pessoas[], int *tamAtualPessoas){
    if(*tamAtualPessoas >= MAX_PESSOAS){
        printf("Sem espaço");
        return;
    }

    struct Pessoa novaPessoa;
    novaPessoa.id = *tamAtualPessoas;
    printf("\nDigite o nome: ");
    fgets(novaPessoa.nome, 50, stdin);
    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';
    printf("\nDigite a idade: ");
    scanf("%d", &novaPessoa.idade);
    printf("\nDigite o peso: ");
    scanf("%lf", &novaPessoa.peso);

    Pessoas[*tamAtualPessoas] = novaPessoa;
    (*tamAtualPessoas)++;
    printf("\nPessoa inserida.");

    while(getchar() != '\0')
}

void listarGrupos(struct Pessoa pessoas[], struct Grupo grupos, int tamAtualPessoas, int tamAtualGrupos){
    char nomeGrupo[50];
    printf("Digite o nome do grupo: ");
    fgets(nomeGrupo, 50, stdin);
    nomeGrupo[strcspn(nomeGrupo, "\n")] = '\0';

    for(int i = 0; i<tamAtualGrupos; i++){
        if(strcmp(grupos[i], nomeGrupo) == 0){
            printf("Integrantes do grupo:");
            for(int j = 0; j<grupos[i].tam; j++){
                int idIntegrante = grupos[i].integrantes[j];
                if(idIntegrante >= 0 && idIntegrante < tamAtualPessoas){
                    printf("%s\n", pessoas[idIntegrante].nome);
                }
            }
            return;
        }
    }
    printf("Grupo não encontrado");
}

void listarPessoasOrdenada(struct Pessoa pessoas[], int tamAtualPessoas){
    struct Pessoa pessoasOrdenadas[MAX_PESSOAS];
    memcpy(pessoasOrdenadas, pessoas, tamAtualPessoas * sizeof(struct Pessoa));

    for(int i = 0; i< tamAtualPessoas - 1; i++){
        for(int j = i+1; j<tamAtualPessoas; j++){
            if(strcmp(pessoasOrdenadas[i].nome, pessoasOrdenadas[j].nome) > 0){
                struct Pessoa temp = pessoasOrdenadas[i];
                pessoasOrdenadas[i] = pessoasOrdenadas[j];
                pessoasOrdenadas[j] = temp;
            }
        }
    }
    printf("Pessoas em ordem alfabetica:\n");
    for(int i = 0; i<tamAtualPessoas; i++){
        printf("nome: %s, Idade: %d, Peso: %.2lf\n", pessoasOrdenadas[i].nome, pessoasOrdenadas[i].idade, pessoasOrdenadas[i].peso)
    }
}

void estatisticaPessoas(struct Pessoa pessoas[], int tamAtualPessoas){
    if(tamAtualPessoas == 0){
        printf("Nenhuma pessoa foi cadastrada.\n");
        return;
    }

    struct Pessoa* maisVelha = &pessoas[0];
    struct Pessoa* jovemMaisPesado = NULL;
    double somaidades = 0.0;
    int countIdades = 0;

    for(int i = 0; i<tamAtualPessoas; i++){
        if(pessoas[i].idade > maisVelha->idade){
            maisVelha = &pessoas[i];
        }

        if(pessoas[i].idade >= 15 && pessoas[i].idade <=29){
            if(jovemMaisPesado == NULL || pessoas[i].peso > jovemMaisPesado->peso){
                jovemMaisPesado = &pessoas[i];
            }
        }
        if(pessoas[i].peso <= 60.0){
            somaIdades += pessoas[i].idade;
            countIdades++;
        }
    }
    
    printf("A pessoa mais velha:\nNome: %s, Idade:%d\n", maisVelha->nome, maisVelha->idade);
    if(jovemMaisPesado){
        printf("O jovem mais pesado e:\nNome: %s, Idade: %d, Peso: %.2lf\n", jovemMaisPesado->nome, jovemMaisPesado->idade, jovemMaisPesado->peso);
    } else{
        printf("Não tem jovens");
    }

    if(countIdades>0){
        double mediaIdades = somaidades/countIdades;
        printf("A media de idades de pessoas de ate 60kg é %.2lf", mediaIdades);
    } else{
        printf("Nenhum jovem com peso de ate 60kg encontrado");
    }
}

void estatisticaGrupos(struct Pessoa pessoas[], int tamAtualPessoas, struct Grupo grupos[], int tamAtualGrupos){
    if(tamAtualGrupos == 0){
        printf("Sem grupos.");
        return;
    }

    struct Grupo* grupoMaiorMediaIdade = NULL;
    struct Grupo* grupoMenorMediaPeso = NULL;
    double maiorMediaIdade = 0.0;
    double menorMediaPeso = 0.0;

    printf("Grupos e quantidade de participantes:\n");
    for(int i = 0; i<tamAtualGrupos; i++){
        double somaIdades = 0.0;
        double somaPesos = 0.0;
        for(int j = 0; j<grupos[i].tam; j++){
            int idIntegrante = grupos[i].integrantes[j];
            if(idIntegrante >= 0 && idIntegrante < tamAtualPessoas){
                somaIdades += pessoas[idIntegrante].idade;
                somaPesos += pessoas[idIntegrante].peso;
            }
        }
        double mediaIdade = somaIdades/grupos[i].tam;
        double mediaPeso = somaPesos/grupos[i].tam;

        printf("Grupo: %s, Participantes: %d\n", grupos[i].nome, grupos[i].tam);

        if(grupoMaiorMediaIdade == NULL || mediaIdade < menorMediaPeso){
            grupoMaiorMediaIdade = &grupos[i];
            grupoMaiorMediaIdade = mediaIdade;
        }

        if(grupoMenorMediaPeso == NULL || mediaPeso < menorMediaPeso){
            grupoMenorMediaPeso = &grupos[i];
            menorMediaPeso = mediaPeso;
        }
    }
    if(grupoMaiorMediaIdade){
        printf("O grupo com a maior média de idade é %s\n:", grupoMaiorMediaIdade.nome);
        for(int i =0; i<grupoMaiorMediaIdade->tam, i++){
            int idIntegrante = grupoMaiorMediaIdade->integrantes[i];
            if(idIntegrante >= 0 && idIntegrante < tamAtualPessoas){
                printf("%s\n", pessoas[idIntegrante].nome);
            }
        }        
    }

    if(grupoMenorMediaPeso){
        printf("O grupo com a menor média de peso é %s\n:", grupoMenorMediaPeso->nome);
        for(int i =0; i<grupoMenorMediaPeso->tam, i++){
            int idIntegrante = grupoMenorMediaPeso->integrantes[i];
            if(idIntegrante >= 0 && idIntegrante < tamAtualPessoas){
                printf("%s\n", pessoas[idIntegrante].nome);
            }
        }        
    }
}


int main(){
    Pessoa pessoas[MAX_PESSOAS];
    Grupo grupos[MAX_GRUPOS];
    int tamAtualPessoas = 0;
    int tamAtualGrupos = 0;

    int opcao;
    do{
        printf("\nMenu:\n");
        printf("1. Inserir pessoa\n");
        printf("2. Listar grupos\n");
        printf("3. Listar pessoas ordenadas\n");
        printf("4. Estatisticas das pessoas\n");
        printf("5. Estatisticas dos grupos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao)
        {
        case 1:
            inserirPessoas(Pessoas, &tamAtualPessoas);
            break;
        
        case 2:
            inserirPessoas(pessoas, tamAtualPessoas, grupos, tamAtualGrupos);
            break;

        case 3:
            listarPessoasOrdenada(pessoas, tamAtualPessoas);
            break;

        case 4:
            estatisticaPessoas(pessoas, tamAtualPessoas);
            break;

        case 5:
            estatisticaGrupos(pessoas, tamAtualPessoas, grupos, tamAtualGrupos);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida.");
            break;
        }
    } while(opcao != 0);

    return 0;
}