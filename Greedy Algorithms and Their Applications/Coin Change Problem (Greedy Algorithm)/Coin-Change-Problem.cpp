#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void greedy_coin_change(vector<int>& denominations, int amount) {
    sort(denominations.rbegin(), denominations.rend()); // Sort in descending order
    cout << "Coins used: ";
    
    for (int coin : denominations) {
        while (amount >= coin) {
            amount -= coin;
            cout << coin << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, amount;
    cout << "Enter the number of denominations: ";
    cin >> n;
    
    vector<int> denominations(n);
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> denominations[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    greedy_coin_change(denominations, amount);

    return 0;
}
