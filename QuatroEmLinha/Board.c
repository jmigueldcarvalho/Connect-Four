/** 
 * @file
 * @author pmms8
 *
 * @brief Biblioteca que contém as funções necessárias à criação do jogo 
 * 4 em linha no estilo jogador vs jogador e jogador vs computador.
 * 
 * @date 2016-10-17 10:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Board.h"
#include "Utils.h"
#include "Structures.h"
#include "Files.h"
#include <time.h>
#include "Registo.h"
/**
 * @brief Indica o número de linhas da matriz do jogo
 */
#define Linhas 6
/**
 * @brief Indica o número de colunas da matriz do jogo
 */
#define Colunas 7
/**
 * @brief Mensagem apresentada ao utilizador
 */
#define JOGADA_INVALIDA "Jogada invalida...\n"
/**
 * @brief Mensagem apresentada ao utilizador
 */
#define COLUNA_CHEIA "Coluna cheia!\n"

/**
 * @brief Preenche o tabuleiro do jogo com espaços
 * Exemplo:
 * @code
 * inicializarMatriz(mesa);
 * @endcode
 * @param mesa o tabuleiro do jogo
 */
void inicializarMatriz(char mesa[][Colunas]) {
    int linha, coluna;
    limparEcra();
    for (linha = 0; linha < Linhas; linha++) {
        for (coluna = 0; coluna < Colunas; coluna++) {
            mesa[linha][coluna] = ' ';
        }
    }
}

/**
 * @brief Imprime o tabuleiro do jogo
 * Exemplo:
 * @code
 * imprimirMatriz(mesa);
 * @endcode
 * @param mesa o tabuleiro do jogo
 */
void imprimirMatriz(char mesa[][Colunas]) {
    int linha, coluna;
    limparEcra();
    for (linha = 0; linha < Linhas; linha++) {
        for (coluna = 0; coluna < Colunas; coluna++) {
            printf("| %c ", mesa[linha][coluna]);
        }
        puts("|");
        puts("-----------------------------");
    }
    puts("  1   2   3   4   5   6   7\n");
}

/**
 * @brief Percorre a matriz do jogo à procura de uma sequência de fichas na vertical
 * Exemplo:
 * @code
 * verificaVertical(mesa,'A');
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogador a letra correspondente ao jogador
 * @return A letra do jogadror se encontrou ou espaço se não encontrou uma sequência
 */
char verificarVertical(char mesa[][Colunas], char jogador) {
    int encontrou = 0, i, j, contador = 0, posicao = 0;
    i = 0;
    while (i < Linhas && !encontrou) {
        j = 0;
        while (j < Colunas && !encontrou) {
            contador = 0;
            posicao = i;
            while (mesa[posicao][j] == jogador && posicao < Linhas) {
                posicao++;
                contador++;
            }
            if (contador >= 4) {
                encontrou = 1;
            }
            j++;
        }
        i++;
    }
    if (encontrou == 1) {
        return jogador;
    } else
        return ' ';
}

/**
 * @brief Percorre a matriz do jogo à procura de uma sequência de fichas na horizontal
 * Exemplo:
 * @code
 * verificaHorizontal(mesa,'A');
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogador a letra correspondente ao jogador
 * @return A letra do jogadror se encontrou ou espaço se não encontrou uma sequência
 */
char verificarHorizontal(char mesa[][Colunas], char jogador) {
    int encontrou = 0, i, j, contador = 0, posicao = 0;

    i = 0;
    while (i < Linhas && !encontrou) {
        j = 0;
        while (j < Colunas && !encontrou) {
            contador = 0;
            posicao = j;
            while (mesa[i][posicao] == jogador && posicao < Colunas) {
                posicao++;
                contador++;
            }
            if (contador >= 4) {
                encontrou = 1;
            }
            j++;
        }
        i++;
    }
    if (encontrou == 1) {
        return jogador;
    } else
        return ' ';
}

/**
 * @brief Percorre a matriz do jogo à procura de uma sequência de fichas na diagonal à direita
 * Exemplo:
 * @code
 * verificaDiagonalDireita(mesa,'A');
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogador a letra correspondente ao jogador
 * @return A letra do jogadror se encontrou ou espaço se não encontrou uma sequência
 */
