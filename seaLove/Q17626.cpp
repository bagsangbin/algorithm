#include<iostream>
#include<cmath>

using namespace std;


void BF(int n, int &min){

    for(int i = 0; i <= sqrt(n); i++)
        for(int j = 0; j <= sqrt(n); j++)
            for(int k = 0; k <= sqrt(n); k++)
                for(int p = 0; p <= sqrt(n); p++)
                    if(n == i*i + j*j + k*k + p*p){
                        min += i?1:0;
                        min += j?1:0;
                        min += k?1:0;
                        min += p?1:0;
                        return;
                    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n=0;
    int min=0;

    cin>>n;
    BF(n, min);
    cout<<min;
}