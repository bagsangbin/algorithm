#include<iostream>
#include<vector>

using namespace std;

void binarySearch(vector<int> &v, int start, int end, int m, int &result) {
    if (start > end) return;

    int mid = (start + end) / 2;
    long long sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > mid) sum += (v[i] - mid);
    }

    if (sum >= m) {
        result = mid; // 가능한 절단 높이 저장
        binarySearch(v, mid + 1, end, m, result); // 더 높은 높이 탐색
    } else {
        binarySearch(v, start, mid - 1, m, result); // 낮은 높이 탐색
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> v;

    int n, m;
    int max = -1;
    cin>>n>>m;
    bool change;
    int result;
    for(int i = 0; i < n; i++){
        int k = 0;
        cin>>k;
        v.push_back(k);
        if(max <= v[i]) max = v[i]; 
    }
    
    binarySearch(v,0,max,m, result);
    cout<<result;

}