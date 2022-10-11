#include <iostream>
#include <string>
#include "Autor.h"

using namespace std;

Autor::Autor()
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