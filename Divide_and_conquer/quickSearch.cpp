#include <algorithm>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// 快速选择的partition函数
int partition(vector<int> &arr, int start, int end) {
    int rand_index = rand() % (end - start) + start;
    swap(arr[start], arr[rand_index]);
    int i = start + 1, j = end, pivot = arr[start];
    while (i < j) {
        while (i < j && arr[i] < pivot)
            i++;
        while (i < j && arr[j] > pivot)
            j--;
        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    // 这段代码处理多种特殊情况
    if (arr[j] > pivot) j--;
    swap(arr[j], arr[start]);
    return j;
}

// 快速选择函数
void quickSelect(vector<int> &arr, int start, int end, int k) {
    if (start >= end) return;

    int pos = partition(arr, start, end);
    int num = pos - start + 1;

    if (num == k) {
        return;
    } else if (num > k) {
        quickSelect(arr, start, pos - 1, k);
    } else {
        quickSelect(arr, pos + 1, end, k - num);
    }
}

// 找到前cnt小的数
vector<int> findKthSmallest(vector<int> arr, int cnt) {
    if (cnt <= 0 || arr.empty()) return vector<int>();
    if (cnt > arr.size()) cnt = arr.size();

    srand((unsigned)time(0));
    quickSelect(arr, 0, arr.size() - 1, cnt);

    vector<int> result(arr.begin(), arr.begin() + cnt);
    sort(result.begin(), result.end()); // 保证返回结果有序
    return result;
}

int main() {
    // 测试样例1: 普通情况，找出前5小的数
    vector<int> arr1 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int cnt1 = 5;
    cout << "Test Case 1 - Finding " << cnt1 << " smallest numbers from: ";
    for (int num : arr1)
        cout << num << " ";
    cout << "\nResult: ";
    for (int num : findKthSmallest(arr1, cnt1))
        cout << num << " ";
    cout << "\n\n";

    // 测试样例2: 边界情况，找出所有数
    vector<int> arr2 = {10, 8, 6, 4, 2};
    int cnt2 = 5;
    cout << "Test Case 2 - Finding " << cnt2 << " smallest numbers from: ";
    for (int num : arr2)
        cout << num << " ";
    cout << "\nResult: ";
    for (int num : findKthSmallest(arr2, cnt2))
        cout << num << " ";
    cout << "\n\n";

    // 测试样例3: 数组中有大量重复元素
    vector<int> arr3 = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    int cnt3 = 4;
    cout << "Test Case 3 - Finding " << cnt3 << " smallest numbers from: ";
    for (int num : arr3)
        cout << num << " ";
    cout << "\nResult: ";
    for (int num : findKthSmallest(arr3, cnt3))
        cout << num << " ";
    cout << endl;

    return 0;
}
