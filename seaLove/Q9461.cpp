#include<iostream>
#include<vector>

using namespace std;


void DP(vector<long> &dp){

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i = 6; i <= 100; i++)
        dp[i] = dp[i-2] + dp[i-3];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    vector<long> dp(100+2, 0);
    DP(dp);

    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<'\n';
    }

}