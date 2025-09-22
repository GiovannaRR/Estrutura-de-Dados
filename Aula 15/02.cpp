#include <iostream>
#include <vector>
using namespace std;

int buscaBinariaInsercao(const vector<int>& v, int chave) {
    int inicio = 0, fim = (int)v.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] == chave) {
            return meio; // encontrado
        }
        else if (v[meio] < chave) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return inicio; 
    //quando nao encontra, o inicio aponta para a posicao correta
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9};

    cout << "Chave 5 -> indice " << buscaBinariaInsercao(v, 5) << endl;
    cout << "Chave 6 -> indice de insercao " << buscaBinariaInsercao(v, 6) << endl;
    cout << "Chave 0 -> indice de insercao " << buscaBinariaInsercao(v, 0) << endl;
    cout << "Chave 10 -> indice de insercao " << buscaBinariaInsercao(v, 10) << endl;
}
