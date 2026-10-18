#include <iostream>
using namespace std;

const int N = 8;
const int INF = 1000000;

int main ( )
{
	setlocale ( LC_ALL, "Russian" );

	//          1   2   3   4   5   6   7   8
	int g[N][N] = {
		/*v1*/{ 0,  2,  0,  8,  2,  0,  0,  0 },
		/*v2*/{ 2,  0,  3, 10,  5,  0,  0,  0 },
		/*v3*/{ 0,  3,  0,  0, 12,  0,  0,  7 },
		/*v4*/{ 8, 10,  0,  0, 14,  3,  1,  0 },
		/*v5*/{ 2,  5, 12, 14,  0, 11,  4,  8 },
		/*v6*/{ 0,  0,  0,  3, 11,  0,  6,  0 },
		/*v7*/{ 0,  0,  0,  1,  4,  6,  0,  9 },
		/*v8*/{ 0,  0,  7,  0,  8,  0,  9,  0 }
	};

	bool inTree[N] = { false };
	inTree[0] = true;
	int total = 0;

	cout << "Алгоритм Прима" << endl;
	cout << "Ребра остовного дерева:" << endl;

	for ( int k = 0; k < N - 1; k++ ) {
		int minW = INF, from = -1, to = -1;

		for ( int i = 0; i < N; i++ ) {
			if ( !inTree[i] ) continue;
			for ( int j = 0; j < N; j++ ) {
				if ( !inTree[j] && g[i][j] != 0 && g[i][j] < minW ) {
					minW = g[i][j];
					from = i;
					to = j;
				}
			}
		}

		inTree[to] = true;
		total += minW;
		cout << "v" << from + 1 << " - v" << to + 1 << "  вес " << minW << endl;
	}

	cout << "Суммарный вес: " << total << endl;
	return 0;
}