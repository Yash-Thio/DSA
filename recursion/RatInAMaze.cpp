#include <iostream>
#include <vector>
using namespace std;

vector<string> paths;
void find(vector<vector<int>> &mat, string path, int row, int col, int n)
{
    if ((row == n - 1) && (col == n - 1) && (mat[row][col] == 1))
    {
        paths.push_back(path);
        return;
    }
    else if (row < 0 || col < 0 || row > n - 1 || col > n - 1)
    {
        return;
    }
    int c = mat[row][col];
    mat[row][col] = 2;
    if (row - 1 > 0 && mat[row - 1][col] == 1)
    {
        path = path + 'U';
        find(mat, path, row - 1, col, n); // up
        path.erase(path.length() - 1, 1);
    }
    if (col + 1 < n && mat[row][col + 1] == 1)
    {
        path = path + 'R';
        find(mat, path, row, col + 1, n); // right
        path.erase(path.length() - 1, 1);
    }
    if (row + 1 < n && mat[row + 1][col] == 1)
    {
        path = path + 'D';
        find(mat, path, row + 1, col, n); // down
        path.erase(path.length() - 1, 1);
    }
    if (col - 1 > 0 && mat[row][col - 1] == 1)
    {
        path = path + 'L';
        find(mat, path, row, col - 1, n); // left
        path.erase(path.length() - 1, 1);
    }
    mat[row][col] = c;
}

int main()
{
    vector<vector<int>> board{{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};
    find(board, "", 0, 0, board.size());
    for (const auto &path : paths)
    {
        cout << path << endl;
    }
}
