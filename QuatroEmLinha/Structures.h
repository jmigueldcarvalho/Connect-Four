/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Structures.h
 * Author: pmms8
 *
 * Created on 2 de Novembro de 2016, 1:09
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief define o numero de linhas do tabuleiro
 */
#define Linhas 6
/**
 * @brief define o numero de colunas do tabuleiro
 */    
#define Colunas 7
    /**
     * @brief define o tamanho do nome do jogador
     */
#define TAM_MAX_NOME 30

    struct Jogador {
        char nome[TAM_MAX_NOME];
        int numeroVitorias;
    };

    struct Jogo {
        unsigned short codigo;
        struct Jogador jogador1;
        struct Jogador jogador2;
        char mesa[Linhas][Colunas];

    };

#ifdef __cplusplus
}
#endif

#endif /* STRUCTURES_H */

