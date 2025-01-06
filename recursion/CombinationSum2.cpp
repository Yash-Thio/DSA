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
        if (i > start && nums[i] == nums[i - 1])
        {
            continue;
        }
        if (sumC + nums[i] <= sum)
        {
            r.push_back(nums[i]);
            helper(nums, sum, sumC + nums[i], r, i + 1);
            r.pop_back();
        }
    }
}

void combinationSum2(vector<int> &nums, int sum)
{
    vector<int> r;
    sort(nums.begin(), nums.end());
    helper(nums, sum, 0, r, 0);
}

int main()
{
    vector<int> nums = {10, 1, 2, 7, 7, 6, 1, 5};
    int sum = 8;
    combinationSum2(nums, sum);
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
