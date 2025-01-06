#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int> &nums, int k)
{
    unordered_map<int, int> count;
    int left = 0, result = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        count[nums[right]]++;

        while (count.size() > k)
        {
            count[nums[left]]--;
            if (count[nums[left]] == 0)
            {
                count.erase(nums[left]);
            }
            left++;
        }

        result += right - left + 1;
    }
    return result;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

// Driver code
int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Number of subarrays with exactly " << k
         << " different integers: " << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}