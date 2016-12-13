/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registo.h
 * Author: pmms8
 *
 * Created on November 23, 2016, 12:16 PM
 */

#ifndef REGISTO_H
#define REGISTO_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Board.h"

    int verificarCodigo(struct Jogo *jogos, unsigned short codigo, unsigned short contJogos);
    bool existeJogo(struct Jogo *jogos, unsigned short contJogos, unsigned short codigo);
    int registoJogo(char mesa[][Colunas], struct Jogo **jogos, unsigned short *contJogos, struct Jogador *jogadores,
            int posicaoJ1, int posicaoJ2);
    int verificarNickname(struct Jogador *jogadores, char username[], unsigned short contJogadores);
    bool existeJogador(struct Jogador *jogadores, unsigned short contJogadores, char nickname[]);
    int registoJogador(struct Jogador **jogadores, unsigned short *contJogadores);
    int registoJogador2(struct Jogador **jogadores, unsigned short *contJogadores, int posicaoJ1);
    int registoPC(struct Jogador **jogadores, unsigned short *contJogadores);

#ifdef __cplusplus
}
#endif

#endif /* REGISTO_H */

