#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void main()
{
	vector <string> str;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s;
	for (int i = 0; fin >> s; i++)
		str.pushback(s);
	



	
	//fout << ;
}