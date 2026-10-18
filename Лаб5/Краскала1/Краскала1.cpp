#include <iostream>
using namespace std;

const int N = 8;
const int M = 16;

struct Edge {
    int a, b, w;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Edge e[M] = {
        { 1, 2, 2 },{ 2, 3, 3 },{ 1, 4, 8 },{ 1, 5, 2 },{ 2, 4, 10 },
        { 2, 5, 5 },{ 3, 5, 12 },{ 3, 8, 7 },{ 4, 5, 14 },{ 4, 6, 3 },
        { 4, 7, 1 },{ 5, 6, 11 },{ 5, 7, 4 },{ 5, 8, 8 },{ 6, 7, 6 },
        { 7, 8, 9 }
    };

    for (int i = 0; i < M - 1; i++)
        for (int j = 0; j < M - 1 - i; j++)
            if (e[j].w > e[j + 1].w) {
                Edge t = e[j]; e[j] = e[j + 1]; e[j + 1] = t;
            }

    int comp[N + 1];
    for (int i = 1; i <= N; i++) comp[i] = i;

    int total = 0, count = 0;
    cout << "Алгоритм Краскала" << endl;
    cout << "Ребра остовного дерева:" << endl;

    for (int i = 0; i < M && count < N - 1; i++) {
        int ca = comp[e[i].a];
        int cb = comp[e[i].b];
        if (ca == cb) continue;

        for (int v = 1; v <= N; v++) {
            if (comp[v] == cb) comp[v] = ca;
        }
        total += e[i].w;
        count++;
        cout << "v" << e[i].a << " - v" << e[i].b << "  вес " << e[i].w << endl;
    }

    cout << "Суммарный вес: " << total << endl;
    return 0;
}