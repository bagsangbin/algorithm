#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m,i,j;
    int sum;

    cin >> n >> m;

    vector<int> v(n + 2, 0);
    vector<int> prefix(n+2, 0);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
        prefix[i] = prefix[i-1] + v[i];
    }

    while(m--){
        sum = 0;
        cin >> i >> j;

        cout << prefix[j] - prefix[i-1] << '\n';
    }
}