//uma matriz 1000x1000 0.454 segundos
#include<ctime>
#include<iostream>

int main(){

    int lin = 0, col = 0;
    int cont = 0;

    std::cout << "Digite o tamanho da matriz M x N : \n"; 
    std::cin >> lin >> col;

    clock_t inicio = clock();

    int * array = new int[lin * col]; 
    int ** matriz = new int*[lin]; 
    for(int i = 0; i < lin; i++){
        matriz[i] = array + i*col; 
    }
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cont++;
            matriz[i][j] = cont;
            //std::cout << " " << matriz[i][j]; 
        }
        //std::cout << std::endl;
    }

    clock_t fim = clock();

    double tempo_execucao = double(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "" << tempo_execucao << " segundos" << std::endl;

    delete[] array;
    delete[] matriz;
}

/*3 a) Localidade de Referencia: quando os dados estao proximos a memoria o acesso eh mais rapido
no caso do boloco contiguo os dados sao organizados sequencialmente, ja no vetor de vetores, os 
dados sao espalhados, o que torna mais lento*/

/*b) Fragmentacao de Memoria: o contiguo eh alocado de forma continua evitando a fragmentacao
diferente do vetor de vetores que a memoria pode ficar fragmentada ja que as linhas sao 
alocadas separadamente*/

