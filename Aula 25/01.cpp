#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> build_c_table(const string& L) {
    map<char, int> freq;
    
    // Conta frequencia de cada caractere
    for (char c : L) freq[c]++;
    
    // Cria C-Table
    map<char, int> C;
    int total = 0;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        C[it->first] = total;
        total += it->second;
    }
    
    return C;
}

int main() {
    string L = "annb$aa";
    auto C = build_c_table(L);

    cout << "C-Table:\n";
    for (auto it = C.begin(); it != C.end(); ++it)
        cout << it->first << " -> " << it->second << "\n";

    return 0;
}
