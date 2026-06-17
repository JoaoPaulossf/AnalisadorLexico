#ifndef ERROLEXICO_H
#define ERROLEXICO_H

#include <exception>
#include <string>

class ErroLexico : public std::exception {
private:
    char caractereEncontrado;
    std::string mensagemErro;
    std::string caracteresEsperados;

public:
    ErroLexico(char encontrado, std::string esperados) : caractereEncontrado(encontrado), caracteresEsperados(esperados) {
        mensagemErro = "Erro lexico : caractere encontrado: '";
        mensagemErro += (caractereEncontrado == '\0') ? "EOF" : std::string(1, caractereEncontrado);
        mensagemErro += "'\nEsperado: " + caracteresEsperados;
    }

    virtual const char* what() const noexcept override {
        return mensagemErro.c_str();
    }
};

#endif