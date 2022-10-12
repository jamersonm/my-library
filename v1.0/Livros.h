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

    int get_tam_livros(){return livros.size();}

    void criar_livro(Autores);
    void criar_livro(string, int, string, string, Autores);
    Livro* get_livro(int);
    Livro* pesquisar_livro(string);
    void exibir_livros();
};

#endif