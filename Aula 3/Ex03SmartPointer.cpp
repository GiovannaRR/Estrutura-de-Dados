#include <iostream>
#include <memory> /* com essa biblioteca podemos usar o "std::unique_ptr" que garante que a memória será liberada
                  mesmo se ocorrer uma exceção.*/

void processoArriscado() {
    std::unique_ptr<int[]> recurso(new int[100]); //cria um ptr que gerencia o array

    recurso[0] = 42;

    throw std::runtime_error("Erro de teste!"); //esta lançando uma exceçao

    std::cout << "Processo concluido :) \nValor: " << recurso[0] << std::endl;
    //o smart pointer "usa" o delete automaticamente
}

int main() {
    try {
        processoArriscado(); //codigo que pode dar erro
    } catch (const std::exception& e) { //caso de erro, aqui resolve
        std::cout << " " << e.what() << std::endl; 
    }

    return 0;
}
