#ifndef AUTORES_H
#define AUTORES_H

#include <list>
#include "Autor.h"

class Autores
{
private:
    list<Autor> autores;
    int index_autores;
public:
    Autores(){}
    ~Autores(){}

    void set_index_autores(int a){index_autores = a;}
    int get_index_autores(){return index_autores;}
    int get_tam_autores(){return autores.size();}

    void criar_autor();
    Autor* get_autor(int);
    void exibir_autores();
};

#endif