#include<iostream>
//#include <algorithm> o comando sort dessa biblioteca ordena automaticamente sort(vet, vet + tam)
#define MAX 255

    void listaOrdenada(int vet[], int &tam, int valor){ 
        int i= tam - 1;
    
        while(i >= 0 && vet[i] > valor){ //desloca
            vet[i + 1] = vet[i];
            i--;
        }
        vet[i + 1] = valor; //insere no lugar correto
        tam++; //aumenta o tamanho do vetor
    }

int main(){
    int vet[MAX];
    int tam = 0, num = 0;

    std::cout << "Digite o tamanho do vetor: \n";
    std::cin >> tam;

    std::cout << "Digite os numeros: \n";
    for(int i = 0; i < tam; i++){
        std::cin >> vet[i];
    }

    std::cout << "Digite um novo numero para ser inserido: \n";
    std::cin >> num;

    listaOrdenada(vet, tam, num);

    for(int i = 0; i < tam; i++){
        std::cout << vet[i] << " ";
    }
    return 0;
}