#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  int a[n];
  int max = INT_MIN;
  for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i%2==0){
            max = (a[i]>max)?a[i]:max;
        }
    }
    cout << max<< endl;
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