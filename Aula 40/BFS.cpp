#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs_caminho_minimo(int s, int n, const vector<vector<int>>& adj) {
    vector<int> distancia(n, -1);
    queue<int> q; // Fila para controlar a ordem de visita

    // Configuração inicial para o vértice de origem 's'
    distancia[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Explora os vizinhos de u
        for (int v : adj[u]) {
            // Se v ainda não foi visitado (distancia é -1)
            if (distancia[v] == -1) {
                // A distância de v é a distância do pai (u) + 1
                distancia[v] = distancia[u] + 1;
                q.push(v);
            }
        }
    }
    
    return distancia;
}

int main() {
    // exemplo :)
    int n = 6; 
    vector<vector<int>> adj(n);
    
    //grafo de exemplo
    adj[0] = {1, 2};    // 0 conecta a 1 e 2
    adj[1] = {0, 3, 4}; // 1 conecta a 0, 3 e 4
    adj[2] = {0};       // 2 conecta a 0
    adj[3] = {1};       // 3 conecta a 1
    adj[4] = {1, 5};    // 4 conecta a 1 e 5
    adj[5] = {4};       // 5 conecta a 4

    int origem = 0;
    vector<int> dists = bfs_caminho_minimo(origem, n, adj);

    cout << "Distancias a partir do vertice " << origem << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "Vertice " << i << ": " << dists[i] << endl;
    }

    return 0;
}