char verificarDiagonalDireita(char mesa[][Colunas], char jogador) {
    int encontrou = 0, i, j, contador = 0, posicaoL = 0, posicaoC = 0;
    i = 0;
    while (i < Linhas && !encontrou) {
        j = 0;
        posicaoC = 0;
        while (j < Colunas && !encontrou) {
            contador = 0;
            while (mesa[posicaoL][posicaoC] == jogador && posicaoC < Colunas && posicaoL < Linhas) {
                posicaoL++;
                posicaoC--;
                contador++;
            }
            posicaoC++;
            if (contador >= 4) {
                encontrou = 1;
            }
            j++;
        }
        posicaoL++;
        i++;
    }
    if (encontrou == 1) {
        return jogador;
    } else
        return ' ';
}

/**
 * @brief Percorre a matriz do jogo à procura de uma sequência de fichas na diagonal à esquerda
 * Exemplo:
 * @code
 * verificaDiagonalEsquerda(mesa,'A');
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogador a letra correspondente ao jogador
 * @return A letra do jogadror se encontrou ou espaço se não encontrou uma sequência
 */
char verificarDiagonalEsquerda(char mesa[][Colunas], char jogador) {
    int encontrou = 0, i, j, contador = 0, posicaoC = 0, posicaoL = 0;
    i = 0;
    while (i < Linhas && !encontrou) {
        j = 0;
        posicaoC = 0;
        while (j < Colunas && !encontrou) {
            contador = 0;
            while (mesa[posicaoL][posicaoC] == jogador && posicaoC < Colunas && posicaoL < Linhas) {
                posicaoL++;
                posicaoC++;
                contador++;
            }
            posicaoC++;
            if (contador >= 4) {
                encontrou = 1;
            }
            j++;
        }
        posicaoL++;
        i++;
    }
    if (encontrou == 1) {
        return jogador;
    } else
        return ' ';
}

/**
 * @brief Invoca as funcoes de verificacao em todas as direções à procura de uma vitória
 * Exemplo:
 * @code
 * quatroEmLinha(mesa,'A');
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogador a letra correspondente ao jogador
 * @return A letra do jogadror se encontrou ou espaço se não encontrou uma sequência
 */
char quatroEmLinha(char mesa[][Colunas], char jogador) {
    if (verificarVertical(mesa, jogador) != ' '
            || verificarHorizontal(mesa, jogador) != ' '
            || verificarDiagonalDireita(mesa, jogador) != ' '
            || verificarDiagonalEsquerda(mesa, jogador) != ' '
            ) {
        return jogador;
    } else
        return ' ';
}

/**
 * @brief Percorre o tabuleiro do jogo e verifica se já não existem espaços na matriz
 * Exemplo:
 * @code
 * tabuleiroCheio(mesa);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @return espaço se estiver imcompleto ou asterisco se já estiver cheio
 */
char tabuleiroCheio(char mesa[][Colunas]) {
    int i, j, imcompleto = 0;
    for (i = 0; i < Linhas; i++) {
        for (j = 0; j < Colunas; j++) {
            if (mesa[i][j] == ' ')
                imcompleto = 1;
        }
    }
    if (imcompleto != 1) {
        return '*';
    } else
        return ' ';
}

/**
 * @brief Dada uma coluna recebida por parametro, verifica se nessa coluna todas as posições já estão preenchidas
 * Exemplo:
 * @code
 * colunaCheia(mesa, 1);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param coluna a coluna requisitada
 * @return 1 se estiver cheia ou -1 se ainda for possivel jogar nessa coluna
 */
int colunaCheia(char mesa[][Colunas], int coluna) {
    int i, imcompleta = 0;
    for (i = 0; i < Linhas; i++) {
        if (mesa[i][coluna] == ' ') {
            imcompleta = 1;
            break;
        }
    }
    if (imcompleta == 1) {
        return -1;
    } else
        return 1;
}

/**
 * @brief Pede ao jogador para introduzir o numero da coluna onde deseja jogar
 * Exemplo:
 * @code
 * pedirColuna(mesa,jogadores,posicao);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogadores a lista de jogadores
 * @param posicaoJogador a posicao do jogador 
 * @return o numero da coluna
 */
