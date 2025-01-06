#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<char>>> result;

void queen(vector<vector<char>> &r, int Queen, int n)
{
    if (Queen == 0)
    {
        result.push_back(r);
        return;
    }
    int i = n - Queen;
    for (int j = 0; j < n; j++)
    {
        int h = 0;
        bool flag = true;
        for (auto c : r)
        {

            for (int k = 0; k < n; k++)
            {
                if ((r[h][k] == 'Q') && (j == k || abs(i - h) == abs(j - k)))
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
            h++;
        }
        if (flag)
        {
            vector<char> vec(n, '.');
            vec[j] = 'Q';
            r.push_back(vec);
            queen(r, Queen - 1, n);
            r.pop_back();
        }
    }
    return;
}

int main() {
  int n = 5;
  vector<vector<char>>r;
  queen(r,n,n);
for (const auto &solution : result) {
    for (const auto &row : solution) {
        for (const auto &ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << endl;
}
  return 0;
}