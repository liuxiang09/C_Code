#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(vector<int>& arr) {
    // 找到数组中的最大值
    int max = *max_element(arr.begin(), arr.end());
    // 创建计数数组
    vector<int> bucket(max + 1, 0);
    // 将数据放入计数数组中
    for (int i = 0; i < arr.size(); i++) {
        bucket[arr[i]]++;
    }
    // 将数组中的数据放回原数组
    int index = 0;
    for (int i = 0; i < bucket.size(); i++) {
        while (bucket[i] > 0) { 
            arr[index++] = i;
            bucket[i]--;
        }
    }
    // 输出排序后的数组
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    // 读入数据
    vector<int> arr = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    // 计数排序
    bucketSort(arr);

    
    return 0;
}