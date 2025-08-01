#include<iostream>
using namespace std;

long long power(long long base, int exp) {
    long long result = 1;
    while(exp > 0){
        if(exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        long long midPower = power(mid, n);

        if(midPower == m) return mid;
        else if(midPower < m) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    int result = NthRoot(n, m);
    cout << result << endl;

    return 0;
}
