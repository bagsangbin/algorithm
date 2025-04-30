#include<iostream>
#include<vector>
using namespace std;

void divide(vector<int> &v, int left, int right, int key, int &keyPoint){
    
    int dividePoint1 = left + (right - left) / 3;
    int dividePoint2 = right - (right - left) / 3;
    
    if(left > right) return;
    
    if(v[dividePoint1] == key || v[dividePoint2] == key) {
        keyPoint = key == v[dividePoint1] ? dividePoint1 : dividePoint2;
        return;
    }

    if(v[dividePoint1] > key) {
        divide(v,left, dividePoint1-1, key, keyPoint);
    }
    else if(v[dividePoint1] < key && key < v[dividePoint2])
    {
        divide(v,dividePoint1+1,dividePoint2-1,key,keyPoint);
    }
    else if(v[dividePoint2] < key){
        divide(v,dividePoint2+1,right, key, keyPoint);
    }

}


int main(){
    vector<int> v = {10, 20, 30, 60, 120, 240, 500, 1200, 2400, 3600, 8000, 160000};
    int keyPoint = -1;

   divide(v,0,v.size()-1,160000, keyPoint);

   cout << keyPoint;
    
}