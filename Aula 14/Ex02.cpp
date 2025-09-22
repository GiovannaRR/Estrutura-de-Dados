#include <iostream>
#include <vector>

using namespace std;

    int buscaBinariaInsercao(const vector<int>& vetor, int chave){
        int inicio = 0;
        int fim = vetor.size() - 1;   // define os limites inicial e final

        while (inicio <= fim) {    // enquanto ainda houver elementos para buscar
            int meio = inicio + (fim - inicio) / 2;   // calcula o meio, evitando overflow
            if (vetor[meio] == chave) {   // se encontrar retorna
                return meio;           
            } 
            else if (chave < vetor[meio]) {
                fim = meio - 1;  //se a chave for menor, busca para a esquerda
            } 
            else {
                inicio = meio + 1;  //se for maior, busca para a direita
            }
        }
        return inicio;  //se não achou, retorna a posição onde deveria ser inserido
    }

int main() {

    vector<int> dados = {1, 3, 5, 7, 9};  // Vetor ordenado
    int chave = 6;
    int pos = buscaBinariaInsercao(dados, chave); 

    cout << "Chave deve ser inserida na posicao: " << pos << endl;

    return 0;
}


