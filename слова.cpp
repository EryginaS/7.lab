// слова.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<fstream>
#include <Windows.h>
int const n = 10000;
using namespace std;
struct dictionary {  string word; };//структура слов 
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// позволяет записывать русские символы в строки/массивы 
	SetConsoleOutputCP(1251);

	struct dictionary mas[n];
	string str,  strnew, use;//сокращенная строка , введенная пользователем , полная строка, введенная пользователем, выполняет роль банки
	int y = 0; //вспомогательная переменная, для счетчика структурного массива 
	cout << "Введите набор букв" << endl;
	getline(cin, str);
	strnew = str;
	cout << "Из этого набора можно получить следующие слова: " << endl;
	//удаляет повторяющиеся буквы
	for (int i = 0; i<str.length(); i++)
		for (int j = i + 1; j<str.length();j++)
			if (str[j] == str[i] || str[j] == ' ')
			{   
				str.erase(j, 1);//операция удаления
				j--;
			}
	
	//для каждой буквы слова заполняем структуру 
	for (int i = 0; i < str.length();i++)
	{
		ifstream fin("словарь.txt");//открываем словарь
		while (!fin.eof())//пока он не закончится
		{
			fin >> use;//считываем слово в банк

			if (use[0] == str[i])//если первый символ слова равен итому символу 
			{
				if (strnew.length() >= use.length())//и длина слова( исходного) не превосходит введенные 
				{
					mas[y].word = use;//заполняет масссив
					y++;
				}
			}



		}

		fin.close();//закрыввается файл
		/*for (int i = 0; i < y; i++)
			cout << mas[i].word << endl;*/
		
		while (y >0) //каждое слово наше структуры 
		{
			string use2 = mas[y-1].word; //используем вспомогательную строку 
			for (int j = 0; j< use2.length();j++)//пока она не закончится
			{
				
				size_t pos = str.find(use2[j]);//ищем вхождение житого элемента в строку 
				if (pos == string::npos)//если его нет , то выходим из цикла и берем след слово структуры
				{
					
					break;
					
				}
				if (use2.length() == j+1) //условие вывода
				{
					if (use2.length() >2 || use2=="я" || use2=="он")//если 1 буква или я
					{
						cout << use2 << endl;
						/*	ofstream fout("result.txt", ios::app);
							fout << use2 << endl;
							fout.close();*/
					}
				}

			}

			y--;
		}





		

	}
	system("pause");
	return 0;
	
}

