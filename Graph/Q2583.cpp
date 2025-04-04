#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int bfs(vector<vector<bool>> &isVisited, int M, int N, int i, int j){
    queue<pair<int, int>> q;
    isVisited[i][j] = true;
    q.push({i,j});
    int ct = 1;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.second + dx[dir];
            int ny = cur.first + dy[dir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(isVisited[ny][nx]) continue;

            isVisited[ny][nx] = true;
            q.push({ny, nx});
            ct++;
        }
    }

    return ct;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M,N,K;
    cin>>M>>N>>K;
    int startX, startY;
    int endX, endY;
    vector<int> result;
    vector<vector<bool>> isVisited(M, vector<bool>(N, false));

    for(int i = 0; i < K; i++){
        cin>>startX>>startY>>endX>>endY;
        for(int j = startY; j < endY; j++){
            for(int k = startX; k < endX; k++){
                isVisited[j][k] = true;
            }
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!isVisited[i][j]) {
                result.push_back(bfs(isVisited, M, N, i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    cout<<result.size()<<'\n';
    for(auto k : result){
        cout<<k<<' ';
    }
}