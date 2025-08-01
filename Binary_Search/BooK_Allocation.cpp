#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) {
            return false;
        }

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }
    return students <= m;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = accumulate(arr.begin(), arr.end(), 0);

    int st = 0, end = sum, ans = -1;
    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int n = books.size();
    int m = 2; // number of students

    int result = allocateBooks(books, n, m);
    cout << "Minimum number of pages: " << result << endl;

    return 0;
}
