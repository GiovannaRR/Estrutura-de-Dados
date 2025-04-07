#include<iostream>

int main(){
    
    int vet[5];
    bool temRepetido = false;

    std::cout << "Digite os numeros: ";
    for(int i = 0; i < 5; i++){
        std::cin >> vet[i];
    }

    std::cout << "\nOs numeros iguais sao:";
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(vet[i] == vet[j]){
                std::cout << " " << vet[j];
                temRepetido = true;
            }
        }
    }

    if(temRepetido == false){
        std::cout << "\nNao tem numeros iguais!";
    }
    return 0;
}
