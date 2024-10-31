#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


void Counting_Sort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> temp(n);
    int count[10] = { 0 }; 


    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

 
    for (int i = n - 1; i >= 0; i--) {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }


    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}


void Radix_Sort(vector<int>& arr) {

    int max_val = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max_val / exp > 0; exp *= 10)
        Counting_Sort(arr, exp);
}


int main() {
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    Radix_Sort(arr);
    for (int num : arr)
        cout << num << " ";
    return 0;
}