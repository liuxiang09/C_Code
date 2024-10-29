#include <iostream>
#include <vector>

using namespace std;

// 希尔排序
void shellSort(vector<int>& arr){
    int n = arr.size();
    for(int gap = n /2;gap>=1;gap/=2){
        for(int current=gap;current<n;current++){
            int current_num = arr[current];
            int pre_index = current - gap;
            while(pre_index >= 0 && arr[pre_index] > current_num ){
                arr[pre_index + gap] = arr[pre_index];
                pre_index -= gap;
            }
            arr[pre_index + gap] = current_num;
        }
    }
}

int main(){
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    shellSort(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}