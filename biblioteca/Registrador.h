#ifndef REGISTRADOR_H
#define REGISTRADOR_H

#include "Biblioteca.h"
class Biblioteca;

using namespace std;

class Registrador: public Biblioteca {
private:

public:
    Registrador(){}
    ~Registrador(){}

    void criar_csv();
    void limpar_csv();
    void ler_csv();
    void escrever_csv();
};

#endif