#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
void helper(vector<int> &nums, int j, int sum, int sumC, vector<int> &r)
{
    if (sumC == sum)
    {
        result.push_back(r);
        return;
    }
    for (int i = j; i < nums.size(); i++)
    {
        if (sumC + nums[i] <= sum)
        {
            r.push_back(nums[i]);
            helper(nums, i + 1, sum, sumC + nums[i], r);
            r.pop_back();
        }
    }
}

void checkSubSequenceSum(vector<int> &nums, int sum)
{
    vector<int> r;
    helper(nums, 0, sum, 0, r);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 6;
    checkSubSequenceSum(nums, sum);
    cout << "Subsets:" << endl;
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