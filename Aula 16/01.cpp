#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    //suporte para valores negativos
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

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    cout << "Counting Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
