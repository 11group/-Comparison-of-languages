#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <functional>

using namespace std;

void input(vector <string>& book)
{
	ifstream fin("text.txt");
	string word;
	//запись книги
	while (fin >> word)
		book.push_back(word);
	fin.close();
}

//поиск наиболее часто встречающегося слова
string find_often_word(vector <string> book, multimap <int, string>& repeat_words)
{
	map <string, int> repeat;
	//проход по всей книге
	for (auto i : book)
	{	//если число эл-тов для данного ключа = 0 (т.е. словарь пуст), добавляем эл-нт, 
		//иначе ищем данный эл-нт по ключу и увеличиваем значение
		if (!repeat.count(i)) repeat.insert({ i, 1 });
		else repeat.find(i)->second++;
	}
	//проходя по всему словарю меняем местами ключ и значение
	for (auto i : repeat)
		repeat_words.insert({ i.second, i.first });
	repeat.clear();
	return repeat_words.rbegin()->second;
}

//добавление пары слов
void add_pair(map <pair<string,string>, int> &pairs, string left, string right)
{
	pair<string, string> n;
	n.first = left;
	n.second = right;
	//если данная пара уже добавлена, то количество таких пар увеличиваем на 1,
	//иначе добавляем пару
	if (pairs.count(n)) pairs.find(n)->second++;
	else pairs.insert({ n, 1 });
}

//поиск наиболее часто встречающихся пар слов
void find_pairs(multimap <int, pair<string, string>, greater<>>& often_pair, vector <string> book, string word)
{
	map <pair<string, string>, int> pairs;
	//проход по всей книге
	for (auto i = begin(book); i < end(book); i++)
		//если выбранное слово совпадает с ключевым
		if (*i == word)
			//добавление пары, если слово является первым в тексте
			if (i == begin(book)) add_pair(pairs, *i, *(i + 1));
			else//добавление пары, если слово является последним в тексте
				if (i == end(book) - 1) add_pair(pairs, *(i - 1), *i);
				else
				{	//добавление пары, если слово стоит в середине текста
					add_pair(pairs, *(i - 1), *i);
					add_pair(pairs, *i, *(i + 1));
				}
	//проходя по всему словарю меняем местами ключ и значение
	for (auto i : pairs)
		often_pair.insert({ i.second, i.first });
	pairs.clear();
}

void output(multimap <int, pair<string, string>, greater<>> often_pair)
{
	int n, j = 0;
	ifstream fin("n.txt");
	ofstream fout("output.txt");
	fin >> n;
	fin.close();
	fout << "Most often pairs of words and numb of their" << endl;
	for (auto i = begin(often_pair); j < n; j++, i++)
		fout << i->second.first << ' ' << i->second.second << '\t' << i->first << endl;
	fout.close();
}

void main()
{
	vector <string> book;
	multimap <int, string> repeat_words;
	multimap <int, pair<string, string>, greater<>> often_pair;
	string word = find_often_word(book, repeat_words);
	input(book);
	find_pairs(often_pair, book, word);
	output(often_pair);
	book.clear();
	repeat_words.clear();
	often_pair.clear();
}
