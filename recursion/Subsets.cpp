#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>result;
void subset(vector<int>& nums, int n, int j, vector<int>& r ) {
    for(int i = j; i < n; i++){
        r.push_back(nums[i]);
        result.push_back(r);
        subset(nums, n, i+1, r);
        r.pop_back();
    }
}

int main() {
    vector<int> nums = {1,2,3}; 
    vector<int> r;
    subset(nums, nums.size(), 0, r);
    result.push_back({});
    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}