#include <iostream>
#include <vector>
using namespace std;

void siftDown(vector<int>& data, int n, int i) {
    int maior = i;        // nó atual
    int esq = 2 * i + 1;  // filho esquerdo
    int dir = 2 * i + 2;  // filho direito

    // verifica se o filho da esquerda é maior
    if (esq < n && data[esq] > data[maior])
        maior = esq;

    // verifica se o filho da direita é maior
    if (dir < n && data[dir] > data[maior])
        maior = dir;

    // se o maior nao for o pai, troca e continua descendo
    if (maior != i) {
        swap(data[i], data[maior]);
        siftDown(data, n, maior);
    }
}

//constrói o Max-Heap em O(n)
void buildHeap(vector<int>& data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(data, n, i);
    }
}

int main() {
    vector<int> v = {3, 5, 1, 10, 2, 7, 6};

    cout << "Antes do buildHeap:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    buildHeap(v);

    cout << "Depois do buildHeap (Max-Heap):\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    return 0;
}
