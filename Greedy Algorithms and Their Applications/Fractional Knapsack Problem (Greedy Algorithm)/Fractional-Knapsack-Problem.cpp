#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator function to sort by value-to-weight ratio
bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare); // Sort in descending order
    double totalValue = 0.0;

    for (Item item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    cout << "Maximum value in Knapsack: " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
