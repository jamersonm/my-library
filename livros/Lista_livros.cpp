#include <iostream>
#include <ios>
#include <limits>
#include "Lista_livros.h"

using namespace  std;

Livro* Lista_livros::get_livro(int resp){
    it = lista_livros.begin();
    advance(it, resp);
    return &(*it);
}

void Lista_livros::criar_livro(Lista_autores autores){
    autores.exibir_autores();
    cout << autores.get_tam_autores() + 1 << ". Criar autor" << endl;
    cout << autores.get_tam_autores() + 2 << ". Voltar" << endl;
    
    int resp;

    do{
        cin >> resp;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(resp == autores.get_tam_autores() + 1)
            autores.criar_autor();
        else if(resp == autores.get_tam_autores() + 2)
            return;
    } while (resp <= 0 || resp > autores.get_tam_autores() + 2);

    Livro l(autores.get_autor(resp));
    lista_livros.push_back(l);
}

void Lista_livros::criar_livro(string titulo, int paginas, string idioma, string nome_autor, Lista_autores autores){
    Livro l(titulo, paginas, idioma, autores.pesquisar_autor(nome_autor));
    lista_livros.push_back(l);
}

Livro* Lista_livros::pesquisar_livro(string titulo){
    for(it = lista_livros.begin(); it != lista_livros.end(); ++it){
        if((*it).get_titulo() == titulo)
            return &(*it);
    }
    cout << "Livro não localizado" << endl;
    return;
}

void Lista_livros::exibir_livros(){
    _index_livros = 1;
    for(it = lista_livros.begin(); it != lista_livros.end(); ++it){
        cout << _index_livros << ". " << (*it).get_titulo() << endl;
        _index_livros++;
    }
}

void Lista_livros::excluir_livro_lista(string titulo){
    for(it = lista_livros.begin(); it != lista_livros.end(); ++it){
        if((*it).get_titulo() == titulo)
            it = lista_livros.erase(it);
    }
}