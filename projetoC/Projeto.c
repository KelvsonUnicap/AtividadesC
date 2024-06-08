#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_PLYLST 200
#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLAYLIST 100
#define TAM_TITULO 50
#define TAM_MUSICAS 100

struct Musica {
    int codigo; // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME]; // nome do artista que canta esta música
};

struct Playlist {
    int codigo; // autoincremento
    int codUsuario; // o código do usuário que criou a playlist
    char titulo[TAM_TITULO]; // título desta playlist
    int qtdMusicas; // qtd atual de músicas incluídas nesta playlist
    int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas
};

struct Usuario {
    int codigo; // autoincremento
    char nome[TAM_NOME];
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylists; // quantid. de playlists criadas pelo usuário
    struct Playlist playlists[TAM_PLAYLIST]; // todas playlists criadas
    int qtdPlaylistsFav; // quantid. de playlists favoritadas pelo usuário
    int playlistsFav[TAM_PLAYLIST]; // códigos das playlists favoritadas pelo usuário
};

// Variáveis globais
struct Usuario usuarios[TAM_MAX_PLYLST];
struct Musica musicas[TAM_MAX_PLYLST];
int qtdUsuarios = 0;
int qtdMusicas = 0;
int qtdPlaylistsTotais = 0;

// Funções auxiliares
int login();
int loginAdmin();
void cadastrarUsuario();
void criarPlaylist(int usuarioIndex);
void listarUsuarios();
void listarPlaylists();
void cadastrarMusica();
void listarMusicas();
void consultarMusica();

int login() {
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];

    printf("Digite seu login: ");
    fgets(login, TAM_LOGIN, stdin);
    login[strcspn(login, "\n")] = '\0';

    printf("Digite sua senha: ");
    fgets(senha, TAM_SENHA, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    for (int i = 0; i < qtdUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i;
        }
    }
    return -1; // Falha no login
}

