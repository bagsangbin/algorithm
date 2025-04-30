#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findMax(vector<int> &v, int begin, int end, int &max){

    if(begin > end) return INT_MIN;
    if(begin == end ) return v[begin];
    int mid = (begin + end) / 2;

    return findMax(v,begin, mid-1, max) >= findMax(v,mid+1, end, max) ? 
            findMax(v,begin, mid-1, max) : findMax(v,mid+1, end, max);
}

int main(){

    vector<int> v = {10, 20, 30, 60, 120, 240, 500, 1200, 2400};

    int max = 0;

    max = findMax(v,0,v.size()-1,max);
    cout<<max;

}