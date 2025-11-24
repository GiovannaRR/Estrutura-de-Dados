#include <iostream>
#include <vector>

using namespace std;

// Enum para representar as cores/estados conforme a dica do slide
enum Cor { BRANCO, CINZA, PRETO };

// Função auxiliar recursiva
bool dfs_ciclo_recursivo(int u, vector<Cor>& cores, const vector<vector<int>>& adj) {
    cores[u] = CINZA; // Marca como 'sendo visitado' (empilha)

    for (int v : adj[u]) {
        // Se encontrar um vizinho cinza, achamos um ciclo
        if (cores[v] == CINZA) {
            return true;
        }
        // Se encontrar um vizinho branco, continuamos a exploração
        if (cores[v] == BRANCO) {
            if (dfs_ciclo_recursivo(v, cores, adj)) {
                return true; //ciclo encontrado
            }
        }
    }

    cores[u] = PRETO; // Marca como 'totalmente explorado' (desempilha)
    return false;
}

// detectar ciclos no grafo
bool possui_ciclo(int n, const vector<vector<int>>& adj) {
    vector<Cor> cores(n, BRANCO); // Todos começam como brancos

    for (int i = 0; i < n; i++) {
        if (cores[i] == BRANCO) {
            if (dfs_ciclo_recursivo(i, cores, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Exemplo 1: Grafo com ciclo (0 -> 1 -> 2 -> 0)
    int n1 = 3;
    vector<vector<int>> adj1(n1);
    adj1[0] = {1};
    adj1[1] = {2};
    adj1[2] = {0}; // Fecha o ciclo

    if (possui_ciclo(n1, adj1)) cout << "Grafo 1 tem ciclo!\n";
    else cout << "Grafo 1 NAO tem ciclo.\n";

    // Exemplo 2: Grafo sem ciclo (0 -> 1 -> 0 -> 2)
    int n2 = 3;
    vector<vector<int>> adj2(n2);
    adj2[0] = {1, 2};
    adj2[1] = {};
    adj2[2] = {};

    if (possui_ciclo(n2, adj2)) cout << "Grafo 2 tem ciclo!\n";
    else cout << "Grafo 2 NAO tem ciclo.\n";

    return 0;
}