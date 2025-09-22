#include <iostream> 
int main(){
    
    int lin = 3, col = 4;
    int mat[lin][col];
    
    std::cout << "Digite os numeros: \n"; //printf() --> std::cout
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            std::cin >> mat[i][j]; //scanf() --> std::cin
        }
    }

    int somaColunas[col] = {0};
    for(int i = 0; i < lin; i++){
        for(int j = 0; j <col; j++){
            somaColunas[j] += mat[i][j];
        }
    }
    
    std::cout << "O valor da soma das colunas eh: \n";
    for(int j = 0; j < col; j++){
        std::cout << "\nColuna:" << somaColunas[j];
    }
    return 0;
}