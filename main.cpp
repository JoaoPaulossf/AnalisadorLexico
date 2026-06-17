#include <iostream>
#include "MeuAnalisadorLexico.h"

int main(int argc, char* argv[]) {
    std::cout << "Analisador Léxico - C++\n";
    std::string arquivoEntrada = "entrada.txt";

    if (argc <= 1) {
        std::cout << "Digite o nome do arquivo ";

        std::string digitado;
        std::getline(std::cin, digitado);

        if(!digitado.empty()){
            arquivoEntrada = digitado;

            if(arquivoEntrada.size() < 4 || arquivoEntrada.substr(arquivoEntrada.size() - 4) != ".txt"){
                arquivoEntrada += ".txt";
            }
        }else{
            arquivoEntrada = argv[1];
        }
    } else {
        arquivoEntrada = argv[1];
    }

    std::cout << "Iniciando análise léxica do arquivo: " << arquivoEntrada << "\n\n";

    try {
        MeuAnalisadorLexico scanner(arquivoEntrada);
        Token t;
        std::string nomesTokens[] = {"NUM", "VAR", "OPERACAO", "ABRE_COLCHETE", "FECHA_COLCHETE", "ABRE_PARENTESE", "FECHA_PARENTESE", "ABRE_CHAVE", "FECHA_CHAVE", "EOF_FIM"};
        do{
            scanner.s0();
            t = scanner.getTokenReconhecido();
            std::cout << "Token reconhecido: " << nomesTokens[t] << "\n";
        } while (t != Token::EOF_FIM);
        
        std::cout << "\nAnálise léxica concluída com sucesso.\n";
    
    } catch (const ErroLexico& e) {
        std::cerr << "Falha na análise!\n" << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << "\n";
        return 1;
    }

    return 0;
}