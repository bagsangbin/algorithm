#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);

    int col;
    int count;

    cin>>col>>count;

    vector<int> v(col,0);

    int j, k,num;
    
    for(int i = 0; i < count; i++)
    {
        cin>>j>>k>>num;
        for(j; j<=k; j++)
        {
            v[j-1] = num;
        }
    }

    for(int i : v)
    {
        cout<<i<<' ';
    }
}