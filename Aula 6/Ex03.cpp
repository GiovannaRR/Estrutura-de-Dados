#include <iostream>
#include <string>
#define MAX 255

class Pilha {
private:
    char array[MAX];
    int topo;

public:
    Pilha() {
        topo = -1;
    }

    void push(char valor) {
        if (topo < MAX - 1) {
            array[++topo] = valor;
        } else {
            std::cout << "Pilha cheia!\n";
        }
    }

    char pop() {
        if (topo >= 0) {
            return array[topo--];
        }
    }

    char top() {
        if (topo >= 0) {
            return array[topo];
        } else {
            return '\0';
        }
    }

    bool vazia() {
        return topo == -1;
    }
};

bool estaBalanceado(std::string expressao) {
    Pilha pilha;

    for (char c : expressao) {
        if (c == '(' || c == '[' || c == '{') {
            pilha.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha.vazia()) return false;

            char topo = pilha.pop();
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return false;
            }
        }
    }

    return pilha.vazia();
}

int main() {
    std::string expressao;

    std::cout << "Digite a expressao: ";
    std::cin >> expressao;

    if (estaBalanceado(expressao)) {
        std::cout << "Expressao balanceada!\n";
    } else {
        std::cout << "Expressao nao balanceada!\n";
    }

    return 0;
}
