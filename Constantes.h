#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

enum Token {
    NUM,
    VAR,
    OPERACAO,
    ABRE_COLCHETE,
    FECHA_COLCHETE,
    ABRE_PARENTESE,
    FECHA_PARENTESE,
    ABRE_CHAVE,
    FECHA_CHAVE,
    EOF_FIM
};

namespace Constantes {
    const std::string OPERADORES = "+-*/";
    const std::string LETRAS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string DIGITOS = "0123456789";
    const std::string ESPACOS = " \t\n\r";
    const char EOF_CHAR = '\0';
}

#endif