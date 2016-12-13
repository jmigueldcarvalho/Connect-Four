
/* 
 * File:   main.c
 * Author: pmms8
 *
 * Created on November 14, 2016, 10:13 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Structures.h"
#include "Files.h"
#include "Board.h"
#include "Utils.h"
#include "Files.h"
#include "Registo.h"
/**
 * @brief Define o numero de linhas do tabuleiro  
 */
#define Linhas 6
/**
 * @brief Define o numero de colunas do tabuleiro 
 */
#define Colunas 7

int main(int argc, char** argv) {
    unsigned short contadorJogos = 0, contadorJogadores = 0;
    struct Jogador *jogadores = NULL;
    struct Jogo *jogos = NULL;
    char mesa[Linhas][Colunas];
    int ret, ret1, ret2, ret3, op;

    puts("Apagar ficheiros?");
    puts("1 - SIM");
    puts("2 - NAO");
    scanf("%d",&op);
    limparBuffer();
    switch (op) {
        case 1:
            ret = remove("Jogadores.dat");
            ret1 = remove("Jogos.dat");
            ret2 = remove("tamanho.txt");
            ret3 = remove("tamanhoJogos.txt");
            if (ret == 0 && ret1 == 0 && ret2 == 0 && ret3 == 0) {
                printf("Ficheiro Apagados!\n");
            } else {
                printf("Nao foi possivel remover ficheiros!\n");
            }
            break;
        case 2:
            break;
    }

    contadorJogadores = carregarJogadores(&jogadores);
    contadorJogos = carregarJogos(&jogos);
    menuPrincipal(mesa, jogadores, &jogos, &contadorJogos, &contadorJogadores);
    for (int i = 0; i < contadorJogadores; i++) {
        free(&jogadores[i]);
    }
    jogadores = NULL;
    for (int i = 0; i < contadorJogos; i++) {
        free(&jogos[i]);
    }
    jogos = NULL;
    return (EXIT_SUCCESS);
}