#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

double helper(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else if (n == -1)
    {
        return 1 / x;
    }
    double half = helper(x, n / 2);

    if (n % 2 == 0)
    {
        return half * half;
    }
    else if (n % 2 == 1 && x > 0)
    {
        return x * half * half;
    }
    else
    {
        return (1 / x) * half * half;
    }
}

double myPow(double x, int n)
{
    if (x < 0 && abs(n) % 2 == 1)
    {
        return (-1) * helper(abs(x), n);
    }
    return helper(abs(x), n);
}

int main()
{
    cout << myPow(-13.62608, 3);
}