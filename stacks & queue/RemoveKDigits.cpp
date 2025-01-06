#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    if (num.size() == k)
    {
        return "0";
    }
    stack<char> st;
    for (int i = 0; i < num.length(); i++)
    {

        while (!st.empty() && int(st.top()) > int(num[i]) && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k)
    {
        st.pop();
        k--;
    }
    string str = "";
    while (!st.empty())
    {
        str = str + st.top();
        st.pop();
    }
    reverse(str.begin(), str.end());
    int start = 0;
    while (start < str.length() && str[start] == '0')
    {
        start++;
    }
    str = str.substr(start);

    if (str.empty())
    {
        return "0";
    }
    return str;
}

int main()
{
    cout << removeKdigits("1432219", 3) << endl;
}