int pedirColuna(char mesa[][Colunas], struct Jogador *jogadores, int posicaoJogador) {
    int coluna;
    limparEcra();
    imprimirMatriz(mesa);
    printf("Jogador %s\n", jogadores[posicaoJogador].nome);
    printf("Numero da coluna, '100' gravar ou '1000' para sair:\n");
    scanf("%d", &coluna);
    limparBuffer();
    return coluna;
}

/**
 * @brief Substitui o espaço na matriz pela letra do jogador
 * Exemplo:
 * @code
 * colocarFicha(mesa,'A',1);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogador a letra do jogador
 * @param coluna o numero da coluna 
 */
void colocarFicha(char mesa[][Colunas], char jogador, int coluna) {
    int i;
    for (i = Linhas - 1; i >= 0; i--) {
        if (mesa[i][coluna] == ' ') {
            mesa[i][coluna] = jogador;
            break;
        }
    }
}

/**
 * @brief Possibilita continuar as jogadas de um determinado jogo guardado (Jogador vs PC)
 * Exemplo:
 * @code
 * reinicioContraComputador(mesa,jogos,jogadores,contJogos,contJogadores,pos1,pos2);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 * @param posicaoJ1 a posicao do primeiro jogador
 * @param posicaoJ2 a posicao do segundo jogador
 */
void reinicioContraComputador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
        unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2) {
    int valido = 1, coluna;
    char jogador1 = 'A', jogador2 = 'B', res;
    do {
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            coluna = pedirColuna(mesa, jogadores, posicaoJ1);
            if (coluna == 1000) {
                return;
            }
            if (coluna == 100) {
                guardarJogos(*jogos, *contJogos);
                return;
            }
            if (coluna < 1 || coluna > 7) {
                printf(JOGADA_INVALIDA);
                novaColuna();
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                printf(COLUNA_CHEIA);
                novaColuna();
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador1, coluna);
        res = quatroEmLinha(mesa, jogador1);
        if (res != ' ') {
            break;
        }
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            srand((unsigned) time(NULL));
            coluna = rand() % 8;
            if (coluna < 1 || coluna > 7) {
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador2, coluna);
        res = quatroEmLinha(mesa, jogador2);
        if (res != ' ') {
            break;
        }
    } while (res == ' ' || tabuleiroCheio(mesa) != '*');
    imprimirMatriz(mesa);
    if (tabuleiroCheio(mesa) == '*') {
        printf("Empate...\n");
    }
    if (res != ' ') {
        if (res == jogador1) {
            jogadores[posicaoJ1].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ1].nome);
            pressionarTecla();
            return;
        }
        if (res == jogador2) {
            jogadores[posicaoJ2].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ2].nome);
            pressionarTecla();
            return;
        }


    }
}

/**
 * @brief Possibilita continuar as jogadas de um determinado jogo guardado (jogador vs Jogador)
 * Exemplo:
 * @code
 * reinicioContraJogador(mesa,jogos,jogadores,contJogos,contJogadores,pos1,pos2);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 * @param posicaoJ1 a posicao do primeiro jogador
 * @param posicaoJ2 a posicao do segundo jogador
 */
void reinicioContraJogador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
        unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2) {
    int coluna, valido = 1;
    char jogador1 = 'A', jogador2 = 'B', res;
    do {
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            coluna = pedirColuna(mesa, jogadores, posicaoJ1);
            if (coluna == 1000) {
                return;
            }
            if (coluna == 100) {
                guardarJogos(*jogos, *contJogos);
                return;
            }
            if (coluna < 1 || coluna > 7) {
                printf(JOGADA_INVALIDA);
                novaColuna();
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                printf(COLUNA_CHEIA);
                novaColuna();
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador1, coluna);
        res = quatroEmLinha(mesa, jogador1);
        if (res != ' ') {
            break;
        }
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            coluna = pedirColuna(mesa, jogadores, posicaoJ2);
            if (coluna == 1000) {
                return;
            }
            if (coluna == 100) {
                guardarJogos(*jogos, *contJogos);
                return;
            }
            if (coluna < 1 || coluna > 7) {
                printf(JOGADA_INVALIDA);
                novaColuna();
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                printf(COLUNA_CHEIA);
                novaColuna();
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador2, coluna);
        res = quatroEmLinha(mesa, jogador2);
        if (res != ' ') {
            break;
        }
    } while (res == ' ' || tabuleiroCheio(mesa) != '*');
    imprimirMatriz(mesa);
    if (tabuleiroCheio(mesa) == '*') {
        printf("Empate...\n");
    }
    if (res != ' ') {
        if (res == jogador1) {
            jogadores[posicaoJ1].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ1].nome);
            pressionarTecla();
            return;
        }
        if (res == jogador2) {
            jogadores[posicaoJ2].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ1].nome);
            pressionarTecla();
            return;
        }
    }
}

