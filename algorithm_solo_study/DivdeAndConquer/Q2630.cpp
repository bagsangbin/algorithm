#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void makeQuardDivide(vector<vector<int>> &arr, int start_x, int end_x,int start_y, int end_y, int &w, int &b);


void makeQuardDivide(vector<vector<int>> &arr, int start_x, int end_x,int start_y, int end_y, int &w, int &b){

    if(start_x >= end_x) return;

    int k = arr[start_x][start_y];
    for(int i = start_x; i < end_x; i++){
        for(int j = start_y; j < end_y; j++){
            if(k!=arr[i][j])
            {
                int mid_x = (start_x + end_x) / 2;
                int mid_y = (start_y + end_y) / 2;

                makeQuardDivide(arr, mid_x, end_x, start_y, mid_y, w, b);  // 우상단
                makeQuardDivide(arr, start_x, mid_x, mid_y, end_y, w, b);  // 좌하단
                makeQuardDivide(arr, mid_x, end_x, mid_y, end_y, w, b);  // 우하단
                makeQuardDivide(arr, start_x, mid_x, start_y, mid_y, w, b);  // 좌상단
                return;
            }
            
        }
    }

    k == 1 ? b++ : w++;

}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    int w = 0;
    int b = 0;

    cin>>N;

    vector<vector<int>> arr(N,vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>arr[i][j];
        }
    }

    makeQuardDivide(arr,0,N,0,N,w,b);

    cout<<w;
    cout<<'\n'<<b;
    

}