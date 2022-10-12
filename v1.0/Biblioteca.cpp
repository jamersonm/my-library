#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ios> //for <streamsize>
#include <limits> //for numeric_limits
#include "Biblioteca.h"

using namespace std;

Biblioteca::Biblioteca()
{
    criar_csv();
    ler_csv();
}

Biblioteca::~Biblioteca()
{
    limpar_csv();
    escrever_csv();
    exit(0);
}

void Biblioteca::interface_principal()
{
    int resp;
    cout << "------- MENU PRINCIPAL -------" << endl << endl;
    cout << "1. Autores" << endl;
    cout << "2. Livros" << endl;
    cout << "3. Sair" << endl;
    while (resp <= 0 || resp > 3)
    {
        cin >> resp;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (resp <= 0 || resp > 3)
            cout << "Opção inválida" << endl;
    }
    switch (resp)
    {
    case 1:
        interface_autores();
        break;
    case 2:
        interface_livros();
        break;
    default:
        Biblioteca::~Biblioteca();
        break;
    }
}

void Biblioteca::interface_autores()
{
    cout << "------- MENU AUTORES -------" << endl << endl;
    int resp;
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
        interface_principal();
        break;
    }
    interface_autores();
}

void Biblioteca::interface_livros()
{
    cout << "------- MENU LIVROS -------" << endl << endl;
    int resp;
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
        interface_principal();
        break;
    }
    interface_livros();
}

void Biblioteca::criar_csv()
{
    ifstream fin;
    fin.open("biblioteca.csv");
    if(fin.is_open())
    {

    }
    else
    {
        fstream fout;
        fout.open("biblioteca.csv", ios::out | ios::app);
    }
}

void Biblioteca::limpar_csv()
{
    fstream fin, fout;

    fin.open("biblioteca.csv", ios::in);
    fout.open("bibliotecanew.csv", ios::out);

    fin.close();
    fout.close();
    remove("biblioteca.csv");
    rename("bibliotecanew.csv", "biblioteca.csv");
}

void Biblioteca::ler_csv()
{
    ifstream fin;
    string linha;
    string titulo;
    string paginas;
    string idioma;
    string nome_autor;
    string nacionalidade;
    string genero;
    fin.open("biblioteca.csv");
    if(fin.is_open())
    {
        while (getline(fin, linha))
        {
            titulo = linha.substr(0, linha.find(','));
            linha.erase(0, titulo.size()+1);
            paginas = linha.substr(0, linha.find(','));
            linha.erase(0, paginas.size()+1);
            idioma = linha.substr(0, linha.find(','));
            linha.erase(0, idioma.size()+1);
            nome_autor = linha.substr(0, linha.find(','));
            linha.erase(0, nome_autor.size()+1);
            nacionalidade = linha.substr(0, linha.find(','));
            linha.erase(0, nacionalidade.size()+1);
            genero = linha;
            int _pagina = stoi(paginas);
            autores.criar_autor(nome_autor,  nacionalidade, genero);
            livros.criar_livro(titulo, _pagina, idioma, nome_autor, autores);
        }
    }
    else
        cout << "Não foi possível abrir o arquivo" << endl;
    fin.close();
}

void Biblioteca::escrever_csv()
{
    ofstream fout;
    ifstream fin;

    fin.open("biblioteca.csv");
    fout.open("biblioteca.csv", ios::app);

    if(fin.is_open())
    {
        for(int i = 0; i < livros.get_tam_livros(); i++)
        {
            fout << livros.get_livro(i)->get_titulo() << ","
                << livros.get_livro(i)->get_paginas() << ","
                << livros.get_livro(i)->get_idioma() << ","
                << autores.pesquisar_autor(livros.get_livro(i)->get_nome_autor())->get_nome() << ","
                << autores.pesquisar_autor(livros.get_livro(i)->get_nome_autor())->get_nacionalidade() << ","
                << autores.pesquisar_autor(livros.get_livro(i)->get_nome_autor())->get_genero() << endl;
        }
    }
    else
    {
        for(int i = 0; i < livros.get_tam_livros(); i++)
        {
            fout << livros.get_livro(i)->get_titulo() << ","
                << livros.get_livro(i)->get_paginas() << ","
                << livros.get_livro(i)->get_idioma() << ","
                << autores.pesquisar_autor(livros.get_livro(i)->get_nome_autor())->get_nome() << ","
                << autores.pesquisar_autor(livros.get_livro(i)->get_nome_autor())->get_nacionalidade() << ","
                << autores.pesquisar_autor(livros.get_livro(i)->get_nome_autor())->get_genero() << endl;
        }   
    }
    fin.close();
    fout.close();
}