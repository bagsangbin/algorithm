#include<vector>
#include<iostream>
#include<queue>

using namespace std;

void bfs(pair<int, int> s, vector<vector<int>> &v){
    queue<pair<int, int>> q;
    v[s.first][s.second] = 0;
    q.push(make_pair(s.first, s.second));

    while(!q.empty()){

        pair<int, int> xy = q.front();
        q.pop();

        if(xy.first + 1 < v.size()){
            if(v[xy.first+1][xy.second] == 1){
                q.push(make_pair(xy.first+1, xy.second));
                v[xy.first+1][xy.second] = 0;
            }
        }
        if(xy.first - 1 >= 0){
            if(v[xy.first-1][xy.second] == 1){
                q.push(make_pair(xy.first-1, xy.second));
                v[xy.first-1][xy.second] = 0;
            }
        }
        if(xy.second + 1 < v[0].size()){
            if(v[xy.first][xy.second+1] == 1){
                q.push(make_pair(xy.first, xy.second+1));
                v[xy.first][xy.second+1] = 0;
            }
        }
        if(xy.second - 1 >= 0){
            if(v[xy.first][xy.second-1] == 1){
                q.push(make_pair(xy.first, xy.second-1));
                v[xy.first][xy.second-1] = 0;
            }
        }

    }


}

void solve(vector<vector<int>> v){

    int c = 0;

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 1){
                bfs(make_pair(i,j), v);
                c++;
            }
        }
    }
    cout<<c<<endl;

}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);

    int t,m, n, k;
    int x,y;
    cin>>t;

    while(t--){
        cin>>m>>n>>k;
        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i = 0; i < k; i++){
            cin>>x>>y;
            v[y][x] = 1;
        }

        solve(v);

    }

}