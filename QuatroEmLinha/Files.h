/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Files.h
 * Author: pmms8
 *
 * Created on 2 de Novembro de 2016, 1:09
 */

#ifndef FILES_H
#define FILES_H

#ifdef __cplusplus
extern "C" {
#endif

    void guardarJogos(struct Jogo *jogos, unsigned short contJogos);
    unsigned short carregarJogos(struct Jogo **jogos);
    void guardarJogadores(struct Jogador *jogadores, unsigned short contJogadores);
    unsigned short carregarJogadores(struct Jogador **jogadores);

#ifdef __cplusplus
}
#endif

#endif /* FILES_H */

