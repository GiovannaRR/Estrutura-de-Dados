#include <iostream>      
#include <vector>  
#include <algorithm> 
#include <random> 
#include <chrono> 

using namespace std;
using namespace std::chrono; 

// funcao para gerar um vetor de inteiros aleatorios
vector<int> gerarVetor(int tamanho) {
    vector<int> v(tamanho);     //cria um vetor com a quantidade de elementos especificada
    for(int i = 0; i < tamanho; ++i) 
        v[i] = rand();          // gera um numero aleatorio para cada posicao
    return v;       
}

// funcao para realizar a busca sequencial
bool buscaSequencial(const vector<int>& v, int chave) {
    for(size_t i = 0; i < v.size(); ++i) {  
        if(v[i] == chave)                  //se encontrar o elemento retorna true
            return true;
    }
    return false;                    
}

//funcao para realizar a busca binaria.
bool buscaBinaria(const vector<int>& v, int chave) {
    int esquerda = 0, direita = v.size() - 1; //define os limites esquerdo e direito do vetor
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;  //calcula a posição do meio
        if (v[meio] == chave)                  //se encontrar o elemento retorna true
            return true;
        else if (v[meio] < chave)              //se o elemento esta na direita
            esquerda = meio + 1;
        else                                   //se o elemento esta na esquerda
            direita = meio - 1;
    }
    return false;                          
}

int main() {
    // vetor contendo os tamanhos de vetores a serem testados
    vector<int> tamanhos = {100, 1000, 10000, 100000, 1000000, 10000000};

    //tabela de resultados
    cout << "Tamanho\tSeq(ms)\tBin(ms)" << endl;

    //loop para cada tamanho de vetor.
    for(int tamanho : tamanhos) {
        vector<int> v = gerarVetor(tamanho);  // Gera um vetor aleatório com o tamanho atual.

        //define a chave para o pior caso da busca sequencial: ultimo elemento
        int chaveSeq = v.back();

        //tempo de busca sequencial.
        double tempoSeqTotal = 0.0;      
        for(int i = 0; i < 10; ++i) {        
            auto inicio = high_resolution_clock::now(); 
            buscaSequencial(v, chaveSeq);               
            auto fim = high_resolution_clock::now();     
            // Acumula o tempo em milissegundos.
            tempoSeqTotal += duration<double, milli>(fim - inicio).count();
        }
        //calcula a media do tempo
        double tempoSeqMedio = tempoSeqTotal / 10.0;

        //ordena o vetor para realizar a busca binaria
        sort(v.begin(), v.end());

        //define a chave para o pior caso da busca binaria: elemento que nao existe
        int chaveBin = -1;

        //medição do tempo de busca binaria.
        double tempoBinTotal = 0.0;    
        for(int i = 0; i < 10; ++i) {         
            auto inicio = high_resolution_clock::now();
            buscaBinaria(v, chaveBin);       
            auto fim = high_resolution_clock::now();   
            // Acumula o tempo em milissegundos.
            tempoBinTotal += duration<double, milli>(fim - inicio).count();
        }
        //calcula a media do tempo.
        double tempoBinMedio = tempoBinTotal / 10.0;

        cout << tamanho << "\t" << tempoSeqMedio << "\t" << tempoBinMedio << endl;
    }

    return 0;
}
