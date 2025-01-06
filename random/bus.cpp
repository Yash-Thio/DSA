#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    int maxi=INT_MIN, mini=INT_MIN,flag=0;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        if (i != 0)
        {
            if (y != (maxi + 1) && y != (maxi - 1) && y != (mini + 1) && y != (mini - 1))
            {
                flag=1;
                cout << "no"<< endl;
                break;
            }
        }
            maxi=max(maxi,v[i]);
            mini=min(mini,v[i]);
        v.push_back(y);
    }
    if(flag==0){
        cout << "yes"<< endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}