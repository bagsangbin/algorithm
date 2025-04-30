#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;



void findMaxMin(int start, int end, vector<int> &v, int &max, int &min) {
    // 배열 요소가 하나인 경우
    if (start == end) {
        if (v[start] > max) max = v[start];
        if (v[start] < min) min = v[start];
        return;
    }
    
    // 배열 요소가 두 개인 경우
    if (end - start == 1) {
        if (v[start] > v[end]) {
            if (v[start] > max) max = v[start];
            if (v[end] < min) min = v[end];
        } else {
            if (v[end] > max) max = v[end];
            if (v[start] < min) min = v[start];
        }
        return;
    }
    
    // 분할 정복
    int mid = (start + end) / 2;
    
    // 왼쪽 부분 배열 탐색
    findMaxMin(start, mid, v, max, min);
    
    // 오른쪽 부분 배열 탐색
    findMaxMin(mid + 1, end, v, max, min);
}

int main(){

    vector<int> v = {2,4,6,1,3,7, 11, 0, 24, 56, 100, 240};
    int max = v[0];
    int min = v[0];

    findMaxMin(0, v.size(), v,max,min);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    return 0;
}