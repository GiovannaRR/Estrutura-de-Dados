#include <iostream>
#include <vector>
#include <algorithm> // Para swap
using namespace std;


    void bubbleSort (vector<int>& arr, int n) {
        bool swapped;
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - 1 - i; ++j) { 
                if (arr[j] < arr[j + 1]) { // Troca se o da esquerda for menor. Ordem decrescente
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

        if (!swapped) break; 

        }
    }

    void imprimir(const vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    int main() {
        vector<int> arr = {7, 3, 9, 2, 5};
        bubbleSort(arr, arr.size());
        cout << "Array ordenado: ";
        imprimir(arr);
        return 0;
    }