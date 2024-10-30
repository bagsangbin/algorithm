#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int index;
    vector<bool> isSubmit(30, false);

    for(int i = 0; i < 28; i++)
    {
        cin>>index;
        isSubmit[index-1] = true;
    }

    for(int j = 0; j < 30; j++)
    {
        if(isSubmit[j] == false) cout<<j+1<<'\n';
    }

}