/**
 * @brief Da inicio a um jogo do tipo Jogador vs PC
 * Exemplo:
 * @code
 * jogadaContraComputador(mesa,jogos,jogadores,contJogos,contJogadores,pos1,pos2);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 * @param posicaoJ1 a posicao do primeiro jogador
 * @param posicaoJ2 a posicao do segundo jogador
 */
void jogadaContraComputador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
        unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2) {
    int valido = 1, coluna;
    char jogador1 = 'A', jogador2 = 'B', res;
    inicializarMatriz(mesa);
    do {
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            coluna = pedirColuna(mesa, jogadores, posicaoJ1);
            if (coluna == 1000) {
                return;
            }
            if (coluna == 100) {
                *contJogos = carregarJogos(jogos);
                do {
                    limparEcra();
                } while (registoJogo(mesa, jogos, &(*contJogos), jogadores, posicaoJ1, posicaoJ2) == -1);
                guardarJogos(*jogos, *contJogos);
                return;
            }
            if (coluna < 1 || coluna > 7) {
                printf(JOGADA_INVALIDA);
                novaColuna();
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                printf(COLUNA_CHEIA);
                novaColuna();
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador1, coluna);
        res = quatroEmLinha(mesa, jogador1);
        if (res != ' ') {
            break;
        }
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            srand((unsigned) time(NULL));
            coluna = rand() % 8;
            if (coluna < 1 || coluna > 7) {
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador2, coluna);
        res = quatroEmLinha(mesa, jogador2);
        if (res != ' ') {
            break;
        }
    } while (res == ' ' || tabuleiroCheio(mesa) != '*');
    imprimirMatriz(mesa);
    if (tabuleiroCheio(mesa) == '*') {
        printf("Empate...\n");
    }
    if (res != ' ') {
        if (res == jogador1) {
            jogadores[posicaoJ1].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ1].nome);
            pressionarTecla();
            return;
        }
        if (res == jogador2) {
            jogadores[posicaoJ2].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ2].nome);
            pressionarTecla();
            return;
        }


    }
}

/**
 * @brief Da inicio a um jogo do tipo Jogador vs PC
 * Exemplo:
 * @code
 * jogadaContraJogador(mesa,jogos,jogadores,contJogos,contJogadores,pos1,pos2);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 * @param posicaoJ1 a posicao do primeiro jogador
 * @param posicaoJ2 a posicao do segundo jogador
 */
