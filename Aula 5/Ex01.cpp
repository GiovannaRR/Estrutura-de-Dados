#include<iostream> //codigo baseado no dos slides

    struct Vertex{
        int valor; // cada no esta guardando um valor
        Vertex* proximo; //ponteiro para o proximo no

        Vertex(int val) : valor(val), proximo(nullptr){} //inicia o valor e o prox como nulo
    };

    class ListaEncadeada{
        private:
        Vertex* head; //cabeça, começo da lista
        Vertex* tail; //"rabo", final

        public:
        ListaEncadeada() : head(nullptr), tail(nullptr){} //começa vazio

        // Inserir no final da lista
        void inserirNoFim(int val) {
            Vertex* novo = new Vertex(val);
            if (head == nullptr) { //caso a lista esteja vazia o novo no sera head e tail
                head = novo;
                tail = novo;
            } else {
                tail->proximo = novo;
                tail = novo; //atualiza tail para o novo no
            }
    }

        // Imprimir a lista
        void print() {
            Vertex* atual = head; //começa no head (começo da lista)
            while (atual != nullptr) { //enquanto nao chega no final (nullptr)
                std::cout << atual->valor << " ";
                atual = atual->proximo;
            }
            std::cout << std::endl;
        }

    // Inverter a lista
    void inverter() {
        Vertex* anterior = nullptr;
        Vertex* atual = head;
        Vertex* proximo = nullptr;

        tail = head; // Atual head vira novo tail

        while (atual != nullptr) {
            proximo = atual->proximo; 
            atual->proximo = anterior; //inverte
            anterior = atual;
            atual = proximo;
        }

        head = anterior; // novo inicio
    }

    // Destrutor para liberar memória
    ~ListaEncadeada() {
        Vertex* atual = head;
        while (atual != nullptr) {
            Vertex* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    ListaEncadeada lista;

    lista.inserirNoFim(10);
    lista.inserirNoFim(20);
    lista.inserirNoFim(30);
    lista.inserirNoFim(40);

    std::cout << "Lista original: ";
    lista.print();

    lista.inverter();

    std::cout << "Lista invertida: ";
    lista.print();

    return 0;
}
   