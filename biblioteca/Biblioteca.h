#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <list>
#include "../livros/Lista_livros.h"
#include "../autores/Lista_autores.h"
#include "Organizador.h"
#include "Registrador.h"

class Biblioteca
{
protected:
    Lista_livros livros;
    Lista_autores autores;
private:
    Organizador org;
    Registrador reg;
public:
    Biblioteca();
    ~Biblioteca();

    Lista_livros get_lista_livros(){return livros;}
    Lista_autores get_lista_autores(){return autores;}

    void menu_principal();
    void menu_autores();
    void menu_livros();
    void menu_ordem();
    void menu_estatisticas();
};

#endif