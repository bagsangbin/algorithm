#include<iostream>
#include<vector>
#include<queue>

using namespace std;



int main(){

     string s;
     cin>>s;

     vector<string> tokens;
     string temp;

     for(char c : s){
        if(c == '-'){
            tokens.push_back(temp);
            temp = "-";
        } else {
            temp += c;
        }
     }

     tokens.push_back(temp);
     int result = 0;
     bool first = true;

     for(string tk : tokens){
        int sum = 0;
        
     }

}