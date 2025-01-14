
#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = countWaysUtil(i - 1, j, dp, obstacleGrid);
    int left = countWaysUtil(i, j - 1, dp, obstacleGrid);

    return dp[i][j] = up + left;
}
int countWays(int m, int n, vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m - 1, n - 1, dp, obstacleGrid);
}

int main() {
    vector<vector<int>> obstacleGrid = {{0,1},{0,0}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n, obstacleGrid) << endl;

    return 0;
}

