#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include "../autores/Autor.h"

using namespace std;

class Livro
{
private:
    string _titulo, _idioma, _nome_autor;
    Autor *_autor;
    int _paginas, _index;
public:
    Livro(Autor*);
    Livro(string, int, string, Autor*);
    ~Livro();

    void set_titulo(string a){_titulo = a;}
    void set_idioma(string a){_idioma = a;}
    void set_nome_autor(string a){_nome_autor = a;}
    void set_paginas(int a){_paginas = a;}
    void set_index(int a){_index = a;}

    string get_titulo(){return _titulo;}
    string get_idioma(){return _idioma;}
    string get_nome_autor(){return _nome_autor;}
    int get_paginas(){return _paginas;}
    int get_index(){return _index;}

    Autor get_autor(){return *_autor;}

    void cadastrar_livro();
    void editar_livro();
    void exibir_livro();
    void excluir_livro();
};

#endif