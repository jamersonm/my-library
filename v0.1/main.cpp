#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include "Livro.h"
#include "Autor.h"
//#include "Datas.h"
//#include "Menus.h"

using namespace std;

Autor autor[100];
//Livro livro[100];
list<string> nome_autores;



int index_lista;
void exibir_lista(list<string> const &g)
{
    int index_lista = 1;
    for(auto const &i: g)
    {
        cout << index_lista << ". " << i << endl;
        index_lista++;
    }
}

int index_autor = 0;
void criar_autor()
{
    autor[index_autor].cadastrar_autor();
    nome_autores.push_back(autor[index_autor].get_nome());
    index_autor++;
}

//int index_livro = 0;
void criar_livro()
{

}

int main()
{
    criar_livro();
    return 0;
}