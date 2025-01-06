#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

void generate(int open, int closed, int n, string s)
{
    if (s.length() == 2 * n)
    {
        result.push_back(s);
        return;
    }
    else if (open == 0)
    {
        generate(open + 1, closed, n, s + '(');
    }
    else if (open == n)
    {
        for (int i = 0; i < (open - closed); i++)
        {
            s = s + ')';
        }
        result.push_back(s);
        return;
    }
    else
    {
        generate(open + 1, closed, n, s + '(');
        if (open > closed)
        {
            generate(open, closed + 1, n, s + ')');
        }
    }
}
int main (){
    generate(0,0,3,"");
    for(auto i: result){
        cout << i << endl;
    }
}