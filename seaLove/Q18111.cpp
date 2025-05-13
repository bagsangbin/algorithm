#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solution(vector<vector<int>> v, int maxHeight, long long b){

    int minTime = 1e9;
    int resultHeight = 0;

    for(int target = 0; target <= maxHeight; target++){
        long long blocks = b;
        int time = 0;

        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                int height = v[i][j];
                if(height > target){
                    blocks += height - target;
                    time += 2 * (height - target);
                } else if(height < target){
                    blocks -= target - height;
                    time += target - height;
                }
            }
        }

        if(blocks < 0) continue;

        if(time < minTime || (time == minTime && target > resultHeight)){
            minTime = time;
            resultHeight = target;
        }
    }

    cout << minTime << ' ' << resultHeight;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long b;
    cin >> n >> m >> b;

    vector<vector<int>> v(n, vector<int>(m));
    int maxH = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            maxH = max(maxH, v[i][j]);
        }
    }

    solution(v, maxH, b);
}