#include <iostream>
#include <string>
#include <ios>
#include <limits>

#include "Livro.h"
#include "../autores/Autor.h"

using namespace std;

Livro::Livro(Autor* autor){
    _autor = autor;
    _nome_autor = autor->get_nome();
    cadastrar_livro();
}

Livro::Livro(string titulo, int paginas, string idioma, Autor* autor){
    _titulo = titulo;
    _paginas = paginas;
    _idioma = idioma;
    _nome_autor = autor->get_nome();
    _autor = autor;
}

Livro::~Livro(){}

void Livro::cadastrar_livro(){
    cout << "Autor: " << _autor->get_nome() << endl;
    cout << "Título: ";
    getline(cin, _titulo);
    cout << "Páginas: ";
    cin >> _paginas;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Idioma: ";
    getline(cin, _idioma);
}

void Livro::editar_livro(){
    cadastrar_livro();
}

void Livro::exibir_livro(){
    cout << "Autor: " << _autor->get_nome() << endl;
    cout << "Título: " << _titulo << endl;
    cout << "Paginas: " << _paginas << endl;
}

void Livro::excluir_livro(){
    Livro::~Livro();
}
