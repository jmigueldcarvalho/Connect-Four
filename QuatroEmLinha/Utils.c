/** 
 * @file
 * @author pmms8
 *
 * @brief Biblioteca que contém as funções auxiliares de implementação da aplicação.
 * 
 * @date 2016-10-17 10:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Utils.h"

const char NOVA_LINHA = '\n';
static const char CAR_NOVA_LINHA = '\n';
static const char CAR_FRASE_FIM = '\0';

/**
 * @brief Limpa o buffer de entrada de dados.
 * @warning Caso não exista nenhuma informação no buffer, o programa pode
 *  ficar a aguardar que exista informação no buffer.
 * 
 * Exemplo:
 * @code
 *  char c:
 * 
 *  c = getchar();
 *  limparBuffer();
 * @endcode
 */
void limparBuffer() {
    char ch;

    while ((ch = getchar()) != NOVA_LINHA && ch != EOF);
}

/**
 * @brief Efetua a limpeza do ecrã puxando o conteúdo para o topo
 * 
 * Exemplo:
 * @code
 * 
 * int a = 0;
 * 
 * printf("%d",a);
 * limparEcra();
 * @endcode
 * 
 */
void limparEcra() {
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif 
}

/**
 * @brief Mostra uma mensagem ao utilizador
 * @param message a mensagem a mostrar
 */
void displayMessage(char const *const message) {
    printf("\n%s", message);
}

/**
 * @brief Permite a leitura de uma string da consola
 * @param value 
 * @param size o tamanho da string
 * @param message a mensagem a apresentar ao utilizador
 * @return true se conseguiu ler, false se não conseguiu
 */
bool readString(char * const value, const unsigned int size, char const* const message) {
    displayMessage(message);
    if (fgets(value, size, stdin) != NULL) {
        const unsigned int sTam = strlen(value) - 1;
        if (value[sTam] == CAR_NOVA_LINHA) {
            value[sTam] = CAR_FRASE_FIM;
        } else {
            limparEcra();
        }
        return true;
    } else
        return false;
}

/**
 * @brief Pede ao utilizador para pressionar uma tecla
 */
void pressionarTecla() {
    printf("Pressione uma tecla para voltar ao menu!\n");
    getchar();
}
/**
 * @brief Pede ao utilizador para pressionar uma tecla
 */
void novaColuna() {
    printf("Pessione uma tecla para introduzir nova coluna!\n");
    getchar();
}