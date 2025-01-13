#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int frogJump(vector<int> &height, int i, vector<int> &dp)
{
    if(i >= height.size()-1) return 0;
    if(dp[i] != -1){
        return dp[i];
    }
    int cost1 = abs(height[i+1] - height[i]) + frogJump(height, i+1, dp);
    int cost2 = i+2 < height.size() ? abs(height[i+2] - height[i]) + frogJump(height, i+2, dp) : INT_MAX;
    dp[i] = min(cost1, cost2);
    return min(cost1, cost2);
}

int main(){
    vector<int>v = {20, 30, 40, 20};
    vector<int>dp(v.size());
    memset(dp.data(), -1, v.size() * sizeof(int));
    cout << frogJump(v,0,dp) << endl;
}