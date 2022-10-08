#include <iostream>
#include <string>
#include "Livro.h"
#include "Autor.h"

using namespace std;

Livro::Livro(Autor* a)
{
    this->autor = a;
    cadastrar_livro();
}

void Livro::cadastrar_livro()
{
    cout << "Autor: " << autor->get_nome() << endl;
    cout << "Título: ";
    getline(cin, _titulo);
    cout << "Páginas: ";
    cin >> _paginas;
    fflush(stdin);
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