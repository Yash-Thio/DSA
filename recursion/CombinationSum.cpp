#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
void helper(vector<int> &nums, int sum, int sumC, vector<int> &r, int start)
{
    if (sumC == sum)
    {
        result.push_back(r);
        return;
    }
    for (int i = start; i < nums.size(); i++)
    {
        if (sumC + nums[i] <= sum)
        {
            r.push_back(nums[i]);
            helper(nums, sum, sumC + nums[i], r, i);
            r.pop_back();
        }
    }
}

void combinationSum(vector<int> &nums, int sum)
{
    vector<int> r;
    helper(nums, sum, 0, r, 0);
}

int main()
{
    vector<int> nums = {2, 3, 4, 7, 10};
    int sum = 7;
    combinationSum(nums, sum);
    for (const auto &subset : result)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
