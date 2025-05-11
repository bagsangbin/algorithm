#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int x, vector<vector<int>> &v, vector<bool> &visited){

    visited[x] = true;

    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(!visited[y])
            dfs(y,v,visited);
    }
}

void bfs(int s, vector<vector<int>> &v, vector<bool> &visited){

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    int c = 0;
    cin>>n>>m;
    vector<vector<int>> v(n+2);
    vector<bool> visited(n+2, false);

    for(int i = 0; i < m; i++){
        int j, k;
        cin>>j>>k;
        v[j].push_back(k);
        v[k].push_back(j);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i,v,visited);
            c++;
        }
    }

    cout<<c;


}