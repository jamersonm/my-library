#include <iostream>
#include <string>
#include <ios> //for <streamsize>
#include <limits> //for numeric_limits
#include "Livro.h"
#include "Autor.h"

using namespace std;

Livro::Livro(Autor* a)
{
    this->autor = a;
    nome_autor = a->get_nome();
    cadastrar_livro();
}

Livro::Livro(string titulo, int paginas, string idioma, Autor* a)
{
    _titulo = titulo;
    _paginas = paginas;
    _idioma = idioma;
    nome_autor = a->get_nome();
    autor = a;
}

Livro::~Livro()
{
}

void Livro::cadastrar_livro()
{
    cout << "Autor: " << autor->get_nome() << endl;
    cout << "Título: ";
    getline(cin, _titulo);
    cout << "Páginas: ";
    cin >> _paginas;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Idioma: ";
    getline(cin, _idioma);
}

void Livro::excluir_livro()
{
    Livro::~Livro();
}

void Livro::exibir_livro()
{
    cout << "Autor: " << autor->get_nome() << endl;
    cout << "Título: " << _titulo << endl;
    cout << "Paginas: " << _paginas << endl;
}
