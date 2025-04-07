#include<iostream>
#define MAX 255

    void inserir(int vet[], int &tam, int valor){
        if(tam < MAX){
            vet[tam] = valor;
            tam++;
        }
        else{
            std::cout << "Lista cheia!\n";
        }
    }

    void remover(int vet[], int &tam, int valor){
        int posicao = -1;
        for(int i = 0; i < tam; i++){
            if(vet[i] == valor){
                posicao = i;
            }
        }
        if(posicao == -1){
            std::cout << "O valor nao existe!\n";
        }
        else{
            for(int i = posicao; i < tam - 1;  i++){
                vet[i] = vet[i + 1];
            }
            tam--;
        }
    }

    void buscar(int vet[], int &tam, int valor){
        for(int i = 0; i < tam; i++){
            if(vet[i] == valor){
                std::cout << "Valor encontrado na posicao: " << i;
            }
        }
    }

int main(){
    int vet[MAX];
    int valor = 0, tam = 0;

    std::cout << "Digite o tamanho do vetor: \n";
    std::cin >> tam;

    std::cout << "Digite os numeros do vetor: \n";
    for(int i = 0; i < tam; i++){
        std::cin >> vet[i];
    }

    std::cout << "Digite o valor para inserir: \n";
    std::cin >> valor;
    inserir(vet, tam, valor);

    std::cout << "Digite o valor para remover: \n";
    std::cin >> valor;
    remover(vet, tam, valor);

    std::cout << "Digite o valor para buscar: \n";
    std::cin >> valor;
    buscar(vet, tam, valor);

    std::cout << "\nVetor atualizado:\n";
    for(int i = 0; i < tam; i++){
        std::cout << " " << vet[i];
    }

    return 0;
}