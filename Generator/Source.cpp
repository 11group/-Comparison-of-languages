#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

void input(vector <char>& letters)
{
	ifstream fin("words.txt");
	char letter;
	while (fin >> letter)
		letters.push_back(letter);
	fin.close();
}

void generator(vector <char> letters)
{
	long int n;
	int numb_letter;
	string word;
	vector <string> book;
	ifstream fin("n.txt");
	fin >> n;
	fin >> numb_letter;
	fin.close();
	ofstream fout("text.txt");
	word.resize(numb_letter, ' ');
	book.resize(n);
	// автоматическая рандомизацияр генератора случайных чисел
	//позволяет каждый раз получать рандомные числа, отличные от предыдущего запуска
	srand(time(0)); 
	for (int i = 0; i < n; )
	{
		for (int k = 0; k < numb_letter; k++)
		{
			int j = 0 + rand() % (letters.size() - 1);
			word[k] = letters[j];
		}
		int s = 1 + rand() % (letters.size() / 2);
		for (int k = 0; k < s && i < n; k++) {
			book[i] = word;
			i++;
		}
	}
	random_shuffle(book.begin(), book.end());
	for (int i = 0; i < n; i++)
		if (i % 10 == 0 && i) fout << book[i] << endl;
		else fout << book[i] << ' ';
	fout.close();
}

void main()
{
	vector <char> letters;
	input(letters);
	generator(letters);
}
