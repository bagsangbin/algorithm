#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int resultNum;
    int max = 0;
    int num;

    vector<double> reportCard(resultNum, 0.0);
    cin>>resultNum;

    for(int i = 0; i < resultNum; i++)
    {
        cin>>num;
        if(max <= num) max = num;
        reportCard[i] = static_cast<double>(num);
    }

    for(int i = 0; i < resultNum; i++)
    {
        reportCard[i] = reportCard[i] * 100 / max;
    }

    double result = 0;
    for(double i : reportCard)
    {
        result += i;
    }

    cout<<result/static_cast<double>(resultNum);


}