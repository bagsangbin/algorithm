#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> english(26,-1);
    string input;
    int count = 0;
    cin>>input;
    for(char ch : input)
    {
        if(english[ch -'a'] == -1) 
        {
            english[ch -'a'] = count;
        }
        
        count++;
    }
    
    for(int i : english)
    {
        cout<<i<<" ";
    }
    
}