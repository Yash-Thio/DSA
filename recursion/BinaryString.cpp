#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

void generate(int i, int n, string s)
{
    if (s.length() == n)
    {
        result.push_back(s);
        return;
    }
    else
    {
        generate(i + 1, n, s + '0');
        if (s[i - 1] != '1')
        {
            generate(i + 1, n, s + '1');
        }
    }
}
int main()
{
    generate(0, 4, "");
    for (auto i : result)
    {
        cout << i << endl;
    }
}