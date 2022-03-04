/*
    常用算法的实现
 */

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (arr[j] < pivot) {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = partition(arr, l, r);
        quick_sort(arr, l, mid - 1);
        quick_sort(arr, mid + 1, r);
    }
}

// int main()
// {
//     vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     quick_sort(arr, 0, arr.size() - 1);
//     for (auto num: arr) {
//         cout<<num<<" ";
//     }
//     cout<<"\n";
// }