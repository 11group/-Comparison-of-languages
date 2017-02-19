#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void input(vector <string>& words)
{
	ifstream fin("words.txt");
	string word;
	while (fin >> word)
		words.push_back(word);
	fin.close();
}

void generator(vector <string> words)
{
	int n, j;
	ifstream fin("n.txt");
	fin >> n;
	fin.close();
	ofstream fout("text.txt");
	// автоматическая рандомизацияр генератора случайных чисел
	//позволяет каждый раз получать рандомные числа, отличные от предыдущего запуска
	srand(time(0)); 
	for (int i = 0; i < n; i++)
	{
		j = rand() % words.size();
		//форматирование текста
		if ((i + 1) % 10 == 0) fout << words[j] << endl;
		else fout << words[j] << ' ';
	}
	fout.close();
}

void main()
{
	vector <string> words;
	input(words);
	generator(words);
}
