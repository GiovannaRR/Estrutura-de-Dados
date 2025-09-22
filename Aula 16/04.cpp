#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

//Counting Sort
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;
    vector<int> count(range, 0), output(arr.size());

    for (int x : arr) count[x - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    arr = output;
}

//Radix Sort
void countingSortDigit(vector<int>& arr, int exp, int base = 10) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(base, 0);

    for (int x : arr) count[(x / exp) % base]++;
    for (int i = 1; i < base; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % base;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr, int base = 10) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= base) {
        countingSortDigit(arr, exp, base);
    }
}

int main() {
    int n = 100000;
    vector<int> arr(n);

    // Gerador de numeros
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n);

    for (int i = 0; i < n; i++) arr[i] = dis(gen);

    //teste Counting Sort
    auto v1 = arr;
    auto start = high_resolution_clock::now();
    countingSort(v1);
    auto end = high_resolution_clock::now();
    cout << "Counting Sort: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    //teste Radix Sort
    auto v2 = arr;
    start = high_resolution_clock::now();
    radixSort(v2, 10);
    end = high_resolution_clock::now();
    cout << "Radix Sort: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    //teste std::sort (MergeSort/IntroSort)
    auto v3 = arr;
    start = high_resolution_clock::now();
    sort(v3.begin(), v3.end());
    end = high_resolution_clock::now();
    cout << "std::sort: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}
