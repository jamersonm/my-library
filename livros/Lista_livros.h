#ifndef LISTA_LIVROS_H
#define LSITA_LIVROS_H

#include <list>
#include "Livro.h"
#include  "../autores/Lista_autores.h"

class Lista_livros
{
private:
    list<Livro> lista_livros;
    list<Livro>::iterator it;
    int _index_livros;
public:
    Lista_livros();
    ~Lista_livros();

    int get_tam_livros(){return lista_livros.size();}
    list<Livro>::iterator get_begin_livros(){return lista_livros.begin();}
    list<Livro>::iterator get_end_livros(){return lista_livros.end();}

    Livro* get_livro(int);

    void criar_livro(Lista_autores);
    void criar_livro(string, int, string, string, Lista_autores);
    Livro* pesquisar_livro(string);
    void exibir_livros();
    void excluir_livro_lista(string);
};

#endif