// time complexity for both the approaches is the same

#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int max = 0;
    int n = 0;
    int j = 0;
    bool b = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            n++;
            if (n > k)
            {
                while (n != k)
                {
                    if (nums[j] == 0)
                    {
                        n--;
                    }
                    j++;
                }
            }
        }
        if (max < (i - j + 1))
        {
            max = i - j + 1;
        }
    }
    return max;
}

// int longestOnes(vector<int> &nums, int k)
// {
//     int max = 0;
//     int n = 0;
//     int i = 0;
//     int j = 0;
//     bool b = false;
//     while (i < nums.size())
//     {
        
//         if (n > k)
//         {
//             if (nums[j] == 0)
//             {
//                 n--;
//             }
//             j++;
//         }
//         else if (nums[i] == 0)
//         {
//             n++;
//         }
//         if(n <= k)
//         {
//             if (max < (i - j + 1))
//             {
//                 max = i - j + 1;
//             }
//             i++;
//         }
//     }
//     return max;
// }

int main()
{
    vector<int> v = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << longestOnes(v, k) << endl;
}