#ifndef LIVRO_H
#define LIVRO_H
#include <string>
#include "Autor.h"

using namespace std;

class Livro
{
private:
    string _titulo, _idioma;
    Autor*autor;
    int _paginas;
public:
    Livro(Autor*);
    ~Livro(){}

    void set_titulo(string a){_titulo = a;}
    void set_idioma(string a){_idioma = a;}
    void set_paginas(int a){_paginas = a;}
    string get_titulo(){return _titulo;}
    string get_autor(){return autor->get_nome();}
    int get_paginas(){return _paginas;}

    void cadastrar_livro();
    void excluir_livro();
    void exibir_livro();
};

#endif