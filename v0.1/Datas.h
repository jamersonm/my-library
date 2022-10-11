#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Autor.h"
#include "Livro.h"
using namespace std;

void criar_csv_livro()
{
	fstream fout;
	fout.open("livros.csv", ios::out | ios::app);
}

void criar_csv_autor()
{
	fstream fout;

	fout.open("autores.csv",  ios::out | ios::app);
}

void escrever_csv_autor(Autor *a)
{
	fstream fout;

	fout.open("autores.csv", ios::out | ios::app);

	fout << a->get_nome() << ","
		<< a->get_nacionalidade() << ","
		<< a->get_genero() << ","
		<< "\n";	
}

void escrever_csv_livro(Livro *l)
{
	fstream fout;

	fout.open("livros.csv", ios::out | ios::app);

	fout << l->get_titulo() << ","
		<< l->get_paginas() << ","
		<< l->get_idioma() << ","
		<< l->get_autor() << ","
		<< l->get_autor_nacionalidade() << ","
		<< l->get_autor_genero() << ","
		<< "\n";
}

void ler_csv()
{
	fstream fin;

	fin.open("data.csv", ios::in);
}

void apagar_csv()
{
	fstream fin, fout;

	fin.open("data.csv", ios::in);
	fout.open("datanew.csv", ios::out);

	int count = 0, i,  roll1, roll;
	string titulo, line, word;
	vector<string> row;
	cout << "Index do livro: ";
	cin >> roll;

	while (!fin.eof())
	{
		row.clear();
		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ','))
		{
			row.push_back(word);	
		}

		int row_size = row.size();
		roll1 = stoi(row[0]);

		if(roll1 != roll)
		{
			if(!fin.eof())
			{
				for(i = 0; i < row_size -1; i++)
				{
					fout << row[i] << ",";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		else
			count = 1;
		if(fin.eof())
			break;
	}
	if(count == 1)
		cout << "Livro deletado!" << endl;
	else
		cout << "Livro não encontrado." << endl;

	fin.close();
    fout.close();
  
    remove("data.csv");
    rename("datanew.csv", "data.csv");
	
}
