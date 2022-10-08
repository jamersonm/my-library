#include <iostream>
#include <string>

#include "Livro.h"
#include "Autor.h"
#include "Datas.h"

int main()
{
    criar_csv();
    Autor a0;
    Livro l0(&a0);
    escrever_csv(&a0, &l0);
    Livro l2(&a0);
    escrever_csv(&a0, &l2);
}