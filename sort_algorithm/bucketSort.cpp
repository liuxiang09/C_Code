#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<int> &arr) {
    // 定义桶的数量
    int bucketCount = 10;
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    // 计算每个桶的范围
    int bucketRange = (maxVal - minVal) / bucketCount + 1;

    // 创建桶
    vector<vector<int>> buckets(bucketCount);

    // 将数据放入不同的桶中
    for (int i = 0; i < arr.size(); i++) {
        int index = (arr[i] - minVal) / bucketRange;
        buckets[index].push_back(arr[i]);
    }

    // 对每个桶进行排序，然后放回原数组
    int idx = 0;
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }

    // 输出排序后的数组
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // 读入数据
    vector<int> arr = {1, 31, 5, 7, 9, 2, 4, 6, 8, 0, 10, 61, 45, 21, 31, 123};
    // 桶排序
    bucketSort(arr);

    return 0;
}
