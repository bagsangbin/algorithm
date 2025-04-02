#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

void dfs(int node, vector<int> &graph, vector<bool> &visited){
    visited[node]= true;
    int next = graph[node];

    if(!visited[next]){
        dfs(next, graph, visited);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> graph(N+1);
        vector<bool> visited(N+1, false);
        int ct = 0;
        
        for(int i = 1; i <= N; i++){
            cin>>graph[i];
        }

        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                dfs(i, graph, visited);
                ct++;
            }
        }
        cout<<ct<<'\n';

    }

    return 0;
}