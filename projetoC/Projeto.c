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

int qtdUsuarios = 0;
int qtdMusicas = 0;
int qtdPlaylistsTotais = 0;

struct Usuario usuarios[TAM_MAX_PLYLST];
struct Musica musicas[TAM_MUSICAS];
struct Playlist playlists[TAM_MAX_PLYLST];

int login();
int loginAdmin();
void criarPlaylist(int usuarioIndex);
void listarPlaylists();
void consultarMusica();
void cadastrarUsuario();
void cadastrarMusica();
void listarUsuarios();
void listarMusicas();
void listarPlaylists();
void listarPlaylistsUsuario(int usuarioIndex);
void listarPlaylistsExcetoUsuario(int usuarioIndex);
void alterarNomeUsuario(int usuarioIndex);
void alterarLoginUsuario(int usuarioIndex);
void alterarSenhaUsuario(int usuarioIndex);
void consultarUsuariosPorNome();

int login() {
    char login[TAM_LOGIN], senha[TAM_SENHA];
    printf("Login: ");
    fgets(login, TAM_LOGIN, stdin);
    login[strcspn(login, "\n")] = '\0';
    printf("Senha: ");
    fgets(senha, TAM_SENHA, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    for (int i = 0; i < qtdUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i;
        }
    }
    return -1;
}

int loginAdmin() {
    char senha[TAM_SENHA];
    printf("Senha de admin: ");
    fgets(senha, TAM_SENHA, stdin);
    senha[strcspn(senha, "\n")] = '\0';
    return strcmp(senha, "m@st3r2024") == 0;
}

void criarPlaylist(int usuarioIndex) {
    if (usuarios[usuarioIndex].qtdPlaylists >= TAM_PLAYLIST) {
        printf("Número máximo de playlists atingido.\n");
        return;
    }

    struct Playlist novaPlaylist;
    novaPlaylist.codigo = ++qtdPlaylistsTotais;
    novaPlaylist.codUsuario = usuarios[usuarioIndex].codigo;
    novaPlaylist.qtdMusicas = 0;

    printf("Título da playlist: ");
    fgets(novaPlaylist.titulo, TAM_TITULO, stdin);
    novaPlaylist.titulo[strcspn(novaPlaylist.titulo, "\n")] = '\0';

    usuarios[usuarioIndex].playlists[usuarios[usuarioIndex].qtdPlaylists++] = novaPlaylist;
    playlists[qtdPlaylistsTotais - 1] = novaPlaylist;
}

void listarPlaylists() {
    for (int i = 0; i < qtdPlaylistsTotais; i++) {
        printf("Código: %d, Título: %s, Criador: %s\n", playlists[i].codigo, playlists[i].titulo, usuarios[playlists[i].codUsuario - 1].nome);
    }
}

