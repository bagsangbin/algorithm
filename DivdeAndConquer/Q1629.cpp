#include<iostream>
#include<algorithm>

using namespace std;

int powe(int a, int b, int c){

    if(b == 0 ) return 1;

    long long temp = powe(a,b/2, c);

    temp = (temp * temp) % c;
    if(b % 2 == 1) temp = temp * a % c;

    return temp; 
}


int main(){

    int a,b,c;
    cin>>a>>b>>c;
    cout<<(powe(a, b,c));

}