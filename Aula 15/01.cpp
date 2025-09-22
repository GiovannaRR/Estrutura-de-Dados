#include <iostream>
#include <vector>
using namespace std;

vector<int> buscaSequencialOcorrencias(const vector<int>& v, int chave) {
    vector<int> indices;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == chave) {
            indices.push_back(i);
        }
    }
    return indices; //vazio se nao encontra
}

int main() {
    vector<int> v = {1, 2, 3, 2, 4, 2};
    int chave = 2;

    vector<int> result = buscaSequencialOcorrencias(v, chave);

    cout << "Ocorrencias de " << chave << ": ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
}