void consultarMusica() {
    int opcao;
    printf("Consultar música por:\n1. Código\n2. Título\n3. Artista\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Consumir o '\n' deixado pelo scanf

    switch (opcao) {
        case 1: {
            int codigo;
            printf("Código: ");
            scanf("%d", &codigo);
            getchar();
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
            printf("Título: ");
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
            printf("Artista: ");
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

void cadastrarUsuario() {
    if (qtdUsuarios >= TAM_MAX_PLYLST) {
        printf("Número máximo de usuários atingido.\n");
        return;
    }

    struct Usuario novoUsuario;
    novoUsuario.codigo = ++qtdUsuarios;

    printf("Nome: ");
    fgets(novoUsuario.nome, TAM_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Login: ");
    fgets(novoUsuario.login, TAM_LOGIN, stdin);
    novoUsuario.login[strcspn(novoUsuario.login, "\n")] = '\0';

    printf("Senha: ");
    fgets(novoUsuario.senha, TAM_SENHA, stdin);
    novoUsuario.senha[strcspn(novoUsuario.senha, "\n")] = '\0';

    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuarios[qtdUsuarios - 1] = novoUsuario;
}

void cadastrarMusica() {
    if (qtdMusicas >= TAM_MUSICAS) {
        printf("Número máximo de músicas atingido.\n");
        return;
    }

    struct Musica novaMusica;
    novaMusica.codigo = ++qtdMusicas;

    printf("Título: ");
    fgets(novaMusica.titulo, TAM_TITULO, stdin);
    novaMusica.titulo[strcspn(novaMusica.titulo, "\n")] = '\0';

    printf("Artista: ");
    fgets(novaMusica.artista, TAM_NOME, stdin);
    novaMusica.artista[strcspn(novaMusica.artista, "\n")] = '\0';

    musicas[qtdMusicas - 1] = novaMusica;
}

void listarUsuarios() {
    for (int i = 0; i < qtdUsuarios; i++) {
        printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
    }
}

void listarMusicas() {
    for (int i = 0; i < qtdMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

void listarPlaylistsUsuario(int usuarioIndex) {
    for (int i = 0; i < usuarios[usuarioIndex].qtdPlaylists; i++) {
        struct Playlist playlist = usuarios[usuarioIndex].playlists[i];
        printf("Código: %d, Título: %s\n", playlist.codigo, playlist.titulo);
        for (int j = 0; j < playlist.qtdMusicas; j++) {
            struct Musica musica = musicas[playlist.musicas[j] - 1];
            printf("   Música %d: %s - %s\n", musica.codigo, musica.titulo, musica.artista);
        }
    }
}

void listarPlaylistsExcetoUsuario(int usuarioIndex) {
    for (int i = 0; i < qtdPlaylistsTotais; i++) {
        struct Playlist playlist = playlists[i];
        if (playlist.codUsuario != usuarios[usuarioIndex].codigo) {
            printf("Código: %d, Título: %s, Criador: %s\n", playlist.codigo, playlist.titulo, usuarios[playlist.codUsuario - 1].nome);
            for (int j = 0; j < playlist.qtdMusicas; j++) {
                struct Musica musica = musicas[playlist.musicas[j] - 1];
                printf("   Música %d: %s - %s\n", musica.codigo, musica.titulo, musica.artista);
            }
        }
    }
}

void alterarNomeUsuario(int usuarioIndex) {
    char senha[TAM_SENHA];
    printf("Confirme sua senha: ");
    fgets(senha, TAM_SENHA, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    if (strcmp(senha, usuarios[usuarioIndex].senha) == 0) {
        printf("Novo nome: ");
        fgets(usuarios[usuarioIndex].nome, TAM_NOME, stdin);
        usuarios[usuarioIndex].nome[strcspn(usuarios[usuarioIndex].nome, "\n")] = '\0';
    } else {
        printf("Senha incorreta.\n");
    }
}

void alterarLoginUsuario(int usuarioIndex) {
    char senha[TAM_SENHA];
    printf("Confirme sua senha: ");
    fgets(senha, TAM_SENHA, stdin);
    senha[strcspn(senha, "\n")] = '\0';

    if (strcmp(senha, usuarios[usuarioIndex].senha) == 0) {
        printf("Novo login: ");
        fgets(usuarios[usuarioIndex].login, TAM_LOGIN, stdin);
        usuarios[usuarioIndex].login[strcspn(usuarios[usuarioIndex].login, "\n")] = '\0';
    } else {
        printf("Senha incorreta.\n");
    }
}

void alterarSenhaUsuario(int usuarioIndex) {
    char senhaAtual[TAM_SENHA], novaSenha[TAM_SENHA], confirmacaoSenha[TAM_SENHA];

    printf("Senha atual: ");
    fgets(senhaAtual, TAM_SENHA, stdin);
    senhaAtual[strcspn(senhaAtual, "\n")] = '\0';

    if (strcmp(senhaAtual, usuarios[usuarioIndex].senha) == 0) {
        printf("Nova senha: ");
        fgets(novaSenha, TAM_SENHA, stdin);
        novaSenha[strcspn(novaSenha, "\n")] = '\0';

        printf("Confirme a nova senha: ");
        fgets(confirmacaoSenha, TAM_SENHA, stdin);
        confirmacaoSenha[strcspn(confirmacaoSenha, "\n")] = '\0';

        if (strcmp(novaSenha, confirmacaoSenha) == 0) {
            strcpy(usuarios[usuarioIndex].senha, novaSenha);
        } else {
            printf("As senhas não coincidem.\n");
        }
    } else {
        printf("Senha atual incorreta.\n");
    }
}

void consultarUsuariosPorNome() {
    char parteNome[TAM_NOME];
    printf("Parte do nome: ");
    fgets(parteNome, TAM_NOME, stdin);
    parteNome[strcspn(parteNome, "\n")] = '\0';

    for (int i = 0; i < qtdUsuarios; i++) {
        if (strstr(usuarios[i].nome, parteNome) != NULL) {
            printf("Nome: %s\n", usuarios[i].nome);
        }
    }
}

int main() {
    int opcao, usuarioIndex = -1;

    while (1) {
        printf("\n1. Menu Usuário\n2. Menu Administrador\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o '\n' deixado pelo scanf

        if (opcao == 1) {
            printf("1. Login\n2. Cadastro\nEscolha uma opção: ");
            int subOpcao;
            scanf("%d", &subOpcao);
            getchar();

            if (subOpcao == 1) {
                usuarioIndex = login();
                if (usuarioIndex == -1) {
                    printf("Login ou senha incorretos.\n");
                    continue;
                }
            } else if (subOpcao == 2) {
                cadastrarUsuario();
                continue;
            } else {
                printf("Opção inválida.\n");
                continue;
            }

            while (1) {
                printf("\nMenu Usuário:\n");
                printf("1. Listar seus dados\n");
                printf("2. Alterar nome\n");
                printf("3. Alterar login\n");
                printf("4. Alterar senha\n");
                printf("5. Listar usuários\n");
                printf("6. Consultar usuários por parte do nome\n");
                printf("7. Listar todas as músicas\n");
                printf("8. Consultar músicas\n");
                printf("9. Listar todas as suas playlists\n");
                printf("10. Listar todas as playlists (exceto as suas)\n");
                printf("11. Cadastrar uma playlist\n");
                printf("12. Inserir música na playlist sua\n");
                printf("13. Excluir música de uma playlist sua\n");
                printf("14. Excluir uma playlist\n");
                printf("15. Favoritar uma playlist\n");
                printf("16. Logout\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                getchar();

                if (opcao == 1) {
                    printf("Código: %d\nNome: %s\nLogin: %s\nQuantidade de Playlists: %d\n", usuarios[usuarioIndex].codigo, usuarios[usuarioIndex].nome, usuarios[usuarioIndex].login, usuarios[usuarioIndex].qtdPlaylists);
                } else if (opcao == 2) {
                    alterarNomeUsuario(usuarioIndex);
                } else if (opcao == 3) {
                    alterarLoginUsuario(usuarioIndex);
                } else if (opcao == 4) {
                    alterarSenhaUsuario(usuarioIndex);
                } else if (opcao == 5) {
                    listarUsuarios();
                } else if (opcao == 6) {
                    consultarUsuariosPorNome();
                } else if (opcao == 7) {
                    listarMusicas();
                } else if (opcao == 8) {
                    consultarMusica();
                } else if (opcao == 9) {
                    listarPlaylistsUsuario(usuarioIndex);
                } else if (opcao == 10) {
                    listarPlaylistsExcetoUsuario(usuarioIndex);
                } else if (opcao == 11) {
                    criarPlaylist(usuarioIndex);
                } else if (opcao == 12) {
                    // Implementar inserir música na playlist do usuário
                } else if (opcao == 13) {
                    // Implementar excluir música da playlist do usuário
                } else if (opcao == 14) {
                    // Implementar excluir playlist do usuário
                } else if (opcao == 15) {
                    // Implementar favoritar uma playlist
                } else if (opcao == 16) {
                    usuarioIndex = -1;
                    break;
                } else {
                    printf("Opção inválida.\n");
                }
            }
        } else if (opcao == 2) {
            if (loginAdmin()) {
                while (1) {
                    printf("\nMenu Administrador:\n");
                    printf("1. Cadastrar usuário\n");
                    printf("2. Cadastrar música\n");
                    printf("3. Listar usuários\n");
                    printf("4. Listar playlists\n");
                    printf("5. Listar músicas\n");
                    printf("6. Logout\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);
                    getchar();

                    if (opcao == 1) {
                        cadastrarUsuario();
                    } else if (opcao == 2) {
                        cadastrarMusica();
                    } else if (opcao == 3) {
                        listarUsuarios();
                    } else if (opcao == 4) {
                        listarPlaylists();
                    } else if (opcao == 5) {
                        listarMusicas();
                    } else if (opcao == 6) {
                        break;
                    } else {
                        printf("Opção inválida.\n");
                    }
                }
            } else {
                printf("Senha de administrador incorreta.\n");
            }
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}