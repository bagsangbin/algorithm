#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<limits.h>
#include<set>
#include<sstream>
#include<map>

using namespace std;

// void travel(int n, vector<vector<int>> W, vector<vector<int>> &P, pair<string, int> startNode, 
//     vector<pair<string, int>> V, int& minLength, map<set<int>, int>& subsetToIndex);

//     void printShortestPath(pair<string, int> startNode, vector<vector<int>> P, map<set<int>, int>& subsetToIndex, vector<pair<string, int>> V, int minLength);

    void travel(int n, vector<vector<int>> W, pair<string, int> startNode, 
        vector<pair<string, int>> V, int& minLength);
int main(int argc, char *argv[])
{
    ifstream file(argv[1]);
    int n;
    if(!file.is_open()){
        cout << "파일 오픈 에러." << endl;
        return -1;
    }

    vector<pair<string, int>> S;
    pair<string, int> startNode;
    int minLength = INT_MAX;
    int i = 0;
    string str;
    
    if(getline(file,str)) str = str.substr(0, str.find(' '));
    startNode.first = str;

    getline(file, str);
    str = str.substr(0, str.find("//"));
    istringstream isstr(str);
    while(isstr >> str){
        S.push_back(make_pair(str, i++));
        if(startNode.first == str) startNode.second = i-1;
    }

    //여기 까지 그래프 읽어오는 파트

    n = S.size();
    //weight matrix
    vector<vector<int>> W(n+1,vector<int>(n+1, INT_MAX));
    map<set<int>, int>subsetToIndex;

    while(getline(file, str)){

        string startNode2 = str.substr(0, str.find(" # "));
        string endNode = str.substr(startNode2.length() + 3, str.find(" # ", startNode2.length() + 3) - startNode2.length() - 3);
        int weight = stoi(str.substr(endNode.length() + startNode2.length() + 6));

        for(int i = 0; i < n; i++){
            W[i][i] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(S[i].first == startNode2 && S[j].first == endNode){
                    W[i][j] = weight;
                }
            }
    }
    int a = 0;
    travel(n,W, startNode, S, minLength);
    
}

void travel(int n, vector<vector<int>> W, pair<string, int> startNode, 
    vector<pair<string, int>> V, int& minLength) {
    
    V.erase(remove(V.begin(), V.end(), startNode), V.end());
    
    vector<set<int>> allSubsets;
    allSubsets.push_back(set<int>());
    //공집합 시작
    
    for (const auto& vertex : V) {
        int currentSize = allSubsets.size();
        for (int i = 0; i < currentSize; i++) {
            set<int> newSet = allSubsets[i];
            newSet.insert(vertex.second);
            allSubsets.push_back(newSet);
        }
    }
    
    map<set<int>, int> subsetToIndex;
    for (int i = 0; i < allSubsets.size(); i++) {
        subsetToIndex[allSubsets[i]] = i;
    }
    
    vector<vector<int>> D(n+1, vector<int>(allSubsets.size(), INT_MAX));

    //PathNext gpt 사용
    //
    vector<vector<int>> pathNext(n+1, vector<int>(allSubsets.size(), -1));
    
    //D[i][0] = W[i][startNode]
    for (int i = 0; i < n; i++) {
        if (i != startNode.second) {
            D[i][0] = W[i][startNode.second];
        }
    }
    
    // k = 부분집합의 크기
    for (int k = 1; k <= n-2; k++) {
        for (int subsetIdx = 0; subsetIdx < allSubsets.size(); subsetIdx++) {
            //k개의 부분 집합에 대해서만 다룬다.
            if (allSubsets[subsetIdx].size() == k) {
                const set<int>& A = allSubsets[subsetIdx];
            
                for (int i = 0; i < n; i++) {
                    if (i != startNode.second && A.find(i) == A.end()) {
                        D[i][subsetIdx] = INT_MAX;
                        
                        for (int j : A) {
                            set<int> A_minus_j = A;
                            A_minus_j.erase(j);
                            
                            int submaskIdx = subsetToIndex[A_minus_j];
                            if (W[i][j] != INT_MAX && D[j][submaskIdx] != INT_MAX) {
                                int newDist = W[i][j] + D[j][submaskIdx];
                                if (newDist < D[i][subsetIdx]) {
                                    D[i][subsetIdx] = newDist;
                                    pathNext[i][subsetIdx] = j;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // D[1][V-{startNode}] 계산
    set<int> allVerticesExceptStart;
    for (const auto& v : V) {
        allVerticesExceptStart.insert(v.second);
    }
    
    int fullSetIdx = subsetToIndex[allVerticesExceptStart];
    D[startNode.second][fullSetIdx] = INT_MAX;
    
    // D[1][V-{startNode}] = minimum (W[1][j] + D[j][V-{v_1,v_j}])
    for (int j = 0; j < n; j++) {
        if (j != startNode.second) {
            // V - {v_1,v_j} 계산
            set<int> V_minus_1_j = allVerticesExceptStart;
            V_minus_1_j.erase(j);
            
            int submaskIdx = subsetToIndex[V_minus_1_j];
            if (W[startNode.second][j] != INT_MAX && D[j][submaskIdx] != INT_MAX) {
                int newDist = W[startNode.second][j] + D[j][submaskIdx];
                if (newDist < D[startNode.second][fullSetIdx]) {
                    D[startNode.second][fullSetIdx] = newDist;
                    pathNext[startNode.second][fullSetIdx] = j; // 최소값을 준 j 저장
                }
            }
        }
    }
    
    // 최단거리
    minLength = D[startNode.second][fullSetIdx];
    
if (minLength != INT_MAX) {
    map<int, string> indexToName;
    for (const auto& vertex : V) {
        indexToName[vertex.second] = vertex.first;
    }
    indexToName[startNode.second] = startNode.first;
    
    int current = startNode.second;
    set<int> remainingSet = allVerticesExceptStart;

    cout<<startNode.first<<" ";

    while (!remainingSet.empty()) {
        int next = pathNext[current][subsetToIndex[remainingSet]];
        if (next != -1) {
            cout<< indexToName[next]<<" ";
            remainingSet.erase(next);
            current = next;
        } else {
            cout << "Lost Tour";
            break;
        }
    }
    } else {
        cout << "No Tour"<< endl;
    }
}