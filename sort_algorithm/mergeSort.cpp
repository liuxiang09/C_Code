#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start1, int end2, vector<int> &res) {
    int end1 = (start1 + end2) / 2, start2 = end1 + 1;
    int i = start1, j = start2, k = start1;
    // 注意条件语句里面要写i和j，不能写start1和start2
    while (i <= end1 && j <= end2) {
        if (arr[i] <= arr[j]) {
            res[k++] = arr[i++];
        } else {
            res[k++] = arr[j++];
        }
    }
    while (i <= end1)
        res[k++] = arr[i++];
    while (j <= end2)
        res[k++] = arr[j++];
    // 把res里面的内容全部转移到arr中
    for (i = start1; i <= end2; i++) {
        arr[i] = res[i];
    }
}

void mergeSort(vector<int> &arr, int start, int end, vector<int> &res) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid, res);
        mergeSort(arr, mid + 1, end, res);
        merge(arr, start, end, res);
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> res(arr.size(), 0);
    mergeSort(arr, 0, arr.size() - 1, res);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}