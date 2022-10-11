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
    int _paginas, _index;
public:
    Livro(Autor*);
    ~Livro(){}

    void set_titulo(string a){_titulo = a;}
    void set_idioma(string a){_idioma = a;}
    void set_paginas(int a){_paginas = a;}
    void set_index(int a){_index = a;}
    int get_index(){return _index;}
    string get_titulo(){return _titulo;}
    string get_idioma(){return _idioma;}
    int get_paginas(){return _paginas;}
    string get_autor(){return autor->get_nome();}
    string get_autor_nacionalidade(){return autor->get_nacionalidade();}
    string get_autor_genero(){return autor->get_genero();}

    void cadastrar_livro();
    void excluir_livro();
    void exibir_livro();
};

#endif