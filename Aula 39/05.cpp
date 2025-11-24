#include <vector>
#include <list>
#include <iostream>

using namespace std;

//representar a conexão
struct Aresta {
    int destino; // O vértice vizinho (v)
    int peso;    // O custo da aresta (w)
};

//estrutura do Grafo
class GrafoPonderado {
    int n; // Número de vértices
    // Vetor de vetores (ou listas) do tipo 'Aresta'
    vector<vector<Aresta>> adj; 

public:
    GrafoPonderado(int numVertices) {
        n = numVertices;
        adj.resize(n);
    }

    void adicionarAresta(int u, int v, int peso) {
        // Adiciona v e o peso à lista de u
        Aresta novaAresta = {v, peso};
        adj[u].push_back(novaAresta);

        // Se for não-direcionado, descomente a linha abaixo :)
        // adj[v].push_back({u, peso}); 
    }
};