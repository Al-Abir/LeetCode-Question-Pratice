#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st;
    int j = mid + 1;
    int invertCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invertCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); ++k) {
        arr[st + k] = temp[k];
    }

    return invertCount;
}

int mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = (st + end) / 2;
        int left = mergeSort(arr, st, mid);
        int right = mergeSort(arr, mid + 1, end);
        int mergeInv = merge(arr, st, mid, end);
        return left + right + mergeInv;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {6, 3, 5, 2, 7};
    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "Inversion count: " << ans << "\n";

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    return 0;
}
