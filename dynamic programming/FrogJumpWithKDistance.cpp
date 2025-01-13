#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int frogJump(vector<int> &height, int i, vector<int> &dp,int k)
{
    if(i >= height.size()-1) return 0;
    if(dp[i] != -1){
        return dp[i];
    }
    int m = INT_MAX;
    for(int j = 1; j<= k; j++){
        int cost = i+j < height.size() ? abs(height[i+j] - height[i]) + frogJump(height, i+j, dp, k) : INT_MAX;
        m = min(m,cost);
    }
    dp[i] = m;
    return m;
}

int main(){
    vector<int>v = {30, 10, 60, 10, 60, 50};
    vector<int>dp(v.size());
    int k = 2;
    memset(dp.data(), -1, v.size() * sizeof(int));
    cout << frogJump(v,0,dp,k) << endl;
}