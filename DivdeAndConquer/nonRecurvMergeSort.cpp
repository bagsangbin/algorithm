#include <iostream>
#include <vector>
using namespace std;

// 병합 함수: 두 배열을 병합하는 함수
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    // 두 배열을 비교하여 병합
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // 남은 원소들 추가
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// 비재귀적 병합 정렬 함수
vector<int> mergeSortIterative(vector<int>& arr) {
    int n = arr.size();
    
    // 크기 1부터 시작해서 크기를 두 배씩 늘려가며 병합
    for (int size = 1; size < n; size *= 2) {
        for (int start = 0; start < n; start += 2 * size) {
            int mid = min(start + size, n);
            int end = min(start + 2 * size, n);
            
            // 두 부분 배열 병합
            vector<int> left(arr.begin() + start, arr.begin() + mid);
            vector<int> right(arr.begin() + mid, arr.begin() + end);
            vector<int> merged = merge(left, right);
            
            // 병합된 배열로 arr 업데이트
            for (int i = 0; i < merged.size(); i++) {
                arr[start + i] = merged[i];
            }
        }
    }

    return arr;
}

int main() {
    vector<int> arr = {123, 34, 189, 56, 15, 120, 9, 240};
    
    // 비재귀적 병합 정렬 실행
    vector<int> sortedArr = mergeSortIterative(arr);

    // 결과 출력
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}