#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

//no da arvore de sufixos
struct Node {
    map<char, Node*> filhos;  //arestas para os filhos
    bool folha = false;       //indica se eh folha
};

//insere um sufixo na arvore
void insereSufixo(Node* raiz, const string& sufixo) {
    Node* atual = raiz;
    for (size_t i = 0; i < sufixo.size(); i++) {
        char c = sufixo[i];
        if (atual->filhos.find(c) == atual->filhos.end()) {
            atual->filhos[c] = new Node();
        }
        atual = atual->filhos[c];
    }
    atual->folha = true;
}

//constroi a arvore de sufixos ingenua O(m²)
Node* construirArvore(const string& texto) {
    Node* raiz = new Node();
    for (size_t i = 0; i < texto.size(); i++) {
        insereSufixo(raiz, texto.substr(i));
    }
    return raiz;
}

//impressao da arvore (DFS) com indentacao
void imprimir(Node* no, string prefixo = "") {
    if (no->folha) {
        cout << prefixo << " (folha)" << endl;
    }
    for (map<char, Node*>::iterator it = no->filhos.begin(); it != no->filhos.end(); ++it) {
        imprimir(it->second, prefixo + it->first);
    }
}

int main() {
    vector<string> textos;
    textos.push_back("BANANA");
    textos.push_back("ABRACADABRA");

    for (size_t i = 0; i < textos.size(); i++) {
        cout << "Arvore de sufixos para \"" << textos[i] << "\":" << endl;
        Node* raiz = construirArvore(textos[i]);
        imprimir(raiz);
        cout << endl;
    }

    return 0;
}
