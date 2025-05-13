#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>

using namespace std;


int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<long long> v;
    vector<long long> k;
    map<long long, int> m;
    for(int i = 0; i <n; i++){
        long long num;
        cin>>num;
        v.push_back(num);
    }
    k = v;

    sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());
    int q = 0;
    for(int i = 0; i < v.size(); i++){
        if(!(m[v[i]] == q)){
            m.insert({v[i],q++});
        }
    }

    for(int i = 0; i < k.size(); i++){
        cout<<m[k[i]]<<' ';
    }

    
}