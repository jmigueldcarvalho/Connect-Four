#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "Structures.h"
#include "Utils.h"
#include "Files.h"

/**
 * @brief Permite gravar a lista de jogos e o numero de jogos em ficheiro
 * @param jogos a lista de jogos
 * @param contJogos o numero de jogos
 */
void guardarJogos(struct Jogo *jogos, unsigned short contJogos) {
    FILE *pt, *pt2;
    pt = fopen("Jogos.dat", "wb");
    pt2 = fopen("tamanhoJogos.txt", "w");
    if (pt == (FILE *) NULL || pt2 == (FILE *) NULL) {
        printf("\nFicheiro danificado ou inexistente!\n");
    } else {
        fwrite(jogos, sizeof (struct Jogo), contJogos, pt);
        fclose(pt);
        fprintf(pt2, "%hu", contJogos);
        fclose(pt2);
    }
}

/**
 * @brief Permite carregar de ficheiro a lista de jogos e o numero de jogos
 * @param jogos a lista de jogos
 * @param contJogos o numero de jogos
 * @return o numero de jogos lido de ficheiro
 */
unsigned short carregarJogos(struct Jogo **jogos) {
    FILE *pt;
    unsigned short tamanho = 0;
    pt = fopen("tamanhoJogos.txt", "r");

    if (pt == (FILE *) NULL) {
        printf("\nFicheiro danificado ou inexistente!\n");
    } else {
        fscanf(pt, "%hu", &tamanho);
        fclose(pt);
    }
    if (tamanho > 0) {
        pt = fopen("Jogos.dat", "rb");
        *jogos = (struct Jogo*) malloc(sizeof (struct Jogo)*tamanho);
    }
    if (pt == (FILE *) NULL) {
        printf("\nFicheiro danificado ou inexistente!\n");
    } else {
        fread(*jogos, sizeof (struct Jogo), tamanho, pt);
        fclose(pt);
    }
    return tamanho;
}

/**
 * @brief Permite gravar a lista de jogadores e o numero de jogadores em ficheiro
 * @param jogadores a lista de jogadores
 * @param contJogadores o numero de jogadores
 */
void guardarJogadores(struct Jogador *jogadores, unsigned short contJogadores) {
    FILE *pt, *pt2;
    pt = fopen("Jogadores.dat", "wb");
    pt2 = fopen("tamanho.txt", "w");
    if (pt == (FILE *) NULL || pt2 == (FILE *) NULL) {
        printf("\nFicheiro danificado ou inexistente!\n");
    } else {
        fwrite(jogadores, sizeof (struct Jogador), contJogadores, pt);
        fclose(pt);
        fprintf(pt2, "%hu", contJogadores);
        fclose(pt2);
    }
}

/**
 * @brief Permite carregar de ficheiro a lista de jogadores e o numero de jogadores
 * @param jogadores a lista de jogadores
 * @param contJogadores o numero de jogadores
 * @return o numero de jogadores lido de ficheiro
 */
unsigned short carregarJogadores(struct Jogador **jogadores) {
    FILE *pt;
    unsigned short tamanho = 0;
    pt = fopen("tamanho.txt", "r");

    if (pt == (FILE *) NULL) {
        printf("\nFicheiro danificado ou inexistente!\n");
    } else {
        fscanf(pt, "%hu", &tamanho);
        fclose(pt);
    }
    if (tamanho > 0) {
        pt = fopen("Jogadores.dat", "rb");
        *jogadores = (struct Jogador*) malloc(sizeof (struct Jogador)*tamanho);
    }
    if (pt == (FILE *) NULL) {
        printf("\nFicheiro danificado ou inexistente!\n");
    } else {
        fread(*jogadores, sizeof (struct Jogador), tamanho, pt);
        fclose(pt);
    }
    return tamanho;
}