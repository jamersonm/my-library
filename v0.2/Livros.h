#ifndef LIVROS_H
#define LIVROS_H

#include <list>
#include "Livro.h"
#include "Autores.h"

class Livros
{
private:
    list<Livro> livros;
    int index_livros;
public:
    Livros(){}
    ~Livros(){}

    void criar_livro(Autores);
    void exibir_livros();
};

#endif