#include <iostream>
#include <string>

using namespace std;

struct Table
{
	char  symbol;
	string code;
	int count;
};

int SizeForTable ( string text )
{
	int size = 0;

	for ( int i = 0; i < text.length ( ); i++ ) {
		bool was = false;

		for ( int j = 0; j < i; j++ ) {
			if ( text[j] == text[i] ) {
				was = true;
				break;
			}
		}
		if ( !was ) {
			size++;
		}
	}

	return size;
}

void TableCode ( string text )
{
	Table* codeT = new Table[SizeForTable ( text )];
	int n = 0;
	for ( int i = 0; i < text.length ( ); i++ ) {
		bool was = false;
		for ( int j = 0; j < n; j++ ) {
			if ( codeT[j].symbol == text[i] ) {
				codeT[j].count++;
				was = true;
				break;
			}
		}
		if ( !was ) {
			codeT[n].symbol = text[i];
			codeT[n].count = 1;
			codeT[n].code = "";
			n++;
		}
	}
	for ( int i = 0; i < n - 1; i++ ) {
		for ( int j = 0; j < n - 1 - i; j++ ) {
			if ( codeT[j].count < codeT[j + 1].count ) {
				Table t = codeT[j];
				codeT[j] = codeT[j + 1];
				codeT[j + 1] = t;
			}
		}
	}

	cout << "\nА) Таблица встречаемости\n";
	cout << "Символ\tКоличество\n";
	for ( int i = 0; i < n; i++ ) {
		cout << codeT[i].symbol << "\t" << codeT[i].count << "\t" << codeT[i].code << "\n";
	}

	string* gSym = new string[n];
	int* gW = new int[n];
	int groups = n;
	for ( int i = 0; i < n; i++ ) {
		gSym[i] = codeT[i].symbol;
		gW[i] = codeT[i].count;
	}
	if ( n == 1 ) {
		codeT[0].code = "0";
	}

	while ( groups > 1 ) {
		int min1 = 0;

		for ( int i = 1; i < groups; i++ ) {
			if ( gW[i] < gW[min1] ) {
				min1 = i;
			}
		}

		int min2 = -1;
		for ( int i = 0; i < groups; i++ ) {
			if ( i == min1 )continue;
			if ( min2 == -1 || gW[i] < gW[min2] ) {
				min2 = i;
			}
		}

		for ( int k = 0; k < n; k++ ) {
			if ( gSym[min1].find ( codeT[k].symbol ) != string::npos ) {
				codeT[k].code = "0" + codeT[k].code;
			}
			if ( gSym[min2].find ( codeT[k].symbol ) != string::npos ) {
				codeT[k].code = "1" + codeT[k].code;
			}
		}

		//  склеиваем min2 в min1
		gSym[min1] += gSym[min2];
		gW[min1] += gW[min2];

		gSym[min2] = gSym[groups - 1];
		gW[min2] = gW[groups - 1];
		groups--;
	}
	delete[] gSym;
	delete[] gW;

	cout << "\nБ) Таблица кодов\n";
	cout << "Символ\tКод\n";
	for ( int i = 0; i < n; i++ ) {
		cout << "'" << codeT[i].symbol << "'\t" << codeT[i].code << "\n";
	}

	cout << "\nВ) Выходная последовательность\n";
	for ( int i = 0; i < text.length ( ); i++ ) {
		for ( int k = 0; k < n; k++ ) {
			if ( codeT[k].symbol == text[i] ) {
				cout << codeT[k].code;
				break;
			}
		}
	}
	cout << "\n";

	delete[] codeT;
}

int main ( )
{
	setlocale ( LC_ALL, "RUS" );
	string text;
	cout << "Введите произвольный текст: \n";
	getline ( cin, text );
	TableCode ( text );
	return 0;
}