#include <iostream>
#include <string>
#include <ios> //for <streamsize>
#include <limits> //for numeric_limits
#include "Livro.h"
#include "Autor.h"
#include "Datas.h"

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