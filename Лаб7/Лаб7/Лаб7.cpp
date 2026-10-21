#include <iostream>

using namespace std;

int main ( )
{
	setlocale ( LC_ALL, "rus" );

	int n;
	cout << "Введите количество элементов N: ";
	if ( !(cin >> n) ) {
		cout << "Это не число\n";
		return 1;
	}
	int* a = new int[n];
	int* len = new int[n];
	int* prev = new int[n];

	cout << "Введите элементы(числа): ";
	for ( int i = 0; i < n; i++ ) {
		if ( !(cin >> a[i]) ) {
			cout << "Это не число\n";
			return 1;
		}
	}

	for ( int i = 0; i < n; i++ ) {
		len[i] = 1;
		prev[i] = -1;
		for ( int j = 0; j < i; j++ ) {
			if ( a[j]<a[i] && len[i] + 1>len[i] ) {
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

	return 0;
}