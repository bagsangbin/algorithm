#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;


int BruteForce(int K, vector<int> &v){


    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v.size(); j++)
            for(int k = 0; k < v.size(); k++)
                if(v[i] + v[j] + v[k] == K)
                    return 1;

    return 0;

    

}


int main(){

    int K, T;
    vector<int> v;

    for(int i = 1; i <= 44; i++){
        v.push_back( i * (i +1) / 2);
    }
    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>K;
        cout<<BruteForce(K,v)<<'\n';
    }


    return 0;
}