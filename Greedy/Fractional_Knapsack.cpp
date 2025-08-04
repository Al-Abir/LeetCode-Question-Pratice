#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Item {
    double value;
    double weight;

    Item(double v, double w) {
        value = v;
        weight = w;
    }
};
// Comparator to sort items by value/weight ratio in descending order
bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(int capacity, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<Item> items;

    // Create list of items
    for (int i = 0; i < n; i++) {
        items.emplace_back(val[i], wt[i]);
    }

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double maxValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take full item
            maxValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take fractional part
            maxValue += (items[i].value / items[i].weight) * capacity;
            break; // capacity is full
        }
    }

    return maxValue;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    double result = fractionalKnapsack(capacity, val, wt);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
