/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: pmms8
 *
 * Created on November 14, 2016, 10:26 AM
 */

#ifndef BOARD_H
#define BOARD_H

#include "Structures.h"


#ifdef __cplusplus
extern "C" {
#endif
    /**
     * @brief Define o numero de colunas do tabuleiro
     */
#define Colunas 7

    void inicializarMatriz(char mesa[][Colunas]);
    void imprimirMatriz(char mesa[][Colunas]);
    char verificarVertical(char mesa[][Colunas], char jogador);
    char verificarHorizontal(char mesa[][Colunas], char jogador);
    char verificarDiagonalDireita(char mesa[][Colunas], char jogador);
    char verificarDiagonalEsquerda(char mesa[][Colunas], char jogador);
    char quatroEmLinha(char mesa[][Colunas], char jogador);
    char tabuleiroCheio(char mesa[][Colunas]);
    int colunaCheia(char mesa[][Colunas], int coluna);
    int pedirColuna(char mesa[][Colunas], struct Jogador *jogadores, int posicaoJogador);
    void colocarFicha(char mesa[][Colunas], char jogador, int coluna);
    void reinicioContraComputador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
            unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2);
    void reinicioContraJogador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
            unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2);
    void jogadaContraComputador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
            unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2);
    void jogadaContraJogador(char mesa[][Colunas], struct Jogo **jogos, struct Jogador *jogadores,
            unsigned short *contJogos, unsigned short *contJogadores, int posicaoJ1, int posicaoJ2);
    void menuJogo(char mesa[][Colunas], struct Jogador *jogadores, struct Jogo **jogos,
            unsigned short *contJogos, unsigned short *contJogadores);
    void reiniciarJogo(struct Jogo **jogos, unsigned short contaJogos, struct Jogador *jogadores, unsigned short contJogadores);
    void mostrarRecordes(struct Jogador *jogadores, unsigned short contJogadores);
    void menuPrincipal(char mesa[][Colunas], struct Jogador *jogadores, struct Jogo **jogos,
            unsigned short *contJogos, unsigned short *contJogadores);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */

