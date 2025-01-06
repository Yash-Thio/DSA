#include <iostream>
#include <vector>

using namespace std;

bool knows(vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(vector<vector<int>>& M, int n) {
    int a = 0;
    int b = n - 1;

    while (a < b) {
        if (knows(M, a, b)) {
            a++;
        } else {
            b--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != a && (knows(M, a, i) || !knows(M, i, a))) {
            return -1;
        }
    }

    return a;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();
    int celebrity = findCelebrity(M, n);

    if (celebrity == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << celebrity << endl;
    }

    return 0;
}