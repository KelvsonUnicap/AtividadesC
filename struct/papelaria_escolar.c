// 2ªQuestão: A papelaria Escolar deseja automatizar o cadastro dos produtos
// comercializados por ela. Faça o programa que irá realizar essa tarefa. O cadastro de
// produtos deve ser implementado utilizando um vetor de 40 registros (estruturas). Sobre
// cada produto deve-se manter as seguintes informações: código, descrição, valor unitário e
// quantidade em estoque. O programa deverá apresentar os seguintes sub-programas:

// (a) Um procedimento para cadastrar um novo produto;
// (b) Um procedimento que, dado um código, permita alterar seu valor unitário;
// (c) Uma função que, dado um código, informe o valor unitário do produto;
// (d) Uma função que, dado um código, informe a quantidade em estoque do produto;
// (e) Um procedimento de venda que, dado o código e a quantidade desejada, e caso
// a quantidade exista no estoque, subtrai a quantidade vendida da quantidade
// existente e informa o valor a ser pago. OBS1: Caso o produto esteja com estoque
// zero, o procedimento de informar ao usuário. OBS2: Caso a quantidade desejada
// seja inferior a quantidade existente o procedimento deve perguntar ao usuário se
// deseja efetivar a compra. Caso afirmativo, o programa deve zerar o estoque e
// informar o valor a ser pago.
// (f) Um procedimento para, dado um código, atualizar a quantidade em estoque do
// produto;
// (g) Um procedimento para exibir o código e a descrição de todos os produtos;
// (h) Um procedimento para exibir o código e a descrição de todos os produtos com
// estoque zero

#include <stdio.h>

#define MAX 40

struct Produtos{
    int codigo;
    char descricao[50];
    double valor;
    int estoque;
};

void menu(struct Produtos produtos[]);
void preencher_id(struct Produtos produto[]);

void cadastro(struct Produtos addProd[], int quantidade);

void mercadoria_novo_valor(struct Produtos produto[]);
void alterar_estoque_via_codigo(struct Produtos produto[]);

void mercadoria(struct Produtos produto[]);
void produtos_acabados(struct Produtos produto[]);

void vender(struct Produtos produto[]);

void main(){
    struct Produtos produtos[MAX];
    menu(produtos);
}

void menu(struct Produtos produtos[]){
    int opcao;
    int quantidade;
    
    printf("\n[1] Cadastrar novo produto\n[2] Alterar valor do produto\n[3] Encontrar produto\n");
    printf("[4] Vender produto\n[5] Atualizar estoque\n[6] Exibir produtos\nDigite a opção que deseja realizar: ");
    
    scanf("%d", &opcao);
    while(getchar() != '\0');

    switch(opcao){
        case 1: 
            scanf("%d", &quantidade);
            cadastro(produtos, quantidade);
            break;
        case 2: mercadoria_novo_valor(produtos);
        case 3: mercadoria(produtos);
        case 4: vender(produtos);
        case 5: alterar_estoque_via_codigo(produtos);
        case 6: mercadoria(produtos);
    }
}

void preencher_id(struct Produtos produto[]){
    for(int i = 0; i<MAX; i++){
        produto[i].codigo = -1;
    }
}

void cadastro(struct Produtos addProd[], int quantidade){}

void mercadoria_novo_valor(struct Produtos produto[]){
    int id;
    
    printf("Digite o codigo do produto que deseja que tenha valor alterado: ");
    scanf("%d", &id);

    for(int i = 0; i<MAX; i++){

    }
}