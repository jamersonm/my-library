#ifndef AUTOR_H
#define AUTOR_H
#include <string>

using namespace std;

class Autor
{
private:
    string _nome, _genero, _nacionalidade;
public:
    Autor();
    Autor(string, string, string);
    ~Autor();

    void set_nome(string a){_nome = a;}
    void set_genero(string a){_genero = a;}
    void set_nacionalidade(string a){_genero = a;}
    string get_nome(){return _nome;}
    string get_genero(){return _genero;}
    string get_nacionalidade(){return _nacionalidade;}

    void cadastrar_autor();
    void editar_autor();
    void excluir_autor();
    void exibir_autor();
};


#endif