#include <iostream>
#include <vector>

using namespace std;

vector<int> buscaSequencialOcorrencias(const vector<int>& vetor, int chave) {
    vector<int> indices; // cria um vetor vazio para guardar os indices
    for (int i = 0; i < vetor.size(); ++i) {
        if (vetor[i] == chave) { // Se o elemento atual for igual à chave
            indices.push_back(i); // adiciona o índice ao vetor indices
        }
    }
    return indices;
}

int main() {
    vector<int> dados = {3, 7, 2, 7, 9, 7};
    int chave = 7; //valor a ser procurado
    vector<int> ocorrencias = buscaSequencialOcorrencias(dados, chave);

    if (ocorrencias.empty()) {
        cout << "Chave nao encontrada." << endl;
    } else {
        cout << "Chave encontrada nos indices: ";
        for (int idx : ocorrencias) {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}
