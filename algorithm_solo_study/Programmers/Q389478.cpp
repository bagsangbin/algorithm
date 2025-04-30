#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    vector<vector<int>> arr;
    int ii=0;
    int answer = 0;
    int index_x = 0;
    int index_y = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % w == 0){
            arr.push_back(vector<int>());
            ii++;
        }
        arr[ii-1].push_back(i+1); // 값 추가
    }
    
    for(int i = 0; i < ceil((double)n / w); i++)
    {
        if(i % 2 == 0)
            reverse(arr[i].begin(), arr[i].end());
    }
    for (int y = 0; y < arr.size(); y++) {
    for (int x = 0; x < arr[y].size(); x++) {
        if (arr[y][x] == num) {
            index_y = y;
            index_x = x;
        }
    }
}
    reverse(arr[arr.size()-1].begin(), arr[arr.size()-1].end());
    for(int i = 0; i < arr[0].size()-arr[arr.size()-1].size(); i++){
        
        arr[arr.size()-1].push_back(-1);
    }
    reverse(arr[arr.size()-1].begin(), arr[arr.size()-1].end());
    
    int result = arr.size()-1 - (index_y);

    if(arr[arr.size()-1][index_x] != -1){
            result += 1;
    }

    return result;
}

