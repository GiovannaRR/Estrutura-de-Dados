#include <iostream>
#define MAX 255

class Pilha {
private:
    int array[MAX];
    int topo;

public:
    Pilha() {
        topo = -1;
    }

    void push(int valor) {
        if (topo < MAX - 1) {
            array[++topo] = valor;
        } else {
            std::cout << "Pilha cheia!\n";
        }
    }

    int pop() {
        if (topo >= 0) {
            return array[topo--];
        } else {
            std::cout << "Pilha vazia!\n";
            return -1;
        }
    }

    int top() {
        if (topo >= 0) {
            return array[topo];
        } else {
            std::cout << "Pilha vazia!\n";
            return -1;
        }
    }

    bool vazia() {
        return topo == -1;
    }

};

class FilaComPilhas {
    private:
    Pilha entrada;
    Pilha saida;
    
    public:
    void enqueue(int valor) {
        entrada.push(valor);
    }

    bool vazia() {
        return entrada.vazia() && saida.vazia();
    }
    
    int dequeue() {
        if (saida.vazia()) {
            while (!entrada.vazia()) {
                int valor = entrada.pop();
                saida.push(valor);
            }
        }
        
        if (!saida.vazia()) {
            return saida.pop();
        } else {
            std::cout << "Fila vazia!\n";
            return -1;
        }
    }
};

int main() {
    FilaComPilhas fila;
    int n, valor;

    std::cout << "Quantos numeros deseja enfileirar? ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Digite o valor " << i + 1 << ": ";
        std::cin >> valor;
        fila.enqueue(valor);
    }

    std::cout << "\nDesenfileirando valores:\n";
    while (!fila.vazia()) {
        std::cout << fila.dequeue() << " ";
    }

    return 0;
}
