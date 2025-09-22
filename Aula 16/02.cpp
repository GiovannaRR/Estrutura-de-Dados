#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//counting Sort estável
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
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr, 10);

    cout << "Radix Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
