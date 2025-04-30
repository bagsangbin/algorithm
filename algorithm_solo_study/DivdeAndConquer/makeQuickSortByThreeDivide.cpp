#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> &v);
void quickSort(vector<int> &v, int start, int end);
void partition(vector<int> &v, int start, int end, int &p);
void swap(int &a, int &b);

int main(){

    vector<int> v = {2, 1, 5, 4, 3, 6, 7, 2 , 5 , 4, 8, 100,200,40,60};
    quickSort(v);

    for(auto k : v){
        cout<<k<<" ";
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void partition(vector<int> &v, int start, int end, int &p){
    int pivot = v[start]; // 피벗값으로 첫 번째 요소 선택
    int i = start + 1;
    int j = end;
    
    while(i <= j){
        // 피벗보다 큰 값을 찾을 때까지 i 증가
        while(i <= end && v[i] <= pivot)
            i++;
            
        // 피벗보다 작은 값을 찾을 때까지 j 감소
        while(j > start && v[j] >= pivot)
            j--;
            
        // i와 j가 교차하지 않았다면 두 값을 교환
        if(i < j)
            swap(v[i], v[j]);
    }
    
    // 피벗을 올바른 위치로 이동
    swap(v[start], v[j]);
    p = j;
}


void quickSort(vector<int> &v){
    quickSort(v, 0, v.size() - 1);
}

void quickSort(vector<int> &v, int start, int end){
    if(start < end){
        int partiPoint;
        partition(v, start, end, partiPoint);
        quickSort(v, start, partiPoint - 1);
        quickSort(v, partiPoint + 1, end);
    }
}