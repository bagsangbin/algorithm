#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;


void solution(){

    int n, k;
    cin >> n >> k;
    int counter = 0;

    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    for(int i = n-1; i >= 0; i--){
        if(k == 0 ) break;

        if(k >= coins[i] ){
            counter += k / coins[i];
            k = k % coins[i];
        }
    }

    cout<<counter;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
    return 0;

}