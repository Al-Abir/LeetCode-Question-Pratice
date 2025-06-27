#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    int res = 0;

    // Step 1: XOR all array elements and numbers from 1 to n
    for (int i = 1; i <= n; i++) res = res ^ ar[i];
    for (int i = 1; i <= n; i++) res = res ^ i;

    // Step 2: Find rightmost set bit (difference bit)
    int setBit = res & ~(res - 1);

    int L = 0, R = 0;

    // Step 3: Divide numbers into two sets and XOR separately
    for (int i = 1; i <= n; i++) {
        if (ar[i] & setBit)
            L = L ^ ar[i];
        else
            R = R ^ ar[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i & setBit)
            L = L ^ i;
        else
            R = R ^ i;
    }

    // Step 4: Check which one is missing and which is repeating
    bool isLMissing = true;
    for (int i = 1; i <= n; i++) {
        if (ar[i] == L) {
            isLMissing = false;
            break;
        }
    }

    if (isLMissing)
        cout << "Missing Number = " << L << " Repeating Number = " << R << endl;
    else
        cout << "Missing Number = " << R << " Repeating Number = " << L << endl;

    return 0;
}
