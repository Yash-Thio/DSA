#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool knows(vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(vector<vector<int>>& M, int n) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(M, a, b)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int c = s.top();
    s.pop();

    for (int i = 0; i < n; i++) {
        if (i != c && (knows(M, c, i) || !knows(M, i, c))) {
            return -1;
        }
    }

    return c;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();
    int result = findCelebrity(M, n);

    if (result == -1) {
        cout << "There is no celebrity." << endl;
    } else {
        cout << "The celebrity is person " << result << "." << endl;
    }

    return 0;
}