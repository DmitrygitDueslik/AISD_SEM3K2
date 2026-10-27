#include <iostream>

using namespace std;

int main ( )
{
	setlocale ( LC_ALL, "rus" );

	int n;
	cout << "¬ведите количество элементов N: ";
	if ( !(cin >> n) || n <= 0 ) {
		cout << "Ёто не число либо меньше,равно 0\n";
		return 1;
	}
	int* a = new int[n];
	int* len = new int[n];
	int* prev = new int[n];

	cout << "¬ведите элементы(числа): ";
	for ( int i = 0; i < n; i++ ) {
		if ( !(cin >> a[i]) ) {
			cout << "Ёто не число, введите заново: ";
			cin.clear ( );
			cin.ignore ( 10000, '\n' );
			i--;
		}
	}

	for ( int i = 0; i < n; i++ ) {
		len[i] = 1;
		prev[i] = -1;
		for ( int j = 0; j < i; j++ ) {
			if ( a[j]<a[i] && len[j] + 1>len[i] ) {
				len[i] = len[j] + 1;
				prev[i] = j;
			}
		}
	}

	int best = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( len[i] >= len[best] ) {
			best = i;
		}
	}

	int maxLen = len[best];

	int* res = new int[maxLen];
	int k = best;
	for ( int i = maxLen - 1; i >= 0; i-- ) {
		res[i] = a[k];
		k = prev[k];
	}
	cout << maxLen << endl;
	for ( int i = 0; i < maxLen; i++ ) {
		cout << res[i];
		if ( i < maxLen - 1 ) cout << ", ";
	}
	cout << endl;
	delete[] a;
	delete[] len;
	delete[] prev;
	delete[] res;
	return 0;
}