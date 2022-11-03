#include <iostream>
#include <fstream>
#include <sstream>
#include "Biblioteca.h"

using namespace std;

void Registrador::criar_csv(){
    ifstream fin;
    fin.open("Biblioteca.csv");
    if(fin.is_open()){}
    else{
        fstream fout;
        fout.open("Biblioteca.csv",  ios::out | ios::app);
        fout.close();
    }
    fin.close();
}

void Registrador::limpar_csv(){
    fstream fin, fout;
    fin.open("Biblioteca.csv", ios::in);
    fout.open("Bibliotecanew.csv",  ios::out);
    fin.close();
    fout.close();
    remove("Biblioteca.csv");
    rename("Bibliotecanew.csv", "Biblioteca.csv");
}

void Registrador::ler_csv(){
    ifstream fin;
    string linha, titulo, paginas, idioma, nome_autor, genero, nacionalidade;
    fin.open("Biblioteca.csv");
    if(fin.is_open()){
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
    else{
        cout << "Não foi possível abrir o arquivo." << endl;
    }
    fin.close();
}

void Registrador::escrever_csv(){
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