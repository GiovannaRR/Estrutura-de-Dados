#include <iostream>
#include <vector> // uso do vector<int>, vetor dinamico
#include <ctime> // contar o tempo 
#include <cstdlib> // rand(), gera numeos aleatorios 

using namespace std;

    void bubbleSort(std::vector<int> arr){ //arr: copia do vetor oriiginal
        int n = arr.size(); //pega o tamanho do vetor
        bool trocou;
        for(int i = 0; i < n - 1; i++){ 
            trocou = false;
            for(int j = 0; j < n - 1 - i; j++){ 
                if(arr[j] > arr[j + 1]){ 
                    swap(arr[j], arr[j + 1]); // se estiver na ordem errada ele troca de lugar 
                    trocou = true; //se 1, então ainda tem que ordenar
                }
            }
            if(!trocou) break; // se 0, então está ordenado
        }
    }

    void selectionSort(std::vector<int> arr){
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            int menor = i;
            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[menor]){
                    menor = j; //acha o menor 
                }
            }
            swap(arr[i], arr[menor]); // troca de lugar
        }
    }

    void insertionSort(std::vector<int> arr){
        int n = arr.size();
        for(int i = 1; i < n; i++){
            int chave = arr[i]; // valor atual a ser inserido
            int j = i - 1;
            while (j >= 0 && arr[j] > chave) {
                arr[j + 1] = arr[j]; // move o maior elemento para a direita
                j--;
            }
            arr[j + 1] = chave; // coloca a chave no lugar certo
        }
    }

    vector<int> gerarVetor(int n) { //função para gerar um vetor aleatorio 
    vector<int> v(n); // cria vetor de tamanho n
    for (int i = 0; i < n; i++)
        v[i] = rand() % 10000; // preenche com número aleatório entre 0 e 9999
    return v;
}

int main() {
    srand(time(0)); // inicializa o gerador de numeros com o tempo

    int n = 1000; // tamanho do vetor
    vector<int> original = gerarVetor(n);
    vector<int> v1 = original, v2 = original, v3 = original;

    clock_t inicio, fim;
    
    // Bubble Sort
    inicio = clock();
    bubbleSort(v1);
    fim = clock();
    cout << "Tempo Bubble Sort: " << (fim - inicio) * 1000.0 / CLOCKS_PER_SEC << " ms\n";
    
    // Selection Sort
    inicio = clock();
    selectionSort(v2);
    fim = clock();
    cout << "Tempo Selection Sort: " << (fim - inicio) * 1000.0 / CLOCKS_PER_SEC << " ms\n";

    // Insertion Sort
    inicio = clock();
    insertionSort(v3);
    fim = clock();
    cout << "Tempo Insertion Sort: " << (fim - inicio) * 1000.0 / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
//Tempo Bubble Sort: 9 ms
//Tempo Selection Sort: 3 ms
//Tempo Insertion Sort: 5 ms
