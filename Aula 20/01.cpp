#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//usando Max-Heap e extraindo k vezes
int KthLargestMaxHeap(vector<int>& data, int k) {
    // Constrói um Max-Heap
    priority_queue<int> maxHeap(data.begin(), data.end());

    int val = -1;
    for (int i = 0; i < k; i++) {
        val = maxHeap.top();
        maxHeap.pop();
    }
    return val;
}

//usando Min-Heap de tamanho k
int KthLargestMinHeap(vector<int>& data, int k) {
    // Min-Heap com os k primeiros elementos
    priority_queue<int, vector<int>, greater<int>> minHeap(data.begin(), data.begin() + k);

    // Processa o resto do vetor
    for (int i = k; i < (int)data.size(); i++) {
        if (data[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(data[i]);
        }
    }
    return minHeap.top(); // k-ésimo maior
}

// --- Teste ---
int main() {
    vector<int> v = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Usando Max-Heap: " << KthLargestMaxHeap(v, k) << endl;
    cout << "Usando Min-Heap: " << KthLargestMinHeap(v, k) << endl;

    return 0;
}
