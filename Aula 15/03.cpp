#include <iostream>
#include <vector>
#include <string>
using namespace std;

int buscaBinariaStrings(const vector<string>& v, const string& chave) {
    int inicio = 0, fim = (int)v.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] == chave) {
            return meio;
        }
        else if (v[meio] < chave) { 
            // comparação lexicográfica
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1; // não encontrada
}

int main() {
    // vetor de strings ORDENADO
    vector<string> nomes = {"Ana", "Bruno", "Carlos", "Daniel", "Fernanda", "Maria"};

    cout << "Buscando 'Carlos': " << buscaBinariaStrings(nomes, "Carlos") << endl;
    cout << "Buscando 'Joao': " << buscaBinariaStrings(nomes, "Joao") << endl;
    cout << "Buscando 'Ana': " << buscaBinariaStrings(nomes, "Ana") << endl;
    cout << "Buscando 'Maria': " << buscaBinariaStrings(nomes, "Maria") << endl;

    return 0;
}
