#include <iostream>
#include <vector>

using namespace std;

    int buscaTernaria(const vector<int>& vetor, int chave, int inicio, int fim){ //divide a busca em 3 pedaços

        if (inicio > fim) return -1;  //condição de parada: não achou

        int terc1 = inicio + (fim - inicio) / 3;   // primeiro 
        int terc2 = fim - (fim - inicio) / 3;      // segundo 

        if (vetor[terc1] == chave) return terc1;  // achou no primeiro 
        if (vetor[terc2] == chave) return terc2;  //achou no segundo

        if (chave < vetor[terc1]) {
            return buscaTernaria(vetor, chave, inicio, terc1 - 1);  // parte esquerda
        } else if (chave > vetor[terc2]) {
            return buscaTernaria(vetor, chave, terc2 + 1, fim);  // parte direita
        } else {
            return buscaTernaria(vetor, chave, terc1 + 1, terc2 - 1);  //meio
        }
    }

int main() {
    vector<int> dados = {1, 3, 5, 7, 9, 11, 13, 15};  //vetor ordenado
    int chave = 7;

    int pos = buscaTernaria(dados, chave, 0, dados.size() - 1);

    if (pos != -1) {
        cout << "Chave encontrada na posição: " << pos << endl;
    } 
    else {
        cout << "Chave nno encontrada." << endl;
    }

    return 0;
}