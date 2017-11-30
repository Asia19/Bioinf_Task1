#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int searchTheWord(string Text, string Pattern, int mm, int nn) // можно передавать размер строк?
{
	int s;
	int count = 0;
	int m = mm - 1;
	int n = nn - 1;
	
	for (int i = n; i <= m; i++)
	{
		s = 0;
		while ((Pattern[s] == Text[i - (n - s)]) && (s < n)) s += 1;
		if ((Pattern[s] == Text[i]) && (s == n)) count++;
	}	
	return count;
}


int main() {
	//считываем по строкам из файла
	string *s;
	s = new string[2];
	ifstream fin("input.txt", ios_base::in);
	for (int i = 0; i < 2; i++) {
		getline(fin, s[i]);
	}

	
	for (int i = 0; i < 2; i++) {
		cout << "s = " << s[i] << endl;
	}
	int m = s[0].length(); // размер текста
	int n = s[1].length(); //  размер паттерна

	// ищем паттерн
	int count = searchTheWord(s[0], s[1], m, n);
	cout << "Count = " << count << endl;

	// записываем результат в файл
	ofstream fout("output.txt", ios_base::out | ios_base::trunc);
	fout << count;
	fout.close();
	delete[] s;	
}