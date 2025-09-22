#include<iostream>

struct Vertex{
    int valor;
    Vertex* anterior;
    Vertex* proximo;

    Vertex(int val) : valor(val), anterior(nullptr), proximo(nullptr){}
};

class ListaDupla{
    private:
    Vertex* head;
    Vertex* tail;

    public:
    ListaDupla() : head(nullptr), tail(nullptr){}

     // Inserção no início da lista
     void push_front(int val) {
        Vertex* begin = new Vertex(val);
        if (head == nullptr) { 
            head = tail = begin;
        } else {
            begin->proximo = head; //novo inicio 
            head->anterior = begin; //antigo inicio aponta para o novo como anterior
            head = begin;      
        }
    }

    // Inserção no final da lista
    void push_back(int val) {
        Vertex* end = new Vertex(val);
        if (head == nullptr) { // Lista vazia
            head = tail = end;
        } else {
            end->anterior = tail;   //novo final aponta para o antigo
            tail->proximo = end;   //antigo final aponta para o novo
            tail = end;
        }
    }

    // Impressão da lista do início ao fim
    void print() {
        Vertex* current = head;
        while (current != nullptr) {
            std::cout << current->valor << " ";
            current = current->proximo;
        }
        std::cout << std::endl;
    }

    void removerDuplicados() {
        Vertex* atual = head;
    
        while (atual != nullptr) {
            Vertex* comparador = atual->proximo;
    
            while (comparador != nullptr) {
                Vertex* proximo = comparador->proximo; //guarda o próximo antes de deletar
    
                if (comparador->valor == atual->valor) {
                    if (comparador->anterior != nullptr) {
                        comparador->anterior->proximo = comparador->proximo;
                    }
    
                    if (comparador->proximo != nullptr) {
                        comparador->proximo->anterior = comparador->anterior;
                    }
    
                    if (comparador == tail) {
                        tail = comparador->anterior;
                    }
                    delete comparador; //libera memoria do no
                }
                comparador = proximo; //vai para o próximo
            }
            atual = atual->proximo;
        }
    }
};

int main() {
    ListaDupla lista;

    lista.push_back(10);
    lista.push_back(10);
    lista.push_back(30);
    lista.push_back(30);

    std::cout << "Lista original: ";
    lista.print();

    lista.removerDuplicados();

    std::cout << "Lista atualizada: ";
    lista.print();

    return 0;
}