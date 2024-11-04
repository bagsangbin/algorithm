#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    int repeatNum = 0;
    string str;

    cin>>count;

    for(int i = 0; i < count; i ++)
    {
        cin>>repeatNum>>str;
        for(char ch : str)
        {
            for(int j = 0; j < repeatNum; j++) cout<<ch;
        }
        cout<<'\n';
    }
}