#include <iostream>
#include <algorithm>

using namespace std;
char arr[3072][6144];

void drawStar(int y, int x, int n) {
    if (n == 3){
        arr[y][x] = '*';
        arr[y+1][x-1] = '*'; arr[y+1][x+1] = '*';
        arr[y+2][x-2] = '*'; arr[y+2][x-1] = '*'; arr[y+2][x] = '*'; arr[y+2][x+1] = '*'; arr[y+2][x+2] = '*';
    }


    else { // n이 0보다 클 때만 재귀 호출
        drawStar(y,x,n/2);
        drawStar(y+n/2, x-n/2, n/2);
        drawStar(y+n/2, x+n/2, n/2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    cin >> N;

    fill(&arr[0][0], &arr[0][0] + 3072 * 6144, ' '); // 배열 초기화

    drawStar(0, N-1, N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*2; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}