using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.IO;

namespace СЯП_лаба_2
{
    partial class pairs
    {
        string word;
        int n_ofter;
    }
    class Program
    {

       static void input(List<string> book)
       {
            string file = @"C:\Users\1\Desktop\СЯП\СЯП лаба 2\СЯП лаба 2\numb_texts.txt";
            int numb = 0;
            string word;
            //открыли файл, считали оттуда число (считывается построчно)
            using (StreamReader sr = new StreamReader(file, System.Text.Encoding.Default))
               word = sr.ReadLine();
            //перевели число из строкового типа в числовой, мб так можно и не делать, но я хз как по-другому
            numb = Int32.Parse(word);
            //в зависимости от числа выбираем один из тестовых файлов
            switch (numb)
            {
                default: file = @"C:\Users\1\Desktop\СЯП\СЯП лаба 2\СЯП лаба 2\text1.txt"; break;
                case 1: file = @"C:\Users\1\Desktop\СЯП\СЯП лаба 2\СЯП лаба 2\text1.txt"; break;
                case 2: file = @"C:\Users\1\Desktop\СЯП\СЯП лаба 2\СЯП лаба 2\text2.txt"; break;
                case 3: file = @"F:\СЯП\СЯП лаба 2\СЯП лаба 2\text3.txt"; break;
                case 4: file = @"F:\СЯП\СЯП лаба 2\СЯП лаба 2\text4.txt"; break;
                case 5: file = @"F:\СЯП\СЯП лаба 2\СЯП лаба 2\text5.txt"; break;
            }
            try  {//считываем построчно
                    using (StreamReader sr = new StreamReader(file, System.Text.Encoding.Default))  {
                        string[] words;
                    //в переменную word он считает в данном случае строку из 10 слов, но будет
                    //воспринимать её как ону строку
                        while ((word = sr.ReadLine()) != null) {
                        //поэтому здесь мы магическим образом разбиваем эту строку на слова(ваще не понимаю как, но да ладно хд)
                        words = word.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        //и добавляем эту коллекцию в список
                            book.AddRange(words);
                        }
                    }
            }
            catch (Exception e)  {
                Console.WriteLine(e.Message);
            }
        }
       static pairs find_often_word(List <string> book, Dictionary<int, string> repeat_words)
       {
            return ;
       }
       static void find_pairs(Dictionary <int, pairs> often_pair, List <string> book, pairs word)
       {

       }
       static void output(pairs word, Dictionary <int, pairs> often_pair, float result_time)
       {

       }
       static void main(string[] args)
       {
           List<string> book = new List<string>();
           input(book);
           Dictionary <int, string> repeat_words = new Dictionary <int, string>();
	       Dictionary <int, pairs> often_pair = new Dictionary <int, pairs>();

           pairs word = find_often_word(book, repeat_words);
	       find_pairs(often_pair, book, word);
           //double end_time = clock();
           //double result_time = (end_time - beg_time)/* / CLOCKS_PER_SEC*/;

	       output(word, often_pair, result_time);
	       book.Clear();
	       repeat_words.Clear();
	       often_pair.Clear();

       }
    







    //поиск наиболее часто встречающегося слова
    //static pair<string,int> find_often_word(const vector <string>& book, multimap <int, string>& repeat_words)
    //{
	   // map <string, int> repeat;
	   // //проход по всей книге
	   // for (auto i : book)repeat[i]++;
	   // /* другой вариант написания строк 48-49
	   // auto res=max_element(repeat.begin(),repeat.end(),
		  //  [&](const pair<string, int>& a, const pair<string, int>& b) {return a.second < b.second;}
	   // );
	   // */
	   // pair<string, int> res("", 0);
	   // for (auto p : repeat)if (p.second > res.second)res = p;

	   // return res;
    //}


    //поиск наиболее часто встречающихся пар слов
    //static void find_pairs(multimap <int, pair<string, string>, greater<>>& often_pair, vector <string>& book, pair<string, int> word)
    //{
    //    map <pair<string, string>, int> pairs;
    //    if (*begin(book) == word.first)
    //        pairs[make_pair(word.first, *(begin(book) + 1))]++;
    //    if (*(end(book)-1) == word.first)
    //        pairs[make_pair(*(end(book) -2),word.first)]++;
    //    //проход по всей книге
    //    for (auto i = begin(book)+1; i < end(book)-1; i++)
    //        //если выбранное слово совпадает с ключевым
    //        if (*i == word.first) {
    //            pairs[make_pair(word.first, *(i+1))]++;
    //            pairs[make_pair(*(i - 1),word.first)]++;
    //        }
    //    //проходя по всему словарю меняем местами ключ и значение
    //    for (auto i : pairs)
    //        often_pair.insert({ i.second, i.first });
    //}

    //static void output(pair<string, int> word, multimap <int, pair<string, string>, greater<>> often_pair, float result_time)
    //{
    //    int n, j = 0;
    //    ifstream fin("n.txt");
    //    ofstream fout("output.txt");
    //    fin >> n;
    //    fin.close();
    //    fout << "Most often words" << endl << word.first << '\t' << word.second << endl << endl;
    //    fout << "Most often pairs of words and numb of their" << endl;
    //    for (auto i = begin(often_pair); i != end(often_pair) && j < n; j++, i++)
    //        fout << i->second.first << ' ' << i->second.second << '\t' << i->first << endl;
    //    fout << endl << "time" << endl << result_time << endl;
    //    fout.close();
    //}

    //void main()
    //{
	   // vector <string> book;
	   // multimap <int, string> repeat_words;
	   // multimap <int, pair<string, string>, greater<>> often_pair;

	   // input(book);
	   // double beg_time = clock();

	   // pair<string,int> word = find_often_word(book, repeat_words);
	   // find_pairs(often_pair, book, word);
	   // double end_time = clock();
	   // double result_time = (end_time - beg_time)/* / CLOCKS_PER_SEC*/;

	   // output(word, often_pair, result_time);
	   // book.clear();
	   // repeat_words.clear();
	   // often_pair.clear();
    //}


}
}
