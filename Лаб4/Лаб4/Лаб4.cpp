#include <iostream>
using namespace std;

const int n = 6;
const int INF = 1000000; 

int main() {
    setlocale(LC_ALL, "Rus");
    int D[n][n] = {
        { 0, 28, 21, 59, 12, 27 },
        { 7,  0, 24, INF, 21,  9 },
        { 9, 32,  0, 13, 11, INF },
        { 8, INF,  5,  0, 16, INF },
        { 14, 13, 15, 10,  0, 22 },
        { 15, 18, INF, INF,  6,  0 }
    };

    int S[n][n]; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            S[i][j] = j + 1; 

    for (int m = 0; m < n; m++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][m] + D[m][j] < D[i][j]) {
                    D[i][j] = D[i][m] + D[m][j];
                    S[i][j] = m + 1;
                }
            }
        }
    }

    cout << "Матрица D (кратчайшие расстояния):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << D[i][j] << "\t";
        cout << endl;
    }

    cout << "\nМатрица S (через какую вершину идёт путь):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (i == j ? 0 : S[i][j]) << "\t";
        cout << endl;
    }
}