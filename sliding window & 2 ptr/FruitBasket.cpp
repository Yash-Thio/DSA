#include <iostream>
#include <vector>
#include <map>
using namespace std;

int totalFruits(vector<int> &v)
{
    int max = 0;
    int left = 0;
    int right = 0;
    map<int, int> map;
    while (right != v.size())
    {
        if (map.size() < 2 || map.find(v[right]) != map.end())
        {
            map[v[right]] = right;
        }
        else
        {
            int l = (map.begin()->second > (next(map.begin())->second)) ? next(map.begin())->first : map.begin()->first;
            left = map[l] + 1;
            map.erase(l);
            map[v[right]] = right;
        }
        max = (max > (right - left + 1)) ? max : (right - left + 1);
        right++;
    }
    return max;
}

int main()
{
    vector<int> v = {3, 1, 2, 2, 2, 2};
    cout << totalFruits(v) << endl;
}