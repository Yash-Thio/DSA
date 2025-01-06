#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int x)
{
    string str = to_string(x);
    if (str.length() > 2)
    {
        if (str[0] == '1' && str[1] == '0')
        {
            if (str[2] != '0')
            {
                if (((str[2] == '1') && (str.length() > 3)) || str[2] != '1')
                {
                    cout << "yes" << endl;
                }
                else
                {
                    cout << "no" << endl;
                }
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else
        {
            cout << "no" << endl;
        }
    }
    else
    {
        cout << "no" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        solve(x);
    }

    return 0;
}