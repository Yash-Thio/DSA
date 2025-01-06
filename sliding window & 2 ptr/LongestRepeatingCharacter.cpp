#include <iostream>
#include <vector>
#include <map>
using namespace std;

// this method also works but i dont know how. the part that confuses me is that
// when we are incrementing left we are also incrementing right.
// i guess this is just a sliding window which finds a window that satisfies the condition and when at a point
// the window does not satisfy the condition it just slides the window one step right in hope of it satisfying once again 
// and find a bigger window henceforth

// int characterReplacement(string s, int k)
// {
//     int left = 0;
//     int right = 0;
//     int maxF = 0;
//     int maxLen = 0;
//     map<char, int> mp;
//     while (right < s.length())
//     {
//         mp[s[right]]++;
//         maxF = max(maxF, mp[s[right]]);
//         if ((right - left + 1 - maxF) > k)
//         {
//             mp[s[left]]--;
//             maxF = max(maxF, mp[s[left]]);
//             left++;
//         }
//         maxLen = (maxLen > (right - left + 1)) ? maxLen : (right - left + 1);
//         right++;
//     }
//     return maxLen;
// }

int characterReplacement(string s, int k)
{
    int left = 0;
    int right = 0;
    int maxF = 1;
    int maxLen = 0;
    map<char, int> mp;
    mp[s[0]]++;
    while (right < s.length())
    {
        if ((right - left + 1 - maxF) > k)
        {
            mp[s[left]]--;
            maxF = 0;
            for (auto &p : mp)
            {
                maxF = max(maxF, p.second);
            }
            left++;
            continue;
        }
        maxLen = max(maxLen, (right - left + 1));
        right++;
        mp[s[right]]++;
        maxF = max(maxF, mp[s[right]]);
    }
    return maxLen;
}

int main()
{
    cout << characterReplacement("AAAB", 0) << endl;
}