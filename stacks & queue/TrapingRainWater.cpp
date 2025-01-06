// most important question of stack, had to think for a whole day.
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int water = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];
            cout << "distance: " << distance << " bounded_height: " << bounded_height << " left height: " << height[st.top()] << " middle height: " << height[top] << " right height: " << height[i] << endl;
            water += distance * bounded_height;
            cout << "water: " << water << endl;
        }
        st.push(i);
    }
    return water;
}

int main()
{
    vector<int> arr = {3,2,0,1,1,4};
    cout<< trap(arr) << endl;
    return 0;
}