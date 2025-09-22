#include<iostream>
#define TAM 2

int main(){
    int matriz1[TAM][TAM];
    int matriz2[TAM][TAM];
    int matriz3[TAM][TAM] = {0};

    std::cout << "Digite os numeros da matriz 1: ";
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            std::cin >> matriz1[i][j];
        }
    }

    std::cout << "Digite os numeros da matriz 2: ";
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            std::cin >> matriz2[i][j];
        }
    }

    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
        matriz3[i][j] += matriz1[i][j] + matriz2[i][j];
        }
    }

    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            std::cout << " " << matriz3[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}