#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    while (!st.empty() && st.top() <= nums[i])
                    {
                        st.pop();
                    }

                    if (st.empty())
                    {
                        nge[i] = -1;
                    }
                    else
                    {
                        nge[i] = st.top();
                    }
                    st.push(nums[i]);
                }
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    while (!(st.size() == 1) && st.top() <= nums[i])
                    {
                        st.pop();
                    }
                    if ((st.size() == 1) && (nums[i] == st.top()))
                    {
                        nge[i] = -1;
                    }
                    else
                    {
                        nge[i] = st.top();
                    }
                    st.push(nums[i]);
                }
            }
        }
        return nge;
    }
};
int main()
{
    Solution obj;
    vector<int> v{5, 7, 1, 2, 6, 0};
    vector<int> res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}