#include<iostream>
#define MAX 255

class Pilha{
    private:
    int array[MAX];
    int topo;

    public: 
    Pilha(){
        topo = -1;
    }

    void push(int valor){
        if(topo < MAX -1){
            array[++topo] = valor;
        }
        else{
            std::cout << "\nPilha cheia!\n";
        }
    }

    int pop(){ //desempilhar
        if(topo >= 0){ //verifica se tem elementos na pilha
            return array[topo--];
        }
        else{
            std::cout << "\nPilha vazia!\n";
            return -1;
        }
    }

    int top(){
        if(topo >= 0){
            return array[topo];
        }
        else{
            std::cout << "\nPilha vazia!\n";
            return -1;
        }
    }

    bool vazia() {
        return topo == -1;
    }

    void print() {
        for (int i = topo; i >= 0; i--) {
            std::cout << (char)array[i] << " ";
        }
        std::cout << std::endl;
    }

    void inverterPilha(){
        Pilha auxiliar;
        while (!vazia()) {
            int valor = pop();
            auxiliar.push(valor);
        }

        while (!auxiliar.vazia()) {
            int valor = auxiliar.pop();
            push(valor);
        }
    }

};

int main(){
    Pilha pil;
    char vet[MAX];
    int tam = 0;

    std::cout << "Qual o tamanho da sua expressao? \n";
    std::cin >> tam;

    std::cout << "Digite a expressao: \n";
    for(int i = 0; i < tam; i++){
        std::cin >> vet[i];
        pil.push((int)vet[i]);
    }

    std::cout << "Pilha antes: ";
    pil.print();

    pil.inverterPilha();

    std::cout << "\nO resultado eh: ";
    pil.print();

    return 0;
}