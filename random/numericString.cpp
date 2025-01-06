#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        string s;
        cin >> s;
        bool flag = true;
        map<int, char> m;
        if (s.length()==n)
        {
            for (int i = 0; i < n; i++)
            {
                if (m.find(arr[i]) != m.end())
                {
                    if (m[arr[i]] != s[i])
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    bool fag = true;
                    for (auto &it : m)
                    {
                        if (it.second == s[i])
                        {
                            fag = false;
                            flag=false;
                            break;
                        }
                    }
                    if(!fag){
                        break;
                    }
                    m[arr[i]] = s[i];
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
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