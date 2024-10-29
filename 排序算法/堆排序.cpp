#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void maxHeapify(vector<int>& arr, int i, int HeapSize) {
    if (i < HeapSize) {
        int left = 2 * i, right = left + 1;
        int largest = i;
        
        if (left < HeapSize && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < HeapSize && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[largest], arr[i]);
            maxHeapify(arr, largest, HeapSize);
        }
    }
}

void buildMaxHeap(vector<int>& arr) {
    int len = arr.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, len);
    }
}

void heapSort(vector<int>& arr) {
    int len = arr.size();
    buildMaxHeap(arr);
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

int main() {
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}