#include<iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char ch;
    cin>>ch;

    cout<<static_cast<int>(ch);
}