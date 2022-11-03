#include <iostream>
#include <string>
#include "Autor.h"

using namespace std;

Autor::Autor(){
    cadastrar_autor();
}

Autor::Autor(string nome, string genero, string nacionalidade){
    _nome = nome;
    _genero = genero;
    _nacionalidade = nacionalidade;
}

Autor::~Autor(){}

void Autor::cadastrar_autor(){
    cout << "Nome: ";
    getline(cin, _nome);
    cout << "Genero: ";
    getline(cin, _genero);
    cout << "Nacionalidade: ";
    getline(cin, _nacionalidade);
}

void Autor::editar_autor(){
    cadastrar_autor();
}

void Autor::exibir_autor(){
    cout << "Nome: "  << _nome << endl;
    cout << "Genero: " << _genero << endl;
    cout << "Nacionalidade: " << _nacionalidade << endl;
}

void Autor::excluir_autor(){
    Autor::~Autor();
}