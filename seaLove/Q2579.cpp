#include<iostream>
#include<vector>

using namespace std;


void DP(vector<int> v){
    int n = v.size();
    vector<int> dp(n,0);
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[2]+v[1];
    dp[3] = max(v[2], v[1]) + v[3];

    for(int i = 4; i <= n-1; i++){
        if(dp[i-2] )
        dp[i] = max(dp[i-3] + v[i-1] + v[i], dp[i-2] + v[i]);
    }

    cout<<dp[n-1];

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> v(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin>>v[i];
    }
    DP(v);

}