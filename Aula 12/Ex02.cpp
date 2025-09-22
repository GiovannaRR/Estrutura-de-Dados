#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& A) {
    bool trocou;
    for (size_t i = 0; i < A.size(); i++) {
        trocou = false;
        for (size_t j = 0; j < A.size() - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

void selectionSort(vector<int>& A) {
    for (size_t i = 0; i < A.size() - 1; i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < A.size(); j++) {
            if (A[j] < A[menor]) menor = j;
        }
        swap(A[i], A[menor]);
    }
}

void insertionSort(vector<int>& A) {
    for (size_t i = 1; i < A.size(); i++) {
        int chave = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = chave;
    }
}

void imprimir(const vector<int>& A) {
    for (int n : A) cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> original = {9, 3, 9, 2, 5};

    vector<int> A1 = original;
    bubbleSort(A1);
    cout << "Bubble Sort: ";
    imprimir(A1);

    vector<int> A2 = original;
    selectionSort(A2);
    cout << "Selection Sort: ";
    imprimir(A2);

    vector<int> A3 = original;
    insertionSort(A3);
    cout << "Insertion Sort: ";
    imprimir(A3);

    return 0;
}
