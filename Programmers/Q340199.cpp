#include <string>
#include <vector>
#include <math.h>
#include<iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while((wallet[1] < bill[1] || wallet[0] < bill[0]) && (wallet[1] < bill[0] || wallet[0] < bill[1])){
        if(bill[0] > bill[1]){
            bill[0] = trunc(bill[0] / 2);
            answer++;
        } 
        else{
            bill[1] = trunc(bill[1] / 2);
            answer++;
        }
    }
    return answer;
}

int main(){
    vector<int> A;
    vector<int> B;
    A.push_back(30);
    A.push_back(15);
    B.push_back(26);
    B.push_back(17);
    cout<<solution(A,B);

}