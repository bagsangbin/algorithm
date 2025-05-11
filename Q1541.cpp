#include<iostream>
#include<vector>
#include<queue>

using namespace std;

string opperand(string s, string num1, string num2, char oper){
    string answer;
    switch (oper){
        case '+':
            answer = stoi(num1) + stoi(num2);
            break;
        case '-':
            answer = stoi(num1) - stoi(num2);
            break;
    }

    return answer;

}

void greed(string s){
    
    queue<char> q;
    string num2;
    string num1;
    char oper;
    for(const auto it : s) q.push(it);

    for(int i = 0; i < s.size(); i++){

        if(s[i] == '+' || s[i] == '-'){
            oper = s[i];
            for(int j = i+1; j < s.size(); j++){
                if(s[j] == '+' || s[j] == '-'){
                    num2 = string(s.begin() + i + 1, s.begin()+ j - 1);
                }
            }

            for(int k = i-1; k >= 0; k++){
                if(s[k] == '+' || s[k] == '-')
                    num1 = string(s.begin() + k, s.begin() + i - 1);
            }
        }
        cout<<opperand(s, num1, num2,oper);
    }
}


int main(){

     string s;
     cin>>s;
    greed(s);

}