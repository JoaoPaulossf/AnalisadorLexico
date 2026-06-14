#include <string>

enum Token{
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

class lexico{
    private:
        std::string entrada;
        int posicao;
        char proxCaractere; 
    public:
        lexico(std::string texto){
            entrada = texto;
            posicao = 0;
            proxToken();
        }
        void proxToken();

        void q0();
        void q1();
        void q2();
        void q3();
        void q4();
        void q5();
        void q6();
        void q7();
        void q8();
        void q9();
        void q10();

        Token tokenReconhecido;
};

void lexico::proxToken(){
    if(posicao < entrada.size()){
        proxCaractere = entrada[posicao++];
    } else {
        proxCaractere = '\0';
    }
}

void lexico::q0(){
    while(proxCaractere == ' ' || proxCaractere == '\t' || proxCaractere == '\n'){
        proxToken();
    }
    if(proxCaractere >= '0' && proxCaractere <= '9'){
        q1();
    } else if((proxCaractere >= 'a' && proxCaractere <= 'z') || (proxCaractere >= 'A' && proxCaractere <= 'Z')){
        q2();
    } else if(proxCaractere == '+' || proxCaractere == '-' || proxCaractere == '*' || proxCaractere == '/'){
        proxToken();
        q3();
    } else if(proxCaractere == '['){
        proxToken();
        q4();
    } else if(proxCaractere == ']'){
        proxToken();
        q5();
    } else if(proxCaractere == '('){
        proxToken();
        q6();
    } else if(proxCaractere == ')'){
        proxToken();
        q7();
    } else if(proxCaractere == '{'){
        proxToken();
        q8();
    } else if(proxCaractere == '}'){
        proxToken();
        q9();
    } else if(proxCaractere == '\0'){
        tokenReconhecido = EOF_FIM;
    }
}

void lexico::q1(){
    tokenReconhecido = NUM;

    if(isdigit(proxCaractere)){
        proxToken();
        q1();
    }
}

void lexico::q2(){
    tokenReconhecido = VAR;

    if(isalnum(proxCaractere)){
        proxToken();
        q2();
    }
}

void lexico::q3(){
    tokenReconhecido = OPERACAO;
}

void lexico::q4(){
    tokenReconhecido = ABRE_COLCHETE;
}

void lexico::q5(){
    tokenReconhecido = FECHA_COLCHETE;
}
 
void lexico::q6(){
    tokenReconhecido = ABRE_PARENTESE;
}

void lexico::q7(){
    tokenReconhecido = FECHA_PARENTESE;
}

void lexico::q8(){
    tokenReconhecido = ABRE_CHAVE;
}

void lexico::q9(){
    tokenReconhecido = FECHA_CHAVE;
}

void lexico::q10(){
    tokenReconhecido = EOF_FIM;
}
