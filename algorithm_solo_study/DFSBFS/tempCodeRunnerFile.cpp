#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

void dfs(int x, vector<vector<int>> &g, vector<bool> &visited){

    visited[x] = true;
    cout<<x<<' ';
    for(int i = 0; i < g[x].size(); i++){
        int y = g[x][i];
        if(!visited[y]){
            dfs(y,g,visited);
        }
    }
}

void bfs(int x, vector<vector<int>> &g, vector<bool> &visited){

    queue<int> q;
    q.push(x);
    visited[x] = true;
    cout<<x<<' ';
    while(!q.empty()){
        int k = q.front();
        q.pop();

        for(int i = 0; i < g[k].size(); i++){
            int y = g[k][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                cout<<y<<' ';
            }

        }
    }

}

int main(){
    int n,m,v;
    cin>>n>>m>>v;
    vector<vector<int>> g(n+2);
    vector<vector<int>> g2;
    vector<bool> visited(n+2, false);
    vector<bool> visited2(n+2, false);

    for(int i = 1; i <= m; i++){
        int j,k;
        cin>>j>>k;
        g[j].push_back(k);
        g[k].push_back(j);
    }
    for(int i = 1; i <= m; i++){
        sort(g[i].begin(), g[i].end());
    }

    g2 = g;
    dfs(v,g2,visited2);
    cout<<endl;
    bfs(v,g,visited);

    
}