#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<float>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    vector<vector<float>> buckets(n);

    for (float x : arr) {
        int idx = n * x; // bucket index
        if (idx >= n) idx = n - 1;
        buckets[idx].push_back(x);
    }

    for (int i = 0; i < n; i++) insertionSort(buckets[i]);

    int k = 0;
    for (int i = 0; i < n; i++)
        for (float x : buckets[i]) arr[k++] = x;
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    bucketSort(arr);

    cout << "Bucket Sort: ";
    for (float x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
