#include <iostream>
#include <vector>

using namespace std;

// 병합(Merge) 함수: 두 개의 정렬된 부분 배열을 합칩니다.
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // 왼쪽 부분 배열 크기
    int n2 = right - mid;    // 오른쪽 부분 배열 크기

    vector<int> leftArr(n1), rightArr(n2);

    // 데이터 복사
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    // 두 개의 부분 배열을 병합
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // 남은 요소 복사 (왼쪽 배열)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // 남은 요소 복사 (오른쪽 배열)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// 병합 정렬 (재귀)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid1 = left + (right - left) / 3; // 왼쪽 중간 인덱스
        int mid2 = right - (right - left) / 3; // 오른쪽 중간 인덱스

        mergeSort(arr, left, mid1);    // 첫번째 정렬
        mergeSort(arr, mid1 + 1, mid2); // 두번쨰 정렬
        mergeSort(arr, mid2 + 1, right); // 세번째 정렬

        merge(arr, left, mid1, mid2);
    
        merge(arr, left, mid2, right);
    }
}

// 메인 함수
int main()
{

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "정렬 전: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "정렬 후: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}