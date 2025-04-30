//as iterative(use dp)

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int bin2(int n, int k){
    int i, j;
    vector<vector<int>> D(n+1, vector<int>(k+1, 0));

    for(i = 0; i <= n; i++)
        for(j = 0; j < min(i, k); j++){
            if(j == 0 || j == i){
                D[i][j] = 1;
            }
            else{
                D[i][j] = D[i-1][j-1] + D[i-1][j];
            }
        }

    return D[n][k];
}

int bin2UseOneArray(int n, int k){
    vector<int> D(k+1,0);
    int p = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i;  j++){
            if(j == 0 || j == i){
                D[p++] = 1;
            }
            else{
                D[p] = D[p - i] + D[p - i - 1];
                p++;
            }
        }
    }

    p = 0;

    for(int i = 0; i <= n; i++)
        p += i;

    return D[p+k];

}

int main(){
    

    cout << bin2UseOneArray(10, 3) << endl;
}