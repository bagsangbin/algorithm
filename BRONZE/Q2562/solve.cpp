#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{

    cin.tie(NULL);

    int number;
    int count = 0;
    int max = -5000;

    //magic number = 9, 알고리즘 요구 명세서의 조건
    for(int i = 0; i < 9; i++)
    {
        cin>>number;
        if(max <= number) 
        {
            count = i+1;
            max = number;
        }
    }

    cout<<max<<'\n'<<count;
}