#ifndef LISTA_AUTORES_H
#define LISTA_AUTORES_H

#include <list>
#include "Autor.h"

class Lista_autores
{
private:
    list<Autor> lista_autores;
    list<Autor>::iterator it;
    int _index_autores;
public:
    Lista_autores();
    ~Lista_autores();

    int get_tam_autores(){return lista_autores.size();}

    Autor* get_autor(int);

    void criar_autor();
    void criar_autor(string, string, string);
    Autor* pesquisar_autor(string);
    void exibir_autores();
    void excluir_autor_lista(string);
};


#endif