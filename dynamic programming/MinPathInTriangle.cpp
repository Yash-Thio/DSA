#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// memoization
int minimumTotal(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp)
{
    if (i == triangle.size())
        return 0;
    if (j >= triangle[i].size())
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = minimumTotal(triangle, i + 1, j, dp);
    int diagonal = minimumTotal(triangle, i + 1, j + 1, dp);

    dp[i][j] = triangle[i][j] + min(down, diagonal);
    return dp[i][j];
}

// tabulation
int solve(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];
}

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    cout << "Minimum path sum (memoization): " << minimumTotal(triangle, 0, 0, dp) << endl;

    cout << "Minimum path sum (tabulation): " << solve(triangle) << endl;

    return 0;
}