int loginAdmin() {
    char senha[TAM_SENHA];

    printf("Digite a senha do administrador: ");
    fgets(senha, TAM_SENHA, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    if (strcmp(senha, "admin@2021") == 0) {
        return 1; // Sucesso no login
    }
    return 0; // Falha no login
}

void cadastrarUsuario() {
    if (qtdUsuarios >= TAM_MAX_PLYLST) {
        printf("Capacidade máxima de usuários atingida!\n");
        return;
    }

    struct Usuario novoUsuario;
    novoUsuario.codigo = qtdUsuarios + 1; // Autoincremento
    printf("Digite o nome do usuário: ");
    fgets(novoUsuario.nome, TAM_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';
    printf("Digite o login do usuário: ");
    fgets(novoUsuario.login, TAM_LOGIN, stdin);
    novoUsuario.login[strcspn(novoUsuario.login, "\n")] = '\0';
    printf("Digite a senha do usuário: ");
    fgets(novoUsuario.senha, TAM_SENHA, stdin);
    novoUsuario.senha[strcspn(novoUsuario.senha, "\n")] = '\0';

    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuarios[qtdUsuarios] = novoUsuario;
    qtdUsuarios++;

    printf("Usuário cadastrado com sucesso!\n");
}

void criarPlaylist(int usuarioIndex) {
    if (usuarios[usuarioIndex].qtdPlaylists >= TAM_PLAYLIST) {
        printf("Capacidade máxima de playlists atingida!\n");
        return;
    }

    struct Playlist novaPlaylist;
    novaPlaylist.codigo = qtdPlaylistsTotais + 1; // Autoincremento
    novaPlaylist.codUsuario = usuarios[usuarioIndex].codigo;
    printf("Digite o título da playlist: ");
    fgets(novaPlaylist.titulo, TAM_TITULO, stdin);
    novaPlaylist.titulo[strcspn(novaPlaylist.titulo, "\n")] = '\0';

    novaPlaylist.qtdMusicas = 0;

    usuarios[usuarioIndex].playlists[usuarios[usuarioIndex].qtdPlaylists] = novaPlaylist;
    usuarios[usuarioIndex].qtdPlaylists++;
    qtdPlaylistsTotais++;

    printf("Playlist criada com sucesso!\n");
}

void listarUsuarios() {
    printf("\n----- Lista de Usuários -----\n");
    for (int i = 0; i < qtdUsuarios; i++) {
        printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
    }
}

void listarPlaylists() {
    printf("\n----- Lista de Playlists -----\n");
    for (int i = 0; i < qtdUsuarios; i++) {
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            printf("Código: %d, Título: %s, Criador: %s\n", usuarios[i].playlists[j].codigo, usuarios[i].playlists[j].titulo, usuarios[i].nome);
        }
    }
}

void cadastrarMusica() {
    if (qtdMusicas >= TAM_MAX_PLYLST) {
        printf("Capacidade máxima de músicas atingida!\n");
        return;
    }

    struct Musica novaMusica;
    novaMusica.codigo = qtdMusicas + 1; // Autoincremento
    printf("Digite o título da música: ");
    fgets(novaMusica.titulo, TAM_TITULO, stdin);
    novaMusica.titulo[strcspn(novaMusica.titulo, "\n")] = '\0';
    printf("Digite o nome do artista: ");
    fgets(novaMusica.artista, TAM_NOME, stdin);
    novaMusica.artista[strcspn(novaMusica.artista, "\n")] = '\0';

    musicas[qtdMusicas] = novaMusica;
    qtdMusicas++;

    printf("Música cadastrada com sucesso!\n");
}

void listarMusicas() {
    printf("\n----- Lista de Músicas -----\n");
    for (int i = 0; i < qtdMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

void consultarMusica() {
    int opcao;
    printf("\n----- Consultar Músicas -----\n");
    printf("1. Consultar por código\n");
    printf("2. Consultar por título\n");
    printf("3. Consultar por artista\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Para consumir o '\n' deixado pelo scanf

    switch (opcao) {
        case 1: {
            int codigo;
            printf("Digite o código da música: ");
            scanf("%d", &codigo);
            getchar(); // Para consumir o '\n' deixado pelo scanf
            for (int i = 0; i < qtdMusicas; i++) {
                if (musicas[i].codigo == codigo) {
                    printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
                    return;
                }
            }
            printf("Música não encontrada.\n");
            break;
        }
        case 2: {
            char titulo[TAM_TITULO];
            printf("Digite parte do título da música: ");
            fgets(titulo, TAM_TITULO, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            int encontrou = 0;
            for (int i = 0; i < qtdMusicas; i++) {
                if (strstr(musicas[i].titulo, titulo) != NULL) {
                    printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
                    encontrou = 1;
                }
            }
            if (!encontrou) {
                printf("Música não encontrada.\n");
            }
            break;
        }
        case 3: {
            char artista[TAM_NOME];
            printf("Digite parte do nome do artista: ");
            fgets(artista, TAM_NOME, stdin);
            artista[strcspn(artista, "\n")] = '\0';
            int encontrou = 0;
            for (int i = 0; i < qtdMusicas; i++) {
                if (strstr(musicas[i].artista, artista) != NULL) {
                    printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
                    encontrou = 1;
                }
            }
            if (!encontrou) {
                printf("Música não encontrada.\n");
            }
            break;
        }
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    int opcaoPrincipal, opcaoAdmin, usuarioIndex;

    while (1) {
        printf("\n----- Menu Principal -----\n");
        printf("1. Usuário\n");
        printf("2. Admin\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoPrincipal);
        getchar(); // Para consumir o '\n' deixado pelo scanf

        switch (opcaoPrincipal) {
            case 1:
                usuarioIndex = login();
                if (usuarioIndex != -1) {
                    while (1) {
                        int opcaoUsuario;
                        printf("\n----- Menu do Usuário -----\n");
                        printf("1. Criar Playlist\n");
                        printf("2. Listar Playlists\n");
                        printf("3. Consultar Músicas\n");
                        printf("4. Logout\n");
                        printf("Escolha uma opção: ");
                        scanf("%d", &opcaoUsuario);
                        getchar(); // Para consumir o '\n' deixado pelo scanf

                        if (opcaoUsuario == 4) break;

                        switch (opcaoUsuario) {
                            case 1:
                                criarPlaylist(usuarioIndex);
                                break;
                            case 2:
                                listarPlaylists();
                                break;
                            case 3:
                                consultarMusica();
                                break;
                            default:
                                printf("Opção inválida!\n");
                        }
                    }
                } else {
                    printf("Login falhou!\n");
                }
                break;
            case 2:
                if (loginAdmin()) {
                    while (1) {
                        printf("\n----- Menu do Admin -----\n");
                        printf("1. Cadastrar Usuário\n");
                        printf("2. Cadastrar Música\n");
                        printf("3. Listar Usuários\n");
                        printf("4. Listar Playlists\n");
                        printf("5. Listar Músicas\n");
                        printf("6. Logout\n");
                        printf("Escolha uma opção: ");
                        scanf("%d", &opcaoAdmin);
                        getchar(); // Para consumir o '\n' deixado pelo scanf

                        if (opcaoAdmin == 6) break;

                        switch (opcaoAdmin) {
                            case 1:
                                cadastrarUsuario();
                                break;
                            case 2:
                                cadastrarMusica();
                                break;
                            case 3:
                                listarUsuarios();
                                break;
                            case 4:
                                listarPlaylists();
                                break;
                            case 5:
                                listarMusicas();
                                break;
                            default:
                                printf("Opção inválida!\n");
                        }
                    }
                } else {
                    printf("Login de admin falhou!\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}