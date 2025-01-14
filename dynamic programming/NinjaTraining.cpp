#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int ninjaTraining(vector<vector<int>> &points, int choice, int day, vector<vector<int>> &dp)
{
    if (day >= points.size())
    {
        return 0;
    }
    if(dp[day][choice] != -1){
        return dp[day][choice];
    }
    int maxPoints = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != choice)
        {
            int activity = points[day][i] + ninjaTraining(points, i, day + 1, dp);
            maxPoints = max(activity, maxPoints);
        }
    }
    dp[day][choice] = maxPoints;
    return maxPoints;
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    vector<vector<int>> dp(points.size(), vector<int>(4, -1));
    int maxPoints = 0;
    for (int i = 0; i < 3; i++) {
        maxPoints = max(maxPoints, ninjaTraining(points, i, 0, dp));
    }
    
    cout << maxPoints << endl;
    return 0;
}