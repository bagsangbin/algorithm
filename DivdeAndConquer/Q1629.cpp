#include<iostream>
#include<algorithm>

using namespace std;

long long powe(int a, int b, int c){

    if(b == 0 ) return 1;

    long long half = powe(a,b/2,c);
    half = (half * half) % c;

    if(b % 2 == 1) half = (half * a) % c;

    return half;
}


int main(){

    int a,b,c;
    cin>>a>>b>>c;
    cout<<(powe(a, b,c));

}