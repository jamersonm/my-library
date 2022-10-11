#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include "Livros.h"
#include "Autores.h"
//#include "Datas.h"
//#include "Menus.h"

using namespace std;

int main()
{
    Autores a;
    Livros l;
    a.criar_autor();
    a.criar_autor();
    l.criar_livro(a);
    l.criar_livro(a);
    return 0;
}