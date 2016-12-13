/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: pmms8
 *
 * Created on October 27, 2016, 12:11 PM
 */

#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

    void limparBuffer();
    void limparEcra();
    void displayMessage(char const *const message);
    bool readString(char * const value, const unsigned int size, char const* const message);
    void pressionarTecla();
    void novaColuna();

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

