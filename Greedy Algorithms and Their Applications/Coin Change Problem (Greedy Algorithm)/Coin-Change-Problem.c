#include <stdio.h>

void greedy_coin_change(int denominations[], int n, int amount) {
    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        while (amount >= denominations[i]) {
            amount -= denominations[i];
            printf("%d ", denominations[i]);
        }
    }
    printf("\n");
}

// Sorting function (Descending Order)
void sort_desc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, amount;
    printf("Enter the number of denominations: ");
    scanf("%d", &n);
    
    int denominations[n];
    printf("Enter the denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &denominations[i]);
    }

    printf("Enter the amount: ");
    scanf("%d", &amount);

    sort_desc(denominations, n);
    greedy_coin_change(denominations, n, amount);

    return 0;
}
