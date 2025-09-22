#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class RankSupport {
    string L;
    int checkpoint_size;
    map<char, vector<int>> checkpoints;

public:
    RankSupport(const string& L, int checkpoint_size = 4) : L(L), checkpoint_size(checkpoint_size) {
        map<char, int> count;
        for (size_t i = 0; i < L.size(); i++) {
            count[L[i]]++;
            if ((i + 1) % checkpoint_size == 0) {
                for (auto it = count.begin(); it != count.end(); ++it)
                    checkpoints[it->first].push_back(it->second);
            }
        }
        for (auto it = count.begin(); it != count.end(); ++it)
            if (checkpoints[it->first].size() * checkpoint_size < L.size())
                checkpoints[it->first].push_back(it->second);
    }

    int query(char c, int i) {
        if (i < 0) return 0;

        int block = i / checkpoint_size;
        int rank = 0;

        if (block > 0) {
            if (checkpoints.find(c) != checkpoints.end())
                rank = checkpoints[c][block - 1];
        }

        int start = block * checkpoint_size;
        int end = i;
        for (int j = start; j <= end; j++)
            if (L[j] == c) rank++;

        return rank;
    }
};

int main() {
    string L = "annb$aa";
    RankSupport rs(L, 3);

    cout << "Rank of 'a' at 0: " << rs.query('a', 0) << endl;
    cout << "Rank of 'a' at 2: " << rs.query('a', 2) << endl;
    cout << "Rank of 'a' at 6: " << rs.query('a', 6) << endl;
    cout << "Rank of 'n' at 3: " << rs.query('n', 3) << endl;

    return 0;
}
