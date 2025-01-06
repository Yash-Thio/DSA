#include <iostream>
#include <vector>
using namespace std;

long long count = 0;
vector<int> even = {2, 4, 6, 8, 0};
vector<int> odd = {2, 3, 5, 7};

int countGoodNumbers(long long n, string s)
{
    if (s.length() == n)
    {
        count++;
        return 1;
    }
    else if (s.length() % 2 == 0)
    {
        for (auto i : even)
        {
            countGoodNumbers(n, s + to_string(i));
        }
    }
    else if (s.length() % 2 != 0)
    {
        for (auto i : odd)
        {
            countGoodNumbers(n, s + to_string(i));
        }
    }
    return 0;
}

int main()
{
    long long n;
    cin >> n;
    countGoodNumbers(n, "");
    cout << count;
}