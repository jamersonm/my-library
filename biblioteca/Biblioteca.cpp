#include <iostream>
#include <ios>
#include <limits>
#include "Biblioteca.h"

using namespace std;

Biblioteca::Biblioteca()
{
    reg.criar_csv();
    reg.ler_csv();
    menu_principal();
}

Biblioteca::~Biblioteca()
{
    reg.limpar_csv();
    reg.escrever_csv();
}

void Biblioteca::menu_principal(){
    int resp;
    int resp;
    cout << "------- MENU PRINCIPAL -------" << endl << endl;
    cout << "1. Autores" << endl;
    cout << "2. Livros" << endl;
    cout << "3. Ordenação e organização" << endl;
    cout << "4. Estatísticas" << endl;
    cout << "5. Sair" << endl;
    while (resp <= 0 || resp > 5)
    {
        cin >> resp;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (resp <= 0 || resp > 5)
            cout << "Opção inválida" << endl;
    }
    switch (resp)
    {
    case 1:
        menu_autores();
        break;
    case 2:
        menu_livros();
        break;
    case 3:
        menu_ordem();
        break;
    case 4:
        menu_estatisticas();
        break;
    default:
        Biblioteca::~Biblioteca();
        break;
    }
}

void Biblioteca::menu_autores()
{
    int resp;
    do{
        cout << "------- MENU AUTORES -------" << endl << endl;
        cout << "1. Adicionar" << endl;
        cout << "2. Exibir" << endl;
        cout << "3. Listar" << endl;
        cout << "4. Editar" << endl;
        cout << "5. Excluir" << endl;
        cout << "6. Voltar" << endl;
        while (resp <= 0 || resp > 6)
        {
            cin >> resp;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (resp <= 0 || resp > 6)
                cout << "Opção inválida" << endl;
        }
        string nome;
        switch (resp)
        {
        case 1:
            autores.criar_autor();
            break;
        case 2:
            cout << "Digite o nome do autor que deseja exibir: ";
            getline(cin, nome);
            autores.pesquisar_autor(nome)->exibir_autor();
            break;
        case 3:
            autores.exibir_autores(); 
            break; 
        case 4:
            cout << "Digite o nome do autor que deseja editar: ";
            getline(cin, nome);
            autores.pesquisar_autor(nome)->editar_autor();
            break;    
        case 5:
            cout << "Digite o nome do autor que deseja excluir: ";
            getline(cin, nome);
            autores.pesquisar_autor(nome)->~Autor();
            break;
        default:
            return;
            break;
        }
    } while (resp != 6);
}

void Biblioteca::menu_livros(){
    int resp;
    do{
        cout << "------- MENU LIVROS -------" << endl << endl;
        cout << "1. Adicionar" << endl;
        cout << "2. Exibir" << endl;
        cout << "3. Listar" << endl;
        cout << "4. Editar" << endl;
        cout << "5. Excluir" << endl;
        cout << "6. Voltar" << endl; 
        while (resp <= 0 || resp > 6)
        {
            cin >> resp;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (resp <= 0 || resp > 6)
                cout << "Opção inválida" << endl;
        }
        string titulo;
        switch (resp)
        {
        case 1:
            livros.criar_livro(autores);
            break;
        case 2:
            cout << "Digite o titulo do livro que deseja exibir: ";
            getline(cin, titulo);
            livros.pesquisar_livro(titulo)->exibir_livro();
            break;
        case 3:
            livros.exibir_livros();
            break;
        case 4:
            cout << "Digite o titulo do livro que deseja editar: ";
            getline(cin, titulo);
            livros.pesquisar_livro(titulo)->editar_livro();    
            break; 
        case 5:
            cout << "Digite o titulo do livro que deseja exluir: ";
            getline(cin, titulo);
            livros.pesquisar_livro(titulo)->excluir_livro();
            break;
        default:
            return;
            break;
        }
    } while (resp != 6);
}

void Biblioteca::menu_ordem(){
    int resp;
    do{
        cout << "------- MENU ORDENAÇÃO -------" << endl << endl;
        int resp;
        cout << "1. Ordem alfabética dos titulos" << endl;
        cout << "2. Ordem alfabética dos autores" << endl;
        cout << "3. Ordenação por nacionalidades" << endl;
        cout << "4. Ordenação por idioma" << endl;
        cout << "5. Ordenação por genero dos autores" << endl;
        cout << "6. Ordem decrescente de páginas" << endl;
        cout << "7. Ordem crescente de páginas" << endl;
        cout << "8. Voltar" << endl;
        while (resp <= 0 || resp > 8)
        {
            cin >> resp;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (resp <= 0 || resp > 8)
                cout << "Opção inválida" << endl;
        }
        switch (resp)
        {
        case 1:
            org.ordem_alfabetica("titulo");
            break;
        case 2:
            org.ordem_alfabetica("nome");
            break;
        case 3:
            org.ordem_alfabetica("nacionalidade");
            break;
        case 4:
            org.ordem_alfabetica("idioma");
            break;
        case 5:
            org.ordem_alfabetica("genero");
            break;
        case 6:
            org.ordem_numerica("decrescente");
            break;
        case 7:
            org.ordem_numerica("crescente");
            break;
        default:
            return;
            break;
        }
    } while (resp != 8);
}