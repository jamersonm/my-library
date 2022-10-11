#include <iostream>
#include "Autor.h"
#include "Livro.h"

using namespace std;

bool ler_opcao(int resp, int min, int max)
{
    cin >> resp;
    if (resp >= min || resp <= max)
        return true;
    cout << "Opção inválida";
    return false;
}

void menu_principal()
{
    int resp;
    do
    {
        cout << "--------   MENU PRINCIPAL -------" << endl;
        cout << "1. Cadastrar autor." << endl;
        cout << "2. Cadastrar livro." << endl;
        cout << "3. Apagar livro." << endl;
        cout << "4. Sair." << endl;
    } while (&resp, ler_opcao(resp, 0, 2) == false);
    switch (resp)
    {
    case 1:
        autor[index_autor].cadastrar_autor();
        nome_autores.push_back(autor[index_autor].get_nome());
        index_autor++; 
        break;
    case 2:
        livro[index_livro].cadastrar_livro();
        index_autor++; 
        break;
    case 3:
        cout << 3;
        break;
    default:
        cout << 4;
        break;
    }
}