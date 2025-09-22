// exemplo de entrada: (5, 'A'), (3, 'B'), (5, 'C'), (2, 'D')
// temos dois pares com valor 5, mas com nomes diferentes: 'A' e 'C'.
// a ordem original entre eles é: (5, 'A') antes de (5, 'C').
// resultado com Selection Sort (instável): (2, 'D'), (3, 'B'), (5, 'C'), (5, 'A')
// dependendo da implementação, os dois elementos com 5 podem trocar de lugar:
// resultado com Insertion Sort (estável): (2, 'D'), (3, 'B'), (5, 'A'), (5, 'C')

#include <iostream>
#include <vector>
using namespace std;

struct Par {
    int chave;
    char nome;
};

void imprimir(const vector<Par>& v) {
    for (auto& p : v)
        cout << "(" << p.chave << ", " << p.nome << ") ";
    cout << "\n";
}

// Selection Sort (instável)
void selectionSort(vector<Par> v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].chave < v[menor].chave)
                menor = j;
        }
        swap(v[i], v[menor]); // pode inverter elementos iguais
    }
    cout << "Selection Sort (instavel): ";
    imprimir(v);
}

// Insertion Sort (estável)
void insertionSort(vector<Par> v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        Par chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].chave > chave.chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
    cout << "Insertion Sort (estavel): ";
    imprimir(v);
}

int main() {
    vector<Par> dados = {
        {5, 'A'}, {3, 'B'}, {5, 'C'}, {2, 'D'}
    };

    cout << "Original: ";
    imprimir(dados);

    selectionSort(dados);
    insertionSort(dados);

    return 0;
}
