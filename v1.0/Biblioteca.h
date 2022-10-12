#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <list>
#include "Livros.h"

class Biblioteca
{
private:
    Livros livros;
    Autores autores;
public:
    Biblioteca();
    ~Biblioteca();

    Livros get_livros(){return livros;}
    Autores get_autores(){return autores;}

    void interface_principal();
    void interface_autores();
    void interface_livros();

    void criar_csv();
    void limpar_csv();
    void escrever_csv();
    void ler_csv();
};

#endif