#include<algorithm>
#include<vector>
#include<iostream>
#include<limits>

using namespace std;

// 참조로 D를 전달하도록 수정
void floyd(int n, const vector<vector<int>> &W, vector<vector<int>> &D){
    int i, j, k;
    D = W;

    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]); // 올바른 수식으로 수정
        }
    }
}

int main(){
    const int INF = 987654321; // 무한대 값 표현 (오버플로우 방지를 위한 적절한 값)
    int n = 4; // 정점의 수
    
    // 인접 행렬 초기화 (1-indexed, 0번 인덱스는 사용하지 않음)
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    
    // 자기 자신으로의 거리는 0
    for(int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    
    // 간선 정보 입력 (예시)
    graph[1][2] = 5;
    graph[1][4] = 10;
    graph[2][3] = 3;
    graph[3][4] = 1;
    
    // 초기 그래프 출력
    cout << "초기 그래프:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    // 결과를 저장할 행렬
    vector<vector<int>> result(n+1, vector<int>(n+1));
    
    // Floyd-Warshall 알고리즘 실행
    floyd(n, graph, result);
    
    // 결과 출력
    cout << "\n모든 정점 간의 최단 거리:" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(result[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << result[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}