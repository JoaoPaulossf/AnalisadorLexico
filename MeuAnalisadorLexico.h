#ifndef MEUANALISADORLEXICO_H
#define MEUANALISADORLEXICO_H

#include "AnalisadorLexico.h"
#include "ErroLexico.h"

class MeuAnalisadorLexico : public AnalisadorLexico {
public:
    MeuAnalisadorLexico(const std::string& arquivoEntrada) : AnalisadorLexico(arquivoEntrada) {}

    void s0(){
        if(proxCaractereIs(Constantes::ESPACOS)){
            leProxCaractere();
            s0();
        } else if(proxCaractereIs(Constantes::DIGITOS)){
            leProxCaractere();
            s1();
        } else if(proxCaractereIs(Constantes::LETRAS)){
            leProxCaractere();
            s2();
        } else if(proxCaractereIs(Constantes::OPERADORES)){
            leProxCaractere();
            s3();
        } else if(proxCaractere == '['){
            leProxCaractere();
            s4();
        } else if(proxCaractere == ']'){
            leProxCaractere();
            s5();
        } else if(proxCaractere == '('){
            leProxCaractere();
            s6();
        } else if(proxCaractere == ')'){
            leProxCaractere();
            s7();
        } else if(proxCaractere == '{'){
            leProxCaractere();
            s8();
        } else if(proxCaractere == '}'){
            leProxCaractere();
            s9();
        } else if(proxCaractere == Constantes::EOF_CHAR){
            s10();
        } else {
            char invalido = proxCaractere;
            
            leProxCaractere();

            std::string esperados = Constantes::DIGITOS + Constantes::LETRAS + Constantes::OPERADORES + "[](){}";
            throw ErroLexico(invalido, esperados);
        }
    }
    void s1(){
        tokenReconhecido = Token::NUM;
        if(proxCaractereIs(Constantes::DIGITOS)){
            leProxCaractere();
            s1();
        }
        else if(proxCaractereIs(Constantes::LETRAS)){
            std::string esperados = "Espaco ou operador apos numero";
            throw ErroLexico(proxCaractere, esperados);
        }
    }

    void s2(){
        tokenReconhecido = Token::VAR;
        if(proxCaractereIs(Constantes::LETRAS + Constantes::DIGITOS) || proxCaractere == '_'){
            leProxCaractere();
            s2();
        }
    }

    void s3(){ tokenReconhecido = Token::OPERACAO; }
    void s4(){ tokenReconhecido = Token::ABRE_COLCHETE; }
    void s5(){ tokenReconhecido = Token::FECHA_COLCHETE; }
    void s6(){ tokenReconhecido = Token::ABRE_PARENTESE; }
    void s7(){ tokenReconhecido = Token::FECHA_PARENTESE; }
    void s8(){ tokenReconhecido = Token::ABRE_CHAVE; }
    void s9(){ tokenReconhecido = Token::FECHA_CHAVE; }
    void s10(){ tokenReconhecido = Token::EOF_FIM; }    
};

#endif