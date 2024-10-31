#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    string str;
    string buf;
    vector<string> strBuffer;


    cin>>count;
    for(int i = 0; i < count; i++)
    {
        cin>>str;
        buf = string(1,str[0]) + str[str.length()-1];
        strBuffer.push_back(buf);
    }
    for(string ch : strBuffer)
    {
        cout<<ch<<'\n';
    }

}