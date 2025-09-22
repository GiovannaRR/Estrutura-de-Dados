#include <iostream>
#include <vector>
#include <string> 

using namespace std;

    int buscaBinariaStrings(const vector<string>& vetor, const string& chave){
        int inicio = 0;
        int fim = vetor.size() - 1;
        while (inicio <= fim) {
            int meio = inicio + (fim - inicio) / 2;
            if (vetor[meio] == chave) {
                return meio;   //encontrou
            } 
            else if (chave < vetor[meio]) {
                fim = meio - 1;   //vai para a  esquerda
            } 
            else {
                inicio = meio + 1;  // vai para a  direita
            }
        }
            return -1;  // Se não encontrou
    }
int main() {
    vector<string> nomes = {"Ana", "Carlos", "João", "Maria", "Zeca"};  // Vetor ordenado
    string chave = "João";

    int pos = buscaBinariaStrings(nomes, chave);

    if (pos != -1) {
        cout << "Chave encontrada na posicao: " << pos << endl;
    } 

    else {
        cout << "Chave nao encontrada." << endl;
    }

    return 0;
}