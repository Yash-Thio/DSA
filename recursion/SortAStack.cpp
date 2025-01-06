#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int t)
{
    if (s.empty() || s.top() <= t) // if (s.top() <= t || s.empty()) this will not work as the first condition
    {                              // contains s.top() which will result in segmentation fault if stack is empty.
        s.push(t);                 // therefore check for empty first; if empty then the second condition will not be checked.
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, t);
    s.push(temp);
}

void sort(stack<int> &s)
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
    v.push(20);
    v.push(-5);
    v.push(11);
    v.push(-3);
    v.push(14);

    sort(v);
    while (!v.empty())
    {
        cout << v.top() << endl;
        v.pop();
    }
    return 0;
}
