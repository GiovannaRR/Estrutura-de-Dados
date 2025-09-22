#include <iostream>

int main(){

    int vet[8];

    std::cout << "Digite os numeros : \n";
    for(int i = 0; i < 8; i++){
            std::cin >> vet[i];
    }

    std::cout << "A inversa:\n";
    for(int  i = 7; i >= 0; i--){
        std::cout  << vet[i] << " ";
    }
    return 0;
}