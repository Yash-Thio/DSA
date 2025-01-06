#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>result;
void subset(vector<int>& nums, int n, int j, int sum ) {
    for(int i = j; i < n; i++){
        sum += nums[i];
        result.push_back(sum);
        subset(nums, n, i+1, sum);
        sum -= nums[i];
    }
}

int main() {
    vector<int> nums = {1,2,3};
    result.push_back(0);
    subset(nums, nums.size(), 0, 0);
    sort(result.begin(),result.end());
    for(auto i : result){
        cout << i << " ";
    }
    return 0;
}