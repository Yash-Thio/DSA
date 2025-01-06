// You are given an array b
//  of n−1
//  integers.

// An array a
//  of n
//  integers is called good if bi=ai&ai+1
//  for 1≤i≤n−1
// , where &
//  denotes the bitwise AND operator.

// Construct a good array, or report that no good arrays exist.
// 4
// 1 2 3
// 5
// 3 5 4 2

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    a[0] = b[0];
    a[n - 1] = b[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        a[i] = b[i] | b[i - 1];
    }
    bool x = true;
    for (int i = 0; i < n-1; i++)
    {
        if (b[i] != (a[i] & a[i + 1]))
        {
            x = false;
            cout << -1<< endl;
            break;
        }
    }
    if (x)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
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