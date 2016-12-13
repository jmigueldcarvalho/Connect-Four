#include <stdbool.h>
#include "Structures.h"
#include "Registo.h"
#include <stdio.h>
#include "Utils.h"
#include "Files.h"
#include <string.h>
#include <stdlib.h>
/**
 * @brief Define o numero de linhas
 */
#define Linhas 6

/**
 * @brief Recebendo um codigo verifica na lista de jogos se o código existe 
 * @param jogos a lista de jogos
 * @param codigo o codigo do jogo
 * @param contJogos o numero de jogos
 * @return a posicao do jogo
 */
int verificarCodigo(struct Jogo *jogos, unsigned short codigo, unsigned short contJogos) {
    int j, i;

    for (i = 0; i < contJogos; i++) {
        if (jogos[i].codigo == codigo) {
            j = i;
            break;
        }
    }
    if (j == i)
        return i;
    else
        return -1;
}

/**
 * @brief Recebendo um codigo envia esse codigo para a funcao que percorre a lista de jogos 
 * @param jogos a lista de jogos
 * @param codigo o codigo do jogo
 * @param contJogos o numero de jogos
 * @return true se o jogo existir, false se chegar ao fim da lista e não encontrar
 */
bool existeJogo(struct Jogo *jogos, unsigned short contJogos, unsigned short codigo) {
    int i = 0;
    while (i < contJogos && verificarCodigo(jogos, codigo, contJogos) == -1)
        i++;

    if (i == contJogos)
        return false;
    else
        return true;
}

/**
 * @brief Permite inserir um novo jogo na lista de jogos
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista de jogos
 * @param contJogos o numero de jogos
 * @param jogadores lista de jogadores
 * @param posicaoJ1 a posicao do jogador 1
 * @param posicaoJ2 a posicao do jogador 2
 * @return a posicao do jogo
 */

int registoJogo(char mesa[][Colunas], struct Jogo **jogos, unsigned short *contJogos, struct Jogador *jogadores,
        int posicaoJ1, int posicaoJ2) {
    struct Jogo *novo = realloc(*jogos, sizeof (struct Jogo) * (*contJogos + 1));
    unsigned short codigo;
    printf("Codigo para o jogo: \n");
    scanf("%uh", &codigo);
    limparBuffer();
    if (novo == NULL) {
        printf("Impossivel realocar memória!\n");
    } else {
        if (existeJogo(*jogos, *contJogos, codigo) != true) {
            novo[*contJogos].codigo = codigo;
            novo[*contJogos].jogador1 = jogadores[posicaoJ1];
            novo[*contJogos].jogador2 = jogadores[posicaoJ2];
            for (int i = 0; i < Linhas; i++) {
                for (int j = 0; j < Colunas; j++) {
                    novo[*contJogos].mesa[i][j] = mesa[i][j];
                }
            }
            *jogos = novo;
            (*contJogos)++;
            return verificarCodigo(*jogos, codigo, *contJogos);
        } else
            return verificarCodigo(*jogos, codigo, *contJogos);
    }
}

/**
 * @brief Recebendo um nome verifica na lista de jogadores se o nome existe 
 * @param jogadores a lista de jogadores
 * @param nickname o nome do jogador
 * @param contJogadores o numero de jogadores
 * @return a posicao do jogador
 */
int verificarNickname(struct Jogador *jogadores, char username[], unsigned short contJogadores) {
    int j, i;
    for (i = 0; i < contJogadores; i++) {
        if (strcmp(jogadores[i].nome, username) == 0) {
            j = i;
            break;
        }
    }
    if (j == i)
        return i;
    else
        return -1;
}

/**
 * @brief Recebendo um nickname envia esse nickname para a funcao que percorre a lista de jogadores 
 * @param jogadores a lista de jogadores
 * @param nickname o codigo do jogadores
 * @param contJogadores o numero de jogos
 * @return true se o jogo existir, false se chegar ao fim da lista e não encontrar
 */
bool existeJogador(struct Jogador *jogadores, unsigned short contJogadores, char nickname[]) {
    int i = 0;
    while (i < contJogadores && verificarNickname(jogadores, nickname, contJogadores) == -1)
        i++;

    if (i == contJogadores)
        return false;
    else
        return true;
}

/**
 * @brief Permite inserir o jogador PC na lista de jogadores
 * @param jogadores a lista de jogadores
 * @param contJogadores o numero de jogadores
 * @return a posicao do jogador
 */
int registoPC(struct Jogador **jogadores, unsigned short *contJogadores) {

    struct Jogador *novo = realloc(*jogadores, sizeof (struct Jogador)* (*contJogadores + 1));
    if (novo == NULL) {
        printf("Impossivel realocar memória!\n");
    } else {
        if (novo[*contJogadores].nome != NULL) {
            if (existeJogador(*jogadores, *contJogadores, "PC") != true) {
                strcpy(novo[*contJogadores].nome, "PC");
                novo[*contJogadores].numeroVitorias = 0;
                *jogadores = novo;
                (*contJogadores)++;
                return verificarNickname(*jogadores, "PC", *contJogadores);
            } else
                return verificarNickname(*jogadores, "PC", *contJogadores);
        }
    }
}

/**
 * @brief Permite inserir o jogador numero 2 na lista de jogadores
 * @param jogadores a lista de jogadores
 * @param contJogadores o numero de jogadores
 * @param posicaoJ1 a posicao do jogador 
 * @return a posicao do jogador se inseriu, -1 se o jogador anterior tem o mesmo nome
 */
int registoJogador2(struct Jogador **jogadores, unsigned short *contJogadores, int posicaoJ1) {
    struct Jogador *novo = realloc(*jogadores, sizeof (struct Jogador)* (*contJogadores + 1));
    char nickname[TAM_MAX_NOME];
    if (novo == NULL) {
        printf("Impossivel realocar memória!\n");
    } else {
        if (novo[*contJogadores].nome != NULL) {
            readString(nickname, TAM_MAX_NOME, "Digite o nickname: \n");
            if (existeJogador(*jogadores, *contJogadores, nickname) != true) {
                strcpy(novo[*contJogadores].nome, nickname);
                novo[*contJogadores].numeroVitorias = 0;
                *jogadores = novo;
                (*contJogadores)++;
                return verificarNickname(*jogadores, nickname, *contJogadores);
            } else
                if (posicaoJ1 == verificarNickname(*jogadores, nickname, *contJogadores)) {
                printf("Nao pode jogar contra si proprio!\n");
                pressionarTecla();
                return -1;
            }
        }
    }
}

/**
 * @brief Permite inserir um novo jogador na lista de jogadores
 * @param jogadores a lista de jogadores
 * @param contJogadores o numero de jogadores
 * @return a posicao do jogador
 */
int registoJogador(struct Jogador **jogadores, unsigned short *contJogadores) {
    struct Jogador *novo = realloc(*jogadores, sizeof (struct Jogador)* (*contJogadores + 1));
    char nickname[TAM_MAX_NOME];
    if (novo == NULL) {
        printf("Impossivel realocar memória!\n");
    } else {
        if (novo[*contJogadores].nome != NULL) {
            readString(nickname, TAM_MAX_NOME, "Digite o nickname: \n");
            if (existeJogador(*jogadores, *contJogadores, nickname) != true) {
                strcpy(novo[*contJogadores].nome, nickname);
                novo[*contJogadores].numeroVitorias = 0;
                *jogadores = novo;
                (*contJogadores)++;
                return verificarNickname(*jogadores, nickname, *contJogadores);
            } else
                return verificarNickname(*jogadores, nickname, *contJogadores);
        }
    }
}