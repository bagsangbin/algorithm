#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int index;
    string str;
    cin>>str;
    cin>>index;

    cout<<str[index-1];
}