#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> result;
bool isPalin(string str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void palindromePartitioning(string str, vector<string> &r, int start)
{
    if (start == str.length())
    {
        result.push_back(r);
        return;
    }
    for (int i = start; i < str.length(); ++i)
    {
        if (isPalin(str, start, i))
        {
            r.push_back(str.substr(start, i - start + 1)); // substr(start, length)
            palindromePartitioning(str, r, i + 1);
            r.pop_back();
        }
    }
}
int main()
{
    vector<string> r;
    palindromePartitioning("aab", r, 0);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}