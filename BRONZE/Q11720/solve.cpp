#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int result = 0;
    string str;
    cin>>str;
    cin>>str;

    for(int i = 0; i < str.length(); i++)
        result += static_cast<int>(str[i]) - '0';


    cout<<result;
}