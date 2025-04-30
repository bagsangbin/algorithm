//as recursive



#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int bio1(int n, int k){
    if(k == 0 || k == n) return 1;

    else
        return bio1(n-1, k-1) + bio1(n-1,k);
}


int main(){
    

    cout << bio1(3, 1) << endl;
}