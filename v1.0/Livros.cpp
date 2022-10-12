#include <iostream>
#include <ios> //for <streamsize>
#include <limits> //for numeric_limits
#include "Livros.h"

using namespace std;

void Livros::criar_livro(Autores a)
{
    a.exibir_autores();
    //cout << a.get_tam_autores() + 1 << ". Criar autor." << endl;
    cout << a.get_tam_autores() + 1 << ". Sair." << endl;
    int resp;
    
    do
    {
        cin >> resp;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(resp == a.get_tam_autores() + 1)
            return;
        /*else if(resp == a.get_tam_autores() + 1)
            a.criar_autor();*/
    } while (resp <= 0 || resp >= a.get_tam_autores() + 2);

    Livro l(a.get_autor(resp));
    livros.push_back(l);
}

void Livros::criar_livro(string titulo, int paginas, string idioma, string nome_autor, Autores a)
{
    Livro l(titulo, paginas, idioma, a.pesquisar_autor(nome_autor));
    livros.push_back(l);
}

void Livros::exibir_livros()
{
    index_livros = 1;
    list<Livro>::iterator it;
    for(it = livros.begin(); it != livros.end(); ++it)
    {
        cout << index_livros << ". " << (*it).get_titulo() << endl;
        index_livros++;   
    }
}

Livro* Livros::get_livro(int resp)
{
    list<Livro>::iterator it = livros.begin();
    advance(it, resp);
    return &(*it);
}

Livro* Livros::pesquisar_livro(string titulo)
{
    list<Livro>::iterator it;
    for(it = livros.begin(); it != livros.end(); ++it)
    {
        if((*it).get_titulo() == titulo)
        {
            return &(*it); 
        }    
    }
    cout << "Livro não localizado" << endl;
    return NULL;    
} 