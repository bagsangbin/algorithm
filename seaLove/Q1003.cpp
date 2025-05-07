#include<iostream>
#include<vector>

using namespace std;

void DP(int n, int &count0, int &count1){

    vector<pair<int, int>> dp(n+1);

    dp[0] = make_pair(1,0);
    dp[1] = make_pair(0,1);

    for(int i = 2; i<= n; i++){
        dp[i] = make_pair(dp[i-1].first + dp[i-2].first, dp[i-1].second + dp[i-2].second);
    }
    count0 = dp[n].first;
    count1 = dp[n].second;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int count0, count1;

    int N;
    int a = 0;
    cin>>N;
    for(int i = 0; i < N; i++){
        count0 = 0;
        count1 = 0;
        cin>>a;
        DP(a, count0, count1);
        cout<<count0<<" "<<count1<<'\n';
    }
    
}
