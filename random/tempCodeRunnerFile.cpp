#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& s, int t)
{
    if (s.empty() || s.top() <= t)
    {
        s.push(t);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, t);
    s.push(temp);
}

void sort(stack<int>& s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        sort(s);
        insert(s, temp);
    }
}

int main()
{
    stack<int> v;
    v.push(30);
    v.push(-5);
    v.push(18);
    v.push(14);
    v.push(-3);

    sort(v);
    while (!v.empty())
    {
        cout << v.top() << endl;
        v.pop();
    }
    return 0;
}
