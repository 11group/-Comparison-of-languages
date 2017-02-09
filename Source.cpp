#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void main()
{
	vector <string> book;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string str;
	//запись книги
	for (int i = 0; fin >> str; i++)
		book.push_back(str);
	map <string, int> repeat_words;
	//проход по всей книге и поиск и подсчёт частоты встречаемости каждого слова
	for (int i = 0; i < book.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < book.size(); j++)
			if (book[i] == book[j]) count++;
		repeat_words.insert(pair<string, int>(book[i], count));
	}



	
	//fout << ;
}