void jogadaContraJogador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
        unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2) {
    int coluna, valido = 1;
    char jogador1 = 'A', jogador2 = 'B', res;
    inicializarMatriz(mesa);
    do {
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            coluna = pedirColuna(mesa, jogadores, posicaoJ1);
            if (coluna == 1000) {
                return;
            }
            if (coluna == 100) {
                *contJogos = carregarJogos(jogos);
                do {
                    limparEcra();
                } while (registoJogo(mesa, jogos, &(*contJogos), jogadores, posicaoJ1, posicaoJ2) == -1);
                guardarJogos(*jogos, *contJogos);
                return;
            }
            if (coluna < 1 || coluna > 7) {
                printf(JOGADA_INVALIDA);
                novaColuna();
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                printf(COLUNA_CHEIA);
                novaColuna();
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador1, coluna);
        res = quatroEmLinha(mesa, jogador1);
        if (res != ' ') {
            break;
        }
        if (tabuleiroCheio(mesa) == '*') {
            break;
        }
        do {
            valido = 1;
            coluna = pedirColuna(mesa, jogadores, posicaoJ2);
            if (coluna == 1000) {
                return;
            }
            if (coluna == 100) {
                *contJogos = carregarJogos(jogos);
                do {
                    limparEcra();
                } while (registoJogo(mesa, jogos, &(*contJogos), jogadores, posicaoJ1, posicaoJ2) == -1);
                guardarJogos(*jogos, *contJogos);
                return;
            }
            if (coluna < 1 || coluna > 7) {
                printf(JOGADA_INVALIDA);
                novaColuna();
                valido = 0;
            }
            coluna--;
            if (colunaCheia(mesa, coluna) == 1) {
                printf(COLUNA_CHEIA);
                novaColuna();
                valido = 0;
            }
        } while (valido == 0);
        colocarFicha(mesa, jogador2, coluna);
        res = quatroEmLinha(mesa, jogador2);
        if (res != ' ') {
            break;
        }
    } while (res == ' ' || tabuleiroCheio(mesa) != '*');
    imprimirMatriz(mesa);
    if (tabuleiroCheio(mesa) == '*') {
        printf("Empate...\n");
    }
    if (res != ' ') {
        if (res == jogador1) {
            jogadores[posicaoJ1].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ1].nome);
            pressionarTecla();
            return;
        }
        if (res == jogador2) {
            jogadores[posicaoJ2].numeroVitorias++;
            guardarJogadores(jogadores, *contJogadores);
            printf("%s ganhou o jogo!\n", jogadores[posicaoJ2].nome);
            pressionarTecla();
            return;
        }
    }
}

/**
 * @brief Menu que dá a escolher o tipo de jogo
 * Exemplo:
 * @code
 * menuJogo(mesa,jogadores,jogos,contJogos,contJogadores);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 */
void menuJogo(char mesa[][Colunas], struct Jogador *jogadores, struct Jogo **jogos,
        unsigned short *contJogos, unsigned short *contJogadores) {
    unsigned short op;
    int pos1, pos2, pos3, pos4;

    limparEcra();
    do {
        puts("--------------------------------------------");
        puts("-----------Pretende jogar contra:-----------");
        puts("-----------1 - Computador-------------------");
        puts("-----------2 - Jogador----------------------");
        puts("-----------3 - VOLTAR-----------------------");
        puts("--------------------------------------------");
        printf("\nInsira a opcao\n\n");
        scanf("%d", &op);
        limparBuffer();
        switch (op) {
            case 1:
                if (*contJogadores == 0) {
                    pos2 = registoPC(&jogadores, &(*contJogadores));
                    guardarJogadores(jogadores, *contJogadores);
                    *contJogadores = carregarJogadores(&jogadores);
                    limparEcra();
                    puts("\nJogador 1: ");
                    pos1 = registoJogador(&jogadores, &(*contJogadores));
                    guardarJogadores(jogadores, *contJogadores);
                    jogadaContraComputador(mesa, jogos, jogadores, &(*contJogos), &(*contJogadores), pos1, pos2);
                    break;
                } else {
                    *contJogadores = carregarJogadores(&jogadores);
                    limparEcra();
                    puts("\nJogador 1: ");
                    pos1 = registoJogador(&jogadores, &(*contJogadores));
                    guardarJogadores(jogadores, *contJogadores);
                    jogadaContraComputador(mesa, jogos, jogadores, &(*contJogos), &(*contJogadores), pos1, 0);
                    break;
                }

            case 2:
                if (*contJogadores == 0) {
                    registoPC(&jogadores, &(*contJogadores));
                    guardarJogadores(jogadores, *contJogadores);
                }
                *contJogadores = carregarJogadores(&jogadores);
                limparEcra();
                puts("\nJogador 1: ");
                pos3 = registoJogador(&jogadores, &(*contJogadores));
                guardarJogadores(jogadores, *contJogadores);
                *contJogadores = carregarJogadores(&jogadores);
                do {
                    limparEcra();
                    puts("\nJogador 2: ");
                    pos4 = registoJogador2(&jogadores, &(*contJogadores), pos3);
                } while (pos4 == -1);
                if (pos4 != -1) {
                    guardarJogadores(jogadores, *contJogadores);
                    jogadaContraJogador(mesa, jogos, jogadores, &(*contJogos), &(*contJogadores), pos3, pos4);
                    break;
                }
            case 3:
                menuPrincipal(mesa, jogadores, jogos, &(*contJogos), &(*contJogadores));
                break;
        }
    } while (op != 3);
}

