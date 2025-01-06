#include <iostream>
#include <map>
using namespace std;

int numberOfSubstrings(string s)
{
    int count = 0;
    int left = 0;
    int right = 0;
    map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 0;
    mp['c'] = 0;
    while (right != s.length())
    {
        mp[s[right]]++;
        while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
        {
            count += s.length() - right;
            mp[s[left]]--;
            left++;
        }
        right++;
    }
    return count;
}

int main(){
    cout << numberOfSubstrings("abcabc") << endl;
}