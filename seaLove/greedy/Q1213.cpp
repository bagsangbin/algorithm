#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    
    string s;
    cin >> s;
    vector<int> str(26, 0);
    for (char c : s) str[c - 'A']++;

    int odd_count = 0;
    char mid;
    for (int i = 0; i < 26; i++) {
        if (str[i] % 2 == 1) {
            odd_count++;
            mid = 'A' + i;
        }
    }

    if ((s.length() % 2 == 0 && odd_count > 0) || (s.length() % 2 == 1 && odd_count != 1)) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    vector<char> answer;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < str[i] / 2; j++) {
            answer.push_back('A' + i);
        }
    }

    for (char c : answer) cout << c;
    if (s.length() % 2 == 1) cout << mid;
    reverse(answer.begin(), answer.end());
    for (char c : answer) cout << c;

    return 0;
}