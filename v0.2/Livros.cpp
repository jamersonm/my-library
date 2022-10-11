#include <iostream>
#include <ios> //for <streamsize>
#include <limits> //for numeric_limits
#include "Livros.h"

using namespace std;

void Livros::criar_livro(Autores a)
{
    a.exibir_autores();
    cout << a.get_tam_autores() + 1 << ". Criar autor." << endl;
    cout << a.get_tam_autores() + 2 << ". Sair." << endl;
    int resp;
    
    do
    {
        cin >> resp;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(resp == a.get_tam_autores() + 2)
            return;
        else if(resp == a.get_tam_autores() + 1)
            a.criar_autor();
    } while (resp <= 0 || resp >= a.get_tam_autores() + 2);

    Livro l(a.get_autor(resp));
    livros.push_back(l);
}