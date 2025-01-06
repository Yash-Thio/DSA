#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> max(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    int n = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() < (i - k + 1))
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[i] > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        n++;
        if(n >= k){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 4, 3, 5, 3, 6, 8};
    int k = 3;
    vector<int> ans = max(nums, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}