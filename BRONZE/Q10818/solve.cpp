#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(void)
{
    int count;
    vector<int> numbers;
    int number;
    int max;
    int min;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>count;
    for(int i = 0; i < count; i++)
    {
        cin>>number;
        numbers.push_back(number);
    }

    min = numbers[0];
    max = min;

    for(int counted : numbers)
    {
        if(max <= counted) max = counted;
        if(min >= counted) min = counted; 
    }

    cout<<min<<" "<<max;
    
}