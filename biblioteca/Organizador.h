#ifndef ORGANIZADOR_H
#define ORGANIZADOR_H

#include "Biblioteca.h"
class Biblioteca;

using namespace std;

class Organizador: public Biblioteca {
private:
    list<Livro>::iterator org_it;
public:
    Organizador(){}
    ~Organizador(){}

    void ordem_numerica(string);
    void ordem_alfabetica(string);
};

#endif