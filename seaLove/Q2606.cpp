#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int x, vector<vector<int>> &v, vector<bool> &isVisited){
    
    isVisited[x] = true;

    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(!isVisited[y]){
            dfs(y,v,isVisited);
        }
    }
}

void bfs(int s, vector<vector<int>> &v, vector<bool> &isVisited){
    queue<int> q;
    q.push(s);
    isVisited[s] = true;

    while(!q.empty()){
        int x= q.front();
        q.pop();

        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(!isVisited[y]){
                q.push(y);
                isVisited[y] = true;
            }
        }
    }
}



int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int comN;
    int conN;
    cin>>comN;
    cin>>conN;
    vector<vector<int>> v(comN+1);
    vector<bool> isVisited(comN+1, false);

    for(int i = 1; i <= conN; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int length = 0;
    bfs(1, v, isVisited);

    for(int i = 2; i <=comN; i++){
        if(isVisited[i] == true) length++;
    }

    cout<<length;

}