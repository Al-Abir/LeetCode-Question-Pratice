#include <bits/stdc++.h>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];     // pivot element
    int i = low - 1;           // index of smaller element

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;              // pivot index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // left subarray
        quickSort(arr, pi + 1, high);  // right subarray
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Before sorting: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "After sorting: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
