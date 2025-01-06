#include <iostream>
#include <map>
#include <utility>
using namespace std;

pair<int, string> longestSubString(string str)
{
    map<char, int> mp;
    int n = str.length();
    int j = 0;
    int max = 0;
    string max_sub = "";
    string sub = "";
    for (int i = 0; i < n; i++)
    {
        if ((mp.find(str[i]) != mp.end()) && (mp[str[i]] >= j))
        {
            j = mp[str[i]] + 1;
        }
        mp[str[i]] = i;
        sub = str.substr(j, i - j + 1);
        max_sub = (sub.length() > max) ? sub : max_sub;
        max = (sub.length() > max) ? sub.length() : max;
    }
    return make_pair(max, max_sub);
}

int main()
{
    pair<int, string> p = longestSubString("abcabcbb");
    cout << p.first << " " << p.second << endl;
}