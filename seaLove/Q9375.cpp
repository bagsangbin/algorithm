#include<iostream>
#include<map>

using namespace std;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    int n;
    int ans;
    string a,b;
    map<string, int>::iterator it;

    cin>>t;
    while(t--){
        map<string, int> m;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a>>b;

            m[b]++;

        }
        ans = 1;
        for(it = m.begin(); it != m.end(); it++){
            ans *= it->second + 1;
        }

        cout<<ans-1<<'\n';
    }

    


}