/**
 * @brief Possibilita continuar a jogar um jogo gravado em ficheiro
 * Exemplo:
 * @code
 * reiniciarJogo(jogos,contJogos,jogadores,contJogadores);
 * @endcode
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 */
void reiniciarJogo(struct Jogo **jogos, unsigned short contaJogos, struct Jogador *jogadores, unsigned short contJogadores) {
    unsigned short codigo;
    int posicao, pos1, pos2 = 0, pos3, pos4;
    printf("\nIntroduza o codigo: \n");
    scanf("%uh", &codigo);
    limparBuffer();
    posicao = verificarCodigo(*jogos, codigo, contaJogos);
    if (posicao == -1) {
        puts("\nCodigo nao existe!");
        pressionarTecla();
        limparEcra();
    } else {
        if (jogos[posicao]->jogador2.nome != "PC") {
            pos3 = verificarNickname(jogadores, jogos[posicao]->jogador1.nome, contJogadores);
            pos4 = verificarNickname(jogadores, jogos[posicao]->jogador2.nome, contJogadores);
            reinicioContraJogador(jogos[posicao]->mesa, jogos, jogadores, &contaJogos, &contJogadores, pos3, pos4);
        } else {
            pos1 = verificarNickname(jogadores, jogos[posicao]->jogador1.nome, contJogadores);
            reinicioContraComputador(jogos[posicao]->mesa, jogos, jogadores, &contaJogos, &contJogadores, pos1, pos2);
        }
    }
}

/**
 * @brief Imprime a pontuação de todos os jogadores
 * Exemplo:
 * @code
 * mostrarRecordes(jogadores,contJogadores);
 * @endcode
 * @param jogadores a lista de jogadores
 * @param contJogadores o numero de jogadores 
 */
void mostrarRecordes(struct Jogador *jogadores, unsigned short contJogadores) {
    int j = 0;
    limparEcra();
    puts("Nickname\t\tVitorias");
    /*    int vitorias[contJogadores];

        for (int i = 0; i < contJogadores; i++) {
            for(int p = 0; p < contJogadores; p++){
            if(jogadores[i].numeroVitorias > jogadores[p].numeroVitorias){ 
                vitorias[j] = jogadores[i].numeroVitorias;
                j++;
                break;
            }
            }
        }
     */
    for (int i = 0; i < contJogadores; i++) {
        printf("%s", jogadores[i].nome);
        printf("\t\t\t%d\n", jogadores[i].numeroVitorias);
    }
    printf("\n");
}

/**
 * @brief Menu inicial
 * Exemplo:
 * @code
 * menuPrincipal(mesa,jogadores,jogos,contJogos,contJogadores);
 * @endcode
 * @param mesa o tabuleiro do jogo
 * @param jogos a lista dos jogos
 * @param jogadores a lista de jogadores
 * @param contJogos o numero de jogos
 * @param contJogadores o numero de jogadores 
 */
void menuPrincipal(char mesa[][Colunas], struct Jogador *jogadores, struct Jogo **jogos,
        unsigned short *contJogos, unsigned short *contJogadores) {
    unsigned short op;
    limparEcra();
    do {
        puts("--------------------------------------------");
        puts("-----------Quatro em Linha!-----------------");
        puts("-----------1 - Novo Jogo--------------------");
        puts("-----------2 - Carregar Jogo---------------");
        puts("-----------3 - Recordes--------------------");
        puts("-----------4 - SAIR-------------------------");
        puts("--------------------------------------------");
        printf("\nInsira a opcao\n");
        scanf("%d", &op);
        limparBuffer();
        switch (op) {
            case 1:
                menuJogo(mesa, jogadores, jogos, &(*contJogos), &(*contJogadores));
                break;
            case 2:
                *contJogos = carregarJogos(jogos);
                reiniciarJogo(jogos, *contJogos, jogadores, *contJogadores);
                break;
            case 3:
                mostrarRecordes(jogadores, *contJogadores);
                break;
            case 4:
                break;
        }
    } while (op != 4);
}