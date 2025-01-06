#include <iostream>
#include <vector>
using namespace std;

bool searchWord(vector<vector<char>> &board, string word, int index, int row, int col, int m, int n)
{
    if (word.length() == index)
    {
        return true;
    }
    if (row < 0 || col < 0 || row == m || col == n || board[row][col] == '@' || word[index] != board[row][col])
    {
        return false;
    }

    char ch = board[row][col];
    board[row][col] = '@';
    bool top = searchWord(board, word, index + 1, row - 1, col, m, n);
    bool right = searchWord(board, word, index + 1, row, col + 1, m, n);
    bool bottom = searchWord(board, word, index + 1, row + 1, col, m, n);
    bool left = searchWord(board, word, index + 1, row, col - 1, m, n);
    board[row][col] = ch;
    return top || bottom || left || right;
}

bool exist(vector<vector<char>> board, string word)
{

    int m = board.size();
    int n = board[0].size();
    int index = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (board[i][j] == word[index])
            {
                if (searchWord(board, word, index, i, j, m, n))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};

    string word = "SEE";

    bool res = exist(board, word);
    if (res == 1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
