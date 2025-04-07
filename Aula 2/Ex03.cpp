#include<iostream>

int main(){
    int vet[5];
    int soma = 0;
    int maior = 0, menor = 0;
    float media = 0, maiorMedia = 0;

    std::cout << "Digite os numeros: \n";
    for(int i = 0; i < 5; i++){
        std::cin >> vet[i];
    }

    maior = menor = vet[0];

    for(int i = 1; i < 5; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
        
        if(vet[i] < menor){
            menor = vet[i];
        }
    }

    for(int i = 0; i < 5; i++){
        soma += vet[i];
    }

    media = soma/5.00;

    int cont = 0;
    for(int i = 0; i < 5; i++){
        if(vet[i] > media){
            maiorMedia = vet[i];
            cont++;
            std::cout << "Numeros maior que a media: " << maiorMedia << std::endl;
        }
    }

    std::cout << "A media eh: " << media;
    std::cout << "\nQuantidade de numeros maior que a media: " << cont;
    std::cout << "\nO maior numero eh: " << maior;
    std::cout << "\nO menor numero eh: " << menor;

    return 0;
}