#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include "Constantes.h"
#include <string>
#include <fstream>
#include <sstream>

class AnalisadorLexico {
protected:
    char proxCaractere;
    std::string entrada;
    size_t posicao;
    Token tokenReconhecido;
public:
    AnalisadorLexico(const std::string& arquivoEntrada){
        posicao = 0;
        std::ifstream arquivo(arquivoEntrada);
        if (!arquivo.is_open()) {
            entrada = "";
        } else {
            std::stringstream buffer;
            buffer << arquivo.rdbuf();
            entrada = buffer.str();
        }
        leProxCaractere();
    }

    void leProxCaractere() {
        if (posicao < entrada.size()) {
            proxCaractere = entrada[posicao++];
        } else {
            proxCaractere = Constantes::EOF_CHAR;
        }
    }

    bool proxCaractereIs(const std::string& conjunto) {
        return conjunto.find(proxCaractere) != std::string::npos;
    }
    Token getTokenReconhecido() const {
        return tokenReconhecido;
    }
};

#endif
