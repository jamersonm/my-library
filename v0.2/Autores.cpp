#include <iostream>
#include "Autores.h"

using namespace std;

void Autores::criar_autor()
{
    Autor a;
    autores.push_back(a);
}

void Autores::exibir_autores()
{
    index_autores = 1;
    list<Autor>::iterator it;
    for(it = autores.begin(); it != autores.end(); ++it)
        {
            cout << index_autores << ". " << (*it).get_nome() << endl;
            index_autores++;   
        }
}

Autor* Autores::get_autor(int resp)
{
    list<Autor>::iterator it = autores.begin();
    advance(it, resp - 1);
    return &(*it);
}