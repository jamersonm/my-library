#include <iostream>
#include "Lista_autores.h"

using namespace std;

Lista_autores::Lista_autores(){}

Lista_autores::~Lista_autores(){}

Autor* Lista_autores::get_autor(int resp){
    it = lista_autores.begin();
    advance(it, resp - 1);
    return &(*it);
}

void Lista_autores::criar_autor(){
    Autor a;
    lista_autores.push_back(a);
}

void Lista_autores::criar_autor(string nome, string genero, string nacionalidade){
    Autor a(nome, genero, nacionalidade);
    lista_autores.push_back(a);
}

Autor* Lista_autores::pesquisar_autor(string nome){
    for(it = lista_autores.begin(); it != lista_autores.end(); ++it){
        if((*it).get_nome() == nome)
            return &(*it);
    }
    cout << "Autor não localizado" << endl;
    return;
}

void Lista_autores::exibir_autores(){
    _index_autores = 1;
    for(it = lista_autores.begin(); it != lista_autores.end(); ++it){
        cout << _index_autores  << ". " << (*it).get_nome() << endl;
        _index_autores++;
    }
}

void Lista_autores::excluir_autor_lista(string nome){
    for(it = lista_autores.begin(); it != lista_autores.end(); ++it){
        if((*it).get_nome() == nome)
            it = lista_autores.erase(it);
    }
}