#include <iostream>
#include <string>
#include "Autor.h"

using namespace std;

Autor::Autor()
{
    cadastrar_autor();
}

Autor::Autor(string nome, string nacionalide, string genero)
{
    _nome = nome;
    _nacionalidade = nacionalide;
    _genero = genero;
}

Autor::~Autor()
{
}

void Autor::cadastrar_autor()
{
    cout << "Nome: ";
    getline(cin, _nome);
    cout << "Genero: ";
    getline(cin, _genero);
    cout << "País de origem: ";
    getline(cin, _nacionalidade);
}

void Autor::excluir_autor()
{
    Autor::~Autor();
}

void Autor::exibir_autor()
{
    cout << "Nome: " << _nome << endl;
    cout << "Gênero: " << _genero << endl;
    cout << "Nacionalidade: " << _nacionalidade << endl;
}

void Autor::editar_autor()
{
    cadastrar_autor();
}