#include<iostream>

int main(){

    int lin = 0, col = 0;
    int cont = 0;

    std::cout << "Digite o tamanho da matriz M x N : \n"; 
    std::cin >> lin >> col;

    int * array = new int[lin * col]; //aloca todos os elementos em um unico bloco de memoria
    int ** matriz = new int*[lin]; //cada ponteiro aponta para uma linha dentro do array

    for(int i = 0; i < lin; i++){
        matriz[i] = array + i*col; /*array + i * col move o ponteiro i para frente fazendo que matriz[i]
                                    represente corretamente cada linha.*/
    }
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cont++;
            matriz[i][j] = cont;
            std::cout << " " << matriz[i][j]; 
        }
        std::cout << std::endl;
    }
    
    //libera o bloco de memoria
    delete[] array; 
    delete[] matriz;
}