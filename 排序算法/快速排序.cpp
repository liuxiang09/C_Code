#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
using namespace std;

int partition(vector<int>& arr, int start, int end) {
    int rand_index = rand() % (end - start) + start;
    swap(arr[start], arr[rand_index]);
    int i = start + 1, j = end, pivot = arr[start];
    while (i < j) {
        while (i < j && arr[i] < pivot) i++;
        while (i < j && arr[j] > pivot) j--;
        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    //这个语句同时处理多个情况，包括特殊情况
    if (i == j && arr[j] > pivot) j--;
    swap(arr[j], arr[start]);
    return j;
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = partition(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}

int main() {
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    srand((unsigned)time(0));
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}