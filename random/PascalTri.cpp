#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<vector<int>>v;
    for(int i=0; i<x;i++){
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i){
                v[i][j]=1;
            }
            else{
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
    }
    for(int i=0; i<x;i++){
        for(int j=0;j<=i;j++)
        {
            cout << v[i][j] << " ";

        }
        cout<<'\n';
    }
    return 0;
}