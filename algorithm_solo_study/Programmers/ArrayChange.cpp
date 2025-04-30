#include<iostream>
#include<vector>

using namespace std;

vector<int> solution(vector<int> arr, int k){
    vector<int> answer;
    for(int &a : arr)
    {
        a = k % 2 == 0 ? a + k : a * k;
    }
    answer = arr;
    return answer;
}

int main(){

    ios::sync_with_stdio(0); //성능 향상, 단 printf나 scanf 사용 불가
    cin.tie(0); //
    //줄바꿈시 endl 보다는 \n을 사용할 것.

    vector<int> arr = {1,1,1,1,2};
    arr = solution(arr, 2);

    cout<<arr[0];

}