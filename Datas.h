#include <iostream>
#include <fstream>
#include "Autor.h"
#include "Livro.h"
using namespace std;

void criar_csv()
{
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open("data.csv", ios::out | ios::app);
}

void escrever_csv(Autor *a, Livro *l)
{
	fstream fin, fout;

	fin.open("data.csv", ios::in);
	fout.open("datanew.csv", ios::out);

	string escrita;
	escrita = l->get_titulo() + ";" + a->get_nome() + ";";
	fout << escrita;

	fin.close();
	fout.close();

	remove("data.csv");
	rename("datanew.csv", "data.csv");
}

void apagar_csv()
{

}
