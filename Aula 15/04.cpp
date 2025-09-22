#include <iostream>
#include <vector>
using namespace std;

int buscaTernaria(const vector<int>& v, int chave) {
    int inicio = 0, fim = (int)v.size() - 1;

    while (inicio <= fim) {
        int terco1 = inicio + (fim - inicio) / 3;
        int terco2 = fim - (fim - inicio) / 3;

        if (v[terco1] == chave) return terco1;
        if (v[terco2] == chave) return terco2;

        if (chave < v[terco1]) {
            fim = terco1 - 1;
        }
        else if (chave > v[terco2]) {
            inicio = terco2 + 1;
        }
        else {
            inicio = terco1 + 1;
            fim = terco2 - 1;
        }
    }
    return -1; // não encontrada
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};

    cout << "Buscando 7: " << buscaTernaria(v, 7) << endl;   // deve achar 3
    cout << "Buscando 1: " << buscaTernaria(v, 1) << endl;   // deve achar 0
    cout << "Buscando 15: " << buscaTernaria(v, 15) << endl; // deve achar 7
    cout << "Buscando 8: " << buscaTernaria(v, 8) << endl;   // não existe -> -1

    return 0;
}
